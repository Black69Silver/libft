/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 15:17:37 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocate in heap memory space for a new string with length equal to 
 * the length of string ’s’.
 * Pass to function ’f’ each character of the string ’s’.
 * Save in the new string the results of function 'f' application.
 * Return a pointer to the new sting. */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	f(unsigned int i, char str)
{
	str = str - i;
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strmapi;
	unsigned int	i;

	if (s && f)
	{
		strmapi = malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (strmapi)
		{
			i = 0;
			while (i < ft_strlen(s))
			{
				strmapi[i] = f(i, s[i]);
				i++;
			}
			strmapi[i] = '\0';
		}
	}
	else
	{
		strmapi = malloc(1);
		if (strmapi != NULL)
			strmapi[0] = '\0';
	}
	return (strmapi);
}


int	main(void)
{
	const char	*s;
	char		*output;

	s = "abcdefghijklmnopqrstuvwxyz";
	output = ft_strmapi(s, f);
	if (output)
	{
		printf(" Input: %s\n", s);
		printf("Output: %s\n", output);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}
