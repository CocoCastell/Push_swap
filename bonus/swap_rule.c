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

#include "checker.h"

void	swap_a(t_head_tail **a)
{
	if (a == NULL || *a == NULL || (*a)->tail == NULL)
		return ;
	if ((*a)->head == (*a)->tail)
		return ;
	(*a)->head = (*a)->head->next;
	if ((*a)->tail == (*a)->head)
		(*a)->tail = (*a)->head->next;
	else
	{
		(*a)->tail->next->next = (*a)->head->next; 
		(*a)->head->next->previous = (*a)->tail->next;
		(*a)->head->next = (*a)->head->previous;
		(*a)->head->previous = (*a)->tail;
		(*a)->tail->next->previous = (*a)->head;
		(*a)->tail->next = (*a)->head;
		if ((*a)->tail->previous == (*a)->head)
			(*a)->tail->previous = (*a)->head->next;
	}
}

void	swap_b(t_head_tail **b)
{
	if (b == NULL || *b == NULL || (*b)->tail == NULL)
		return ;
	if ((*b)->head == (*b)->tail)
		return ;
	(*b)->head = (*b)->head->next;
	if ((*b)->tail == (*b)->head)
		(*b)->tail = (*b)->head->next;
	else
	{
		(*b)->tail->next->next = (*b)->head->next; 
		(*b)->head->next->previous = (*b)->tail->next;
		(*b)->head->next = (*b)->head->previous;
		(*b)->head->previous = (*b)->tail;
		(*b)->tail->next->previous = (*b)->head;
		(*b)->tail->next = (*b)->head;
		if ((*b)->tail->previous == (*b)->head)
			(*b)->tail->previous = (*b)->head->next;
	}
}

void	swap_a_b(t_head_tail **a, t_head_tail **b)
{
	if (a == NULL || *a == NULL || (*a)->tail == NULL)
		return ;
	if (b == NULL || *b == NULL || (*b)->tail == NULL)
		return ;
	swap_a(a);
	swap_b(b);
}
