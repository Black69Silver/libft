/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/30 15:40:07 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Locate the first occurrence of the null-terminated string 'needle'
 * in the string 'haystack', where not more than 'len' characters are searched.
 * Characters that appear after a `\0' character are not searched.
 * If 'needle' is an empty string, 'haystack' is returned.
 * If 'needle' occurs nowhere in 'haystack', NULL is returned.
 * Otherwise a pointer to the first character of
 * the first occurrence of 'needle' is returned. */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < len
				&& haystack[i + j] && needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
