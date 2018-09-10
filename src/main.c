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
	exit(-1);
}

void	lemin_init(t_lemin *lemin, t_queue *queue, t_queue *rooms)
{
	queue->head = NULL;
	queue->tail = NULL;
	rooms->head = NULL;
	rooms->tail = NULL;
	lemin->out = NULL;
	lemin->count_ants = 0;
	lemin->count_start = 0;
	lemin->count_end = 0;
	lemin->flag_start = 0;
	lemin->flag_end = 0;
	lemin->path_len = 0;
}

int		main(void)
{
	t_lemin	*lemin;
	t_queue	*queue;
	t_queue *rooms;
	char	*line;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	rooms = (t_queue*)ft_memalloc(sizeof(t_queue));
	lemin_init(lemin, queue, rooms);
	read_amount_of_ants(lemin);
	line = read_rooms(lemin, queue);
	create_adjacent_matrix(lemin, queue, line);
	find_shortest_path(lemin, queue);
	ft_printf("%s\n", lemin->out);
	print_pathes(lemin, rooms);
	ft_strdel(&lemin->out);
	return (0);
}
