/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/31 02:19:38 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* If a character is not between A-Z or a-z, returns 0. */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

int main () 
{
    // Test cases
    int test_cases[] = {'A', 'a', 'Z', 'z', '0', '9', '!', '@', ' '};
    int i = 0;

    while (i < 9)
    {
        char current_char = test_cases[i];
        int result = ft_isalpha (current_char);

        printf("Current character is %c - %d.\n", current_char, result);
        printf("Library funciton result: %d.\n\n", isalpha (current_char));
        i = i + 1;
    }
    return 0;
}