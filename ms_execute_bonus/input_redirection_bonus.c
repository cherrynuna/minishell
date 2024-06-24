/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:44:11 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:11 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pipe_bonus.h"

void	input_redirection(char *filename, t_process *data)
{
	int	filedesc;

	input_redirection_flag_ctl(data);
	filedesc = open(filename, O_RDONLY, 0644);
	if (filedesc == -1)
		error_handler(filename, NULL, 1);
	data->fd[READ] = filedesc;
}
