/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rule.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_head_tail **a, t_head_tail **b)
{
	if (a == NULL || *a == NULL || (*a)->head == NULL)
		return ;
	if ((*a)->head == (*a)->tail)
		return ;
	(*a)->head = (*a)->tail;
	(*a)->tail = (*a)->head->previous;
	save_op(a, b, rra);
}

void	ft_rrb(t_head_tail **a, t_head_tail **b)
{
	if (b == NULL || *b == NULL || (*b)->head == NULL)
		return ;
	if ((*b)->head == (*b)->tail)
		return ;
	(*b)->head = (*b)->tail;
	(*b)->tail = (*b)->head->previous;
	save_op(a, b, rrb);
}

static void	silent_rr(t_head_tail **stack)
{
	if ((*stack)->head == (*stack)->tail)
		return ;
	(*stack)->head = (*stack)->tail;
	(*stack)->tail = (*stack)->head->previous;
}

void	ft_rrr(t_head_tail **a, t_head_tail **b)
{
	if (a == NULL || *a == NULL || (*a)->head == NULL)
		return ;
	if (b == NULL || *b == NULL || (*b)->head == NULL)
		return ;
	silent_rr(a);
	silent_rr(b);
	save_op(a, b, rrr);
}
