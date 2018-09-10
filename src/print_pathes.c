/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pathes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 17:40:40 by omiroshn          #+#    #+#             */
/*   Updated: 2018/09/07 17:40:41 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_pathes(t_lemin *lemin, t_queue *queue)
{
	int i;

	i = -1;
	while (++i < lemin->path_len)
	{
		ft_printf("%s\n", lemin->final[i]);
	}

}