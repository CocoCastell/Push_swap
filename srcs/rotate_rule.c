/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_head_tail **a, t_head_tail **b)
{
	if (a == NULL || *a == NULL || (*a)->head == NULL)
		return ;
	if ((*a)->head == (*a)->tail)
		return ;	
	(*a)->tail = (*a)->head;
	(*a)->head = (*a)->tail->next;
	save_op(a, b, ra);
}

void	ft_rb(t_head_tail **a, t_head_tail **b)
{
	if (b == NULL || *b == NULL || (*b)->head == NULL)
		return ;
	if ((*b)->head == (*b)->tail)
		return ;
	(*b)->tail = (*b)->head;
	(*b)->head = (*b)->tail->next;
	save_op(a, b, rb);
}

static void	silent_rotate(t_head_tail **stack)
{
	if ((*stack)->head == (*stack)->tail)
		return ;
	(*stack)->tail = (*stack)->head;
	(*stack)->head = (*stack)->tail->next;
}

void	ft_rr(t_head_tail **a, t_head_tail **b)
{
	if (a == NULL || *a == NULL || (*a)->head == NULL)
		return ;
	if (b == NULL || *b == NULL || (*b)->head == NULL)
		return ;
	silent_rotate(a);
	silent_rotate(b);
	save_op(a, b, rr);
}
