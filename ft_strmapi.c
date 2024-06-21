/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 01:34:00 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocate in heap memory space for a new string with length equal to 
 * the length of string ’s’.
 * Pass to function ’f’ each character of the string ’s’.
 * Save in the new string the results of function 'f' application.
 * Return a pointer to the beginning of the sting. */

#include <stdlib.h>
#include "libft.h"

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
