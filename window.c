/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:08:02 by samjaabo          #+#    #+#             */
/*   Updated: 2023/01/10 16:08:35 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_move_up(char **map)
{
	int	row;
	int	col;
	
	int	*pos;

	pos = ft_player_pos(map);
	row = pos[1];
	col = pos[0];
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

	pos = ft_player_pos(map);
	row = pos[1];
	col = pos[0];
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

	pos = ft_player_pos(map);
	row = pos[1];
	col = pos[0];
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

	pos = ft_player_pos(map);
	row = pos[1];
	col = pos[0];
	if (map[row + 1][col] == 'E' && !ft_count_elements(map, 'C'))
		exit(0);
	if (map[row + 1][col] != '1' && map[row + 1][col] != 'E')
	{
		map[row + 1][col] = 'P';
		map[row][col] = '0';
		return (1);
	}
	return (0);
}

int movments(int key, t_widget *widget)
{
	char		**map;
	static int	mov_count;

	map = widget->map;
	if (key == 126)
		mov_count += ft_move_up(map);
	else if (key == 123)
		mov_count += ft_move_left(map);
	else if (key == 124)
		mov_count += ft_move_right(map);
	else if (key == 125)
		mov_count += ft_move_down(map);
	else if (key == 53)
		exit(0);
	ft_printar(map);
	self_show_widget(widget);
	printf("%d\n", mov_count);
	return (0);
}

// int main(void)
// {
// 	void *mlx;
// 	void *win;
// 	int fd;
// 	int *pos;
	

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 640, 480, "Key Press Test");
// 	mlx_key_hook(win, movments, NULL);
// 	mlx_loop(mlx);
// 	return (0);
// }