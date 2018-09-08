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

void	create_empty_matrix(t_lemin *lemin, int length)
{
	int i;

	lemin->matrix = (int**)ft_memalloc(sizeof(int*) * length);
	i = -1;
	while (++i < length)
		lemin->matrix[i] = (int*)ft_memalloc(sizeof(int) * length);

	// int j;
	// i = -1;
	// while (++i < length && (j = -1))
	// {
	// 	while (++j < length)
	// 		ft_printf("%d", lemin->matrix[i][j]);
	// 	ft_printf("\n");
	// }
}

void	set_indexes(t_queue *queue)
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

void	create_adjacent_matrix(t_lemin *lemin, t_queue *queue, char *first)
{
	char *line;

	set_indexes(queue);
	create_empty_matrix(lemin, queue->length);
	if (!first || first[0] == '\0')
		print_error("Empty line.");
	if (ft_strchr(first, '#'))
		check_comments(first, lemin);
	else
		split_links(lemin, queue, first);
	while (get_next_line(0, &line))
	{
		if (!line || line[0] == '\0')
			print_error("Empty line.");
		if (ft_strchr(line, '#'))
			check_comments(line, lemin);
		else
			split_links(lemin, queue, line);
	}
	ft_strdel(&line);
}
