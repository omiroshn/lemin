/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacent_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 21:59:35 by omiroshn          #+#    #+#             */
/*   Updated: 2018/09/08 21:59:36 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	void	create_empty_matrix(t_lemin *lemin, int length)
{
	int i;

	lemin->matrix = (int**)ft_memalloc(sizeof(int*) * length);
	i = -1;
	while (++i < length)
		lemin->matrix[i] = (int*)ft_memalloc(sizeof(int) * length);
}

static	void	set_indexes(t_queue *queue)
{
	int		i;
	t_node	*node;

	node = queue->head;
	i = 1;
	while (node != NULL)
	{
		if (node->start == 1)
			node->index = 0;
		else
			node->index = i++;
		node = node->next;
	}
}

static	int		read_first_line(t_lemin *lemin, t_queue *queue, char *first)
{
	set_indexes(queue);
	create_empty_matrix(lemin, queue->length);
	if (!first || first[0] == '\0')
	{
		ft_strdel(&first);
		return (-1);
	}
	if (ft_strchr(first, '#'))
	{
		check_comments(first, lemin);
		ft_strdel(&first);
	}
	else if (split_links(lemin, queue, first) == -1)
	{
		ft_strdel(&first);
		return (-1);
	}
	return (1);
}

void			create_adjacent_matrix(t_lemin *lemin,
										t_queue *queue,
											char *first)
{
	char *line;

	if (read_first_line(lemin, queue, first) == -1)
		return ;
	while (get_next_line(0, &line) > 0)
	{
		if (!line || line[0] == '\0')
		{
			ft_strdel(&line);
			return ;
		}
		if (ft_strchr(line, '#'))
		{
			check_comments(line, lemin);
			ft_strdel(&line);
		}
		else if (split_links(lemin, queue, line) == -1)
		{
			ft_strdel(&line);
			return ;
		}
		else
			ft_strdel(&line);
	}
	ft_strdel(&line);
}
