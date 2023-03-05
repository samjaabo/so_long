/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:56:11 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/05 17:43:34 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int count_rows(char **map)
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
			else if (wid->map[wid->row][wid->col] == '0')
				mlx_put_image_to_window(wid->self, wid->window,
					wid->ground_img, wid->size * wid->col, wid->size * wid->row);
			wid->col++;
		}
		wid->row++;
	}
}

static void	__init__(t_widget *widget, char *map_file)
{
	int	tmp;

	widget->map = ft_read_map(map_file);
	ft_map_rules(widget->map);
	widget->self = mlx_init();
	widget->exit_img = mlx_xpm_file_to_image(widget->self,
		"./textures/exit-closed.xpm", &tmp, &tmp);
	widget->ground_img = mlx_xpm_file_to_image(widget->self,
		"./textures/ground2.xpm", &tmp, &tmp);
	widget->wall_img = mlx_xpm_file_to_image(widget->self,
		"./textures/ground1.xpm", &tmp, &tmp);
	widget->enemy_img = mlx_xpm_file_to_image(widget->self,
		"./textures/dog-enemy.xpm", &tmp, &tmp);
	widget->cols = ft_strlen(widget->map[0]);
	widget->rows = count_rows(widget->map);
	widget->row = 0;
	widget->col = 0;
	widget->size = tmp;
	widget->window = mlx_new_window(widget->self, widget->cols * widget->size,
		(widget->rows + 1) * widget->size, "so_long");
}

static void	__init__bonus(t_widget *widget)
{
	int	tmp;

	widget->player_to_left = mlx_xpm_file_to_image(widget->self,
		"./textures/player-to-left.xpm", &tmp, &tmp);
	widget->player_to_right = mlx_xpm_file_to_image(widget->self,
		"./textures/player-to-right.xpm", &tmp, &tmp);
	widget->collect_img2 = mlx_xpm_file_to_image(widget->self,
		"./textures/collect-1.xpm", &tmp, &tmp);
	widget->collect_img1 = mlx_xpm_file_to_image(widget->self,
		"./textures/collect-0.xpm", &tmp, &tmp);
	widget->collect_img = widget->collect_img1;
	widget->exit_opened = mlx_xpm_file_to_image(widget->self,
		"./textures/exit-opened.xpm", &tmp, &tmp);
	widget->player_img = widget->player_to_left;
	widget->mov_count = 0;
	ft_is_not_null(widget);
}

int	main(int argc, char **argv)
{
	t_widget	widget;

	ft_is_true_args(argc, argv);
	__init__(&widget, argv[1]);
	__init__bonus(&widget);
	mlx_hook(widget.window, ON_KEYDOWN, USELESS, ft_exec_move, &widget);
	mlx_hook(widget.window, ON_DESTROY, USELESS, ft_destroy, &widget);
	mlx_loop_hook(widget.self , ft_update, &widget);
	mlx_loop(widget.self);
	return (0);
}
