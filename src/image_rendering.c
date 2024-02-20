/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:27:50 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/20 18:24:03 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


// t_img *init_img(char *path, int height, int width)
// {
//     t_img *img;
    
//     img->path = path;
//     img->height = height;
//     img->width = width;
//     return (img);
// }
void render_image(void	*mlx_ptr, void	*win_ptr, t_img *img, int position_x, int position_y)
{
    // void *img = 
    // if (!img)
    //     return (NULL);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img, position_x, position_y); 
}