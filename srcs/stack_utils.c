/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	save_op(t_head_tail **a, t_head_tail **b, enum e_op op)
{
	t_list	*new;

	new = ft_lstnew((void *)(uintptr_t)op);
	if (new == NULL)
		error_free(1, NULL, a, b);
	ft_lstadd_back(&((*a)->op_list), new);
}

static void	string_op(enum e_op op)
{
	char	*string[12];

	if (op <0 || op > 11)
		return ;
	string[0] = "null";
	string[1] = "sa";
	string[2] = "sb";
	string[3] = "ss";
	string[4] = "pa";
	string[5] = "pb";
	string[6] = "ra";
	string[7] = "rb";
	string[8] = "rr";
	string[9] = "rra";
	string[10] = "rrb";
	string[11] = "rrr";
	ft_printf("%s\n", string[op]);
}

void	print_op(t_list *op)
{
	t_list	*current;
	int	op_nb;

	op_nb = 0;
	if (op == NULL)
		return ;
	current = op;
	while (current != NULL)
	{
		string_op((enum e_op)(uintptr_t)current->content);
		current = current->next;
		op_nb++;
	}
	ft_printf("\nOperations: %i\n", op_nb);
}

bool	is_sorted(t_head_tail **stack)
{
	t_stack	*next_node;
	t_stack	*current;

	if (stack == NULL || *stack == NULL || (*stack)->head == NULL)
		return (true);
	next_node = (*stack)->head->next;
	current = (*stack)->head;
	if (current == next_node)
		return (true);
	while (next_node != (*stack)->head)
	{
		if (current->normalised_value > next_node->normalised_value)
			return (false);
		current = next_node;
		next_node = current->next;
	}
	return (true);
}
