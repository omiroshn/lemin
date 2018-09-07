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
	//system("leaks lemin");
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
}

// void	read_connections(t_lemin *lemin, char *first_line)
// {
// 	char *line;

// 	while (get_next_line(0, &line))
// 	{
// 		//check_comments(line, lemin);
// 		ft_strdel(&line);
// 	}
// }

void	split_rooms(t_lemin *lemin, char *line)
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
}

void	read_rooms(t_lemin *lemin)
{
	char *line;

	while (get_next_line(0, &line) && ft_strchr(line, '-') == 0)
	{
		if (!line || line[0] == '\0')
			print_error("Empty line.");
		if (ft_strchr(line, '#'))
			check_comments(line, lemin);
		else
		{
			split_rooms(lemin, line);
			join_str(line, lemin);
		}
		ft_strdel(&line);
	}
	if (lemin->count_start != 1 || lemin->count_end != 1)
		print_error("No ##start or ##end found.");
	//read_connections(lemin, line);
	ft_strdel(&line);
}

int		main(int argc, char **argv)
{
	t_lemin *lemin;
	t_queue *queue;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	lemin_init(lemin);
	read_amount_of_ants(lemin);
	read_rooms(lemin);
	ft_printf("%s\n", lemin->out);
	ft_strdel(&lemin->out);
	//system("leaks lem-in");
	return (0);
}
