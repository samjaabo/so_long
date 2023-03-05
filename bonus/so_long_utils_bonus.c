/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:28:55 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/05 16:25:58 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**ft_realloc(char **array, char *new)
{
	int		count;
	char	**strs;
	char	**arcpy;
	char	**cpy;

	count = 0;
	while (array && array[count])
		count++;
	strs = malloc((count + 2) * sizeof(char *));
	if (!strs || !new)
		ft_error("malloc fail", array);
	cpy = strs;
	arcpy = array;
	while (array && *array)
		*strs++ = *array++;
	*strs++ = new;
	*strs = NULL;
	free(arcpy);
	return (cpy);
}

char	**ft_read_map(char *file)
{
	int		fd;
	char	**ar;
	char	*tmp;

	ar = NULL;
	fd = open(file, O_RDWR);
	if (fd < 0)
		ft_error("while reading from file", NULL);
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

void	ft_is_true_args(int argc, char **argv)
{
	int		len;
	char	*file;

	if (argc != 2)
		ft_error("usage:./so_long <map_file>.ber", NULL);
	file = argv[1];
	len = ft_strlen(file);
	if (len < 4)
		ft_error("usage:./so_long <map_file>.ber", NULL);
	if (ft_strcmp(file + len - 4, ".ber") != 0)
		ft_error("usage:./so_long <map_file>.ber", NULL);
}