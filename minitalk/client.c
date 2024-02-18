/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:00:37 by medalgic          #+#    #+#             */
/*   Updated: 2023/10/16 18:59:44 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	d;
	int	result;

	i = 0;
	d = 1;
	result = 0;
	if (str[i] == '-')
	{
		d = d * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10);
		result = result + (str[i] - '0');
		i++;
	}
	return (result * d);
}

void	client(char a, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((a >> i & 1) == 1)
		{
			kill (pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(1000);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(av[1]);
	if (0 > pid)
	{
		write(1, "pid negative", 13);
		return (0);
	}
	while (av[2][i])
	{
		client(av[2][i], pid);
		i++;
	}
}
