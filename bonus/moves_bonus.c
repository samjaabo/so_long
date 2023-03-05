/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:02 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/05 16:25:38 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_move_up(char **map, int *count)
{
	int	row;
	int	col;
	int	*pos;

	pos = ft_element_pos(map, 'P');
	row = pos[ROW];
	col = pos[COL];
	if (map[row - 1][col] == 'N')
		ft_exit(map, 0);
	if (map[row - 1][col] == 'E' && !ft_count_elements(map, 'C'))
		ft_exit(map, 0);
	if (map[row - 1][col] != '1' && map[row - 1][col] != 'E')
	{
		map[row - 1][col] = 'P';
		map[row][col] = '0';
		*count += 1;
	}
	return (0);
}

static int	ft_move_left(char **map, int *count)
{
	int	row;
	int	col;
	int	*pos;

	pos = ft_element_pos(map, 'P');
	row = pos[ROW];
	col = pos[COL];
	if (map[row][col - 1] == 'N')
		ft_exit(map, 0);
	if (map[row][col - 1] == 'E' && !ft_count_elements(map, 'C'))
		ft_exit(map, 0);
	if (map[row][col - 1] != '1' && map[row][col - 1] != 'E')
	{
		map[row][col - 1] = 'P';
		map[row][col] = '0';
		*count += 1;
	}
	return (0);
}

static int	ft_move_right(char **map, int *count)
{
	int	row;
	int	col;
	int	*pos;

	pos = ft_element_pos(map, 'P');
	row = pos[ROW];
	col = pos[COL];
	if (map[row][col + 1] == 'N')
		ft_exit(map, 0);
	if (map[row][col + 1] == 'E' && !ft_count_elements(map, 'C'))
		ft_exit(map, 0);
	if (map[row][col + 1] != '1' && map[row][col + 1] != 'E')
	{
		map[row][col + 1] = 'P';
		map[row][col] = '0';
		*count += 1;
	}
	return (0);
}

static int	ft_move_down(char **map, int *count)
{
	int	row;
	int	col;
	int	*pos;

	pos = ft_element_pos(map, 'P');
	row = pos[ROW];
	col = pos[COL];
	if (map[row + 1][col] == 'N')
		ft_exit(map, 0);
	if (map[row + 1][col] == 'E' && !ft_count_elements(map, 'C'))
		ft_exit(map, 0);
	if (map[row + 1][col] != '1' && map[row + 1][col] != 'E')
	{
		map[row + 1][col] = 'P';
		map[row][col] = '0';
		*count += 1;
	}
	return (0);
}

int ft_exec_move(int key, t_widget *widget)
{
	char		**map;
	static int	mov_count;

	map = widget->map;
	if (key == 126 || key == 13)
		ft_move_up(map, &mov_count);
	else if (key == 123 || key == 0)
		ft_move_left(map, &mov_count);
	else if (key == 124 || key == 2)
		ft_move_right(map, &mov_count);
	else if (key == 125 || key == 1)
		ft_move_down(map, &mov_count);
	else if (key == 53)
		ft_destroy(widget);
	if (key == 123 || key == 0)
		widget->player_img = widget->player_to_left;
	if (key == 124 || key == 2)
		widget->player_img = widget->player_to_right;
	widget->mov_count = mov_count;
	return (0);
}
