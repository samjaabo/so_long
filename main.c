/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:56:11 by samjaabo          #+#    #+#             */
/*   Updated: 2023/01/06 20:06:53 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error(const char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

int	ft_is_map(char c)
{
	return (c == 'P' || c == 'C' || c == 'E' || c == '0' || c == '1');
}

void	ft_allowed_chars(char **map)
{
	char	*tmp;

	while (*map)
	{
		tmp = *map;
		if (*tmp == 0)
			ft_error("invalid map");
		while (*tmp)
		{
			if (ft_is_map(*tmp) != 1)
				ft_error("invalid chars in map");
			++tmp;
		}
		++map;
	}
}

void	ft_is_same_width(char **map)
{
	int		width;

	width = ft_strlen(*map);
	while (*map)
	{
		if (width != ft_strlen(*map))
			ft_error("invalid map width");
		++map;
	}
}

void	ft_is_walls_map(char **map)
{
	char	*tmp;

	tmp = *map++;
	while (*tmp == '1')
		++tmp;
	if (*tmp != 0)
		ft_error("invalid map");
	while (*map)
	{
		tmp = *map;
		if (*tmp != '1')
			ft_error("invalid map");
		while (*tmp)
			++tmp;
		if (*--tmp != '1')
			ft_error("invalid map");
		++map;
	}
	tmp = *--map;
	while (*tmp == '1')
		++tmp;
	if (*tmp != 0)
		ft_error("invalid map");
}

void	ft_map_rules(char **map)
{
	ft_allowed_chars(map);
	ft_is_same_width(map);
	ft_is_walls_map(map);
	if (ft_count_elements(map, 'C') == 0)
		ft_error("01");
	if (ft_count_elements(map, 'P') != 1)
		ft_error("02");
	if (ft_count_elements(map, 'E') != 1)
		ft_error("03");
}

int main(void)
{
	char **map;
	int fd;
	int *pos;
	
	map = ft_read_map("tests.txt");
	ft_map_rules(map);
	ft_printar(map);
	return (0);
}