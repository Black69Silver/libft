/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/30 18:17:07 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* From the beginning and the end of string 's1' remove characters contained
 * in ’set’ string, if present. Calculate the length of the resulting string.
 * Allocate in heap memory a slot with that length.
 * Fill that memory with the trimmed string or NULL if the allocation fails. */

#include <stdlib.h>
#include <sys/types.h>
#include "libft.h"

size_t	end(size_t len_s1, size_t len_set, char const *s1, char const *set)
{
	ssize_t	i_s1;
	size_t	i_set;

	i_s1 = len_s1 - 1;
	i_set = 0;
	while (i_s1 >= 0 && i_set < len_set)
	{
		while (i_set < len_set && s1[i_s1] != set[i_set])
			i_set++;
		if (s1[i_s1] == set[i_set] && i_set < len_set)
		{
			i_s1--;
			i_set = 0;
		}
	}
	return (len_s1 = i_s1 + 1);
}

size_t	begin(size_t len_s1, size_t len_set, char const *s1, char const *set)
{
	size_t	i_s1;
	size_t	i_set;

	i_s1 = 0;
	i_set = 0;
	while (i_s1 < len_s1 && i_set < len_set)
	{
		while (s1[i_s1] != set[i_set] && i_set < len_set)
			i_set++;
		if (s1[i_s1] == set[i_set] && i_set < len_set)
		{
			i_s1++;
			i_set = 0;
		}
	}
	return (len_s1 - i_s1);
}

char	*ft_copy(char const *s1, size_t len_s1, size_t len_s2)
{
	char	*s2;
	size_t	i;

	s2 = malloc(sizeof(char) * (len_s2 + 1));
	if (s2)
	{
		i = 0;
		while (i < len_s2)
		{
			s2[i] = s1[len_s1 - len_s2 + i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_set;
	size_t	len_s1;
	size_t	len_s2;

	len_set = ft_strlen(set);
	len_s1 = ft_strlen(s1);
	len_s1 = end(len_s1, len_set, s1, set);
	len_s2 = begin(len_s1, len_set, s1, set);
	return (ft_copy(s1, len_s1, len_s2));
}
