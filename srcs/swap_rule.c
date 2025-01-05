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

void	ft_sa(t_head_tail **a, t_head_tail **b, t_list **op_list)
{
	t_stack *current;

	current = (*a)->head;
	(*a)->head = current->next;
	(*a)->tail->next = (*a)->head;
	current->next = (*a)->head->next;
	current->previous = (*a)->head;
	(*a)->head->next->previous = current;
	(*a)->head->next = current;
	(*a)->head->previous = (*a)->tail;
	save_op(a, b, op_list, sa);
}

void	ft_sb(t_head_tail **b, t_head_tail **a, t_list **op_list)
{
        t_stack	*current;

	current = (*b)->head;
	(*b)->head = current->next;
	(*b)->tail->next = (*b)->head;
	current->next = (*b)->head->next;
	current->previous = (*b)->head;
	(*b)->head->next->previous = current;
	(*b)->head->next = current;
	(*b)->head->previous = (*b)->tail;
	save_op(a, b, op_list, sb);
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

void	ft_ss(t_head_tail **a, t_head_tail **b, t_list **op_list)
{
	silent_swap(a);
	silent_swap(b);
	save_op(a, b, op_list, ss);
}
