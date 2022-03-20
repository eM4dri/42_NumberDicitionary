/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_handler1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:14:48 by emadriga          #+#    #+#             */
/*   Updated: 2021/04/25 19:15:43 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_row_len1(char *dict, int row, int *row_len)
{
	int		isok;
	char	*memory;

	isok = 1;
	memory = malloc(1);
	if (!(memory))
	{
		ft_show_error(1);
		isok = 0;
	}
	else
		isok = ft_row_len2(dict, memory, row, row_len);
	free(memory);
	return (isok);
}

int	ft_row_len2(char *dict, char *memory, int row, int *row_len)
{
	int		fd;
	int		isok;

	isok = 1;
	fd = open(dict, O_RDONLY);
	if (fd < 0)
		isok = 0;
	else
		isok = ft_row_len3(fd, memory, row, row_len);
	if (close(fd) < 0 && fd != -1)
		isok = 0;
	return (isok);
}

int	ft_row_len3(int fd, char *memory, int row, int *row_len)
{
	int	isok;
	int	len;

	isok = 1;
	len = 0;
	if (row > 0)
		while (read(fd, memory, 1) && row > 0)
			if (memory[0] == '\n')
				row--;
	read(fd, memory, 1);
	while (memory[0] != '\n')
	{
		read(fd, memory, 1);
		len++;
	}
	*row_len = len;
	return (isok);
}

int	ft_rows_count1(char *dict, int *row)
{
	int		isok;
	char	*memory;

	isok = 1;
	memory = malloc(1);
	if (!(memory))
	{
		ft_show_error(1);
		isok = 0;
	}
	else
		isok = ft_rows_count2(dict, memory, row);
	free(memory);
	return (isok);
}

int	ft_rows_count2(char *dict, char *memory, int *row_tot)
{
	int	isok;
	int	fd;
	int	row;

	isok = 1;
	fd = open(dict, O_RDONLY);
	if (fd < 0)
		isok = 0;
	row = 0;
	while (read(fd, memory, 1) && isok)
		if (memory[0] == '\n')
			row++;
	*row_tot = row;
	if (close(fd) < 0 && fd != -1)
		isok = 0;
	if (!isok)
		ft_show_error(2);
	return (isok);
}
