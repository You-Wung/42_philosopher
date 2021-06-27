/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 22:04:43 by tyou              #+#    #+#             */
/*   Updated: 2021/06/23 19:38:11 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		err(char *str)
{
	printf("%s\n", str);
	exit(0);
}

int		is_space(char str)
{
	if (str == '\t' || str == '\n' || str == '\v' || str == '\f'
					|| str == '\r' || str == ' ')
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *str)
{
	int			i;
	long long	rt;
	int			sign;

	sign = 1;
	i = 0;
	rt = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (rt * sign < -2147483648 || rt * sign > 2147483647)
			break ;
		rt = (rt * 10) + (str[i] - 48);
		i++;
	}
	if (rt * sign < -2147483648)
		return (0);
	else if (rt * sign > 2147483647)
		return (-1);
	return (sign * rt);
}
