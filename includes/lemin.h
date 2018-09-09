/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:21:25 by omiroshn          #+#    #+#             */
/*   Updated: 2018/09/03 13:21:26 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "colored_str.h"

# define INFINITY 2147483647

typedef struct		s_node
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				index;
	int				start;
	int				end;
	struct s_node	*next;
}					t_node;

typedef struct		s_queue
{
	int		length;
	t_node	*head;
	t_node	*tail;
}					t_queue;

typedef struct		s_lemin
{
	int		**matrix;
	int		*distance;
	int		*visited;
	int		*path;
	char	*out;
	int		count_ants;
	int		count_start;
	int		flag_start;
	int		count_end;
	int		flag_end;
}					t_lemin;

char	*join_str(char *where, char *what);
void	check_comments(char *line, t_lemin *lemin);
void	read_amount_of_ants(t_lemin *lemin);
void	print_error(char *number);
t_node	*new_node(t_lemin *lemin, char **split);
void	enqueue(t_lemin *lemin, t_queue *queue, char **split);
void	check_repeating_names_and_coords(t_queue *queue);
void	split_rooms(t_lemin *lemin, t_queue *queue, char *line);
char	*read_rooms(t_lemin *lemin, t_queue *queue);
void	create_empty_matrix(t_lemin *lemin, int length);
void	set_indexes(t_queue *queue);
void	create_adjacent_matrix(t_lemin *lemin, t_queue *queue, char *first);
void	check_existance_of_link(t_queue *queue, char **split);
int		find_index(t_queue *queue, char *name);
void	fill_matrix(t_lemin *lemin, t_queue *queue, char **split);
void	split_links(t_lemin *lemin, t_queue *queue, char *line);
void	find_shortest_path(t_lemin *lemin, t_queue *queue);
void	print_matrix(int **matrix, int length);

#endif
