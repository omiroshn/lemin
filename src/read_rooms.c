/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 17:40:47 by omiroshn          #+#    #+#             */
/*   Updated: 2018/09/07 17:40:48 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	t_node	*new_node(t_lemin *lemin, char **split)
{
	t_node	*node;

	node = (t_node*)ft_memalloc(sizeof(t_node));
	node->name = ft_strdup(split[0]);
	node->coord_x = ft_atoi(split[1]);
	node->coord_y = ft_atoi(split[2]);
	node->next = NULL;
	if (lemin->flag_start == 1)
	{
		node->start = 1;
		lemin->flag_start = 0;
	}
	else
		node->start = 0;
	if (lemin->flag_end == 1)
	{
		node->end = 1;
		lemin->flag_end = 0;
	}
	else
		node->end = 0;
	return (node);
}

static	void	enqueue(t_lemin *lemin, t_queue *queue, char **split)
{
	if (queue->tail == NULL)
	{
		queue->tail = new_node(lemin, split);
		queue->head = queue->tail;
	}
	else
	{
		queue->tail->next = new_node(lemin, split);
		queue->tail = queue->tail->next;
	}
	queue->length++;
}

static	void	check_repeating_names_and_coords(t_queue *queue)
{
	t_node *step;
	t_node *next_step;

	step = queue->head;
	while (step != NULL)
	{
		next_step = step->next;
		while (next_step != NULL)
		{
			if (ft_strcmp(step->name, next_step->name) == 0)
				print_error("This name is already taken.");
			if (step->coord_x == next_step->coord_x &&
				step->coord_y == next_step->coord_y)
				print_error("Coordinates are repeating.");
			next_step = next_step->next;
		}
		step = step->next;
	}
}

static	void	split_rooms(t_lemin *lemin, t_queue *queue, char *line)
{
	char	**split;
	int		i;
	int		j;

	if (ft_isspace(line[0]))
		print_error("Wrong symbol.");
	ft_countwords(line, ' ') < 3 ? print_error("Not enough coordinates.") : 0;
	ft_countwords(line, ' ') > 3 ? print_error("Too many coordinates.") : 0;
	split = ft_strsplit(line, ' ');
	split[0][0] == 'L' ? print_error("Wrong name.") : 0;
	i = 0;
	while (split[++i] && (j = -1))
		if (!ft_isdigit(split[i][++j]))
			print_error("Coordinate isn't a number");
	enqueue(lemin, queue, split);
	i = -1;
	while (++i < 3)
		ft_strdel(&split[i]);
	free(split);
}

char			*read_rooms(t_lemin *lemin, t_queue *queue)
{
	char *line;

	while (get_next_line(0, &line) > 0 && ft_strchr(line, '-') == 0)
	{
		if (!line || line[0] == '\0')
			print_error("Empty line.");
		if (ft_strchr(line, '#'))
			check_comments(line, lemin);
		else
		{
			split_rooms(lemin, queue, line);
			lemin->out = join_str(lemin->out, line);
		}
		ft_strdel(&line);
	}
	check_repeating_names_and_coords(queue);
	if (lemin->count_start != 1 || lemin->count_end != 1)
		print_error("No ##start or ##end found.");
	return (line);
}
