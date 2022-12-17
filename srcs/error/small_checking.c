/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:14:17 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/17 17:28:46 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_overflow(char *argv)
{
	char	*max;
	char	*min;

	max = "2147483647";
	min = "-2147483648";
	if (ft_strlen(argv) < 10)
		return (1);
	if (argv[0] == '-' && ft_strncmp(argv, min, ft_strlen(argv)) > 0)
		return (0);
	else if (ft_strncmp(argv, max, ft_strlen(argv)) > 0)
		return (0);
	return (1);
}

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

int	is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	spaces(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == ' ')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
