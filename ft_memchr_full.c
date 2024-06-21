/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 02:23:12 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return a pointer to the first occurrence of 'c'
 * (converted to an unsigned char) within the first 'n' of string 's'. */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	if (n != 0)
	{
		while (str[i] != (unsigned char) c && i < n - 1)
			i++;
		if (str[i] == (unsigned char) c)
			return (&str[i]);
	}
	return (NULL);
}

int	main(void)
{
//	const void	*s = "The quick brown fox jumps over the lazy dog.";
//	const void	*s = "bonjourno";
	char s[] = {0, 1, 2 ,3 ,4 ,5};
//	int			c;
//	size_t		n;

	char *actual = ft_memchr(s, 0, 0);
	char *expected = memchr(s, 0, 0);
	printf("actual: %s, s: %s", actual, expected);
//	ft_memchr(s, 2 + 256, 3) == s + 2); showLeaks(); //Cast check

//	c = 'n';
//	n = 2;
//	printf("Written function result: %s\n", ft_memchr(s, c, n));
//	printf("Library function result: %s\n", memchr(s, c, n));
	return (0);
}
