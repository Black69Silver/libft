/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2024/01/17 16:50:31 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 'haystack' and 'needle' are null-terminated strings. 
 * Not more than 'len' characters are searched.
 * Characters that appear after a `\0' character are not searched.
 */

#include <stdio.h>
#include <string.h>
#include "libft.h"

/**
 * @brief	Locate the first occurrence of 'needle' in 'haystack'. 
 * @param	char	*haystack : a string to search in.
 * @param	char	*needle : a string to search for.
 * @param	size_t	len : number of characters in 'haystack' to be searched.
 * @return	If 'needle' is an empty string, 'haystack' is returned.
 * 			If 'needle' occurs nowhere in 'haystack', NULL is returned.
 * 			Otherwise a pointer to the first character of
 * 			the first occurrence of 'needle' is returned.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_h;
	size_t	i_n;

//	printf("\thaystack: %s\n", haystack);
//	printf("\tneedle: %s\n", needle);
	i_h = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i_h] && i_h < len)
	{
		i_n = 0;
		if (haystack[i_h] == needle[i_n])
		{
			while (haystack[i_h + i_n] == needle[i_n] && i_h + i_n < len
				&& haystack[i_h + i_n] && needle[i_n])
				i_n++;
			if (needle[i_n] == '\0')
				return ((char *)&haystack[i_h]);
		}
		i_h++;
	}
//	printf("position in haystack: %zu, position in needle: %zu, needle: %s\n", i_h, i_n, needle);
//	printf("Leftover string: %s\n\n", &haystack[i]);
	return (NULL);
}

int	main(void)
{
//	const char	haystack[] = "The quick brown fox jumps over the lazy dog";
//	const char	needle[] = "brown";
//	const char	haystack[] = "MZIRIBMZIRIBMZE123";
//	const char	needle[] = "MZIRIBMZE";
	const char	haystack[] = "lorem ipsum dolor sit amet";
	const char	needle[] = "ipsum";
//	const char	haystack[] = "see FF your FF return FF now FF";
//	const char	needle[] = "FF";
//	const char	haystack[] = "123456789";
//	const char	needle[] = "9";
//	const char	haystack[] = "";
//	const char	needle[] = "";
//	const char	haystack[] = "xyz";
//	const char	needle[] = "abc";
	size_t		len;

	len = 30;
	printf("haystack: %s\n", haystack);
	printf("  needle: %s\n", needle);
	printf(" written: %s\n", ft_strnstr(haystack, needle, len));
	printf("expected: %s\n", strnstr(haystack, needle, len));
	return (0);
}
