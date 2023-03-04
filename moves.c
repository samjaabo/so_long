/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:02 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/04 13:36:24 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_move_up(char **map)
{
	int	row;
	int	col;
	int	*pos;

	pos = ft_element_pos(map, 'P');
	row = pos[ROW];
	col = pos[COL];
	if (map[row - 1][col] == 'E' && !ft_count_elements(map, 'C'))
		exit(0);
	if (map[row - 1][col] != '1' && map[row - 1][col] != 'E')
	{
		map[row - 1][col] = 'P';
		map[row][col] = '0';
		return (1);
	}

	return (0);
}

static int	ft_move_left(char **map)
{
	int	row;
	int	col;
	int	*pos;

	pos = ft_element_pos(map, 'P');
	row = pos[ROW];
	col = pos[COL];
	if (map[row][col - 1] == 'E' && !ft_count_elements(map, 'C'))
		exit(0);
	if (map[row][col - 1] != '1' && map[row][col - 1] != 'E')
	{
		map[row][col - 1] = 'P';
		map[row][col] = '0';
		return (1);
	}
	return (0);
}

static int	ft_move_right(char **map)
{
	int	row;
	int	col;
	int	*pos;

	pos = ft_element_pos(map, 'P');
	row = pos[ROW];
	col = pos[COL];
	if (map[row][col + 1] == 'E' && !ft_count_elements(map, 'C'))
		exit(0);
	if (map[row][col + 1] != '1' && map[row][col + 1] != 'E')
	{
		map[row][col + 1] = 'P';
		map[row][col] = '0';
		return (1);
	}
	return (0);
}

static int	ft_move_down(char **map)
{
	int	row;
	int	col;
	int	*pos;

	pos = ft_element_pos(map, 'P');
	row = pos[ROW];
	col = pos[COL];
	if (map[row + 1][col] == 'E' && !ft_count_elements(map, 'C'))
		ft_exit(map, 0);
	if (map[row + 1][col] != '1' && map[row + 1][col] != 'E')
	{
		map[row + 1][col] = 'P';
		map[row][col] = '0';
		return (1);
	}
	return (0);
}

int ft_exec_move(int key, t_widget *widget)
{
	char		**map;
	static int	mov_count;

	map = widget->map;
	if (key == 126 || key == 13)
		mov_count += ft_move_up(map);
	else if (key == 123 || key == 0)
		mov_count += ft_move_left(map);
	else if (key == 124 || key == 2)
		mov_count += ft_move_right(map);
	else if (key == 125 || key == 1)
		mov_count += ft_move_down(map);
	else if (key == 53)
		ft_destroy(widget);
	mlx_clear_window(widget->self, widget->window);
	self_show_widget(widget);
	ft_putnbr(mov_count);
	return (0);
}
