/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 01:03:21 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocate sufficient memory for a copy of string 's1'.
 * Copy string 's1' to the new location.
 * Return a pointer to it.
 * (Subsequently, the pointer may be used as an argument to the function free.)
 * If insufficient memory is available / new string cannot be created,
 * return NULL pointer. */

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
