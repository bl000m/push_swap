/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:57:58 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/15 16:21:57 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_add_back(t_stack **stack, t_stack *new)
{
	if (stack == NULL)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
		stack_last(*stack)->next = new;
}
