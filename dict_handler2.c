/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_handler2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:14:52 by emadriga          #+#    #+#             */
/*   Updated: 2021/04/25 19:15:44 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_get_row(char *dict, char *row_content, int row)
{
	int	fd;
	int	isok;
	int	i;

	isok = 1;
	i = 0;
	fd = open(dict, O_RDONLY);
	if (fd < 0)
		isok = 0;
	if (row > 0)
		while (row > 0 && read(fd, &row_content[0], 1))
			if (row_content[0] == '\n')
				row--;
	read(fd, &row_content[i], 1);
	while (row_content[i] != '\n')
		read(fd, &row_content[++i], 1);
	if (close(fd) < 0 && fd != -1)
		isok = 0;
	return (isok);
}
