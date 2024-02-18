/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 05:06:12 by medalgic          #+#    #+#             */
/*   Updated: 2023/07/22 05:06:12 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(int a)
{
	int	ret;
	int	tmp;

	ret = 0;
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	if (a < 0)
	{
		tmp = write(1, "-", 1);
		if (tmp == -1)
			return (-1);
		ret += tmp;
		a *= -1;
	}
	if (a > 9)
	{
		tmp = ft_int(a / 10);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (write(1, &"0123456789"[a % 10], 1) == -1)
		return (-1);
	return (ret + 1);
}

int	ft_hex(unsigned int a, char c)
{
	int	ret;
	int	tmp;

	tmp = 0;
	ret = 0;
	if (a >= 16)
		tmp = ft_hex(a / 16, c);
	if (tmp == -1)
		return (-1);
	ret += tmp;
	if (c == 'X')
		if (write(1, &"0123456789ABCDEF"[a % 16], 1) == -1)
			return (-1);
	if (c == 'x')
		if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
			return (-1);
	return (ret + 1);
}

int	ft_point(unsigned long a, int sign)
{
	int	ret;
	int	tmp1;
	int	tmp2;

	tmp1 = 0;
	tmp2 = 0;
	ret = 0;
	if (sign == 1)
	{
		tmp1 = write(1, "0x", 2);
		if (tmp1 == -1)
			return (-1);
		ret += tmp1;
		sign = 0;
	}
	if (a >= 16)
		tmp2 = ft_point(a / 16, 0);
	if (tmp2 == -1)
		return (-1);
	ret += tmp2;
	if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
		return (-1);
	return (ret + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		if (write(1, &str[i], 1) == -1)
			return (-1);
	return (i);
}

int	ft_unsigned(unsigned int a)
{
	int	ret;
	int	tmp;

	tmp = 0;
	ret = 0;
	if (a >= 10)
		tmp = ft_unsigned(a / 10);
	if (tmp == -1)
		return (-1);
	ret += tmp;
	if (write(1, &"0123456789"[a % 10], 1) == -1)
		return (-1);
	return (ret + 1);
}
