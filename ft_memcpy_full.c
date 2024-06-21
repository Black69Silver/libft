/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 02:25:17 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies 'n' bytes from memory area 'src' to memory area 'dst'.
 * If 'dst' and 'src' overlap, behavior is undefined. */

/* An advantage of void pointers: malloc() and calloc() return 'void *' type.
 * Void pointers allow them to be used to allocate memory of any data type */

#include <stdio.h>
#include <string.h>
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

int	main(void)
{
	char	*src;
	char	dst[1] = "";
	size_t	n;

//	src = "This is a string.h library function.";
	src = "";
	n = 12;
	printf("  %zu chars to copy from: %s\n", n, src);
	printf("Written function result: %s\n", ft_memcpy (dst, src, n));
	printf("Library function result: %s\n", memcpy (dst, src, n));
	return (0);
}
