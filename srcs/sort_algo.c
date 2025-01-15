/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_a(t_head_tail **a, t_head_tail **b)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->head->normalised_value;
	second = (*a)->head->next->normalised_value;
	third = (*a)->tail->normalised_value;
	if (first > second && second < third && third > first)
		ft_sa(a, b);
	else if (first < second && second > third && third < first)
		ft_rra(a, b);
	else if (first > second && second < third && third < first)
		ft_ra(a, b);
	else if (first > second && second > third && third < first)
	{
		ft_sa(a, b);
		ft_rra(a, b);
	}
	else if (first < second && first < third && second > third)
	{
		ft_sa(a, b);
		ft_ra(a ,b);
	}
}

static void	sort_four_five_a(t_head_tail **a, t_head_tail **b, int size)
{
	while (size > 4)
	{
		if ((*a)->head->normalised_value == 1)
		{
			ft_pb(a, b);
			size--;
		}
		else if ((*a)->tail->normalised_value == 1)
			ft_rra(a, b);
		else
			ft_ra(a, b);
	}
	while (size > 3)
	{
		if ((*a)->head->normalised_value == 0)
		{
			ft_pb(a, b);
			size--;
		}
		else if ((*a)->tail->normalised_value == 0)
			ft_rra(a, b);
		else
			ft_ra(a, b);
	}
	ft_sb(a, b);
	sort_three_a(a, b);
}

void	push_swap_sort(t_head_tail **a, t_head_tail **b)
{
	if ((*a)->size <= 1 || is_sorted(a) == true)
		return ;
	else if ((*a)->size == 2)
		ft_sa(a, b);
	else if ((*a)->size == 3)
		sort_three_a(a, b);
	else if ((*a)->size <= 5)
	{
		sort_four_five_a(a, b, (*a)->size);
		ft_pa(a, b);
		ft_pa(a, b);
	}
	else
		big_sort(a, b);
}
