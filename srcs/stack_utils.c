/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	save_op(t_head_tail **a, t_head_tail **b, t_list **op_list, enum e_op op)
{
	t_list	*new;

	new = ft_lstnew((void *)(uintptr_t)op);
	if (!new)
	{
		free_stack(a);
		free_stack(b);
		free(op_list);
		write(2, "Error\n", 6);
		exit(1);
	}
	ft_lstadd_back(op_list, new);
}

void	print_op(t_list **op)
{
	t_list	*current;
	
	int i = 1;
	if (op == NULL ||  *op == NULL)
		return ;
	current = *op;
	while (current != NULL)
	{
		ft_printf("%d - ", i);
		ft_printf("%d\n", current->content);
		i++;
		current = current->next;
	}
}
