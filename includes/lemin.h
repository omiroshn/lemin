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

typedef struct		s_node
{
	char			*name;
	int				coord_x;
	int				coord_y;
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
	char	*out;
	int		count_ants;
	int		count_start;
	int		flag_start;
	int		count_end;
	int		flag_end;
}					t_lemin;

void	join_str(char *line, t_lemin *lemin);
void	check_comments(char *line, t_lemin *lemin);
void	read_amount_of_ants(t_lemin *lemin);
void	print_error(char *number);

#endif
