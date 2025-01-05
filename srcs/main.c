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
	t_list	*op;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv, argc == 2);
	op = malloc(sizeof(t_list));
	if (op == NULL)
		return (1);
	op->next = NULL;
	op->content = NULL;
	print_op(&op);
	ft_sa(&a, &b, &op);
	ft_sa(&a, &b, &op);
	ft_sa(&a, &b, &op);
	return (0);
}
