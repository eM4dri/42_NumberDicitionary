/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:14:56 by emadriga          #+#    #+#             */
/*   Updated: 2021/04/26 19:20:49 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_units(char *dict, int *pos, char *number, int digits)
{
	int		isok;
	char	ntochar[4];

	isok = 1;
	ntochar[0] = number[*pos] + '\0';
	ntochar[1] = '\0';
	isok = ft_search_word1(dict, ntochar);
	if (digits > 3)
		isok = ft_uppperhundreds(dict, digits);
	return (isok);
}

int	ft_tens(char *dict, int *pos, char *number, int digits)
{
	int		isok;
	char	ntochar[4];

	isok = 1;
	ntochar[0] = number[*pos] + '\0';
	if (number[*pos] == '1')
	{
		ntochar[1] = number[*pos + 1] + '\0';
		(*pos)++;
	}
	else
		ntochar[1] = '0';
	ntochar[2] = '\0';
	isok = ft_search_word1(dict, ntochar);
	if (digits > 3 && (number[*pos] == '1' || number[*pos + 1] == '0'))
		isok = ft_uppperhundreds(dict, digits - 1);
	return (isok);
}

int	ft_hundreds(char *dict, int *pos, char *number, int digits)
{
	int		isok;
	char	ntochar[4];

	isok = 1;
	ntochar[0] = number[*pos] + '\0';
	ntochar[1] = '\0';
	isok = ft_search_word1(dict, ntochar);
	write(1, " ", 1);
	isok = ft_search_word1(dict, "100");
	if(number[*pos + 1] == '0' && number[*pos + 2] == '0')
		isok = ft_uppperhundreds(dict, digits - 2);
	return (isok);
}

int	ft_uppperhundreds(char *dict, int digits)
{
	int		isok;
	char	*ntochar;
	int		i;

	isok = 0;
	if (digits % 3 == 1)
	{
		ntochar = malloc(digits);
		ntochar[0] = '1';
		i = 1;
		while (i < digits)
			ntochar[i++] = '0';
		ntochar[i] = '\0';
		write(1, " ", 1);
		isok = ft_search_word1(dict, ntochar);
		free(ntochar);
	}
	return (isok);
}
