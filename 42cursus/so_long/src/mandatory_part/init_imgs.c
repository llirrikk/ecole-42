/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:55:09 by sserwyn           #+#    #+#             */
/*   Updated: 2022/01/30 22:17:45 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	*init_img_utils(void *mlx_ptr, char *filename)
{
	void	*result;
	int		wight;
	int		height;

	wight = 0;
	height = 0;
	result = mlx_xpm_file_to_image(mlx_ptr, filename, &wight, &height);
	return (result);
}

void	init_imgs(t_mlx *mlx, t_img *img)
{
	img->empty = init_img_utils(mlx->ptr, "./images/floor.xpm");
	img->wall = init_img_utils(mlx->ptr, "./images/wall.xpm");
	img->collectable_item = init_img_utils(mlx->ptr, "./images/bone.xpm");
	img->exit = init_img_utils(mlx->ptr, "./images/home.xpm");
	img->player = init_img_utils(mlx->ptr, "./images/dog.xpm");
}
