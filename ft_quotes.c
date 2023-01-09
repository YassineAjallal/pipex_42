/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:54:59 by yajallal          #+#    #+#             */
/*   Updated: 2023/01/09 23:09:27 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
char **ft_quotes(char *cmd)
{
	char c;
	char **quotes;
	int i;
	
	i = 0;
	c = 0;

	while(cmd[i])
	{
		if(cmd[i] == 39 || cmd[i] == 34)
		{
			c = cmd[i];
			break;
		}
		i++;
	}
	if (c != 0)
	{
		quotes = ft_split(cmd, c);
		quotes[0] = ft_strtrim(quotes[0], " ");
	}
	else
		quotes = ft_split(cmd, ' ');
	return (quotes);
}