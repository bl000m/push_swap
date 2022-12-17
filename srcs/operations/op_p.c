/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:12:08 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/15 16:06:14 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	p(t_stack **from, t_stack **to, char choice)
{
	t_stack	*ptr;
	t_stack	*top;

	top = *from;
	ptr = (*from)->next;
	if (!(*to))
	{
		*to = stack_new(top->nb);
		free(top);
	}
	else
		stack_add_front(to, top);
	*from = ptr;
	ft_printf("p%c\n", choice);
}
