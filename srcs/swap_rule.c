/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_head_tail **stack)
{
	t_stack *current;

	current = (*stack)->head;
	(*stack)->head = current->next;
	(*stack)->tail->next = (*stack)->head;
	current->next = (*stack)->head->next;
	current->previous = (*stack)->head;
	(*stack)->head->next->previous = current;
	(*stack)->head->next = current;
	(*stack)->head->previous = (*stack)->tail;
	ft_printf("sa\n");	
}

void	sb(t_head_tail **stack)
{
        t_stack	*current;

	current = (*stack)->head;
	(*stack)->head = current->next;
	(*stack)->tail->next = (*stack)->head;
	current->next = (*stack)->head->next;
	current->previous = (*stack)->head;
	(*stack)->head->next->previous = current;
	(*stack)->head->next = current;
	(*stack)->head->previous = (*stack)->tail;
	ft_printf("sb\n");
}

static void	silent_swap(t_head_tail **stack)
{
        t_stack	*current;

	current = (*stack)->head;
	(*stack)->head = current->next;
	(*stack)->tail->next = (*stack)->head;
	current->next = (*stack)->head->next;
	current->previous = (*stack)->head;
	(*stack)->head->next->previous = current;
	(*stack)->head->next = current;
	(*stack)->head->previous = (*stack)->tail;
}

void	ss(t_head_tail **a, t_head_tail **b)
{
	silent_swap(a);
	silent_swap(b);
	ft_printf("ss\n");	
}
