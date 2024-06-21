/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/24 19:44:55 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the string ’s’ to the given file descriptor followed by a newline. */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	len;

	if (s && fd)
	{
		len = 0;
		while (s[len] != 0)
			len++;
		write(fd, s, len);
		write(fd, "\n", 1);
	}
}

int	main(void)
{
	char	*s;
	int		fd;

	s = "The quick brown fox jumps over the lazy dog";
	fd = 1;
	printf("\n%s\n", s);
	ft_putendl_fd(s, fd);
	printf("\n");
	return (0);
}
