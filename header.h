/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:15:07 by emadriga          #+#    #+#             */
/*   Updated: 2021/04/25 20:15:31 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_row_len1(char *dict, int row, int *len);
int		ft_row_len2(char *dict, char *memory, int row, int *row_len);
int		ft_row_len3(int fd, char *memory, int row, int *row_len);
int		ft_rows_count1(char *dict, int *row);
int		ft_rows_count2(char *dict, char *memory, int *row_tot);
int		ft_get_row(char *dict, char *row_content, int row);
void	ft_get_words(char *dict, char *number);
int		ft_get_words2(char *dict, int *pos, char *number, int num_len);
int		ft_search_word1(char *dict, char *to_find);
int		ft_search_word2(char *dict, char *to_find, int row, int *found);
int		ft_units(char *dict, int *pos, char *number, int digits);
int		ft_tens(char *dict, int *pos, char *number, int digits);
int		ft_hundreds(char *dict, int *pos, char *number, int digits);
void	ft_show_error(int error_code);
int		ft_checknumber(char *number);
void	ft_print_result(char *row_content, char *to_find);
void	ft_solve(int argc, char *argv[]);
int		ft_numlen (char *number);
int		ft_strncmp(char *to_find, char *found, int n);
void	ft_show_error(int error_code);
int		ft_uppperhundreds(char *dict, int digits);
int		check_number(char *line, int *advanced);
int		check_spaces(char *line, int *advanced);
int		check_writable(char *line, int *advance);
int		check_line(char *line);
int		check_dict(char *dict);
#endif
