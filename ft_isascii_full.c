/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 02:20:08 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* If a character value is not between ASCII value 0-127, returns 0. */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int	main(void) 
{
    // Test cases
    int test_cases[] = {'A', 'a', 'Z', 'z', '0', '9', '!', '@', ' '};
    int i = 0;

    while (i < 9)
    {
        char current_char = test_cases[i];
        int result = ft_isascii (current_char);

        printf("Current character is %c - %d.\n", current_char, result);
        printf("Library funciton result: %d.\n\n", isascii (current_char));
        i = i + 1;
    }
    return 0;
}