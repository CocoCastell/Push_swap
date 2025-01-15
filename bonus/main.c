/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_head_tail	*a;
	t_head_tail	*b;
	t_list		*op;
	int		check;

	a = NULL;
	b = NULL;
	op = NULL;
	check = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, &b, argv, argc == 2);
	while (check == 0)
		check = get_rules(&op, 0);
	apply_rules(op, &a, &b);
	if (is_sorted(&a) && is_empty(b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&op, del);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
