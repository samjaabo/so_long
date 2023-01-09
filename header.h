/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:06:58 by samjaabo          #+#    #+#             */
/*   Updated: 2023/01/09 09:00:00 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <errno.h>

# include "get_next_line.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdint.h>
# include <limits.h>

#include <mlx.h>

//utils functions
char		*ft_reallco_str(char *oldstr, char new);
char		**ft_split_args(const char *str, char c);
void		 ft_printar(char **t);



//project functions
int 	movments(int key, void *param);

//so_long_utils.c
void	ft_error(const char *msg);
void	ft_perror(char *str);
char	**ft_read_map(char *file);
int		*ft_player_pos(char **map);
int		ft_count_elements(char **map, char c);
char	*ft_clear(char **ar);
char	**ft_realloc(char **array, char *new);


//map_check_path_algo.c
void	ft_is_valid_path(char **_map);

//map_rules.c
void	ft_map_rules(char **map);
#endif