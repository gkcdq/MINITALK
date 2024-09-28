/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:49:02 by tmilin            #+#    #+#             */
/*   Updated: 2024/09/28 16:05:04 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int				pid;
	char			*message;

	if (ac != 3)
	{
		ft_printf("\n\tUsage : ./client PID <message>\n\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	return (0);
}
