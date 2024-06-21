/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_full.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/11/12 22:29:06 by ggeorgie         ###   ########.fr       */
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

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
/*
void	ft_putchar(char c, int fd)
{
	c = c + '0';
	write(fd, &c, 1);
printf(" is 'write' output.\n");
}
*/
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
printf(" is 'write' output.\n");
	}
	return (i_out);
}

void	ft_next(int n, int fd, size_t i_out, size_t	n_out)
{
	size_t	i_div;
	size_t	div;

	while (n / 10 > 0)
	{
//printf("n: %d, i_div: %zu, ", n, i_div);
		div = ft_divisor(i_out);
printf("\ncurrent n: %d, n_out: %zu, i_out: %zu, div: %zu, i_div: %zu\n", n, n_out, i_out, div, i_div);
		ft_putchar_fd(n_out + '0', fd);		// print the left-most digit
//printf("div: %zu\n", div);
//printf("n: %d, div: %zu\n", n, div);
		n = n % div;				// obtain the remains of 'n' to be printed
		n_out = n;
		i_div = i_out;
//printf("i_div: %zu, n_out: %zu\n", i_div, n_out);
		while (n_out / 10 > 0)
		{
			n_out = n_out / 10;
			i_div--;
//printf("handle '0's n_out: %zu, div: %zu, i_div: %zu, i_out: %zu\n", n_out, div, i_div, i_out);
		}
		if (i_div > 1)				// handle '0's
			i_out = ft_print_zero (i_div, i_out, fd);
		i_out--;
//printf("after division n: %d, n_out: %zu, i_out: %zu, i_div: %zu, div: %zu\n\n", n, n_out, i_out, i_div, div);
	}
	ft_putchar_fd(n + '0', fd);				// print the right-most digit
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i_out;
	size_t	n_out;

	if (n == -2147483648)			// handle INT_MAX
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)					// handle '-'
		{
			write(fd, "-", 1);
			n = -n;
printf(" is 'write' output.\n");
		}
		i_out = 0;					// calculate length of 'n'
		n_out = n;	
//printf("current n: %d\n", n);
		while (n_out / 10 > 0)
		{
			n_out = n_out / 10;
			i_out++;
		}
//printf("current n: %d, n_out: %zu, i_out: %zu\n", n, n_out, i_out);
		ft_next(n, fd, i_out, n_out);
	}
}

int	main(void)
{
	int	n;
	int	fd;

	n = -1002030;
//	n = -2147483647;
//	n = -42;
	fd = 1;
	printf("%d\n", n);
	ft_putnbr_fd(n, fd);
	printf("\n");
	return (0);
}
