/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wo_q_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:02:54 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:58 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand_bonus.h"

char	*expand_wo_q(char *eof, t_execute *ms_exe)
{
	t_pars_tree	*tree;
	int			start;

	tree = new_tree_node(1, eof);
	start = 0;
	while (eof[start] != '\0')
	{
		if (eof[start] == '$')
			replace_d(tree, ms_exe, &start, 1);
		start++;
	}
	free(tree);
	return (eof);
}
