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

#include "../includes/push_swap.h"

/*void	pa(t_head_tail **a, t_head_tail **b, t_list **op_list)
{
        t_stack	*current;

	if ((*b)->head == NULL)
		return ;
	current = (*b)->head;
	(*b)->tail->next = current->next;
	(*b)->head = current->next;
	current->next->previous = (*b)->tail;
	(*a)->tail->next = current;
	current->previous = (*a)->tail;
	current->next = (*a)->head;
	current->next->previous = current;
	(*a)->head = current;
	ft_printf("pa\n");
}*/

void    ft_pa(t_head_tail **a, t_head_tail **b, t_list **op_list)
{
        t_stack *current;

        if ((*b)->head == NULL)
                return ;
        current = (*a)->head;
        (*b)->tail->next = current->next;
        (*b)->head = current->next;
        (*b)->head->previous = (*a)->tail;
        if ((*a)->head == NULL)
        {
                (*a)->head = current;
                (*a)->tail = current;
                current->next = current;
                current->previous = current;
        }
        else
        {
                (*a)->tail->next = current;
                current->previous = (*a)->tail;
                current->next = (*a)->head;
                current->next->previous = current;
                (*a)->head = current;
        }
	save_op(a, b, op_list, pb);
}

void	ft_pb(t_head_tail **a, t_head_tail **b, t_list **op_list)
{
	t_stack	*current;

	if ((*a)->head == NULL)
		return ;
	current = (*a)->head;
	(*a)->tail->next = current->next;
	(*a)->head = current->next;
	(*a)->head->previous = (*a)->tail;
	if ((*b)->head == NULL)
	{
		(*b)->head = current;
		(*b)->tail = current;
		current->next = current;
		current->previous = current;
	}
	else
	{
		(*b)->tail->next = current;
		current->previous = (*b)->tail;
		current->next = (*b)->head;
		current->next->previous = current;
		(*b)->head = current;
	}
	save_op(a, b, op_list, pb);
}
