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

#ifndef CHECKER_H
# define CHECKER_H

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
	int		real_value;
	struct s_stack	*previous;
	struct s_stack	*next;
}		t_stack;


typedef struct	s_head_tail
{
	t_stack	*head;
	t_stack	*tail;
}		t_head_tail;

//Stack

void	print_stack_bonus(t_head_tail **a);
bool	is_sorted(t_head_tail **a);
bool    is_empty(t_head_tail *stack);
void	exit_error();
void	del(void *content);
void	free_matrix(char **argv);
void	free_op_list(t_list **op_list);
void	free_stack(t_head_tail **stack);
void	apply_rules(t_list *op, t_head_tail **a, t_head_tail **b);
void	stack_init(t_head_tail **a, t_head_tail **b, char **argv, bool flag_argc_2);
void	error_free(bool flag_argc_2, char **argv, t_head_tail **a, t_head_tail **b);
int	get_rules(t_list **list, int fd);
int	check_synthax(char *str);
int	check_repetition(long nbr, t_head_tail **a);

//Instructions

void	swap_a(t_head_tail **a);
void	swap_b(t_head_tail **b);
void	rot_a(t_head_tail **a);
void	rot_b(t_head_tail **b);
void	rev_a(t_head_tail **a);
void	rev_b(t_head_tail **b);
void    swap_a_b(t_head_tail **a, t_head_tail **b);
void	push_a(t_head_tail **a, t_head_tail **b);
void	push_b(t_head_tail **a, t_head_tail **b);
void	rot_a_b(t_head_tail **a, t_head_tail **b);
void	rev_a_b(t_head_tail **a, t_head_tail **b);

#endif
