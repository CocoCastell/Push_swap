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

void	sort(t_head_tail **a, t_head_tail **b)
{
	if ((*a)->size <= 1 || is_sorted(a) == true)
		return ;
	else if ((*a)->size == 2)
		ft_sa(a, b);
	else if ((*a)->size == 3)
		sort_three(a, b);
	/*else if ((*a)->size <= 5)
		sort_five(a, b);
	else
		big_sort(a, b);*/
}	

void	sort_three(t_head_tail **a, t_head_tail **b)
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
	else
	{
		ft_sa(a, b);
		ft_ra(a ,b);
	}
}

/*void	sort_five(t_head_tail **a)
{

}*/
