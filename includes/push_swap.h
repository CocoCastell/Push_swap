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
}		t_head_tail;

enum 	e_op
{
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

//temporaire
void    print_stack(t_head_tail **a);

//Stack

void	stack_init(t_head_tail **a, char **argv, bool flag_argc_2);
void	free_stack(t_head_tail **stack);
void	error_free(bool flag_argc_2, char **argv, t_head_tail **stack);
void	free_matrix(char **argv);
void	print_op(t_list **op);
int	check_repetition(long nbr, t_head_tail **a);
int	check_synthax(char *str);

//Instructions

void	ft_sa(t_head_tail **a, t_head_tail **b, t_list **op_list);
void	ft_sb(t_head_tail **b, t_head_tail **a, t_list **op_list);
void    ft_ss(t_head_tail **a, t_head_tail **b, t_list **op_list);
void	ft_pa(t_head_tail **a, t_head_tail **b, t_list **op_list);
void	ft_pb(t_head_tail **a, t_head_tail **b, t_list **op_list);
void	ft_rr(t_head_tail **a, t_head_tail **b, t_list **op_list);
void	ft_ra(t_head_tail **a, t_head_tail **b, t_list **op_list);
void	ft_rb(t_head_tail **b, t_head_tail **a, t_list **op_list);
void	ft_rra(t_head_tail **a, t_head_tail **b, t_list **op_list);
void	ft_rrb(t_head_tail **b, t_head_tail **a, t_list **op_list);
void	ft_rrr(t_head_tail **a, t_head_tail **b, t_list **op_list);
void	save_op(t_head_tail **a, t_head_tail **b, t_list **op_list, enum e_op op);

#endif
