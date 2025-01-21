/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:47:17 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/21 12:15:58 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
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
	usleep(100);
}

//Send the message bit by bit.
static void	send_message(pid_t pid, char *message)
{
	int		bit;
	int		index;

	while (*message)
	{
		index = 7;
		while (index >= 0)
		{
			bit = (*message >> index) & 1;
			send_bits(pid, bit);
			index--;
		}
		message++;
	}
	index = 7;
	while (index >= 0)
	{
		bit = (0 >> index) & 1;
		send_bits(pid, bit);
		index--;
	}
}

int	is_valid_pid(char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: ./client <server PID> <message>\n");
		return 1; 
	}
	
	if (!is_valid_pid(argv[1]))
    {
        ft_printf("Error: Server PID is not a valid number.\n");
        return (1);
    }

	pid_t server_pid = ft_atoi(argv[1]); // Convertir el argumento a un número
    if (server_pid <= 0) // Verificar que el PID sea mayor que 0
    {
        ft_printf("Error: Invalid server PID. Try Again.\n");
        return (1);
    }

    // Verificar si el PID pertenece a un proceso activo
    if (kill(server_pid, 0) == -1)
    {
        ft_printf("Error: Unable to verify the server.");
        return (1);
    }
	
    char *message = argv[2];
    send_message(server_pid, message);

    printf("Message sent to the server with PID %d: %s\n", server_pid, message);

	return (0);
}