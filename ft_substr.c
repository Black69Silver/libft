/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 01:55:07 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocate in heap memory a slot with maximum size ’len’.
 * Make its content equal to the content of string ’s’,
 * beginning at position ’start’.
 * Return the newly created string or NULL if the allocation fails. */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr_end(char *substr, size_t len_substr, char const *s,
	unsigned int start)
{
	size_t	i;

	i = 0;
	if (substr != NULL)
	{
		while (i < len_substr)
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_str;
	size_t	len_substr;
	char	*substr;

	len_str = ft_strlen(s);
	if (*s == '\0' || start > len_str)
	{
		substr = malloc(1);
		if (substr != NULL)
			substr[0] = '\0';
		return (substr);
	}
	if (len_str == 0)
		return ("");
	if (start + len <= len_str)
		len_substr = len;
	else
		len_substr = len_str - start;
	substr = malloc(sizeof(char) * (len_substr + 1));
	return (ft_substr_end(substr, len_substr, s, start));
}
