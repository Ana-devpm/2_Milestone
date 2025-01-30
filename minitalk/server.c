/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:47:20 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/23 11:37:17 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit_buffer	g_buffer = {0, 0};

static void	reset_buffer(void)
{
	g_buffer.byte = 0;
	g_buffer.bit = 0;
}

static void	handler_bit(int sig)
{
	if (sig == SIGUSR1)
		g_buffer.byte = g_buffer.byte << 1;
	else if (sig == SIGUSR2)
		g_buffer.byte = (g_buffer.byte << 1) | 1;
	g_buffer.bit++;
}

static void	process_byte(siginfo_t *info)
{
	unsigned char	byte;

	byte = g_buffer.byte;
	if (byte == '\0')
	{
		ft_printf("\nMessage received.\n");
		if (info && info->si_pid)
		{
			kill(info->si_pid, SIGUSR1);
		}
		reset_buffer();
	}
	else
	{
		write(1, &byte, 1);
		reset_buffer();
	}
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	handler_bit(sig);
	(void)context;
	if (g_buffer.bit == 8)
		process_byte(info);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR1.\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR2.\n");
		exit(EXIT_FAILURE);
	}
	printf("Server started. PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
