/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/23 18:59:38 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocate sufficient memory for a copy of string 's1'.
 * Copy string 's1' to the new location.
 * Return a pointer to it.
 * (Subsequently, the pointer may be used as an argument to the function free.)
 * If insufficient memory is available / new string cannot be created,
 * return NULL pointer ~~and set errno to ENOMEM to indicate the error~~. */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_str;
	char	*s2;
	size_t	i;

	len_str = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len_str + 1));
	i = 0;
	if (s2)
	{
		while (i < len_str)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}

int	main(void)
{
	const char	s1[] = "The quick brown fox jumps over the lazy dog.";

	printf("Expected result: %s\n", strdup(s1));
	printf("  Actual result: %s\n", ft_strdup(s1));
	return (0);
}
