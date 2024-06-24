/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:11:33 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"
/*char *getcwd (char *buff, size_t buff_size)*/

int	ft_pwd(char **argv)
{
	char	*pwd;

	if (ft_strcmp("pwd", argv[0]) != 0)
		return (1);
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (0);
	ft_printf ("%s\n", pwd);
	free(pwd);
	return (0);
}
