/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:32:52 by samjaabo          #+#    #+#             */
/*   Updated: 2023/02/20 15:53:51 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*ft_split_int(int n)
{
	static char	s[12];

	if (n < 0)
		n = n * -1;
	s[0] = '0';
	s[1] = n / 1000000000 + '0';
	s[2] = n % 1000000000 / 100000000 + '0';
	s[3] = n % 100000000 / 10000000 + '0';
	s[4] = n % 10000000 / 1000000 + '0';
	s[5] = n % 1000000 / 100000 + '0';
	s[6] = n % 100000 / 10000 + '0';
	s[7] = n % 10000 / 1000 + '0';
	s[8] = n % 1000 / 100 + '0';
	s[9] = n % 100 / 10 + '0';
	s[10] = n % 10 / 1 + '0';
	s[11] = '\0';
	return ((char *)s);
}

static char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return ("-2147483648");
	str = ft_split_int(n);
	while (*str == '0')
		++str;
	if (n < 0)
		*--str = '-';
	if (n == 0)
		--str;
	return (str);
}

void	ft_putnbr(int n)
{
	ft_putstr(ft_itoa(n));
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (*--s1 - *--s2);
	return (*s1 - *s2);
}