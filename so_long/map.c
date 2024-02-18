/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:08:30 by medalgic          #+#    #+#             */
/*   Updated: 2023/11/07 18:16:49 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void	ber_control(char *map_name)
{
	int	arg_len;

	arg_len = ft_strlen(map_name);
	if (map_name[arg_len - 1] != 'r' || map_name[arg_len - 2] != 'e'
		|| map_name[arg_len - 3] != 'b' || map_name[arg_len - 4] != '.')
		err_msg2("Map must have .ber extension!");
}

void	tmp_control(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		err_msg2("Map not found!");
	close(fd);
}

void	map_control(char *map_name, t_game *data)
{
	ber_control(map_name);
	data->maplocation = ft_strjoin("map/", map_name);
	tmp_control(data->maplocation);
}

void	*cmalloc(long int i)
{
	void	*c;

	c = NULL;
	c = malloc(i);
	if (!c)
		err_msg2("malloc error");
	while (0 <= i)
	{
		((char *)c)[i] = 0;
		i--;
	}
	return (c);
}

void	err_msg2(char *err)
{
	ft_printf("%s", err);
	exit(1);
}
