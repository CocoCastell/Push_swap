/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 15:59:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_head_tail **a)
{
	t_stack	*current;

	current = (*a)->head;
	if ((*a)->tail != NULL)
	{
	while (current != (*a)->tail)
	{
		if (current->real_value < 9)
			ft_printf("%i      |    %i\n", current->real_value, current->normalised_value);
		else if (current->real_value < 99)
			ft_printf("%i     |    %i\n", current->real_value, current->normalised_value);
		else if (current->real_value < 999)
			ft_printf("%i    |    %i\n", current->real_value, current->normalised_value);
		else if (current->real_value < 9999)
			ft_printf("%i   |    %i\n", current->real_value, current->normalised_value);
		else if (current->real_value < 99999)
			ft_printf("%i  |    %i\n", current->real_value, current->normalised_value);
		current = current->next;
	}
        if (current->real_value < 9)
		ft_printf("%i      |    %i\n", current->real_value, current->normalised_value);
	else if (current->real_value < 99)
		ft_printf("%i     |    %i\n", current->real_value, current->normalised_value);
	else if (current->real_value < 999)
		ft_printf("%i    |    %i\n", current->real_value, current->normalised_value);
	else if (current->real_value < 9999)
		ft_printf("%i   |    %i\n", current->real_value, current->normalised_value);
	else if (current->real_value < 99999)
		ft_printf("%i  |    %i\n", current->real_value, current->normalised_value);
	}
}

void	normalise_stack(t_head_tail **a, int i)
{
        t_stack	*current;
	t_stack	*next_node;

	if (a == NULL || *a == NULL || (*a)->head == NULL)
		return ;
        current = (*a)->head;
	while (current != (*a)->tail)
	{
        	i = 0;
		next_node = current->next;
		while (next_node != current)
		{
			if (next_node->real_value < current->real_value)
				i++;
			next_node = next_node->next;
		}
		current->normalised_value = i;
		current = current->next;
	}
	i = 0;
	next_node = current->next;
	while (next_node != current)
	{
		if (next_node->real_value < current->real_value)
			i++;
		next_node = next_node->next;
	}
	current->normalised_value = i;
}

static void	add_value_to_stack(t_head_tail **a, long nbr)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		free_stack(a);
		exit(1);
	}
	new_node->real_value = nbr;
	new_node->normalised_value = -1;
	if ((*a)->tail == NULL)
	{
		new_node->next = new_node;
		new_node->previous = new_node;
		(*a)->head = new_node;
		(*a)->tail = new_node;
	}
	else
	{
		(*a)->tail->next = new_node;
		new_node->previous = (*a)->tail;
		new_node->next = (*a)->head;
		(*a)->tail = new_node;
		(*a)->head->previous = new_node;
	}
}

static int	stack_alloc(t_head_tail **a, t_head_tail **b)
{
	*a = malloc(sizeof(t_head_tail));
	if (a == NULL)
		return (-1);
	(*a)->tail = NULL;
	(*a)->head = NULL;
	(*a)->size = 0;
	(*a)->op_list = NULL;
	*b = malloc(sizeof(t_head_tail));
	if (b == NULL)
	{
		free(a);
		return (-1);
	}
	(*b)->tail = NULL;
	(*b)->head = NULL;
	(*a)->size = 0;
	(*b)->op_list = (*a)->op_list;
	return (0);
}

void    stack_init(t_head_tail **a, t_head_tail **b, char **argv, bool flag_argc_2)
{
        long    nbr;
        int     i;
	
	if (stack_alloc(a, b) == -1)
		error_free(1 , argv, a, b);
	i = 1;
        if (flag_argc_2 == 1)
        {
		i = 0;
		if (check_synthax(argv[0]))
			error_free(flag_argc_2, argv, NULL, NULL);
	}
	while (argv[i] != NULL)
        {
                nbr = ft_atol(argv[i]);
                if (nbr > INT_MAX || nbr < INT_MIN)
                        error_free(flag_argc_2, argv, a, NULL);
                if (check_repetition(nbr, a))
			 error_free(flag_argc_2, argv, a, NULL);
                add_value_to_stack(a, nbr);
		(*a)->size++;
		i++;
        }
	normalise_stack(a, 0);
	print_stack(a);
}
