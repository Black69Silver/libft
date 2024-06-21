/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 18:54:43 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocate in heap memory a slot sufficient to fit the concatenation of
 * ’s1’ and ’s2’. Fill it up.
 * Return the new string or NULL if the allocation fails. */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(len_s1 + len_s2 + 1);
	if (str != NULL)
	{
		i = 0;
//		while (i < len_s1)
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		i = 0;
//		while (i < len_s2)
		while (s2[i])
		{
			str[len_s1 + i] = s2[i];
			i++;
		}
		str[len_s1 + len_s2] = '\0';
	}
	return (str);
}

int	main(void)
{
	char const	*s1;
	char const	*s2;

//	s1 = "The quick brown fox ";
	s2 = "jumps over the lazy dog.";
	printf("\nPrefix: %s\n", s1);
	printf("Suffix: %s\n", s2);
	printf("Return: %s\n\n", ft_strjoin(s1, s2));
	return (0);
}
