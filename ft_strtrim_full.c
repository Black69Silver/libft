/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/02 20:00:05 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* From the beginning and the end of string 's1' remove characters contained
 * in ’set’ string, if present. Calculate the length of the resulting string.
 * Allocate in heap memory a slot with that length.
 * Fill that memory with the trimmed string or NULL if the allocation fails. */

#include <stdio.h>
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
		{
printf("s1 @ %zu: %c; set @ %zu: %c\n", i_s1, s1[i_s1], i_set, set[i_set]);
			i_set++;
		}
		if (s1[i_s1] == set[i_set] && i_set < len_set)
		{
printf("s1 @ %zu: %c; set @ %zu: %c\n", i_s1, s1[i_s1], i_set, set[i_set]);
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
		{
printf("s1 @ %zu: %c; set @ %zu: %c\n", i_s1, s1[i_s1], i_set, set[i_set]);
			i_set++;
		}
		if (s1[i_s1] == set[i_set] && i_set < len_set)
		{
printf("s1 @ %zu: %c; set %zu @ %c\n", i_s1, s1[i_s1], i_s1, set[i_set]);
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
//printf("End trim input:\n\tlen_s1: %zu, len_s2: %zu, len_set: %zu\n", len_s1, len_s2, len_set);
printf("End trim input:\t\tlen_s1: %zu, len_set: %zu\n", len_s1, len_set);
	len_s1 = end(len_s1, len_set, s1, set);
//printf("End trim output, front trim input:\n\ts1: %s; len_s1: %zu, len_s2: %zu, len_set: %zu\n", s1, len_s1, len_s2, len_set);
printf("End trim output, front trim input:\tlen_s1: %zu\n", len_s1);
	len_s2 = begin(len_s1, len_set, s1, set);
printf("Front trim output:\tlen_s1: %zu, len_s2: %zu\n", len_s1, len_s2);
	return (ft_copy(s1, len_s1, len_s2));
}

int	main(void)
{
	char const	*s1;
	char const	*set;

	s1 = "cabaxcydzbac";
	set = "abcd";
	printf("\nInput:\n\tstring: %s\n\t   set: %s\n", s1, set);
	printf("Output: %s\n\n", ft_strtrim(s1, set));
	return (0);
}
