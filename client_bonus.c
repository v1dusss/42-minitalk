/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:58:18 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/14 17:38:26 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(char *message, int server_pid)
{
	int	i;
	int	j;

	i = -1;
	while (message[++i] != '\0')
	{
		j = -1;
		while (++j < 8)
		{
			if (message[i] & (1 << j))
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(69);
		}
	}
	j = -1;
	while (j++ < 8)
	{
		kill(server_pid, SIGUSR2);
		usleep(69);
	}
	return ;
}

void	received_message(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Message sent successfully\n");
		exit(0);
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("Message could not sent, due to an error at the server\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (argc != 3)
		return (ft_printf("Usage: %s <server_pid> <message>\n", argv[0]));
	signal(SIGUSR1, received_message);
	signal(SIGUSR2, received_message);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(message, server_pid);
	ft_printf("Waiting for server response.\n");
	pause();
	return (0);
}
