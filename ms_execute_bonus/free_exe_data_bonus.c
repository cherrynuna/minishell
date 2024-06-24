/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exe_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:51:34 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

void	free_exe_data(t_pars_tree **ctl_cmd, t_process *data)
{
	t_pars_tree	*cur;

	free(data->argv);
	free(data->redirection);
	data->argv = NULL;
	data->redirection = NULL;
	cur = *ctl_cmd;
	delete_tree_node(ctl_cmd);
	printf ("ctl_cmd: %p\n", *ctl_cmd);
}
