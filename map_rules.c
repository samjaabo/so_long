/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:38:44 by samjaabo          #+#    #+#             */
/*   Updated: 2023/01/09 09:07:34 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_is_map(char c)
{
	return (c == 'P' || c == 'C' || c == 'E' || c == '0' || c == '1');
}

static void	ft_allowed_chars(char **map)
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

static void	ft_is_same_width(char **map)
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

static void	ft_is_walls_map(char **map)
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
		ft_error("invalid map");
	if (ft_count_elements(map, 'P') != 1)
		ft_error("invalid map");
	if (ft_count_elements(map, 'E') != 1)
		ft_error("invalid map");
	ft_is_valid_path(map);
}
