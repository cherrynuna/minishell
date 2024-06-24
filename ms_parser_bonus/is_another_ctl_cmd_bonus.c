/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_another_ctl_cmd_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:02:25 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:33:59 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_bonus.h"

void	is_another_ctl_cmd(int *lexer, char **cursor)
{
	char	*str;
	int		val;

	if (*lexer == INT_MIN)
		return ;
	val = is_control_oprator(*cursor);
	if (val != 0)
	{
		str = ft_substr(*cursor, 0, val);
		syntax_error(lexer, str);
	}
}
