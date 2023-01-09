/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:40:09 by yajallal          #+#    #+#             */
/*   Updated: 2023/01/09 17:40:23 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_perror(int fd, char *s, ...)
{
	va_list	par;
	int		i;

	va_start(par, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 's')
				ft_putstr_fd(va_arg(par, char *), fd);
		}
		else
			ft_putchar_fd(s[i], fd);
		if (s[i])
			i++;
	}
}
