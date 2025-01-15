/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/11/14 10:04:41 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_op_synthax(char *b, int size)
{
	if (size == 3)
	{
		if (b[0] == 'r' && b[1] == 'r')
		{
			if (b[2] == 'a' || b[2] == 'b'|| b[2] == 'r')
				return (0);
		}
	}
	else if (size == 2)
	{
		if (b[0] == 's' && (b[1] == 'a' || b[1] == 'b' || b[1] == 's'))
			return (0);
		if (b[0] == 'r' && (b[1] == 'a' || b[1] == 'b' || b[1] == 'r'))
			return (0);
		if (b[0] == 'p' && (b[1] == 'a' || b[1] == 'b'))
			return (0);
	}
	return (1);
}

static int	check_op_error(int bytes_read, char buffer[5])
{
	if (bytes_read <= 2 || buffer[1] == '\n')
		return (1);
	if (bytes_read == 3)
	{
		buffer[3] = '\0';
		if (buffer[2] != '\n')
			return (1);
		buffer[2] = '\0';
	}
	else if (bytes_read == 4)
	{
		buffer[4] = '\0';
		if (buffer[3] != '\n')
			return (1);
		buffer[3] = '\0';
	}
	if (check_op_synthax(buffer, bytes_read - 1) == 1)
		return (1);
	return (0);
}

int	get_rules(t_list **list, int fd)
{
	ssize_t	bytes_read;
	char	buffer[5];
	char	*str_copy;
	t_list	*new;

	if (fd != 0)
		exit_error();
	bytes_read = read(fd, buffer, 4);
	if (bytes_read == 0)
		return (1);
	if (check_op_error(bytes_read, buffer) == 1)
		exit_error();
	str_copy = strdup(buffer);
	new = ft_lstnew(str_copy);
	ft_lstadd_back(list, new);
	return (0);
}
