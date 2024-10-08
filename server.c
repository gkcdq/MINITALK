/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:49:28 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/08 12:42:21 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	g_buffer[BUFFER_SIZE + 1];

void	buffer_s(void)
{
	ft_printf("\n%s", g_buffer);
	g_buffer[0] = '\0';
}

void	fill_buffer(char c)
{
	static int	buffer_index = 0;

	if (buffer_index < BUFFER_SIZE - 1)
	{
		g_buffer[buffer_index] = c;
		buffer_index++;
		g_buffer[buffer_index] = '\0';
	}
	if (buffer_index >= BUFFER_SIZE - 1)
	{
		buffer_s();
		buffer_index = 0;
	}
}

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
		if (c == '\0')
		{
			buffer_s();
		}
		else
		{
			fill_buffer(c);
		}
		count_bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("\n	Usage : ./server\n\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\n	PID : %d\n\n", pid);
	signal(SIGUSR1, bit_signal);
	signal(SIGUSR2, bit_signal);
	while (1)
	{
		pause();
	}
	return (0);
}

//CODE DU PREMIER PUSH (SANS BUFFER).

/*
#include "minitalk.h"

void    bit_signal(int bit)
{
    static int    count_bit = 0;
    static char    c = 0;

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

int    main(int ac, char **av)
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
