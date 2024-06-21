/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/28 22:31:31 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Output the integer ’n’ to the given file descriptor 'fd':
	* handle INT_MAX
	* handle sign
	* calculate length of 'n' (i_out + 1)
	* calculate appropriate divisor -> ft_divisor
	* using modulo, obtain the remains of 'n' to be printed
	* print the left-most digit
	* repeat the previous 2 steps until finished
	* in '0' is encountered -> ft_print_zero
 */

#include <unistd.h>
#include "libft.h"

void	ft_putchar(char c, int fd)
{
	c = c + '0';
	write(fd, &c, 1);
}

size_t	ft_divisor(size_t i_out)
{
	size_t	div;

	div = 1;
	while (i_out > 0)
	{
		div = div * 10;
		i_out--;
	}
	return (div);
}

size_t	ft_print_zero(size_t i_div, size_t i_out, int fd)
{
	while (i_div > 1)
	{
		write(fd, "0", 1);
		i_div--;
		i_out--;
	}
	return (i_out);
}

void	ft_next(int n, int fd, size_t i_out, size_t	n_out)
{
	size_t	i_div;
	size_t	div;

	while (n / 10 > 0)
	{
		div = ft_divisor(i_out);
		ft_putchar(n_out, fd);
		n = n % div;
		n_out = n;
		i_div = i_out;
		while (n_out / 10 > 0)
		{
			n_out = n_out / 10;
			i_div--;
		}
		if (i_div > 1)
			i_out = ft_print_zero (i_div, i_out, fd);
		i_out--;
	}
	ft_putchar(n, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i_out;
	size_t	n_out;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		i_out = 0;
		n_out = n;
		while (n_out / 10 > 0)
		{
			n_out = n_out / 10;
			i_out++;
		}
		ft_next(n, fd, i_out, n_out);
	}
}
