/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:49:17 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/08 12:33:25 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# define BUFFER_SIZE 200000
// server.c
void	bit_signal(int bit);

// client.c
void	send_char(int pid, char c);

#endif
