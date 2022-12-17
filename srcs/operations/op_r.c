/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:13:55 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/13 10:11:39 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	r(t_stack **stack, char choice)
{
	t_stack	*runner;
	int		first;

	runner = *stack;
	first = runner->nb;
	if (!runner || !runner->next)
		return ;
	while (runner->next != NULL)
	{
		runner->nb = runner->next->nb;
		runner = runner->next;
	}
	runner->nb = first;
	ft_printf("r%c\n", choice);
}
