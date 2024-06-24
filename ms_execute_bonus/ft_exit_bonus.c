/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:45:31 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

static unsigned char	put_exit_err(int idx, int flag, \
										unsigned char result, char *str)
{
	if (idx > 2)
	{
		ft_fprintf(2, "diveshell: exit: too many arguments\n");
		result = 1;
	}
	else if (flag == TRUE)
	{
		ft_fprintf (2, "diveshell: %s: numeric argument required\n", str);
		result = 255;
	}
	return (result);
}

static int	longlong_range(char *str, int *flag)
{
	int		sign;
	char	*ll_max;
	int		res;

	sign = 0;
	if (str[0] == '-')
		sign = -1;
	else
		sign = 1;
	if (sign == -1)
		ll_max = "-9223372036854775808";
	else
		ll_max = "+9223372036854775807";
	if (ft_strlen(str) > ft_strlen(ll_max))
		*flag = TRUE;
	res = strtol(str, NULL, 10);
	if ((res == 0 && ft_strlen(str) > 2) || (res == -1 && ft_strlen(str) > 2))
		*flag = TRUE;
	return (res);
}

unsigned char	get_exit_status(int *mode, char result, char *argv[])
{
	int		flag;
	int		idx1;
	int		idx2;

	idx1 = 1;
	flag = FALSE;
	while (argv[idx1] != NULL)
	{
		idx2 = 0;
		while (argv[idx1][idx2] != '\0')
		{
			if (ft_isdigit(argv[idx1][idx2]) != 1)
				flag = TRUE;
			if (argv[idx1][0] == '-' || argv[idx1][0] == '+')
				flag = FALSE;
			idx2++;
		}
		result = longlong_range(argv[idx1], &flag);
		idx1++;
	}
	result = put_exit_err(idx1, flag, result, argv[1]);
	if (idx1 == 1)
		*mode = 1;
	return (result);
}

int	ft_exit(char *argv[], t_execute *ms_exe)
{
	t_env_lst		*exit_code;
	unsigned char	result;
	int				mode;
	int				temp;

	result = 0;
	mode = 0;
	exit_code = ft_getenv_from_node(ms_exe->builtin_env_lst, "?");
	temp = get_exit_status(&mode, result, argv);
	if (mode != 1)
		exit (temp);
	else
		result = ft_atoi(exit_code->content);
	ft_printf ("exit\n");
	exit (result);
}
