/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:56:11 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/04 22:13:29 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int count_cols(char **map)
{
	return (ft_strlen(*map));
}

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

int	ft_show_collect_animation(t_widget *wid)
{
	static int last;

	wid->row = 0;
	while (wid->row < wid->rows)
	{
		wid->col = 0;
		while (wid->col < wid->cols)
		{
			if (wid->map[wid->row][wid->col] == 'C' && last == 0)
				mlx_put_image_to_window(wid->self, wid->window,
					wid->collect_img, wid->size * wid->col, wid->size * wid->row);
			if (wid->map[wid->row][wid->col] == 'C' && last == 1)
				mlx_put_image_to_window(wid->self, wid->window,
					wid->collect_1, wid->size * wid->col, wid->size * wid->row);
			wid->col++;
		}
		wid->row++;
	}
	if (last == 0)
		last = 1;
	else
		last = 0;
	return (0);
}

int	ft_show_enemy_animation(t_widget *wid)
{
	static int last;

	wid->row = 0;
	while (wid->row < wid->rows)
	{
		wid->col = 0;
		while (wid->col < wid->cols)
		{
			if (wid->map[wid->row][wid->col] == 'N' && last == 0)
				mlx_put_image_to_window(wid->self, wid->window,
					wid->enemy_0, wid->size * wid->col, wid->size * wid->row);
			if (wid->map[wid->row][wid->col] == 'N' && last == 1)
				mlx_put_image_to_window(wid->self, wid->window,
					wid->enemy_1, wid->size * wid->col, wid->size * wid->row);
			wid->col++;
		}
		wid->row++;
	}
	if (last == 0)
		last = 1;
	else
		last = 0;
	return (0);
}

static void	__init__(t_widget *widget, char *map_file)
{
	int	tmp;

	widget->map = ft_read_map(map_file);
	ft_map_rules(widget->map);
	widget->self = mlx_init();
	widget->exit_img = mlx_xpm_file_to_image(widget->self,
		"../textures/exit-opened.xpm", &tmp, &tmp);
	widget->collect_img = mlx_xpm_file_to_image(widget->self,
		"../textures/collect-0.xpm", &tmp, &tmp);
	widget->ground_img = mlx_xpm_file_to_image(widget->self,
		"../textures/ground2.xpm", &tmp, &tmp);
	widget->wall_img = mlx_xpm_file_to_image(widget->self,
		"../textures/ground1.xpm", &tmp, &tmp);
	widget->cols = count_cols(widget->map);
	widget->rows = count_rows(widget->map);
	widget->row = 0;
	widget->col = 0;
	widget->size = tmp;
	widget->window = mlx_new_window(widget->self, widget->cols*widget->size,
		widget->rows*widget->size, "so_long");
	ft_is_not_null(widget, 1);
}

static void	__init__bonus(t_widget *widget)
{
	int	tmp;

	widget->player_to_left = mlx_xpm_file_to_image(widget->self,
		"../textures/player-to-left.xpm", &tmp, &tmp);
	widget->player_to_right = mlx_xpm_file_to_image(widget->self,
		"../textures/player-to-right.xpm", &tmp, &tmp);
	widget->exit_1 = mlx_xpm_file_to_image(widget->self,
		"../textures/exit-closed.xpm", &tmp, &tmp);
	widget->collect_1 = mlx_xpm_file_to_image(widget->self,
		"../textures/collect-1.xpm", &tmp, &tmp);
	widget->enemy_0 = mlx_xpm_file_to_image(widget->self,
		"../textures/enemy-0.xpm", &tmp, &tmp);
	widget->enemy_1 = mlx_xpm_file_to_image(widget->self,
		"../textures/enemy-1.xpm", &tmp, &tmp);
	widget->player_img = widget->player_to_left;
	ft_is_not_null(widget, 0);
	self_show_widget(widget);
}

int	ft_update(t_widget *widget)
{
	static int	counter;

	(void)widget;
	if (counter >= 2000)
	{
		ft_show_collect_animation(widget);
		ft_show_enemy_animation(widget);
		counter = 0; 
	}
	counter++;
	return (0);
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

// #include <stdio.h>
// #include <time.h>

// void print_hello_every_second() {
//     clock_t start_time = clock();
//     double elapsed_time = 0.0;

//     while (1) {
//         elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
//         if (elapsed_time >= 1.0) {
//             printf("Hello!\n");
//             start_time = clock();
//         }
//     }
// }

// int main() {
//     print_hello_every_second();
//     return 0;
// }
