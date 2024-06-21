/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/15 21:22:17 by ggeorgie         ###   ########.fr       */
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

#include <stdio.h>
#include <string.h>
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
	printf("Inputs: len_src: %zu, len_dst: %zu, dstsize: %zu\n", len_src, len_dst, dstsize);
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

int	main(void)
{
	char	dest_expected[100] = "abcdef";
	char	dest_actual[100] = "abcdef";
	char	src[4] = "123";
	size_t	expected;
	size_t	actual;
	size_t	len_dest_expected;
	size_t	len_dest_actual;

	printf("\nsource string: %s \ndestination string: %s\n\n", src, dest_expected);
	len_dest_expected = ft_strlen(dest_expected);
	len_dest_actual = ft_strlen(dest_actual);
	for (int dstsize = 0; dstsize < 21; dstsize++)
	{
		dest_expected[len_dest_expected] = 0;
		dest_actual[len_dest_actual] = 0;
		expected = strlcat(dest_expected, src, dstsize);
		actual = ft_strlcat(dest_actual, src, dstsize);

		if (strcmp(dest_expected, dest_actual) != 0)
			printf("ERROR! ");
		else
			printf(" OK :) ");
		printf(" Dest string, expected: %s, actual: %s\n", dest_expected, dest_actual);

		if (expected != actual)
			printf("ERROR! ");
		else
			printf(" OK :) ");
		printf("Return value, expected: %lu, actual: %lu\n\n", expected, actual);
	}
}
