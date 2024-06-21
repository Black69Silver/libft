/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/10 13:06:12 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocate contiguous memory with size 'count' * 'size' bytes.
 * (Which is to be used by 'count' (number of) objects of 'size' bytes each.)
 * Fill the allocated memory with '0's.
 * Return a pointer to the allocated memory. */

#include <stdio.h>
#include <stdlib.h>
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

void	test_ft_calloc(size_t count, size_t size)
{
	void	*result = ft_calloc(count, size);

	printf("\nTesting ft_calloc with count = %zu, size = %zu\n", count, size);
	if (result != NULL)
	{
		printf("Memory allocation successful.\n");
//		Print the allocated memory content (for demonstration purposes)
		unsigned char	*byte_array = (unsigned char *)result;
		printf("Allocated memory content: ");
		for (size_t i = 0; i < count * size; ++i)
		{
			printf("\n%zu: %0X", i, byte_array[i]);
		}
		printf("\n");
//		Free the allocated memory
		free(result);
		printf("Memory freed successfully.\n");
	}
	else
		printf("Memory allocation failed.\n");
}

int	main(void)
{
	test_ft_calloc(3, sizeof(int));
	test_ft_calloc(2, sizeof(double));
	test_ft_calloc(8, sizeof(char));
	return (0);
}
