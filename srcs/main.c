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
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, &b, argv, argc == 2);
	ft_sa(&a, &b);
	ft_ra(&a, &b);
	//sort(&a, &b);
	ft_printf("\n");	
	print_op(a->op_list);
	ft_printf("\n");
	print_stack(&a);
	return (0);
}
