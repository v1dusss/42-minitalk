/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:19:14 by vsivanat          #+#    #+#             */
/*   Updated: 2024/02/10 17:08:41 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int n)
{
	if ((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z'))
		return (1);
	return (0);
}
