/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort(t_head_tail **a, t_head_tail **b)
{
	t_chunk	full_chunk;
	
	full_chunk.loc = TOP_A;
	full_chunk.size = (*a)->size;
	rec_chunk_sort(a, b, &full_chunk);
}

void	rec_chunk_sort(t_head_tail **a, t_head_tail **b, t_chunk *chunk_to_sort)
{
	t_split_desti	desti;

	if (chunk_to_sort->size <= 3)
	{
		if (chunk_to_sort->size == 3)
			sort_three(a, b, chunk_to_sort);
		else if (chunk_to_sort->size == 2)
			sort_two(a, b, chunk_to_sort);
		else if (chunk_to_sort->size == 1)
		{
			if (chunk_to_sort->loc == BOTTOM_B || chunk_to_sort->loc \
			== BOTTOM_A || chunk_to_sort->loc == TOP_B)
				move_to(a, b, chunk_to_sort->loc, TOP_A);
			chunk_to_sort->size--;
		}
		return ;
	}
	desti.size.min = 0;
	desti.size.mid = 0;
	desti.size.max = 0;
	split_chunk(a, b, chunk_to_sort, &desti);
	rec_chunk_sort(a, b, &desti.max);
	rec_chunk_sort(a, b, &desti.mid);
	rec_chunk_sort(a, b, &desti.min);
}

void	sort_two(t_head_tail **a, t_head_tail **b, t_chunk *chunk)
{
	if (chunk->loc == BOTTOM_B || chunk->loc == BOTTOM_A || chunk->loc == TOP_B)
	{
			move_to(a, b, chunk->loc, TOP_A);
			move_to(a, b, chunk->loc, TOP_A);
	}
	if ((*a)->head->normalised_value > (*a)->head->next->normalised_value)
		ft_sa(a, b);
	chunk->size = chunk->size - 2;
}

static void	sort_three_algo(t_head_tail **a, t_head_tail **b, int index[3])
{
	if (index[0] < index[1] && index[1] > index[2])
	{
		ft_ra(a, b);
		ft_sa(a, b);
		ft_rra(a, b);
	}
	else if (index[0] > index[1] && index[0] > index[2])
	{
		ft_sa(a, b);
		ft_ra(a, b);
		ft_sa(a, b);
		ft_rra(a, b);
	}
}

void	sort_three(t_head_tail **a, t_head_tail **b, t_chunk *chunk)
{
	int	index[3];

	if (chunk->loc == BOTTOM_B || chunk->loc == BOTTOM_A || chunk->loc == TOP_B)
	{
		move_to(a, b, chunk->loc, TOP_A);
		move_to(a, b, chunk->loc, TOP_A);
		move_to(a, b, chunk->loc, TOP_A);
	}
	index[0] = (*a)->head->normalised_value;
	index[1] = (*a)->head->next->normalised_value;
	index[2] = (*a)->head->next->next->normalised_value;
	chunk->loc = TOP_A;
	sort_three_algo(a, b, index);
	sort_two(a, b, chunk);
	chunk->size--;
}
