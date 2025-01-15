/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	global_push(t_head_tail **stack, t_stack **current)
{
	if ((*stack)->head == NULL)
	{
		(*stack)->head = *current;
		(*stack)->tail = *current;
		(*current)->next = *current;
		(*current)->previous = *current;
	}
	else
	{
		(*stack)->tail->next = *current;
		(*current)->previous = (*stack)->tail;
		(*current)->next = (*stack)->head;
		(*current)->next->previous = *current;
		(*stack)->head = *current;
	}
}

void    push_a(t_head_tail **a, t_head_tail **b)
{
        t_stack *current;

        if ((*b)->head == NULL)
                return ;
        current = (*b)->head;
	if ((*b)->head == (*b)->tail)
	{
		(*b)->tail = NULL;
		(*b)->head = NULL;
        }
	else
	{
		(*b)->tail->next = current->next;
		(*b)->head = current->next;
		(*b)->head->previous = (*b)->tail;
	}
	global_push(a, &current);
}

void	push_b(t_head_tail **a, t_head_tail **b)
{
	t_stack	*current;

	if ((*a)->head == NULL)
		return ;
	current = (*a)->head;
	if ((*a)->head == (*a)->tail)
	{
		(*a)->tail = NULL;
		(*a)->head = NULL;
	}
	else
	{
		(*a)->tail->next = current->next;
		(*a)->head = current->next;
		(*a)->head->previous = (*a)->tail;
	}
	global_push(b, &current);
}
