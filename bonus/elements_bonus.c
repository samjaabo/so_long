/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:28:53 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/05 16:24:44 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	*ft_element_pos(char **map, char element)
{
	char		*tmp;
	static int	pos[2];

	pos[COL] = 0;
	pos[ROW] = 0;
	while (*map)
	{
		tmp = *map;
		pos[COL] = 0;
		while (*tmp)
		{
			if (*tmp == element)
				return (pos);
			pos[COL]++;
			++tmp;
		}
		pos[ROW]++;
		++map;
	}
	return (NULL);
}

int	ft_count_elements(char **map, char element)
{
	char	*tmp;
	int		count;

	count = 0;
	while (*map)
	{
		tmp = *map;
		while (*tmp)
		{
			if (*tmp == element)
				++count;
			++tmp;
		}
		++map;
	}
	return (count);
}
