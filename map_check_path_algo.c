/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:30:07 by samjaabo          #+#    #+#             */
/*   Updated: 2023/02/20 16:41:40 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_arraydup(char	**tab)
{
	char	**ar;
	char	**cp;
	int		size;

	size = 0;
	cp = tab;
	while (*tab++)
		++size;
	ar = malloc((size + 1) * sizeof(char *));
	if (!ar)
		return (NULL);
	tab = cp;
	cp = ar;
	while (size--)
	{
		*ar = ft_strdup(*tab++);
		if (!*ar++)
			return (ft_clear(cp), NULL);
	}
	*ar = NULL;
	return (cp);
}

static int	is_path(char c)
{
	return (c == '0' || c == 'C');
}

static void	ft_check_path(char **map, int row, int col)
{
	if (is_path(map[row - 1][col]))
	{
		map[row - 1][col] = 'P';
		ft_check_path(map, row - 1, col);
	}
	if (is_path(map[row][col + 1]))
	{
		map[row][col + 1] = 'P';
		ft_check_path(map, row, col + 1);
	}
	if (is_path(map[row + 1][col]))
	{
		map[row + 1][col] = 'P';
		ft_check_path(map, row + 1, col);
	}
	if (is_path(map[row][col - 1]))
	{
		map[row][col - 1] = 'P';
		ft_check_path(map, row, col -1);
	}
}

void	ft_is_valid_path(char **_map)
{
	char	**map;
	int		row;
	int		col;

	map = ft_arraydup(_map);
	if (!map)
		ft_error("malloc fail", map);
	ft_check_path(map, ft_element_pos(map, 'P')[ROW],
		ft_element_pos(map, 'P')[COL]);
	if (ft_count_elements(map, 'C'))
	{
		printf("Error\ninvalid map: invalid paths to Collectable");
		exit(1);
	}
	row = ft_element_pos(map, 'E')[ROW];
	col = ft_element_pos(map, 'E')[COL];
	if (map[row - 1][col] != 'P' && map[row][col + 1] != 'P'
		&& map[row + 1][col] != 'P' && map[row][col - 1] != 'P')
	{
		printf("Error\ninvalid map: invalid paths to Exit");
		exit(1);
	}
	ft_clear(map);
}
