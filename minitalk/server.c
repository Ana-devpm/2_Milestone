/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:47:20 by afailde-          #+#    #+#             */
/*   Updated: 2025/03/10 17:33:59 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit_buffer	g_buffer = {0, 0, NULL};

static void	reset_buffer(void)
{
	g_buffer.byte = 0;
	g_buffer.bit = 0;
}

static char	*malloc_build_str(char	*str, char byte)
{
	int		len;
	char	*final_str;

	len = 0;
	if (str)
		len = ft_strlen(str);
	final_str = ft_calloc((len + 2), sizeof(char));
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

static void	process_byte(void)
{
	char	*mssg;

	if (g_buffer.byte == '\0')
	{
		if (g_buffer.str)
		{
			write (1, g_buffer.str, ft_strlen(g_buffer.str));
			write (1, "\n", 1);
			free (g_buffer.str);
			g_buffer.str = NULL;
		}
	}
	else
	{
		mssg = malloc_build_str(g_buffer.str, g_buffer.byte);
		if (!mssg)
			exit(1);
		g_buffer.str = mssg;
	}
	reset_buffer();
}

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_buffer.byte = g_buffer.byte << 1;
	else if (sig == SIGUSR2)
		g_buffer.byte = (g_buffer.byte << 1) | 1;
	g_buffer.bit++;
	if (g_buffer.bit == 8)
		process_byte();
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server started. PID: %d\n", getpid());
	while (1)
		continue ;
	return (0);
}
