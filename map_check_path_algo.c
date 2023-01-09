/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:30:07 by samjaabo          #+#    #+#             */
/*   Updated: 2023/01/09 09:13:02 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	*ft_exit_pos(char **map)
{
	char		*tmp;
	static int	pos[2];

	pos[0] = 0;
	pos[1] = 0;
	while (*map)
	{
		tmp = *map;
		pos[0] = 0;
		while (*tmp)
		{
			if (*tmp == 'E')
				return (pos);
			pos[0]++;
			++tmp;
		}
		pos[1]++;
		++map;
	}
	return (NULL);
}

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

static void	ft_write_map_paths(char **map, int row, int col)
{
	if (is_path(map[row - 1][col]))
	{
		map[row - 1][col] = 'P';
		ft_write_map_paths(map, row - 1, col);
	}
	if (is_path(map[row][col + 1]))
	{
		map[row][col + 1] = 'P';
		ft_write_map_paths(map, row, col + 1);
	}
	if (is_path(map[row + 1][col]))
	{
		map[row + 1][col] = 'P';
		ft_write_map_paths(map, row + 1, col);
	}
	if (is_path(map[row][col - 1]))
	{
		map[row][col - 1] = 'P';
		ft_write_map_paths(map, row, col -1);
	}
}

void	ft_is_valid_path(char **_map)
{
	char	**map;
	int		row;
	int		col;

	map = ft_arraydup(_map);
	if (!map)
		ft_perror("Error\nmalloc fail");
	ft_write_map_paths(map, ft_player_pos(map)[1], ft_player_pos(map)[0]);
	if (ft_count_elements(map, 'C'))
	{
		printf("Error\ninvalid map: invalid paths to Collectable");
		exit(1);
	}
	row = ft_exit_pos(map)[1];
	col = ft_exit_pos(map)[0];
	if (map[row - 1][col] != 'P' && map[row][col + 1] != 'P'
		&& map[row + 1][col] != 'P' && map[row][col - 1] != 'P')
	{
		printf("Error\ninvalid map: invalid paths to Exit");
		exit(1);
	}
	ft_clear(map);
}
