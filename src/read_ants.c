/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 17:40:40 by omiroshn          #+#    #+#             */
/*   Updated: 2018/09/07 17:40:41 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*join_str(char *where, char *what)
{
	char	*temp;
	char	*ret;

	temp = where;
	ret = ft_strjoin(temp, what);
	ft_strdel(&temp);
	temp = ret;
	ret = ft_strjoin(temp, "\n");
	ft_strdel(&temp);
	return (ret);
}

void	check_comments(char *line, t_lemin *lemin)
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
	if (lemin->count_start > 1 || lemin->count_end > 1)
		print_error("Several starts or ends.");
	lemin->out = join_str(lemin->out, line);
}

void	read_amount_of_ants(t_lemin *lemin)
{
	char	*line;
	int		i;

	while (get_next_line(0, &line) > 0 && line[0] == '#')
	{
		if ((ft_strstr(line, "##start") && ft_strlen(line) == 7)
			|| (ft_strstr(line, "##end") && ft_strlen(line) == 5))
			print_error("Number of ants was not defined.");
		check_comments(line, lemin);
		ft_strdel(&line);
	}
	if (!line || line[0] == '\0')
		print_error("Empty line.");
	i = -1;
	while (line[++i])
		if (ft_isspace(line[i]) || !ft_isdigit(line[i]))
			print_error("Wrong symbol.");
	if ((lemin->count_ants = ft_atoi(line)) <= 0)
		print_error("Number of ants <= 0 or > than MAXINT.");
	lemin->out = join_str(lemin->out, line);
	ft_strdel(&line);
}
