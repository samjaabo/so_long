/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:38:44 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/04 21:11:25 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_map(char c)
{
	return (c == 'P' || c == 'C' || c == 'E' || c == '0' || c == '1'
		|| c == 'N');
}

static void	ft_allowed_chars(char **map)
{
	char	*tmp;
	char	**_map;

	_map = map;
	while (*map)
	{
		tmp = *map;
		if (*tmp == 0)
			ft_error("invalid map", _map);
		while (*tmp)
		{
			if (ft_is_map(*tmp) != 1)
				ft_error("invalid chars in map", _map);
			++tmp;
		}
		++map;
	}
}

static void	ft_is_same_width(char **map)
{
	int		width;
	char	**_map;

	_map = map;
	width = ft_strlen(*map);
	while (*map)
	{
		if (width != (int)ft_strlen(*map))
			ft_error("invalid map width", _map);
		++map;
	}
}

static void	ft_is_walls_map(char **map)
{
	char	*tmp;
	char	**_map;

	_map = map;
	tmp = *map++;
	while (*tmp == '1')
		++tmp;
	if (*tmp != 0)
		ft_error("invalid map", _map);
	while (*map)
	{
		tmp = *map;
		if (*tmp != '1')
			ft_error("invalid map", _map);
		while (*tmp)
			++tmp;
		if (*--tmp != '1')
			ft_error("invalid map", _map);
		++map;
	}
	tmp = *--map;
	while (*tmp == '1')
		++tmp;
	if (*tmp != 0)
		ft_error("invalid map", _map);
}

void	ft_map_rules(char **map)
{
	ft_allowed_chars(map);
	ft_is_same_width(map);
	ft_is_walls_map(map);
	if (ft_count_elements(map, 'C') == 0)
		ft_error("invalid map", map);
	if (ft_count_elements(map, 'P') != 1)
		ft_error("invalid map", map);
	if (ft_count_elements(map, 'E') != 1)
		ft_error("invalid map", map);
	ft_is_valid_path(map);
}
