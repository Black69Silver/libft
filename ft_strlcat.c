/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/15 21:22:27 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 1. Append to 'dst' string characters from 'src' string,
 *    so that the final length of 'dst' string is not longer than either
 *    'dstsize' - 1 and
 *    the length of original 'dst' string + the length of 'src' string.
 *    Then add '\0' to the end.
 * N.B. If 'dstsize' is more than the length reserved for
 *	  the original 'dst' string, the function returns an error.
 * 2. Return the length of 'src' string + the smaller of
 *    the length of 'dst' string and 'dstsize'.
 */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dst;
	size_t	output;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = 0;
	if (len_dst < dstsize)
		output = len_src + len_dst;
	else
		output = len_src + dstsize;
	while (src[i] && len_dst + i + 1 < dstsize
		&& len_dst + i < len_dst + len_src)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (output);
}
