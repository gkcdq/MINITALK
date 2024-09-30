/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:49:17 by tmilin            #+#    #+#             */
/*   Updated: 2024/09/30 14:45:42 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define BUFFER_SIZE
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

// server.c
void	bit_signal(int bit);

// client.c
void	send_char(pid_t pid, char c);

#endif
