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

#include "checker.h"

void	rev_a(t_head_tail **a)
{
	if (a == NULL || *a == NULL || (*a)->head == NULL)
		return ;
	if ((*a)->head == (*a)->tail)
		return ;
	(*a)->head = (*a)->tail;
	(*a)->tail = (*a)->head->previous;
}

void	rev_b(t_head_tail **b)
{
	if (b == NULL || *b == NULL || (*b)->head == NULL)
		return ;
	if ((*b)->head == (*b)->tail)
		return ;
	(*b)->head = (*b)->tail;
	(*b)->tail = (*b)->head->previous;
}

void	rev_a_b(t_head_tail **a, t_head_tail **b)
{
	if (a == NULL || *a == NULL || (*a)->head == NULL)
		return ;
	if (b == NULL || *b == NULL || (*b)->head == NULL)
		return ;
	rev_a(a);
	rev_b(b);
}
