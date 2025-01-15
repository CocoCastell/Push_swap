/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	del(void *content)
{
	free(content);
}

void	exit_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

bool	is_empty(t_head_tail *stack)
{
	if (stack == NULL || stack->head == NULL)
		return (true);
	else
		return (false);
}

bool    is_sorted(t_head_tail **stack)
{
        t_stack *next_node;
        t_stack *current;

        if (stack == NULL || *stack == NULL || (*stack)->head == NULL)
                return (true);
        next_node = (*stack)->head->next;
        current = (*stack)->head;
        if (current == next_node)
                return (true);
        while (next_node != (*stack)->head)
        {
                if (current->real_value > next_node->real_value)
                        return (false);
                current = next_node;
                next_node = current->next;
        }
        return (true);
}
