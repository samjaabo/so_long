/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:32:32 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/05 16:33:29 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_path(char c)
{
	return (c == '0' || c == 'P');
}

static void	ft_check(char **map, int row, int col)
{
	if (map[row][col] == 'P')
		ft_exit(map, 0);
	map[row][col] = 'N';

}

static void	ft_random_move(char **map, int row, int col)
{
	int random;

	srand(clock());
	random = rand() % 4;
	if (is_path(map[row - 1][col]) && random == 0)
	{
		ft_check(map, row - 1, col);
		map[row][col] = '0';
	}
	else if (is_path(map[row][col + 1]) && random == 1)
	{
		ft_check(map, row, col + 1);
		map[row][col] = '0';
	}
	else if (is_path(map[row + 1][col]) && random == 2)
	{
		ft_check(map, row + 1, col);
		map[row][col] = '0';
	}
	else if (is_path(map[row][col - 1]) && random == 3)
	{
		ft_check(map, row, col - 1);
		map[row][col] = '0';
	}
}

void	self_show_enemy(t_widget *wid)
{
	static int	one_sec = 0;

	wid->row = 0;
	while (wid->row < wid->rows)
	{
		wid->col = 0;
		while (wid->col < wid->cols)
		{
			if (wid->map[wid->row][wid->col] == 'N')
			{
				if (one_sec != time(NULL))
				{
					ft_random_move(wid->map, wid->row, wid->col);
				 	one_sec = time(NULL);
				}
				mlx_put_image_to_window(wid->self, wid->window,
					wid->enemy_img, wid->size * wid->col, wid->size * wid->row);
			}
			wid->col++;
		}
		wid->row++;
	}
}
