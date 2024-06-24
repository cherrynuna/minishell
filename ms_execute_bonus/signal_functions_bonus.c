/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 03:28:07 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/16 14:32:33 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute_bonus.h"

void	signal_def(int sig)
{
	if (sig)
		return ;
}

static void	sigint_handler(int sig)
{
	if (sig != SIGINT)
		return ;
	g_signal = SIGINT;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \b\b", 1);
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	sigquit_handler(int sig)
{
	if (sig != SIGQUIT)
		return ;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \b\b", 1);
}

void	signal_second(int sig)
{
	if (sig == SIGINT)
	{
		g_signal = 1;
		rl_on_new_line();
		rl_redisplay();
		ft_printf ("b\b  \n");
		exit(1);
	}
	if (sig == SIGQUIT)
		ft_printf ("\b\b  \b\b");
}

void	signal_on(int type)
{
	if (type == 0)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, sigquit_handler);
	}
	if (type == 1)
	{
		signal(SIGINT, signal_second);
		signal(SIGQUIT, sigquit_handler);
	}
	if (type == 2)
	{
		signal(SIGINT, signal_def);
		signal(SIGQUIT, signal_def);
	}
	if (type == 3)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
