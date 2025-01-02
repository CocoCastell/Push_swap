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

typedef struct	s_stack
{
	int	real_value;
	int	normalised_value;
	struct s_stack *previous;
	struct s_stack *next;
}		t_stack;

typedef struct s_head_tail
{
	t_stack *head;
	t_stack *tail;
}		t_head_tail;

//temporaire
void    print_stack(t_head_tail **a);

void	stack_init(t_head_tail **a, char **argv, bool flag_argc_2);
void	free_stack(t_head_tail **stack);
int	check_synthax(char *str);
void	error_free(bool flag_argc_2, char **argv, t_head_tail **stack);
void	free_matrix(char **argv);
int	check_repetition(long nbr, t_head_tail **a);

//Instructions

void	sa(t_head_tail **stack);
void	sb(t_head_tail **stack);
void    ss(t_head_tail **a, t_head_tail **b);
void	pa(t_head_tail **a, t_head_tail **b);
void	pb(t_head_tail **a, t_head_tail **b);
void	rr(t_head_tail **a, t_head_tail **b);
void	ra(t_head_tail **stack);
void	rb(t_head_tail **stack);
void	rra(t_head_tail **stack);
void	rrb(t_head_tail **stack);
void	rrr(t_head_tail **a, t_head_tail **b);

#endif
