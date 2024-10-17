/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:49:02 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/11 14:57:44 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bits(pid_t pid, char s)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((s & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Wrong number of argument\n");
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (message[i] != '\0')
	{
		send_bits(pid, message[i]);
		i++;
	}
	send_bits(pid, '\n');
	return (0);
}

// CODE DU PREMIER PUSH.

/*#include "minitalk.h"

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
	int                i;
	int                pid;
	char            *message;

	if (ac != 3)
	{
		ft_printf("\n\tUsage : ./client PID ""message""\n\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid != ft_atoi(av[1]))
		return (0);
	message = av[2];
	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	return (0);
}*/
