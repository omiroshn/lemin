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

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "colored_str.h"

typedef struct		s_lemin
{
	char	*out;
	int		count_ants;
	int		count_start;
	int		flag_start;
	int		count_end;
	int		flag_end;
}					t_lemin;

#endif
