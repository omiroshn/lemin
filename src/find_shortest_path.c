/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 13:42:53 by omiroshn          #+#    #+#             */
/*   Updated: 2018/09/09 13:42:54 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	shag_algoritma(t_lemin *lemin, int length, int minindex)
{
	int	i;
	int	min;

	min = INFINITY;
	i = -1;
	while (++i < length)
		if (lemin->visited[i] == 0 && lemin->distance[i] < min)
		{
			min = lemin->distance[i];
			minindex = i;
		}
	lemin->visited[minindex] = 1;
	i = -1;
	while (++i < length)
		if (lemin->visited[i] == 0 &&
				lemin->matrix[minindex][i] == 1 &&
				lemin->distance[minindex] != INFINITY &&
				lemin->distance[minindex] + lemin->matrix[minindex][i]
													< lemin->distance[i])
		{
			lemin->distance[i] =
				lemin->distance[minindex] + lemin->matrix[minindex][i];
		}
	return (minindex);
}

static int	find_end_index(t_queue *queue)
{
	t_node *node;

	node = queue->head;
	while (node != NULL)
	{
		if (node->end == 1)
			return (node->index);
		node = node->next;
	}
	return (-1);
}

static char	*find_index_name(t_queue *queue, int index)
{
	t_node *node;

	node = queue->head;
	while (node != NULL)
	{
		if (node->index == index)
			return (node->name);
		node = node->next;
	}
	return (NULL);
}

static void	calculate_shortest_path(t_lemin *lemin,
										t_queue *queue,
											int endindex)
{
	int i;
	int j;
	int	temp;
	int	weight;

	lemin->path_len = 1;
	weight = lemin->distance[endindex];
	while (endindex > 0 && (i = -1))
		while (++i < queue->length)
			if (lemin->matrix[endindex][i] != 0)
			{
				temp = weight - lemin->matrix[endindex][i];
				if (temp == lemin->distance[i])
				{
					weight = temp;
					endindex = i;
					lemin->path[lemin->path_len++] = i;
				}
			}
	lemin->final = (char**)malloc(sizeof(char*) * (lemin->path_len + 1));
	i = lemin->path_len;
	j = 0;
	while (--i >= 0)
		lemin->final[j++] = ft_strdup(find_index_name(queue, lemin->path[i]));
	lemin->final[j] = NULL;
}

void		find_shortest_path(t_lemin *lemin, t_queue *queue)
{
	int i;
	int	minindex;
	int	endindex;

	lemin->distance = (int*)ft_memalloc(sizeof(int) * queue->length);
	lemin->visited = (int*)ft_memalloc(sizeof(int) * queue->length);
	lemin->path = (int*)ft_memalloc(sizeof(int) * queue->length);
	i = -1;
	while (++i < queue->length)
	{
		lemin->distance[i] = INFINITY;
		lemin->visited[i] = 0;
		lemin->path[i] = 0;
	}
	lemin->distance[0] = 0;
	i = -1;
	while (++i < queue->length)
		minindex = shag_algoritma(lemin, queue->length, minindex);
	endindex = find_end_index(queue);
	if (lemin->distance[endindex] == INFINITY)
		print_error("End point not found.");
	lemin->path[0] = endindex;
	calculate_shortest_path(lemin, queue, endindex);
}
