/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/26 17:29:44 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copy 'n' bytes from memory area 'src' to memory area 'dst'
 * in a non-destructive manner, i.e. even if they overlap.
 * Compare 'src' and 'dst' addresses to find which is higher.
 * If 'dst' > 'src', copy from end to beginning. 
 * If 'dst' < 'src', copy from beginning to end. */

#include <sys/types.h>
#include "libft.h"

void	*from_end(unsigned char *adj_dst, unsigned char *adj_src, ssize_t n)
{
	ssize_t	i;

	i = n - 1;
	while (i >= 0)
	{
		adj_dst[i] = adj_src[i];
		i--;
	}
	return (adj_dst);
}

void	*from_begin(unsigned char *adj_dst, unsigned char *adj_src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		adj_dst[i] = adj_src[i];
		i++;
	}
	return (adj_dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*adj_dst;
	unsigned char	*adj_src;

	adj_dst = dst;
	adj_src = (unsigned char *) src;
	if (dst > src)
		return (from_end(adj_dst, adj_src, n));
	else if (dst < src)
		return (from_begin(adj_dst, adj_src, n));
	else
		return (adj_src);
}
