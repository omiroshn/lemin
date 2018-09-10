/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 21:59:28 by omiroshn          #+#    #+#             */
/*   Updated: 2018/08/21 21:59:29 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_error(char *number)
{
	ft_printf("ERROR: %s\n", number);
	// system("leaks lem-in");
	exit(-1);
}

void	lemin_init(t_lemin *lemin)
{
	lemin->out = NULL;
	lemin->count_ants = 0;
	lemin->count_start = 0;
	lemin->count_end = 0;
	lemin->flag_start = 0;
	lemin->flag_end = 0;
	lemin->path_len = 0;
}

void	print_queue(t_queue *queue)
{
	t_node *node;

	node = queue->head;
	while (node != NULL)
	{
		ft_printf("%s %d %d %d\n", node->name, node->coord_x, node->coord_y, node->index);
		node = node->next;
	}
}

void	print_matrix(int **matrix, int length)
{
	int i;
	int j;

	i = -1;
	while (++i < length && (j = -1))
	{
		while (++j < length)
			ft_printf("%d", matrix[i][j]);
		ft_printf("\n");
	}
}

int		main(void)
{
	t_lemin	*lemin;
	t_queue	*queue;
	char	*line;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	lemin_init(lemin);
	read_amount_of_ants(lemin);
	line = read_rooms(lemin, queue);
	create_adjacent_matrix(lemin, queue, line);
	find_shortest_path(lemin, queue);
	ft_printf("%s\n", lemin->out);
	print_pathes(lemin, queue);
	// print_matrix(lemin->matrix, queue->length);
	// print_queue(queue);
	ft_strdel(&lemin->out);
	// system("leaks lem-in");
	return (0);
}
