/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_exe_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:56:01 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

void	set_tree_to_int_max(t_pars_tree *tree)
{
	if (tree->left != NULL && tree->right != NULL && \
		tree->left->type == INT_MAX && tree->right->type == INT_MAX)
		tree->type = INT_MAX;
}

int	get_type_flag(int type)
{
	if ((type & SUB_SHELL) == SUB_SHELL)
		type -= SUB_SHELL;
	type = move_last_process_flag(type);
	return (type);
}

int	move_last_process_flag(int type)
{
	if ((type & LAST_PROCESS) == LAST_PROCESS)
		type -= LAST_PROCESS;
	return (type);
}

int	add_last_process_flag(int type)
{
	if ((type & LAST_PROCESS) != LAST_PROCESS)
		type += LAST_PROCESS;
	return (type);
}
