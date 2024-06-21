/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/23 02:22:09 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Write 'n' NULL characters in string pointed to with '*s'. */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*adj_s;

	i = 0;
	adj_s = s;
	if (n != 0)
	{
		while (i < n)
		{
			adj_s[i] = '\0';
			i++;
		}
	}
}
