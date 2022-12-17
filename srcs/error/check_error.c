/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:09:20 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/17 17:41:41 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_input(char **argv)
{
	int	i;
	int	zeros;

	zeros = 0;
	i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]) || !is_overflow(argv[i]))
			return (0);
		zeros += is_zero(argv[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	return (1);
}

int	check_duplicate(t_stack *stack, int argc)
{
	t_stack	*runner_1;
	t_stack	*runner_2;

	if (argc < 2)
		return (1);
	runner_1 = stack;
	runner_2 = runner_1->next;
	if (stack_size(stack) == 1)
		return (0);
	while (runner_1->next != NULL)
	{
		while (runner_2 != NULL)
		{
			if (runner_1->nb == runner_2->nb)
				return (0);
			runner_2 = runner_2->next;
		}
		runner_1 = runner_1->next;
		runner_2 = runner_1->next;
	}
	return (1);
}

void	exit_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	already_ordered(t_stack **stack)
{
	t_stack	*runner;
	int		count;

	count = 0;
	runner = *stack;
	while (runner->next)
	{
		if (runner->next->nb > runner->nb)
			count++;
		runner = runner->next;
	}
	if (count == stack_size(*stack) - 1)
		return (1);
	return (0);
}
