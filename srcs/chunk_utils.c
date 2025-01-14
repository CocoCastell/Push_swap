/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	chunk_init(t_split_desti *desti)
{
	desti->min.size = 0;
	desti->mid.size = 0;
	desti->max.size = 0;
}

void	chunk_to_top(t_head_tail **a, t_head_tail **b, t_chunk *chunk_to_sort)
{
	if (chunk_to_sort->loc == BOTTOM_B && (*b)->size == chunk_to_sort->size)
		chunk_to_sort->loc = TOP_B;
	if (chunk_to_sort->loc == BOTTOM_A && (*a)->size == chunk_to_sort->size)
		chunk_to_sort->loc = TOP_A;
}
