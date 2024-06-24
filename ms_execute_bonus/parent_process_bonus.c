/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:26:49 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

int	parent_process(t_process *data)
{
	if (data->fd[WRITE] != WRITE)
		close(data->fd[WRITE]);
	if (data->ex_fd != -1)
		close(data->ex_fd);
	data->ex_fd = data->fd[READ];
	if (data->argv != NULL)
	{
		free(data->argv);
		data->argv = NULL;
	}
	if (data->redirection != NULL)
	{
		free(data->redirection);
		data->redirection = NULL;
	}
	return (0);
}
