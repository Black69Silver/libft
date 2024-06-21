/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 15:07:03 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return a pointer of the first occurrence of 'c'
 * in the string pointed to by 's', or, if not found, NULL. */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len_str;
	char	*output;

	i = 0;
	len_str = ft_strlen(s);
	while (i < len_str && s[i] != (unsigned char) c)
		i++;
	if (s[i] == (unsigned char) c)
		output = (char *)&s[i];
	else
		output = NULL;
	return (output);
}

int	main(void)
{
//	const char	s[] = "The quick brown fox jumps over the lazy dog";
	const char	s[] = "abc";
	int			c;

//	c = 'u';
	c = 'a' + 256;
	printf("First occurence of '%c' in '%s'?\n", c, s);
	printf("Written function: %s.\n", ft_strchr(s, c));
	printf("Library function: %s.\n", strchr(s, c));
	return (0);
}
