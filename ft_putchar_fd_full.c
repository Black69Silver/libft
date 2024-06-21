/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/24 20:01:56 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the character ’c’ to the given file descriptor 'fd'. */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	main(void)
{
	char	c;
	int		fd;

	c = 'T';
	fd = 1;
	printf("\n%c\n", c);
	ft_putchar_fd(c, fd);
	printf("\n");
	return (0);
}
