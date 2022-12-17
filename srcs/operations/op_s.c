/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:09:23 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/15 16:36:46 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	s(t_stack **stack, char choice)
{
	int		temp;

	temp = (*stack)->nb;
	(*stack)->nb = (*stack)->next->nb;
	(*stack)->next->nb = temp;
	ft_printf("s%c\n", choice);
}
