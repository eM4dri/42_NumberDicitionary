/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:15:14 by emadriga          #+#    #+#             */
/*   Updated: 2021/04/25 20:20:10 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define DICTIONARY "numbers.dict"

void	ft_show_error(int error_code)
{
	if (error_code == 1)
		write(1, "Error\n", 6);
	else if (error_code == 2)
		write(1, "Dict Error\n", 11);
}

void	ft_print_result(char *row_content, char *to_find)
{
	while (*to_find != '\0' && *row_content == *to_find)
	{
		row_content++;
		to_find++;
	}
	while (*row_content == ' ' || *row_content == ':')
		row_content++;
	while (*row_content != '\n')
		write(1, row_content++, 1);
}

void	ft_solve(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_get_words(DICTIONARY, argv[1]);
	}
	else if (argc == 3)
	{
		if (check_dict(argv[1]))
			ft_get_words(argv[1], argv[2]);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2 || argc == 3)
	{
		if (ft_checknumber(argv[argc - 1]))
			ft_solve(argc, argv);
		else
			ft_show_error(0);
	}
	else
		ft_show_error(0);
	return (0);
}
