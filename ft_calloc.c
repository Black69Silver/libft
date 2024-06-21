/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/16 23:10:56 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocate contiguous memory with size 'count' * 'size' bytes.
 * (Which is to be used by 'count' (number of) objects of 'size' bytes each.)
 * Fill the allocated memory with '0's.
 * Return a pointer to the allocated memory. */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	char	*array;

	total_size = count * size;
	array = malloc(total_size);
	if (array != NULL)
		ft_memset(array, 0, total_size);
	return (array);
}
