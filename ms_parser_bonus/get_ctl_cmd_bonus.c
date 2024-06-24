/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ctl_cmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:28:10 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:33:59 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_bonus.h"

int	get_ctl_cmd(int lexer, char **cursor, \
									t_pars_tree **end_ptr, t_pars_tree **ptr)
{
	t_pars_tree	*temp;
	char		*ctl_cmd;

	if (is_control_cmd(*cursor) == 0 || lexer == INT_MIN)
		return (lexer);
	if (lexer == REDIRECTION)
	{
		syntax_error(&lexer, ft_substr(*cursor, 0, 1));
		return (INT_MIN);
	}
	ctl_cmd = ft_substr(*cursor, 0, 2);
	if (ctl_cmd == NULL)
		error_handler(*cursor, NULL, 12);
	(*cursor) += 2;
	if (*ptr == NULL || lexer == 64 || lexer == 128)
		syntax_error(&lexer, ctl_cmd);
	else
	{
		lexer = CTL_CMD;
		temp = new_tree_node(lexer, ctl_cmd);
		(*ptr) = add_tree_front(*ptr, temp);
		*end_ptr = temp;
	}
	return (lexer);
}
