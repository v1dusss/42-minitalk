/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:57:30 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/14 17:37:13 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	clear_server_struct(t_server *server)
{
	server->i = 0;
	server->bit = 0;
	server->str = NULL;
	server->c = 0;
	server->begin = 1;
}

void	if_8_bit(t_server *server, siginfo_t *info)
{
	server->str[server->i] = server->c;
	if (server->c == 0)
	{
		ft_printf("%s", server->str);
		free(server->str);
		server->begin = 0;
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	server->c = 0;
	server->bit = 0;
	server->i++;
	server->count++;
}

void	expand_str(t_server *server, siginfo_t *info)
{
	char	*temp;

	temp = ft_calloc(ft_strlen(server->str) + 100, sizeof(char));
	if (temp == NULL)
	{
		ft_printf("Error: Memory allocation failed\n");
		free(server->str);
		kill(info->si_pid, SIGUSR2);
		exit(1);
	}
	ft_strlcpy(temp, server->str, ft_strlen(server->str) + 1);
	free(server->str);
	server->str = temp;
	server->count = 0;
}

void	catch_massage(int sig, siginfo_t *info, void *ucontext)
{
	static t_server	server;

	(void)ucontext;
	if (server.begin == 0)
	{
		clear_server_struct(&server);
		server.str = ft_calloc(100 + 1, sizeof(char));
		if (server.str == NULL)
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf("Error: Memory allocation failed");
			exit(1);
		}
	}
	if (sig == SIGUSR1)
		server.c |= (1 << server.bit);
	if (++server.bit == 8)
	{
		if_8_bit(&server, info);
		if (server.begin == 0)
			return ;
		if (server.count >= 99)
			expand_str(&server, info);
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;
	struct sigaction	sa_msg;

	if (argc != 1)
		return (ft_printf("Usage: %s\n", argv[0]));
	sa_msg.sa_sigaction = catch_massage;
	sa_msg.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_msg, NULL);
	sigaction(SIGUSR2, &sa_msg, NULL);
	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	while (1)
		pause();
	return (0);
}
