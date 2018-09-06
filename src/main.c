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

void	check_commands(char *line, t_lemin *lemin)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		lemin->count_start++;
		lemin->flag_start = 1;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		lemin->count_end++;
		lemin->flag_end = 1;
	}
	else if (line[0] != '#')
		print_error("");
	if (lemin->count_start > 1 || lemin->count_end > 1)
		print_error("");
	//join_str(lemin, line);
}

int		check_comments(char *line, t_lemin *lemin)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (line[++i])
		if (line[i] == '#')
			count++;
	if (ft_strstr(line, "##start") && count == 2 && ft_strlen(line) == 7)
		print_error("Number of ants was not defined.");
	if (ft_strstr(line, "##end") && count == 2 && ft_strlen(line) == 5)
		print_error("Number of ants was not defined.");
	lemin->out = ft_strjoin(lemin->out, line);
	lemin->out = ft_strjoin(lemin->out, "\n");
	return (count);
}

void	read_amount_of_ants(t_lemin *lemin)
{
	char *line;
	int i;

	while (get_next_line(0, &line) && line[0] == '#')
	{
		ft_printf(":%s\n", line);
		check_comments(line, lemin);
		// check_commands(line, lemin);
	}
	if (!*line)
		print_error("Empty line.");
	ft_printf(";%s\n", line);
	i = -1;
	while (line[++i])
	{
		if (ft_isspace(line[i]))
			print_error("Wrong symbol.");
		else if (!ft_isdigit(line[i]))
			print_error("Wrong symbol.");
	}
	lemin->count_ants = ft_atoi(line);
	if (lemin->count_ants <= 0)
		print_error("Number of ants <= 0 or > than MAXINT");
	ft_printf("ants: %d\n", lemin->count_ants);
	ft_printf("\n\n%s\n", lemin->out);
}

int		main(int argc, char **argv)
{
	t_lemin *lemin;

	lemin = (t_lemin*)malloc(sizeof(t_lemin));
	read_amount_of_ants(lemin);
	return (0);
}
