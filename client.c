/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:49:02 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/08 11:46:25 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char bit)
{
	if (bit == '0')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send_bits(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> (7 - i)) & 1)
			send_bit(pid, '1');
		else
			send_bit(pid, '0');
		usleep(500);
		i++;
	}
}

void	send_message(int pid, const char *message)
{
	while (*message)
	{
		send_bits(pid, *message);
		message++;
	}
	send_bits(pid, 0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("\n\tUsage: %s <PID> <message>\n\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}

//CODE DU PREMIER PUSH (SANS BUFFER).

/*#include "minitalk.h"

void    send_char(int pid, char c)
{
    int    bit;

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

int    main(int ac, char **av)
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
