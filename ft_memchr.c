/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/26 15:58:00 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return a pointer to the first occurrence of 'c'
 * (converted to an unsigned char) within the first 'n' of string 's'. */

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
