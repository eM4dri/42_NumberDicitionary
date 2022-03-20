/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:15:01 by emadriga          #+#    #+#             */
/*   Updated: 2021/04/25 19:15:46 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_get_words(char *dict, char *number)
{
	int	i;
	int	isok;
	int	counter;
	int	numlen;

	isok = 1;
	i = -1;
	while (number[++i] == '0')
	{
		if (number[i + 1] == '\0')
			isok = ft_search_word1(dict, &number[i]);
	}
	counter = -1;
	numlen = ft_numlen(number);
	while (number[i] && isok)
	{
		if (number[i] != '0')
		{
			if (++counter > 0)
				write(1, " ", 1);
			isok = ft_get_words2(dict, &i, number, numlen);
		}
		i++;
	}
}

int	ft_get_words2(char *dict, int *pos, char *number, int num_len)
{
	int	isok;
	int	digits;

	isok = 1;
	digits = num_len - *pos;
	if (digits % 3 == 1)
		isok = ft_units(dict, pos, number, digits);
	else if (digits % 3 == 2)
		isok = ft_tens(dict, pos, number, digits);
	else if (digits % 3 == 0)
		isok = ft_hundreds(dict, pos, number, digits);
	return (isok);
}

int	ft_search_word1(char *dict, char *to_find)
{
	int	isok;
	int	row;
	int	found;
	int	row_tot;

	row = -1;
	isok = 1;
	found = 0;
	isok = ft_rows_count1(dict, &row_tot);
	while (++row < row_tot && !found && isok)
	{
		isok = ft_search_word2(dict, to_find, row, &found);
	}
	if (!found)
		ft_show_error(1);
	return (isok);
}

int	ft_search_word2(char *dict, char *to_find, int row, int *found)
{
	int		isok;
	char	*row_content;
	int		row_len;

	isok = 1;
	isok = ft_row_len1(dict, row, &row_len);
	row_content = malloc(row_len);
	if (! row_content)
		isok = 0;
	else
	{
		isok = ft_get_row(dict, row_content, row);
		*found = ft_strncmp(to_find, row_content, ft_numlen(to_find));
		if (*found)
			ft_print_result(row_content, to_find);
	}
	free(row_content);
	if (!isok)
		ft_show_error(1);
	return (isok);
}
