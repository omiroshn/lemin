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
	int				ant_name;
	int				ant_index;
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
	int		path_len;
	char	**final;
}					t_lemin;

void				print_error(char *number);
char				*join_str(char *where, char *what);
void				read_amount_of_ants(t_lemin *lemin);
void				check_comments(char *line, t_lemin *lemin);
char				*read_rooms(t_lemin *lemin, t_queue *queue);
void				find_shortest_path(t_lemin *lemin, t_queue *queue);
int					split_links(t_lemin *lemin, t_queue *queue, char *line);
void				print_pathes(t_lemin *lemin, t_queue *rooms);
void				create_adjacent_matrix(t_lemin *lemin,
											t_queue *queue,
												char *first);

#endif
