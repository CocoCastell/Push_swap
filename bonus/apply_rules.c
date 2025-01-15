/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rules.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	find_and_apply(char *str, t_head_tail **a, t_head_tail **b)
{
	size_t	n;

	n = 2;
	if (ft_strncmp(str, "rra", 3) == 0)
		rev_a(a);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		rev_b(b);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		rev_a_b(a, b);
	else if (ft_strncmp(str, "sa", n) == 0)
		swap_a(a);
	else if (ft_strncmp(str, "sb", n) == 0)
		swap_b(b);
	else if (ft_strncmp(str, "ss", n) == 0)
		swap_a_b(a, b);
	else if (ft_strncmp(str, "pa", n) == 0)
		push_a(a, b);
	else if (ft_strncmp(str, "pb", n) == 0)
		push_b(a, b);
	else if (ft_strncmp(str, "ra", n) == 0)
		rot_a(a);
	else if (ft_strncmp(str, "rb", n) == 0)
		rot_b(b);
	else if (ft_strncmp(str, "rr", n) == 0)
		rot_a_b(a, b);
}

void	apply_rules(t_list *op, t_head_tail **a, t_head_tail **b)
{
	while (op != NULL)
	{
		find_and_apply((char *)op->content, a, b);
		op = op->next;
	}
}
