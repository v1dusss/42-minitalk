/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:57:30 by vsivanat          #+#    #+#             */
/*   Updated: 2024/02/04 14:21:37 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	decode_char(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int main(int argc, char **argv)
{
	int	pid;
	
	if (argc == 1)
	{
		pid = getpid9();
		ft_printf("PID: %d\n", pid);
		while (argc = 1)
		{
			signal(SIGUSR1, decode_char);
			signal(SIGUSR2, decode_char);
			pause();
		}
		return (0);
	}
	ft_printf("no commans are suportet\n");
	return (0);
}
 
// int	main(int argc, char **argv)
// {
// 	int	pid;

// 	(void)argv;
// 	if (argc != 1)
// 	{
// 		ft_printf("Wrong number of arguments\n");
// 		return (0);
// 	}
// 	pid = getpid();
// 	ft_printf("%d\n", pid);
// 	while (argc == 1)
// 	{
// 		signal(SIGUSR1, decode_char);
// 		signal(SIGUSR2, decode_char);
// 		pause();
// 	}
// 	return (0);
// }
