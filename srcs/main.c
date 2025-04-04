/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_head_tail *a;
	t_head_tail *b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, &b, argv, argc == 2);
	push_swap_sort(&a, &b);
	print_op(a->op_list);
	free_stack(&b);
	free_stack(&a);
	return (0);
}

void	free_op_list(t_list **op_list)
{
	t_list	*current;
	t_list	*tmp;
	
	if (op_list == NULL || *op_list == NULL)
		return;
	current = *op_list;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*op_list = NULL;
}
