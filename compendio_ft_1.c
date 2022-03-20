/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compendio_ft_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:14:44 by emadriga          #+#    #+#             */
/*   Updated: 2021/04/25 20:21:05 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_checknumber(char *number)
{
	int	isok;
	int	i;

	isok = 1;
	i = 0;
	if (number[0] == '\0')
		isok = 0;
	while (isok == 1 && number[i] != '\0')
	{
		if (number[i] < '0' || number[i] > '9')
			isok = 0;
		i++;
	}
	if (!isok)
		ft_show_error(1);
	return (isok);
}

int	ft_numlen (char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(char *to_find, char *found, int n)
{
	int	i;

	i = 0;
	while ((to_find[i] != 0 || found[i] != ':' || found[i] != ' ') && i < n)
	{
		if (to_find[i] != found[i])
			return (0);
		i++;
	}
	return (1);
}
