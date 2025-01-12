/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	split_chunk(t_head_tail **a, t_head_tail **b, t_chunk *chunk_to_split, t_split_desti *desti)
{
	int	pivot[2];
	int	value;

	find_pivots(a, b, pivots, chunk_to_split);
	find_top_pivots(a, b, pivots, chunk_to_split);
	find_bottom_pivots(a, b, pivots, chunk_to_split);
	set_split_loc(chunk_to_split, &desti->min, &desti->mid, &desti->max);
	while (chunk_to_split->size > 0)
	{
		value = find_value(a, b, chunk_to_split->loc);
		if (value < pivot[0])
		{
			move_to(a, b, chunk_to_split->loc, desti->min.loc);
			desti->min.size++;
		}
		else if (value < pivot[1])
		{
			move_to(a, b, chunk_to_split->loc, desti->mid.loc);
			desti->mid.size++;
		}
		else
		{
			move_to(a, b, chunk_to_split->loc, desti->max.loc);
			desti->max.size++;
		}
		chunk_to_split->size--;
	}
	ft_printf("stack a\n");
	print_stack(a);
	ft_printf("stack b\n");
	print_stack(b);
}

int	find_value(t_head_tail **a, t_head_tail **b, enum e_loc loc)
{
	int	value;

	if (loc == TOP_A)
		value = (*a)->head->normalised_value;
	else if (loc == BOTTOM_A)
		value = (*a)->tail->normalised_value;
	else if (loc == TOP_B)
		value = (*b)->head->normalised_value;
	else if (loc == BOTTOM_B)
		value = (*b)->tail->normalised_value;
	return (value);
}

void	set_split_loc(t_chunk *chunk_to_split, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (chunk_to_split->loc == TOP_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = BOTTOM_A;
	}
	else if (chunk_to_split->loc == TOP_B)
	{
		min->loc = BOTTOM_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
	else if (chunk_to_split->loc == BOTTOM_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = TOP_A;
	}
	else if (chunk_to_split->loc == BOTTOM_B)
	{
		min->loc = TOP_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
}

void    find_bottom_pivots(t_head_tail **a, t_head_tail **b, int pivots[2], t_chunk *chunk)
{
        int     size;
        int     total;
        t_stack *current;

        total = 0;
        size = chunk->size;
        if (chunk->loc == BOTTOM_A)
                current = (*a)->head;
        else if (chunk->loc == BOTTOM_B)
                current = (*b)->tail;
        while (size > 0)
        {
                if (chunk->loc == BOTTOM_A)
                        total += current->normalised_value;
                else if (chunk->loc == BOTTOM_B)
                        total += current->normalised_value;
                current = current->next;
                size--;
        }
        pivots[0] = total / 3;
        pivots[1] = total / 3 + pivots[0];
}

void	find_top_pivots(t_head_tail **a, t_head_tail **b, int pivots[2], t_chunk *chunk)
{
	int	size;
	int	total;
	t_stack	*current;

	total = 0;
	size = chunk->size;
	if (chunk->loc == TOP_A)
		current = (*a)->head;
	else if (chunk->loc == TOP_B)
		current = (*b)->tail;
	while (size > 0)
	{
		if (chunk->loc == TOP_A)
			total += current->normalised_value;
		else if (chunk->loc == TOP_B)
			total += current->normalised_value;
		current = current->next;
		size--;
	}
	pivots[0] = total / 3;
	pivots[1] = total / 3 + pivots[0];
}
