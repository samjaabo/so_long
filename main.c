/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:56:11 by samjaabo          #+#    #+#             */
/*   Updated: 2023/01/10 17:52:00 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int count_cols(char **map)
{
	return (ft_strlen(*map));
}
int count_rows(char **map)
{
	int n;

	n = 0;
	while(*map++)
		++n;
	return (n);
}

void	self_show_widget(t_widget *wid)
{
	wid->row = 0;
	while (wid->row < wid->rows)
	{
		wid->col = 0;
		while (wid->col < wid->cols)
		{
			if (wid->map[wid->row][wid->col] == '1')
				mlx_put_image_to_window(wid->self, wid->window,
					wid->wall_img, wid->size * wid->col, wid->size * wid->row);
			else if (wid->map[wid->row][wid->col] == 'C')
				mlx_put_image_to_window(wid->self, wid->window,
					wid->collect_img, wid->size * wid->col, wid->size * wid->row);
			else if (wid->map[wid->row][wid->col] == 'P')
				mlx_put_image_to_window(wid->self, wid->window,
					wid->player_img, wid->size * wid->col, wid->size * wid->row);
			else if (wid->map[wid->row][wid->col] == 'E')
				mlx_put_image_to_window(wid->self, wid->window,
					wid->exit_img, wid->size * wid->col, wid->size * wid->row);
			else
				mlx_put_image_to_window(wid->self, wid->window,
					wid->ground_img, wid->size * wid->col, wid->size * wid->row);
			wid->col++;
		}
		wid->row++;
	}
}

void	__init__(t_widget *widget, char *map_file)
{
	int	tmp;

	widget->map = ft_read_map(map_file);
	ft_map_rules(widget->map);
	widget->player_img = mlx_xpm_file_to_image(widget->self,
		 "./textures/player.xpm", &tmp, &tmp);
	widget->exit_img = mlx_xpm_file_to_image(widget->self,
		"./textures/exit.xpm", &tmp, &tmp);
	widget->collect_img = mlx_xpm_file_to_image(widget->self,
		"./textures/collect.xpm", &tmp, &tmp);
	widget->ground_img = mlx_xpm_file_to_image(widget->self,
		"./textures/ground.xpm", &tmp, &tmp);
	widget->wall_img = mlx_xpm_file_to_image(widget->self,
		"./textures/wall.xpm", &tmp, &tmp);
	widget->cols = count_cols(widget->map);
	widget->rows = count_rows(widget->map);
	widget->row = 0;
	widget->col = 0;
	widget->size = tmp;
	widget->self = mlx_init();
	widget->window = mlx_new_window(widget->self, widget->cols*widget->size,
		widget->rows*widget->size, "42 so_long");
	self_show_widget(widget);
}

int main()
{
	int			tmp;
	t_widget	widget;

	__init__(&widget, "tests.txt");
	mlx_key_hook(widget.window, movments, &widget);
	mlx_loop(widget.self);
}