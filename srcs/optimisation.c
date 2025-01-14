/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	merge(t_list *to_delete, enum e_op op)
{
	t_list	*next_op;
	
	if (to_delete == NULL || to_delete->next == NULL)
		return ;
	next_op = to_delete->next;
	to_delete->next = next_op->next;
	if (op == sa)
		to_delete->content = (void *)(uintptr_t)ss;
	else if (op == ra)
		to_delete->content = (void *)(uintptr_t)rr;
	else if (op == rra)
		to_delete->content = (void *)(uintptr_t)rrr;
	free(next_op);
}

static void	check_merge(t_list *op, bool *has_changed)
{
	enum e_op	c_op;
	enum e_op	n_op;

	if (op == NULL || op->next == NULL)
		return ;
	c_op = (enum e_op)(uintptr_t)op->content;
	n_op = (enum e_op)(uintptr_t)op->next->content;
	if ((c_op == sa && n_op == sb) || (c_op == sb && n_op == sa))
		merge(op, sa);
	else if ((c_op == ra && n_op == rb) || (c_op == rb && n_op == ra))
		merge(op, ra);
	else if ((c_op == rra && n_op == rrb) || (c_op == rrb && n_op == rra))
		merge(op, rra);
	else
		*has_changed = false;
}

static void	*cancel(t_list **head_op, t_list *op)
{
	t_list	*temp;
	t_list	*current;
	t_list	*next;

	if (*head_op == op)
	{
		if (op->next->next != NULL)
			*head_op = op->next->next;
		else
			return (*head_op = NULL);
		current = op;
		next = current->next;
		free (current);
		free(next);
		return (*head_op);
	}
	temp = *head_op;
	while (temp->next != op)
		temp = temp->next;
	current = op;
	if (current->next->next != NULL)
		temp->next = current->next->next;
	else
		temp->next = NULL;
	next = current->next;
	free(current);
	free(next);
	return (temp);
}

static void	*check_neutral(t_list **head_op, t_list *op)
{
	bool		has_changed;
	enum e_op       c_op;
	enum e_op       n_op;
	t_list		*output;

	if (op == NULL || op->next == NULL)
		return (NULL);
	output = op;
	has_changed = true;
	while (has_changed == true && output != NULL && *head_op != NULL)
	{
		c_op = (enum e_op)(uintptr_t)output->content;
		if (output->next != NULL)
			n_op = (enum e_op)(uintptr_t)output->next->content;
		else
			break ;
		if ((c_op == pa && n_op == pb) || (c_op == pb && n_op == pa) || 
		(c_op == ra && n_op == rra) || (c_op == rra && n_op == ra) || 
		(c_op == rb && n_op == rrb) || (c_op == rrb && n_op == rb) || 
		(c_op == sa && n_op == sa) || (c_op == sb && n_op == sb) ||
		(c_op == rr && n_op == rrr) || (c_op == rrr && n_op == rr) || (c_op == ss && n_op == ss))
			output = cancel(head_op, output);
		else
			has_changed = false;
	}
	return (output);
}

void	opti(t_list **head_op)
{
	t_list	*current;
	bool	has_merge_changed;
	
	if (head_op == NULL || *head_op == NULL) 
		return ;
	current = *head_op;
	while (current != NULL)
	{
		has_merge_changed = true;
		while (has_merge_changed == true)
		{
			current = check_neutral(head_op, current);
			if (current == NULL)
				return ;
			check_merge(current, &has_merge_changed);
		}
		current = current->next;
	}
}
