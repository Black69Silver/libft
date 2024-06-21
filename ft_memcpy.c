/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/26 17:00:11 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies 'n' bytes from memory area 'src' to memory area 'dst'.
 * If dst and src overlap, behavior is undefined. */

/* An advantage of void pointers: malloc() and calloc() return void * type.
 * Void pointers allow them to be used to allocate memory of any data type */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*adj_dst;
	unsigned char	*adj_src;

	i = 0;
	adj_dst = dst;
	adj_src = (unsigned char *) src;
	if (dst == NULL && src == NULL && n > 0)
		return (NULL);
	while (i < n)
	{
		adj_dst[i] = adj_src[i];
		i++;
	}
	return (adj_dst);
}
