/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:48:17 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/17 11:46:39 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_in_range(int x, int min, int max)
{
	return (x >= min && x <= max);
}

int	find_top_index(t_stack **stack_a, int min, int max)
{
	int		top_index;
	int		index;
	t_stack	*runner;

	index = 1;
	top_index = 0;
	runner = *stack_a;
	while (runner)
	{
		if (is_in_range(runner->nb, min, max))
		{
			top_index = index;
			break ;
		}
		index++;
		runner = runner->next;
	}
	if (top_index == 0)
		return (-1);
	return (top_index - 1);
}

int	find_bottom_index(t_stack **stack_a, int min, int max)
{
	int		bottom_index;
	int		index;
	t_stack	*runner;

	index = 1;
	bottom_index = 0;
	runner = *stack_a;
	while (runner)
	{
		if (is_in_range(runner->nb, min, max))
			bottom_index = index;
		index++;
		runner = runner->next;
	}
	if (bottom_index == 0)
		return (-1);
	return (bottom_index - 1);
}

int	find_index(t_stack **stack_a, int min, int max)
{
	int		index;
	int		bottom_index;
	int		top_index;

	index = 0;
	bottom_index = find_bottom_index(stack_a, min, max);
	top_index = find_top_index(stack_a, min, max);
	if (top_index <= (stack_size(*stack_a) - bottom_index))
		index = top_index;
	else
		index = bottom_index;
	if (top_index == -1 && bottom_index == -1)
		return (-1);
	return (index);
}

void	scan_a(t_stack **stack_a, t_stack **stack_b, int *i, int *count)
{
	int	size;
	int	j;

	j = -1;
	size = stack_size(*stack_a);
	while (++j < size)
	{
		if (((*stack_a)->nb >> *i) & 1)
			r(stack_a, 'a');
		else
		{
			p(stack_a, stack_b, 'b');
			(*count)++;
		}
	}
}
