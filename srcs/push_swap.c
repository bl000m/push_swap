/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:19:20 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/17 16:34:50 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack **stack_a)
{
	if (stack_size(*stack_a) == 2)
	{
		if ((*stack_a)->nb > (*stack_a)->next->nb)
			s(stack_a, 'a');
	}
	else if (stack_size(*stack_a) == 3)
		case_3(stack_a);
	else if (stack_size(*stack_a) == 5 || stack_size(*stack_a) == 4)
		case_5(stack_a);
	else if (stack_size(*stack_a) > 5 && stack_size(*stack_a) <= 100)
		case_100(stack_a);
	else if (stack_size(*stack_a) > 100)
		case_500(stack_a);
	stack_free(stack_a);
}

void	case_3(t_stack **stack_a)
{
	t_stack	*top;
	t_stack	*middle;
	t_stack	*bottom;

	top = *stack_a;
	middle = top->next;
	bottom = middle->next;
	if (top->nb > middle->nb && top->nb < bottom->nb && middle->nb < bottom->nb)
		s(stack_a, 'a');
	if (top->nb > middle->nb && top->nb > bottom->nb && middle->nb < bottom->nb)
		r(stack_a, 'a');
	if (top->nb > middle->nb && top->nb > bottom->nb && middle->nb > bottom->nb)
		s(stack_a, 'a');
	if (top->nb < middle->nb && top->nb > bottom->nb && middle->nb > bottom->nb)
		rr(stack_a, 'a');
	if (top->nb < middle->nb && top->nb < bottom->nb && middle->nb > bottom->nb)
	{
		s(stack_a, 'a');
		r(stack_a, 'a');
	}
}

void	case_5(t_stack **stack_a)
{
	t_stack	*runner;
	t_stack	*stack_b;
	int		smallest_index;

	stack_b = NULL;
	runner = *stack_a;
	if (already_ordered(stack_a))
		return ;
	while (runner && stack_size(*stack_a) > 3)
	{
		smallest_index = ft_min(*stack_a);
		target_to_top(stack_a, smallest_index, 'a');
		p(stack_a, &stack_b, 'b');
		runner = runner->next;
	}
	case_3(stack_a);
	while (stack_size(stack_b) > 0)
		p(&stack_b, stack_a, 'a');
	stack_free(&stack_b);
}

void	case_100(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		min;
	int		max;
	int		delta;

	min = ft_min_value(*stack_a);
	max = ft_max_value(*stack_a);
	delta = max - min;
	stack_b = NULL;
	if (already_ordered(stack_a))
		return ;
	while (min < (max - (delta / 5) * 2))
	{
		target_to_b(stack_a, min, (min + delta / 5), &stack_b);
		min += delta / 5;
	}
	target_to_b(stack_a, min, max, &stack_b);
	highest_to_a(&stack_b, stack_a);
	stack_free(&stack_b);
}

void	case_500(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;
	int		count;

	i = 0;
	count = 0;
	replace_by_index(stack_a);
	while (!already_ordered(stack_a))
	{
		scan_a(stack_a, &stack_b, &i, &count);
		while (count > 0)
		{
			p(&stack_b, stack_a, 'a');
			count--;
		}
		i++;
	}
}
