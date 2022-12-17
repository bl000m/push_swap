/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:05:11 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/17 13:35:11 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_min(t_stack *stack)
{
	int	min;
	int	index;
	int	smallest_index;

	smallest_index = 0;
	min = stack->nb;
	index = 0;
	while (stack)
	{
		if (stack->nb < min)
		{
			min = stack->nb;
			smallest_index = index;
		}
		index++;
		stack = stack->next;
	}
	return (smallest_index);
}

int	ft_max(t_stack *stack)
{
	int	max;
	int	index;
	int	highest_index;

	highest_index = 0;
	max = stack->nb;
	index = 0;
	while (stack)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			highest_index = index;
		}
		index++;
		stack = stack->next;
	}
	return (highest_index);
}

int	ft_min_value(t_stack *stack)
{
	int	min;
	int	index;

	min = stack->nb;
	index = 0;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		index++;
		stack = stack->next;
	}
	return (min);
}

int	ft_max_value(t_stack *stack)
{
	int	max;
	int	index;

	max = stack->nb;
	index = 0;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		index++;
		stack = stack->next;
	}
	return (max);
}

void	replace_by_index(t_stack **stack)
{
	t_stack	*runner;
	int		*indexes;
	int		size;
	int		i;

	i = 0;
	size = stack_size(*stack);
	indexes = malloc(sizeof(*indexes) * size);
	if (indexes == NULL)
		return ;
	runner = *stack;
	while (runner)
	{
		indexes[i++] = runner->nb;
		runner = runner->next;
	}
	runner = *stack;
	while (runner)
	{
		runner->nb = how_much_lower(indexes, runner->nb, size);
		runner = runner->next;
	}
	free(indexes);
}
