/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:19:06 by asarig            #+#    #+#             */
/*   Updated: 2018/01/21 14:37:14 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

void	error(void);
int		ft_check_pieces(char **array, int nr);
char	*ft_read_file(char *filename);
int		ft_filechecker(char *file);
void	ft_free_matrix(char **tetris);
char	**ft_hash_to_alph(char **tetri, int nrtetr);
int		ft_size(int nrtetr);
int		ft_measure(char **tetris);
int		ft_dot(char *piece);
char	**ft_put_to_array(char *f, int nrtetr);
int		ft_check_pieces(char **array, int nr);
char	**ft_take_piece_off(char **tetris, char *piece);
char	**ft_new_square(int size);
void	ft_print_result(char **solution);
char	**ft_resolve(char **tetriminos, int nrtetr);

#endif
