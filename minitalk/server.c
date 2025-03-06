/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:47:20 by afailde-          #+#    #+#             */
/*   Updated: 2025/03/04 12:17:01 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit_buffer	g_buffer = {0, 0, NULL};

static void	reset_buffer(void)
{
	g_buffer.byte = 0;
	g_buffer.bit = 0;

	if(g_buffer.str)
	{
		free(g_buffer.str);
		g_buffer.str = NULL;
	}
}

static void	handler_bit(int sig)
{
	if (sig == SIGUSR1)
		g_buffer.byte = g_buffer.byte << 1;
	else if (sig == SIGUSR2)
		g_buffer.byte = (g_buffer.byte << 1) | 1;
	g_buffer.bit++;
}
static char	*malloc_build_str(char	*str, char byte)
{
	int		len;
	char	*final_str;
	
	len = 0;
	if (str)
		len = ft_strlen(str);
	final_str = malloc((len + 2) * sizeof(char));
	if (!final_str)
		return (NULL);
	if (final_str)
	{
		ft_memcpy(final_str, str, len);
		free(str);
	}
	final_str[len] = byte;
	final_str[len + 1] = '\0';
	return (final_str);
}
static void	process_byte(siginfo_t *info)
{
	unsigned char	byte;

	byte = g_buffer.byte;
	if (byte == '\0')
	{
		ft_printf("\nMessage: %s\n", g_buffer.str);
		if (info && info->si_pid)
			kill(info->si_pid, SIGUSR1);
		reset_buffer();
	}
	else
		g_buffer.str = malloc_build_str(g_buffer.str, byte);
	g_buffer.byte = 0;
	g_buffer.bit = 0;
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
