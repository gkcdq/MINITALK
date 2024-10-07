/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:49:28 by tmilin            #+#    #+#             */
/*   Updated: 2024/09/30 19:53:44 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*buffer = NULL;

void	free_buffer(char *buffer)
{
	if (buffer)
		free(buffer);
}



void	bit_signal(int bit)
{
	static int	count_bit;
	static int	c;
	static int	i = 0;
	static int	j = 0;
	static int	buffer_size = 2;
	char		*new_buffer;

	if (!buffer)
		buffer = malloc(sizeof(char) * buffer_size + 1);
	if (bit == SIGUSR1)
		c |= (0x01 << count_bit);
	count_bit++;
	if (count_bit == 8)
	{
		if (c == '\0')
		{
			ft_printf("\0");
			ft_printf("%s", buffer);
			free_buffer(buffer);
			exit(0);
		}
		buffer[i] = c;
		count_bit = 0;
		c = 0;
		i++;
		j++;
		if (i >= buffer_size)
		{
			buffer_size *= 2;
			new_buffer = realloc(buffer, sizeof(char) * buffer_size + 1);
			if (!new_buffer)
			{
				free_buffer(buffer);
				exit(1);
			}
			buffer = new_buffer;
		}
	}
	if (j == 2)
	{
		buffer[i] = '\0';
		ft_printf("%s", buffer);
		j = 0;
		i = 0;
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
	signal(SIGINT, free_buffer);
	while (1)
	{
		pause();
	}
	free_buffer(buffer);
	return (0);
}



/*if (j > 2 && c == '\0')
		{
			buffer[i] = '\0';
			ft_printf("%s", buffer);
			free_buffer(buffer);
			return ;
		}*/

/*void	bit_signal(int bit)
{
	static int	count_bit;
	static int	c;
	static int	i = 0;
	static int	j = 0;
	static int	buffer_size = 2;

	if (!buffer)
		buffer = malloc(sizeof(char) * buffer_size + 1);
	if (bit == SIGUSR1)
		c |= (0x01 << count_bit);
	count_bit++;
	if (count_bit == 8)
	{
		if (j != 100 && c == '\0')
		{
			ft_printf("%s", buffer);
		}
		if (c == '\0')
		{
			ft_printf("\0");
			free_buffer(buffer);
			return ;
		}
		buffer[i] = c;
		//ft_printf("%c", buffer[i]);
		count_bit = 0;
		c = 0;
		i++;
		j++;
	//	ft_printf("%d\n", j);
	}
	if (j == 2)
	{
		buffer[i] = '\0';
		ft_printf("%s", buffer);
		char *new_buffer = realloc(buffer, sizeof(char) * buffer_size + 1);
		if (!buffer)
		{
			free(buffer);
			exit(0) ;
		}
		buffer = new_buffer;
		j = 0;
	}
}*/
