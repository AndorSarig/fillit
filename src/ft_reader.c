/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:01:34 by asarig            #+#    #+#             */
/*   Updated: 2018/01/16 18:25:30 by asarig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read_file(char *filename)
{
	int		buff_size;
	char	*buff;
	int		fd;

	buff_size = 550;
	if (!(buff = malloc(sizeof(char) * buff_size + 1)))
		error();
	if (!(fd = open(filename, O_RDONLY)))
		error();
	read(fd, buff, buff_size);
	if (ft_strlen(buff) > 545)
		error();
	close(fd);
	buff[ft_strlen(buff)] = '\0';
	return (buff);
}
