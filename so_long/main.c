/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 05:42:30 by abulut            #+#    #+#             */
/*   Updated: 2023/11/07 18:18:48 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./ft_printf/ft_printf.h"
#include "./minilibx/mlx.h"
#include "stdlib.h"
#include "fcntl.h"

void	err_msg(char *err, t_game *data)
{
	int	line;

	line = 0;
	ft_printf("%s", err);
	if (data)
	{
		while (line <= data->map_height - 1)
			free(data->map[line++]);
		free(data->map);
	}
	exit(1);
}

int	copen(const char *fn)
{
	int	fd;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		err_msg2("map not open");
	return (fd);
}

static void	*ftt_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = c;
		i++;
	}
	return (s);
}

int	exit_point(t_game *data)
{
	int	line;

	line = 0;
	if (data->winpointer)
		mlx_destroy_window(data->mlxpointer, data->winpointer);
	free(data->mlxpointer);
	while (line <= data->map_height - 1)
		free(data->map[line++]);
	free(data->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		err_msg2("There should be 1 map!");
	ftt_memset(&data, 0, sizeof(t_game));
	map_control(argv[1], &data);
	map_reading(&data);
	map_processing(&data);
	wall_control(&data);
	data.mlxpointer = mlx_init();
	images_in_game(&data);
	data.winpointer = mlx_new_window(data.mlxpointer, (data.map_width * 120),
			(data.map_height * 120), "solong");
	adding_in_graphics(&data);
	map_bug(&data);
	placeholder(&data, data.x_axis, data.y_axis);
	mlx_hook(data.winpointer, 2, 0, controls_working, &data);
	mlx_hook(data.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(data.mlxpointer);
	return (0);
}
