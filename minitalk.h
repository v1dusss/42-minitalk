/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:08:02 by vsivanat          #+#    #+#             */
/*   Updated: 2024/03/14 17:06:17 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>

typedef struct s_server
{
	int				bit;
	int				i;
	int				begin;
	int				count;
	char			c;
	char			*str;
}	t_server;

typedef struct s_client
{
	int				received;
}	t_client;

#endif
