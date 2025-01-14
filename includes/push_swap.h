/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft_b/includes/libft.h"
# include "../libft/gnl_b/includes/get_next_line_bonus.h"
# include "../libft/ft_printf_b/includes/ft_printf_bonus.h"

//Structures and enumerations
	//stacks

typedef struct	s_stack
{
	int	real_value;
	int	normalised_value;
	struct s_stack *previous;
	struct s_stack *next;
}		t_stack;


typedef struct	s_head_tail
{
	t_stack	*head;
	t_stack	*tail;
	t_list	*op_list;
	int	size;
}		t_head_tail;


enum 	e_op
{
	null,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

	//chunks

enum	e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
};

typedef struct	s_chunk
{
	enum e_loc	loc;
	int		size;
}		t_chunk;

typedef struct	s_split_desti
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}		t_split_desti;

//Temporaire
void    print_stack(t_head_tail **a);

//Stack

void	print_op(t_list *op);
void	free_matrix(char **argv);
void	free_op_list(t_list **op_list);
void	free_stack(t_head_tail **stack);
void	stack_init(t_head_tail **a, t_head_tail **b, char **argv, bool flag_argc_2);
void	error_free(bool flag_argc_2, char **argv, t_head_tail **a, t_head_tail **b);
bool	is_sorted(t_head_tail **a);
int	check_synthax(char *str);
int	check_repetition(long nbr, t_head_tail **a);

//Instructions

void	ft_sa(t_head_tail **a, t_head_tail **b);
void	ft_sb(t_head_tail **a, t_head_tail **b);
void    ft_ss(t_head_tail **a, t_head_tail **b);
void	ft_pa(t_head_tail **a, t_head_tail **b);
void	ft_pb(t_head_tail **a, t_head_tail **b);
void	ft_rr(t_head_tail **a, t_head_tail **b);
void	ft_ra(t_head_tail **a, t_head_tail **b);
void	ft_rb(t_head_tail **a, t_head_tail **b);
void	ft_rra(t_head_tail **a, t_head_tail **b);
void	ft_rrb(t_head_tail **a, t_head_tail **b);
void	ft_rrr(t_head_tail **a, t_head_tail **b);
void	save_op(t_head_tail **a, t_head_tail **b, enum e_op op);

//Sorting

void	opti(t_list **op);
void	chunk_init(t_split_desti *desti);
void	init_desti_chunks(t_split_desti *desti);
void	big_sort(t_head_tail **a, t_head_tail **b);
void	push_swap_sort(t_head_tail **a, t_head_tail **b);
void	sort_two(t_head_tail **a, t_head_tail **b, t_chunk *chunk);
void	sort_three(t_head_tail **a, t_head_tail **b, t_chunk *chunk);
void	chunk_to_top(t_head_tail **a, t_head_tail **b, t_chunk *chunk_to_sort);
void    rec_chunk_sort(t_head_tail **a, t_head_tail **b, t_chunk *chunk_to_sort);
void	find_pivots(t_head_tail **a, t_head_tail **b, int pivot[2], t_chunk *chunk);
void	set_split_loc(t_chunk *chunk_to_split, t_chunk *min, t_chunk *mid, t_chunk *max);
void	move_to(t_head_tail **a, t_head_tail **b, enum e_loc loc_source, enum e_loc loc_desti);
void	split_chunk(t_head_tail **a, t_head_tail **b, t_chunk *chunk_to_split, t_split_desti *desti);
int	find_value(t_head_tail **a, t_head_tail **b, enum e_loc loc);

#endif
