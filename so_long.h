/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:06:58 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/05 19:00:51 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

enum e_const {
	USELESS = 0,
	COL = 0,
	ROW = 1,
	ON_KEYDOWN = 2,
	ON_DESTROY = 17,
};

typedef struct widget_s {
	char	**map;
	void	*self;
	void	*window;
	void	*ground_img;
	void	*wall_img;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	int		rows;
	int		cols;
	int		row;
	int		col;
	int		size;
}			t_widget;

/*
** moves.c
*/
int			ft_exec_move(int key, t_widget *widget);

/*
** so_long_utils.c
*/
char		**ft_read_map(char *file);
void		ft_is_true_args(int argc, char **argv);

/*
** map_check_path_algo.c
*/
void		ft_is_valid_path(char **_map);

/*
** map_rules.c
*/
void		ft_map_rules(char **map);

/*
** main.c
*/
void		self_show_widget(t_widget *wid);

/*
** elements.c
*/
int			*ft_element_pos(char **map, char element);
int			ft_count_elements(char **map, char element);

/*
** libft.c
*/
void		ft_putstr(char *s);
void		ft_putnbr(int n);
int			ft_strcmp(const char *s1, const char *s2);

/*
** exit_and_arror.c handling errors here
*/
void		ft_exit(char **map, int p_exit);
void		ft_error(const char *msg, char **map);
char		*ft_clear(char **ar);
void		ft_is_not_null(t_widget *wid);
int			ft_destroy(t_widget *wid);

#endif