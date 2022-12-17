/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:15:21 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/13 10:13:26 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rr(t_stack **stack, char choice)
{
	t_stack	*front;
	t_stack	*back;
	t_stack	*head;

	head = *stack;
	back = *stack;
	front = *stack;
	if (*stack == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	*stack = front;
	ft_printf("rr%c\n", choice);
}
