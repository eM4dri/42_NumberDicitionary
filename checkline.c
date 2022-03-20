/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:14:35 by emadriga          #+#    #+#             */
/*   Updated: 2021/04/25 20:04:24 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_number(char *line, int *advanced)
{
	int	i;
	int	isok;

	i = 0;
	isok = 1;
	while (isok == 1)
	{
		isok = (*line >= '0' && *line <= '9');
		line++;
		i++;
		if (*line == ' ' || *line == ':')
		{
			break ;
		}
	}
	*advanced = i;
	return (isok);
}

int	check_spaces(char *line, int *advanced)
{
	int	i;
	int	isok;

	isok = 1;
	i = 0;
	while (isok == 1 && *line != ':')
	{
		isok = (*line == ' ');
		line++;
		i++;
	}
	i++;
	*advanced = i;
	return (isok);
}

int	check_writable(char *line, int *advance)
{
	int	isok;
	int	i;

	isok = 1;
	i = 0;
	while (isok == 1 && *line != '\0')
	{
		if (*line > 31 && *line != 127 && *line != ' ' )
		{
			break ;
		}
		isok = (*line == ' ');
		line++;
		i++;
	}
	*advance = i;
	return (isok);
}

int	check_line(char *line)
{
	int		*i;
	int		isok;
	char	*line_aux;

	i = malloc(4);
	isok = 1;
	line_aux = line;
	isok = check_number(line_aux, i);
	line_aux += *i;
	*i = 0;
	if (isok)
	{
		isok = check_spaces(line_aux, i);
		line_aux += *i;
	}
	if (isok)
		isok = check_writable(line_aux, i);
	free (i);
	return (isok);
}

int	check_dict(char *dict)
{
	int		isok;
	int		row;
	int		row_tot;
	char	*row_content;
	int		row_len;

	row = -1;
	isok = 1;
	isok = ft_rows_count1(dict, &row_tot);
	while (++row < row_tot && isok)
	{
		isok = ft_row_len1(dict, row, &row_len);
		row_content = malloc(row_len);
		if (! row_content)
			isok = 0;
		else
		{
			isok = ft_get_row(dict, row_content, row);
			isok = check_line(row_content);
		}
		free(row_content);
	}
	return (isok);
}
