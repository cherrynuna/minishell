/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_relative_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:47:57 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 15:50:31 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static int	get_flag_relative_cmd(char *cmd)
{
	if (cmd == NULL)
		return (FALSE);
	if (cmd[0] == '.')
		return (TRUE);
	if (cmd[0] == '/')
		return (2);
	return (FALSE);
}

char	*is_relative_cmd(char *cmd)
{
	struct stat	file_stat;
	int			flag;
	char		*path;

	path = NULL;
	flag = get_flag_relative_cmd(cmd);
	if (flag == 2 && \
		stat(cmd, &file_stat) == 0 && (file_stat.st_mode & S_IFMT) == S_IFDIR)
		error_handler (cmd, "is a directory", 126);
	if (flag != FALSE && \
		stat(cmd, &file_stat) == 0 && (file_stat.st_mode & S_IFMT) == S_IFDIR)
	{
		error_handler (cmd, "is a directory", 126);
		return (NULL);
	}
	if (flag == TRUE || (flag == 2 && access(cmd, F_OK) == 0))
		path = ft_strdup(cmd);
	if (flag == TRUE && access(cmd, F_OK) != 0)
		error_handler(cmd, NULL, 127);
	if (flag == TRUE && access(cmd, X_OK) != 0)
		error_handler(cmd, NULL, 126);
	return (path);
}
