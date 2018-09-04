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

void	print_error()
{
	ft_printf("ERROR\n");
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
		print_error();
	if (lemin->count_start > 1 || lemin->count_end > 1)
		print_error();
	//join_str(lemin, line);
}

void	read_amount_of_ants(t_lemin *lemin)
{
	char *line;
	int i;

	while (get_next_line(0, &line) && line[0] == '#')
	{
		if (!ft_strstr(line, "##start") || !ft_strstr(line, "##end"))
			print_error();
		check_commands(line, lemin);
	}
	i = -1;
	while (line[++i])
	{
		if (ft_isspace(line[i]))
			print_error();
		else if (!ft_isdigit(line[i]))
			print_error();
	}
	lemin->count_ants = ft_atoi(line);
	
	ft_printf("ants: %d\n", lemin->count_ants);
}

int		main(int argc, char **argv)
{
	t_lemin *lemin;

	lemin = (t_lemin*)malloc(sizeof(t_lemin));
	read_amount_of_ants(lemin);
	return (0);
}
