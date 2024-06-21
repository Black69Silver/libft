/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_full.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 15:08:33 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Pass by address each character of string 's' as argument to function ’f’. */

#include <stdio.h>
#include "libft.h"

void	f(unsigned int i, char *s)
{
	(void) i;
	printf("%c", *s + 22);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s && *s && f)
	{
		i = 0;
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}

int	main(void)
{
	char	*s;

	s = "abcd";
	printf(" Input: %s\n", s);
	printf("Output: ");
	ft_striteri(s, f);
	printf("\n");
	return (0);
}
