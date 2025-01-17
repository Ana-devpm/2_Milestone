/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:47:17 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/17 16:48:32 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "utils/libft/libft.h"
#include "utils/ft_printf/ft_printf.h"
//Send_bits, tell us what signal do we send depending on the bit.
//SIGUSR1 for 0 and SIGUSR2 for 1.
static void	send_bits(pid_t pid, int bit)
{
	if (bit == 0)
	{
		kill(pid, SIGUSR1);
	}
	else
	{
		kill(pid, SIGUSR2);
	}
}

//Send the message bit by bit.
static void	send_message(pid_t pid, char *message)
{
	char	text;
	int		index;
	int		bit;
	int		i;

	text = *message;
	index = 7;
	i = 0;
	while (*message)
	{
		while (index >= 0)
		{
			bit = (text >> index) & 1;
			send_bits(pid, bit);
			usleep(100);
			index--;
		}
		message++;
	}
}

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Uso: ./client <PID del servidor> <mensaje>\n");
		return 1; 
	}
	
	pid_t server_pid = ft_atoi(argv[1]);  // Convertimos el PID del servidor
    if (server_pid <= 0)  // Verificamos si el PID es válido
    {
        ft_printf("PID del servidor no válido.\n");
        exit(EXIT_FAILURE);
    }

    char *message = argv[2];  // El mensaje a enviar

    // Llamamos a la función para enviar el mensaje al servidor
    send_message(server_pid, message);

    printf("Mensaje enviado al servidor con PID %d: %s\n", server_pid, message);

	return (0);
}