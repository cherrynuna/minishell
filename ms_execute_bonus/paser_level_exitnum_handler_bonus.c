/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paser_level_exitnum_handler_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:44:43 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

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
