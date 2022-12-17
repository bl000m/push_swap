/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:24:50 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/17 12:27:37 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_free(t_stack **stack)
{
	t_stack	*ptr;

	while (*stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
}

void	array_free(char **result, int max)
{
	int	i;

	i = 0;
	while (i < max)
		free(result[i++]);
	free(result);
	return ;
}
