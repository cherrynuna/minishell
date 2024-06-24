/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_flag_ctl_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:25:46 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:11 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pipe_bonus.h"

void	input_redirection_flag_ctl(t_process *data)
{
	ssize_t	fd;

	fd = read(data->fd[READ], NULL, 0);
	if (fd != -1 && data->fd[READ] != READ)
		close(data->fd[READ]);
}

void	output_redirection_flag_ctl(t_process *data)
{
	ssize_t	fd;

	fd = write(data->fd[WRITE], NULL, 0);
	if (fd != -1 && data->fd[WRITE] != WRITE)
		close(data->fd[WRITE]);
}
