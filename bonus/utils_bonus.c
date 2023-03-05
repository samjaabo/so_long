/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:29:51 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/05 19:09:26 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_check_exit(t_widget *wid)
{
	if (ft_count_elements(wid->map, 'C') == 0)
		wid->exit_img = wid->exit_opened;
}

static void	ft_animate_collectable(t_widget *wid)
{
	static int	per_sec = 0;

	if (per_sec != time(NULL))
	{
		if (wid->collect_img == wid->collect_img1)
			wid->collect_img = wid->collect_img2;
		else
			wid->collect_img = wid->collect_img1;
		per_sec = time(NULL);
	}
}

int	ft_update(t_widget *widget)
{
	mlx_clear_window(widget->self, widget->window);
	self_show_widget(widget);
	self_show_enemy(widget);
	ft_check_exit(widget);
	ft_animate_collectable(widget);
	mlx_string_put(widget->self, widget->window,
		widget->cols / 2 * widget->size,
		widget->rows * widget->size + widget->size / 2,
		0xFFFFFF, ft_itoa(widget->mov_count));
	return (0);
}
