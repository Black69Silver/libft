/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/26 19:05:59 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return a pointer of the last occurrence of 'c'
 * in the string pointed to by 's', or, if not found, NULL. */

#include <sys/types.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	ssize_t	i;
	size_t	len_str;

	len_str = ft_strlen(s) + 1;
	if (len_str == 0)
		return (NULL);
	i = len_str - 1;
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
