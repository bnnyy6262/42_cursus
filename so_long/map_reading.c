/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 05:42:42 by abulut            #+#    #+#             */
/*   Updated: 2023/11/07 18:02:08 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./gnl/get_next_line.h"
#include "unistd.h"

void	wall_control(t_game *data)
{
	int	i;
	int	j;
	int	width;
	int	height;

	j = 0;
	i = 0;
	width = data->map_width - 1;
	height = data->map_height - 1;
	while (i <= height)
	{
		if (data->map[i][0] != '1' || data->map[i][width] != '1')
			err_msg("The map is not covered with walls!", data);
		i++;
	}
	while (j <= width)
	{
		if (data->map[0][j] != '1' || data->map[height][j] != '1')
			err_msg("The map is not covered with walls!", data);
		j++;
	}
}

static void	size_control(t_game *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != 'C' && line[i] != 'P' && line[i] != 'E'
			&& line[i] != '1' && line[i] != '0')
			err_msg("Map is wrong!", data);
		i++;
	}
	if (i != data->map_width)
		err_msg("Line in text is wrong!", data);
}

void	map_processing(t_game *data)
{
	int		fd;
	char	*line;

	data->index.i = 0;
	data->map = (char **)cmalloc(sizeof(char *) * (data->map_height + 1));
	fd = copen(data->maplocation);
	while (data->index.i < data->map_height)
	{
		data->index.j = 0;
		line = get_next_line(fd);
		size_control(data, line);
		data->map[data->index.i]
			= (char *)cmalloc(sizeof(char) * (data->map_width + 1));
		if (line == NULL)
			break ;
		while (data->index.j < data->map_width)
		{
			data->map[data->index.i][data->index.j] = line[data->index.j];
			data->index.j++;
		}
		data->map[data->index.i][data->index.j] = '\0';
		data->index.i++;
		free(line);
	}
	close(fd);
}

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\n' && string[width] != '\0')
		width++;
	return (width);
}

void	map_reading(t_game *data)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

	y = 0;
	fd = copen(data->maplocation);
	line = get_next_line(fd);
	x = width_of_map(line);
	while (1)
	{
		free(line);
		y++;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	if (line)
		free(line);
	data->map_height = y;
	data->map_width = x;
	if (data->map_width == 1 || data->map_height == 1)
		err_msg("Map is not rectangular!", data);
	close(fd);
}
