/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/26 18:56:57 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return a pointer of the first occurrence of 'c'
 * in the string pointed to by 's', or, if not found, NULL. */

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
