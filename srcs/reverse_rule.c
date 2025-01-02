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

void	rra(t_head_tail **stack)
{
	if (*stack == NULL || (*stack)->head == NULL)
		return ;
	if ((*stack)->head == (*stack)->tail)
		return ;
	(*stack)->head = (*stack)->tail;
	(*stack)->tail = (*stack)->head->previous;
	ft_printf("rra\n");
}

void	rrb(t_head_tail **stack)
{
	if (*stack == NULL || (*stack)->head == NULL)
		return ;
	if ((*stack)->head == (*stack)->tail)
		return ;
	(*stack)->head = (*stack)->tail;
	(*stack)->tail = (*stack)->head->previous;
	ft_printf("rrb\n");
}

static void	silent_rr(t_head_tail **stack)
{
	if (*stack == NULL || (*stack)->head == NULL)
		return ;
	if ((*stack)->head == (*stack)->tail)
		return ;
	(*stack)->head = (*stack)->tail;
	(*stack)->tail = (*stack)->head->previous;
}

void	rrr(t_head_tail **a, t_head_tail **b)
{
	silent_rr(a);
	silent_rr(b);
	ft_printf("rrr\n");
}
