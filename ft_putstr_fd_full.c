/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_full.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/21 23:36:17 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the string ’s’ to the given file descriptor 'fd'. */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	len;

	if (s && fd)
	{
		len = 0;
		while (s[len] != 0)
			len++;
		write(fd, s, len);
	}
}

int	main(void)
{
	char	*s;
	int		fd;

	s = "The quick brown fox jumps over the lazy dog";
	fd = 1;
	printf("\n%s\n", s);
	ft_putstr_fd(s, fd);
	printf("\n");
	return (0);
}
