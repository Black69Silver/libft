/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeorgie <ggeorgie@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:44:21 by ggeorgie          #+#    #+#             */
/*   Updated: 2023/10/30 23:58:07 by ggeorgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Make an array for counters
	-> ssize_t	int_var[6]:
	* [0] length of 's' and 'str',
	* [1] length of sub-string,
	* [2] total number of sub-strings,
	* [3] index of sub-string,
	* [4] position within sub-string,
	* [5] position within 'str'.
 * Save 's' in string 'str' while replacing each character ’c’ with '\0'.
	-> ft_c_to_0
 * Count the number of newly appeared sub-strings.
	-> ft_ss_count
	ss = sub-string = word
 * Initialize 'pointers' array.
		pointers = malloc(sizeof(char *) * (int_var[2] + 1));
* For each sub-string:
	-> ft_fill_word
	* Using ft_strlen, discover its length.
	* Allocate in heap memory space for it, including '\0'.
		word = malloc(sizeof(char) * (int_var[1] + 1));
	* If unsuccessful at any point, free all previously allocated spaces.
	* Copy sub-string to 'word'.
	* Return to 'pointers' a pointer to 'word'.
		-> ft_fill_pointers
 * Add a NULL pointer at the end of 'pointers'.
 * Return the string of pointers. */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_c_to_0(char *str, ssize_t *int_var, char const *s, char c)
{
	ssize_t	i;

	i = 0;
printf("ft_c_to_0 internals:\n");
	while (i < int_var[0])
	{
		if (s[i] == c)
			str[i] = '\0';
		else
			str[i] = s[i];
printf("str %zu: %c\n", i, str[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

ssize_t	ft_ss_count(char *str, ssize_t *int_var)
{
	ssize_t	i;

	i = 0;
	int_var[2] = 0;
printf("\nft_ss_count internals:\n");
	while (i < int_var[0])
	{
		if (str[i] != '\0' && str[i + 1] == '\0')
			int_var[2]++;
printf("count_ss @ %zu: %zu; str: %c\n", i, int_var[2], str[i]);
		i++;
	}
	return (int_var[2]);
}

char	*ft_fill_word(char *str, ssize_t *int_var, char **pointers)
{
	char	*word;

	int_var[4] = 0;
	word = malloc(sizeof(char) * (int_var[1] + 1));
	if (word == NULL)
	{
		while (int_var[3] > 0)
		{
			free(pointers[int_var[3] - 1]);
			int_var[3]--;
		}
		return (NULL);
	}
	while (int_var[4] < int_var[1])
	{
		word[int_var[4]] = str[int_var[5] + int_var[4]];
printf("Output new string: ss_position: %zu, str_position: %zu, ss value: %c\n", int_var[4], int_var[5] + int_var[4], word[int_var[4]]);
		int_var[4]++;
	}
	word[int_var[4]] = '\0';
	return (word);
}

char	**ft_fill_pointers(char *str, char **pointers, ssize_t *int_var)
{
	char	*word;

	int_var[3] = 0;
	int_var[5] = 0;
	while (int_var[3] < int_var[2])
	{
		while (str[int_var[5]] == '\0')
			int_var[5]++;
		int_var[1] = ft_strlen(&str[int_var[5]]);
printf("\nSubstring #: %zu, position in original string: %zu, substring length: %zu\n", int_var[3], int_var[5], int_var[1]);
		word = ft_fill_word(str, int_var, pointers);
		if (word == NULL)
		{
			free(pointers);
			return (NULL);
		}
		pointers[int_var[3]] = word;
printf("Location in heap memory: %p. Value: %s\n", pointers[int_var[3]], pointers[int_var[3]]);
		int_var[5] = int_var[5] + int_var[1];
		int_var[3]++;
	}
	pointers[int_var[3]] = NULL;
printf("\nLocation of NULL pointer in heap memory: %p. Value: %s\n\n", pointers[int_var[3]], pointers[int_var[3]]);
	return (pointers);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**pointers;
	ssize_t	int_var[6];

	if (s == NULL)
		return (NULL);
	int_var[0] = ft_strlen(s);
//	if((str = malloc(sizeof(char) * (len_s + 1)))) -> not alowed Assignment in control structure
	str = malloc(sizeof(char) * (int_var[0] + 1));
printf("String length: %zu; delimiter: %c\n\n", int_var[0], c);
	if (str != NULL)
		str = ft_c_to_0(str, int_var, s, c);
	else
	{
		free(str);
		return (NULL);
	}
	int_var[2] = ft_ss_count(str, int_var);
	pointers = malloc(sizeof(char *) * (int_var[2] + 1));
	if (pointers != NULL)
		pointers = ft_fill_pointers(str, pointers, int_var);
	else
		free(pointers);
	free(str);
	return (pointers);
}

int	main(void)
{
//	char const	*s = "      split       this for   me  !       ";
//	char		c = ' ';
	char const	*s = "1c34ccc990";
	char		c = 'c';

	printf("\nInput: %s\n", s);
	printf("Output (pointer_to_pointers): %p\n\n", ft_split(s, c));
/*
	char		**split;

	split = ft_split(s, c);
	if (split == NULL)
	{
		printf("split returns NULL");
		return (-1);
	}
	while (*split != NULL)
	{
		printf("%s\n", *split);
		split++;
	}
*/	return (0);
}
