/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin_function_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 09:37:50 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

int	is_cmd_turn_out(char **argv, t_execute *ms_exe)
{
	int	result;

	result = 0;
	if (argv == NULL)
		return (0);
	if (ft_strcmp(*argv, "echo") == 0)
		result = ft_echo(argv);
	if (ft_strcmp(*argv, "cd") == 0)
		result = ft_cd(argv, ms_exe);
	if (ft_strcmp(*argv, "pwd") == 0)
		result = ft_pwd(argv);
	if (ft_strcmp(*argv, "export") == 0)
		result = ft_export(argv, ms_exe);
	if (ft_strcmp(*argv, "unset") == 0)
		result = ft_unset(argv, ms_exe);
	if (ft_strcmp(*argv, "env") == 0)
		result = ft_env(argv, ms_exe);
	if (ft_strcmp(*argv, "exit") == 0)
		result = ft_exit(argv, ms_exe);
	return (result);
}

int	is_builtin_function(char *argv)
{
	if (argv == NULL)
		return (0);
	if (ft_strcmp(argv, "echo") == 0)
		return (1);
	if (ft_strcmp(argv, "cd") == 0)
		return (1);
	if (ft_strcmp(argv, "pwd") == 0)
		return (1);
	if (ft_strcmp(argv, "export") == 0)
		return (1);
	if (ft_strcmp(argv, "unset") == 0)
		return (1);
	if (ft_strcmp(argv, "env") == 0)
		return (1);
	if (ft_strcmp(argv, "exit") == 0)
		return (1);
	return (0);
}
