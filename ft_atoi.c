/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:08:01 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/30 22:05:46 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* In string 'str':
 * Remove white spaces in the beginning of the input string.
 * Consider '+' or '-' signs.
 * Return the first sequence of numeric characters converted to an integer.
 * Neglect the rest of the string. Works as lib funciton
 * from -9223372036854775808 to +9223372036854775807 or 9,223,372,036,854,775,806
 */

int	ft_atoi(const char *str)
{
	int	sign;
	int	output;

	sign = 1;
	output = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		output = output * 10 + ((int)*str - '0');
		str++;
	}
	output = output * sign;
	return (output);
}
