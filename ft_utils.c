/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:41:41 by samjaabo          #+#    #+#             */
/*   Updated: 2023/01/09 08:24:27 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
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

char	*ft_reallco_str(char *oldstr, char new)
{
	char	*s;
	char	*ss;
	char	*old;
	int		len;

	old = oldstr;
	if (!oldstr)
		ft_perror("malloc fail");
	len = ft_strlen(oldstr);
	s = malloc(len + 2);
	if (!s)
		ft_perror("malloc fail");
	ss = s;
	while (oldstr && *oldstr)
		*ss++ = *oldstr++;
	*ss++ = new;
	*ss = 0;
	free(old);
	return (s);
}

static char	**ft_del_empty(char **ar, char c)
{
	char	**cpy;
	char	**new;
	int		i;

	cpy = ar;
	new = NULL;
	while (*ar)
	{
		i = 0;
		while ((*ar)[i] && (*ar)[i] == c)
			++i;
		if ((*ar)[i] == '\0')
			free(*ar);
		else
			new = ft_realloc(new, *ar);
		++ar;
	}
	free(cpy);
	return (new);
}

char	**ft_split_args(const char *str, char c)
{
	char	**args;
	char	quote_char;
	char	*buf;
	int		i;

	buf = ft_strdup("");
	args = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote_char = str[i++];
			while (str[i] && str[i++] != quote_char)
				buf = ft_reallco_str(buf, str[i - 1]);
		}
		else if (str[i] == c && ++i)
		{
			args = ft_realloc(args, buf);
			buf = ft_strdup("");
		}
		else
			buf = ft_reallco_str(buf, str[i++]);
	}
	return (ft_del_empty(ft_realloc(args, buf), c));
}

void ft_printar(char **t)
{
	if (!t)
	{
		printf("(null)");
		return ;
	}
	while(*t)
		printf("%s\n", *t++);
}