/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/16 22:43:24 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Sets the first "n" positions of a string pointed to by "str" with
 * the value of an unsigned char "c". */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	adj_c;
	unsigned char	*adj_str;

	i = 0;
	adj_c = (unsigned char) c;
	adj_str = str;
	while (i < n)
	{
		adj_str[i] = adj_c;
		i++;
	}
	return (adj_str);
}
