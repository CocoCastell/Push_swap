/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_to_top_a(t_head_tail **a, t_head_tail **b, enum e_loc loc_source)
{
	if (loc_source == BOTTOM_A)
		ft_rra(a, b);
	else if (loc_source == TOP_B)
		ft_pa(a, b);
	else if (loc_source == BOTTOM_B)
	{
		ft_rrb(a, b);
		ft_pa(a, b);
	}
}

static void	move_to_bottom_a(t_head_tail **a, t_head_tail **b, enum e_loc loc_source)
{
	if (loc_source == TOP_A)	
		ft_ra(a, b);
	else if (loc_source == TOP_B)
	{
		ft_pa(a, b);
		ft_ra(a, b);
	}
	else if (loc_source == BOTTOM_B)
	{
		ft_rrb(a, b);
		ft_pa(a, b);
		ft_ra(a, b);
	}
}

static void	move_to_top_b(t_head_tail **a, t_head_tail **b, enum e_loc loc_source)
{
	if (loc_source == TOP_A)
		ft_pb(a, b);
	else if (loc_source == BOTTOM_B)
		ft_rrb(a, b);
	else if (loc_source == BOTTOM_A)
	{
		ft_rra(a, b);
		ft_pb(a, b);
	}
}

static void	move_to_bottom_b(t_head_tail **a, t_head_tail **b, enum e_loc loc_source)
{
	if (loc_source == TOP_A)
	{
		ft_pb(a, b);
		ft_rb(a, b);
	}
	else if (loc_source == BOTTOM_A)
	{
		ft_rra(a, b);
		ft_pb(a, b);
		ft_rb(a, b);
	}
	else if (loc_source == TOP_B)
		ft_rb(a, b);
}

void    move_to(t_head_tail **a, t_head_tail **b, enum e_loc loc_source, enum e_loc loc_desti)
{
        if (loc_desti == TOP_A)
                move_to_top_a(a, b, loc_source);
        if (loc_desti == BOTTOM_A)
                move_to_bottom_a(a, b, loc_source);
        if (loc_desti == TOP_B)
                move_to_top_b(a, b, loc_source);
        if (loc_desti == BOTTOM_B)
                move_to_bottom_b(a, b, loc_source);
}
