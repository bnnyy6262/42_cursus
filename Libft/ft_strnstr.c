/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:31:51 by medalgic          #+#    #+#             */
/*   Updated: 2023/07/07 19:31:53 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	len_n;

	len_n = ft_strlen(needle);
	if (len_n == 0)
		return ((char *)haystack);
	if (len == 0)
		return ((char *) 0);
	i = 0;
	while (i <= (len - len_n) && haystack[i] != '\0')
	{
		if (ft_strncmp(&haystack[i], needle, len_n) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return ((char *) 0);
}
