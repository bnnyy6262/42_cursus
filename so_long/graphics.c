/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:08:01 by medalgic          #+#    #+#             */
/*   Updated: 2023/11/07 18:01:21 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx/mlx.h"

void	place_player(t_game *data, int height, int width)
{
	mlx_put_image_to_window(data->mlxpointer,
		data->winpointer, data->player, width * 120, height * 120);
	data->y_axis = height;
	data->x_axis = width;
}

void	place_collectable(t_game *data, int height, int width)
{
	mlx_put_image_to_window(data->mlxpointer,
		data->winpointer, data->collectable, width * 120, height * 120);
	data->collectables++;
}

void	images_in_game(t_game *data)
{
	int	i;
	int	j;

	data->floor = mlx_xpm_file_to_image(data->mlxpointer,
			"images/flour.xpm", &i, &j);
	data->barrier = mlx_xpm_file_to_image(data->mlxpointer,
			"images/wall.xpm", &i, &j);
	data->player = mlx_xpm_file_to_image(data->mlxpointer,
			"images/dog.xpm", &i, &j);
	data->exit = mlx_xpm_file_to_image(data->mlxpointer,
			"images/cat.xpm", &i, &j);
	data->collectable = mlx_xpm_file_to_image(data->mlxpointer,
			"images/bread.xpm", &i, &j);
	if (!(data->floor && data->barrier && data->player
			&&data->exit && data->mlxpointer))
		image_control(data);
}

void	adding_in_graphics(t_game *data)
{
	int	height;
	int	width;

	data->collectables = 0;
	height = -1;
	while (++height < data->map_height)
	{
		width = -1;
		while (data->map[height][++width])
		{
			if (data->map[height][width] == '1')
				mlx_put_image_to_window(data->mlxpointer,
					data->winpointer, data->barrier, width * 120, height * 120);
			if (data->map[height][width] == 'C')
				place_collectable(data, height, width);
			if (data->map[height][width] == 'P')
				place_player(data, height, width);
			if (data->map[height][width] == 'E')
				mlx_put_image_to_window(data->mlxpointer,
					data->winpointer, data->exit, width * 120, height * 120);
			if (data->map[height][width] == '0')
				mlx_put_image_to_window(data->mlxpointer,
					data->winpointer, data->floor, width * 120, height * 120);
		}
	}
}

void	image_control(t_game *data)
{
	if (data->floor)
		mlx_destroy_image(data->mlxpointer, data->floor);
	if (data->barrier)
		mlx_destroy_image(data->mlxpointer, data->barrier);
	if (data->player)
		mlx_destroy_image(data->mlxpointer, data->player);
	if (data->exit)
		mlx_destroy_image(data->mlxpointer, data->exit);
	if (data->collectable)
		mlx_destroy_image(data->mlxpointer, data->collectable);
	err_msg("image error", data);
}
