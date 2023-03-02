/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:27:29 by samjaabo          #+#    #+#             */
/*   Updated: 2023/02/20 16:41:48 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char **map, int p_exit)
{
	if (map)
		ft_clear(map);
	exit(p_exit);
}

void	ft_error(const char *msg, char **map)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	ft_exit(map, 1);
}

char	*ft_clear(char **ar)
{
	char	**cp;

	if (!ar)
		return (NULL);
	cp = ar;
	while (*ar)
		free(*ar++);
	free(cp);
	return (NULL);
}

void	ft_is_not_null(t_widget *wid)
{
	if (!wid->collect_img || !wid->exit_img || !wid->ground_img
		|| !wid->player_img || !wid->wall_img || !wid->window || !wid->self)
		ft_error("mlx fail returns NULL", wid->map);
}

int	ft_destroy(t_widget *wid)
{
	ft_exit(wid->map, 0);
	return (0);
}
