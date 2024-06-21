/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_full.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 02:22:17 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Convert an integer 'n' to a string. Negative numbers must be handled.
 * Calculate the string length. Allocate in heap memory space for the string. 
 * Save the string in the allocated space. Return a pointer to the string. */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

size_t	ft_intlen(int n)
{
	size_t	intlen;

	intlen = 1;
	if (n < 0)
	{
		n = -n;
		intlen++;
	}
	while (n / 10 > 0)
	{
		intlen++;
		n = n / 10;
	}
	return (intlen);
}

char	*ft_fill_str(int nb, char *str, size_t str_len)
{
	str[str_len] = '\0';
printf("last str[%zu]: %c\n", str_len, str[str_len]);
	str_len--;
	while (nb / 10 > 0)
	{
		str[str_len] = nb % 10 + '0';
		nb = nb / 10;
printf("str[%zu]: %c\n", str_len, str[str_len]);
		str_len--;
	}
	str[str_len] = nb % 10 + '0';
printf("str[%zu]: %c\n", str_len, str[str_len]);
printf("str[%d]: %c\n", 0, str[0]);
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	str_len;
	char	*str;
	int		nb;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	nb = n;
	str_len = ft_intlen(n);
	str = malloc(sizeof(char) * (str_len + 1));
	if (str != NULL)
	{
		if (nb < 0)
		{
			str[0] = '-';
			nb = -nb;
		}
printf("cleaned: %d\n", nb);
		str = ft_fill_str(nb, str, str_len);
	}
	return (str);
}

int	main(void)
{
	int	n;

//	n = 0;
	n = -2147483648;
	printf(" Input: %d\n", n);
	printf("Output: %s\n", ft_itoa(n));
	return (0);
}
