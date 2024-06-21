/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/12/09 22:24:09 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copy up to 'dstsize'-1 characters from 'src' string to 'dst' string,
 * add '\0' to the end if 'dstsize' is not 0.
 * Calculate and return the total length of 'src' string. */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (dstsize < 1)
		return (len_src);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	printf("Destination result: %s\n", dst);
	return (len_src);
}

int	main(void)
{
	char	src[] = "Text (to be) copied from src to dest.";
	size_t	dstsize = 7;
	char	dst[dstsize];

	printf("Copy %zu chars from: %s\n", dstsize - 1, src);
	printf("Written function result: %lu\n", ft_strlcpy (dst, src, dstsize));
	printf("Library function result: %lu\n", strlcpy (dst, src, dstsize));
	return (0);
}
