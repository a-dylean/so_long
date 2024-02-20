/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:27:50 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/20 16:41:18 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


t_img *init_img(char path, int height, int width)
{
    t_img *img;
    
    img->img_height = height;
    return (img);
}
void render_image(void	*mlx_ptr, void	*win_ptr, t_img *img, int position_x, int position_y)
{
    void *img = mlx_xpm_file_to_image(mlx_ptr, img->relative_path, &img->img_width, &img->img_height);
    if (!img)
        return (NULL);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img, position_x, position_y); 
}