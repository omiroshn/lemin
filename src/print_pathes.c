/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pathes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 17:40:40 by omiroshn          #+#    #+#             */
/*   Updated: 2018/09/07 17:40:41 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	void	add_ant(t_queue *rooms, int current_ant)
{
	t_node *node;

	node = (t_node*)malloc(sizeof(t_node));
	node->ant_name = 1;
	node->ant_index = current_ant;
	node->next = NULL;
	if (rooms->tail == NULL)
	{
		rooms->tail = node;
		rooms->head = rooms->tail;
	}
	else
	{
		rooms->tail->next = node;
		rooms->tail = rooms->tail->next;
	}
}

static	int		print_ants(t_queue *rooms, int path_len, char **final)
{
	t_node	*node;
	int		stop;

	stop = 1;
	node = rooms->head;
	while (node != NULL)
	{
		if (node->ant_name < path_len)
		{
			ft_printf("L%d-%s", node->ant_index, final[node->ant_name]);
			if (node->next != NULL)
				write(1, " ", 1);
			node->ant_name++;
			stop = 0;
		}
		node = node->next;
	}
	return (stop);
}

void			print_pathes(t_lemin *lemin, t_queue *rooms)
{
	int	current_ant;
	int	stop;

	stop = 0;
	current_ant = 1;
	if (lemin->path_len == 2)
	{
		while (current_ant <= lemin->count_ants)
			add_ant(rooms, current_ant++);
		print_ants(rooms, lemin->path_len, lemin->final);
		write(1, "\n", 1);
	}
	else
	{
		while (1)
		{
			if (current_ant <= lemin->count_ants)
				add_ant(rooms, current_ant++);
			stop = print_ants(rooms, lemin->path_len, lemin->final);
			if (stop == 1)
				break ;
			write(1, "\n", 1);
		}
	}
}
