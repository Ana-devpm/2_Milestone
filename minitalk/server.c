/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:47:20 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/17 16:32:08 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
# include "utils/libft/libft.h"
# include "utils/ft_printf/ft_printf.h"

t_bit_buffer	g_buffer = {0, 0};

static void	handler_bit(int sig)
{
	(void)context;
	
	if (sig == SIGUSR1)
    {
        g_buffer.byte = g_buffer.byte << 1;
    }
    else if
    {
        g_buffer.byte = (g_buffer.byte << 1) | 1; 
    }
    g_buffer.bite++;
}

static void process_byte()
{
     if (byte == '\0')
    {
        write(1, "\nMensaje recibido: ", 19);
        write(1, &byte, 1);
        printf("\nMensaje recibido completamente.\n");
        exit(0);
    }
    else
    {
        write(1, &byte, 1);
    }
}

static void signal_handler(int sig, siginfo_t *info, void *context)
{
    handler_bit(sig);

    if (g_buffer.bit == 8)
    {
        process_byte(g_buffer.byte);
        g_buffer.byte = 0;
        g_buffer.bit = 0;
    }
}

int main (void)
{
   struct sigaction sa;

    // Configuración del manejador de señales
    sa.sa_flags = SA_SIGINFO;  // Usamos SA_SIGINFO para obtener más información sobre la señal
    sa.sa_sigaction = signal_handler;  // La función que manejará las señales
    sigemptyset(&sa.sa_mask);  // No bloqueamos ninguna señal adicional

    // Configurar los manejadores para SIGUSR1 y SIGUSR2
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_printf("Error al configurar SIGUSR1");
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("Error al configurar SIGUSR2");
        exit(EXIT_FAILURE);
    }

    printf("Servidor iniciado. PID: %d\n", getpid());

    while (1)
    {
        pause();
    }
    return 0;
}