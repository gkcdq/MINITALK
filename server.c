/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:49:28 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/11 15:00:33 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum)
{
	static int	i;
	static int	bit;

	if (signum == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		i = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("\n    Usage : ./server\n\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\n    PID : %d\n\n", pid);
	while (!0)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}

// CODE DU PREMIER PUSH.

/*
#include "minitalk.h"

void	bit_signal(int bit)
{
	static int	count_bit = 0;
	static char	c = 0;

	if (bit == SIGUSR1)
		c = c << 1;
	else if (bit == SIGUSR2)
		c = (c << 1) | 1;
	count_bit++;
	if (count_bit == 8)
	{
		ft_printf("%c", c);
		count_bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int    pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("\n    Usage : ./server\n\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\n    PID : %d\n\n", pid);
	signal(SIGUSR1, bit_signal);
	signal(SIGUSR2, bit_signal);
	while (1)
	{
		pause();
	}
	return (0);
}*/
