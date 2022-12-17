/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:21:33 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/17 13:38:04 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	target_to_top(t_stack **stack, int index, char choice)
{
	if (index == 0)
		return ;
	else if (index == 1)
	{
		r(stack, choice);
		return ;
	}
	else if (index == 2)
	{
		r(stack, choice);
		r(stack, choice);
		return ;
	}
	else if ((stack_size(*stack) - index) > (stack_size(*stack) / 2))
		index_top(stack, index, choice);
	else if ((stack_size(*stack) - index) <= (stack_size(*stack) / 2))
		index_bottom(stack, index, choice);
}

void	order_stack_b(t_stack **stack_b)
{
	int	index_min;

	if (!(*stack_b))
		return ;
	index_min = ft_min(*stack_b);
	target_to_top(stack_b, index_min, 'b');
}

void	target_to_b(t_stack **stack_a, int min, int max, t_stack **stack_b)
{
	int		index;

	index = 0;
	while ((*stack_a) && index >= 0)
	{
		index = find_index(stack_a, min, max);
		if (index == -1)
			break ;
		target_to_top(stack_a, index, 'a');
		order_stack_b(stack_b);
		p(stack_a, stack_b, 'b');
	}
}

void	highest_to_a(t_stack **stack_b, t_stack **stack_a)
{
	int		index;

	index = 0;
	while ((*stack_b) && index >= 0)
	{
		index = ft_max(*stack_b);
		target_to_top(stack_b, index, 'b');
		p(stack_b, stack_a, 'a');
	}
}

void	back_to_a(t_stack **stack_b, t_stack **stack_a, int count)
{
	while (count > 0)
	{
		p(stack_b, stack_a, 'a');
		count--;
	}
}
