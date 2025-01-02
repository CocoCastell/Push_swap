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

void	ra(t_head_tail **stack)
{
	if (*stack == NULL || (*stack)->head == NULL)
		return ;
	if ((*stack)->head == (*stack)->tail)
		return ;	
	(*stack)->tail = (*stack)->head;
	(*stack)->head = (*stack)->head->next;
	ft_printf("ra\n");
}

void	rb(t_head_tail **stack)
{
	if (*stack == NULL || (*stack)->head == NULL)
		return ;
	if ((*stack)->head == (*stack)->tail)
		return ;
	(*stack)->tail = (*stack)->head;
	(*stack)->head = (*stack)->head->next;
	ft_printf("rb\n");
}

static void	silent_rotate(t_head_tail **stack)
{
	if (*stack == NULL || (*stack)->head == NULL)
		return ;
	if ((*stack)->head == (*stack)->tail)
		return ;
	(*stack)->tail = (*stack)->head;
	(*stack)->head = (*stack)->head->next;
}

void	rr(t_head_tail **a, t_head_tail **b)
{
	silent_rotate(a);
	silent_rotate(b);
	ft_printf("rr\n");
}
