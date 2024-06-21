/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:08:51 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/24 20:55:25 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Count and return the number of characters in a string preceding the '\0'. */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

int	main(void)
{
	char	text[] = "Text to be counted.";
	char	*str;

	str = text;
	printf("Written function result: %zu.\n", ft_strlen(str));
	printf("Library funciton result: %lu.\n\n", strlen (text));
	return (0);
}
