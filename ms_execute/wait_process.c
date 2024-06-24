/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:58:13 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 03:53:56 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

t_env_lst	*get_last_execute_exit_code(unsigned char exit_no, \
												t_execute *ms_exe)
{
	t_env_lst	*node;
	char		*exit_str;

	node = ft_getenv_from_node(ms_exe->builtin_env_lst, "?");
	if (node == NULL)
	{
		node = ft_env_lstnew("?", NULL);
		ft_env_lstadd_back(&ms_exe->builtin_env_lst, node);
	}
	else
		free(node->content);
	exit_str = ft_itoa(exit_no);
	if (exit_str == NULL)
		error_handler("exitno", NULL, 12);
	node->content = exit_str;
	return (node);
}

int	get_wsignal(int status, int res)
{
	if (WIFSIGNALED(status))
	{
		res = WTERMSIG(status);
		if (res == SIGINT)
			ft_printf ("\n");
		else if (res == SIGQUIT)
			ft_printf ("Quit: %d\n", res);
		res = res + 128;
	}
	return (res);
}

static void	closed_wait(int final_status, int res, \
						t_process *data, t_execute *ms_exe)
{
	res = get_wsignal(final_status, res);
	if (data->process_num)
		get_last_execute_exit_code(res, ms_exe);
	init_process_data(data);
}

void	wait_process(t_execute *ms_exe, t_process *data)
{
	int				result_pid;
	int				status;
	int				final_status;
	int				res;
	unsigned int	idx;

	idx = 0;
	res = 0;
	final_status = 0;
	status = 0;
	if (data->ex_fd != READ)
		close(data->ex_fd);
	while (idx < data->process_num)
	{
		result_pid = wait(&status);
		if (data->pid == result_pid)
		{
			final_status = status;
			res = WEXITSTATUS(status);
		}
		if (result_pid == -1)
			break ;
		idx++;
	}
	closed_wait(final_status, res, data, ms_exe);
}
