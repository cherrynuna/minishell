/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paser_level_exitnum_handler.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:44:43 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/14 20:52:45 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

void	set_syntax_error_exitnum(int lexer, t_execute *ms_exe)
{
	t_env_lst	*exit_no;

	if (lexer == INT_MIN)
	{
		exit_no = get_last_execute_exit_code(0, ms_exe);
		free(exit_no->content);
		exit_no->content = ft_itoa(258);
	}
}
