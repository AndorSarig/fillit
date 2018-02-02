/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:01:59 by asarig            #+#    #+#             */
/*   Updated: 2018/01/18 16:57:13 by rbudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		nrtetr;
	char	*file;
	char	**tetriminos;
	char	**solution;

	if (argc != 2)
		error();
	file = ft_read_file(argv[1]);
	if ((nrtetr = ft_filechecker(file)) < 0)
		error();
	if (ft_strlen(file) <= 1)
		error();
	if (ft_strlen(file) > nrtetr * 20 + nrtetr - 1)
		error();
	tetriminos = ft_put_to_array(file, nrtetr);
	if (ft_check_pieces(tetriminos, nrtetr) == 1)
		error();
	tetriminos = ft_hash_to_alph(tetriminos, nrtetr);
	solution = ft_resolve(tetriminos, nrtetr);
	ft_print_result(solution);
	return (0);
}
