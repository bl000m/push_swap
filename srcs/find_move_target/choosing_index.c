/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choosing_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:24:24 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/17 13:32:27 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	index_top(t_stack **stack, int index, char choice)
{
	while (index > 0)
	{
		r(stack, choice);
		index--;
	}
}

void	index_bottom(t_stack **stack, int index, char choice)
{
	while (index < stack_size(*stack))
	{
		rr(stack, choice);
		index++;
	}
}

int	how_much_lower(int *indexes, int nb, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (indexes[i++] < nb)
			count++;
	}
	return (count);
}
