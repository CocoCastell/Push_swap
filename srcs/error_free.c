/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_matrix(char **argv)
{
	int	i;
	
	i = 0;
	if (argv == NULL || *argv == NULL)	
		return ;
	while (argv[i] != NULL)
		free(argv[i++]);
	free(argv);
}

void	free_stack(t_head_tail **stack)
{
	t_stack *tmp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = (*stack)->head;
	while (current != (*stack)->tail)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(current);
	(*stack)->head = NULL;
	(*stack)->tail = NULL;
}

void	error_free(bool flag_argc_2, char **argv, t_head_tail **stack)
{
	free_stack(stack);
	if (flag_argc_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_synthax(char *str)
{
	if (str == NULL)
		return (1);
	if (*str != '-' && *str != '+' && (*str < '0' || *str > '9'))
		return (1);
	str++;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);	
}

int	check_repetition(long nbr, t_head_tail **a)
{
	t_stack *current;

	if ((*a)->tail == NULL)
			return (0);
	current = (*a)->head;
	while (current != (*a)->tail)
	{
		if (current->real_value == nbr)
			return (1);
		current = current->next;
	}
	if (current->real_value == nbr)
		return (1);
	return (0);
}
