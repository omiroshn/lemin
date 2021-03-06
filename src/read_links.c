/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 22:01:21 by omiroshn          #+#    #+#             */
/*   Updated: 2018/09/08 22:01:22 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	void	check_existance_of_link(t_queue *queue, char **split)
{
	t_node	*node;
	char	*left;
	char	*right;
	int		l_exists;
	int		r_exists;

	l_exists = 0;
	r_exists = 0;
	left = split[0];
	right = split[1];
	node = queue->head;
	while (node != NULL)
	{
		if (ft_strcmp(node->name, left) == 0)
			l_exists = 1;
		if (ft_strcmp(node->name, right) == 0)
			r_exists = 1;
		if (l_exists && r_exists)
			return ;
		node = node->next;
	}
	!l_exists ? print_error("Left name doesn't exit.") : 0;
	!r_exists ? print_error("Right name doesn't exit.") : 0;
}

static	int		find_index(t_queue *queue, char *name)
{
	t_node *node;

	node = queue->head;
	while (node != NULL)
	{
		if (ft_strcmp(node->name, name) == 0)
			return (node->index);
		node = node->next;
	}
	return (-1);
}

static	int		fill_matrix(t_lemin *lemin, t_queue *queue, char **split)
{
	int	v1;
	int	v2;

	v1 = find_index(queue, split[0]);
	v2 = find_index(queue, split[1]);
	if (v1 == -1 || v2 == -1)
		print_error("Index not found.");
	if (lemin->matrix[v1][v2] == 0 && lemin->matrix[v2][v1] == 0)
	{
		lemin->matrix[v1][v2] = 1;
		lemin->matrix[v2][v1] = 1;
		return (0);
	}
	return (-1);
}

int				split_links(t_lemin *lemin, t_queue *queue, char *line)
{
	char	**split;
	int		i;
	int		words;

	i = -1;
	while (line[++i])
		if (ft_isspace(line[i]))
			print_error("Wrong symbol.");
	words = ft_countwords(line, '-');
	words < 2 ? print_error("Not enough arguments.") : 0;
	words > 2 ? print_error("Too many arguments.") : 0;
	split = ft_strsplit(line, '-');
	if (ft_strcmp(split[0], split[1]) == 0)
		return (-1);
	check_existance_of_link(queue, split);
	if (fill_matrix(lemin, queue, split) == -1)
		return (-1);
	i = -1;
	while (++i < 3)
		ft_strdel(&split[i]);
	free(split);
	lemin->out = join_str(lemin->out, line);
	return (1);
}
