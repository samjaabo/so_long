/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:28:55 by samjaabo          #+#    #+#             */
/*   Updated: 2023/01/09 08:49:56 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error(const char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

char	**ft_read_map(char *file)
{
	int fd;
	char	**ar;
	char	*tmp;

	ar = NULL;
	fd = open("tests.txt", O_RDWR);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			tmp[ft_strlen(tmp) - 1] = 0;
		ar = ft_realloc(ar, tmp);
	}
	return (ar);
}

int	*ft_player_pos(char **map)
{
	char		*tmp;
	static int	pos[2];

	pos[0] = 0;
	pos[1] = 0;
	while (*map)
	{
		tmp = *map;
		pos[0] = 0;
		while (*tmp)
		{
			if (*tmp == 'P')
				return (pos);
			pos[0]++;
			++tmp;
		}
		pos[1]++;
		++map;
	}
	return (NULL);
}

int	ft_count_elements(char **map, char c)
{
	char	*tmp;
	int		count;

	count = 0;
	while (*map)
	{
		tmp = *map;
		while (*tmp)
		{
			if (*tmp == c)
				++count;
			++tmp;
		}
		++map;
	}
	return (count);
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

char	**ft_realloc(char **array, char *new)
{
	int		count;
	char	**strs;
	char	**arcpy;
	char	**cpy;

	if (!new)
		ft_perror("malloc fail");
	count = 0;
	while (array && array[count])
		count++;
	strs = malloc((count + 2) * sizeof(char *));
	if (!strs)
		ft_perror("malloc fail");
	cpy = strs;
	arcpy = array;
	while (array && *array)
		*strs++ = *array++;
	*strs++ = new;
	*strs = NULL;
	free(arcpy);
	return (cpy);
}
