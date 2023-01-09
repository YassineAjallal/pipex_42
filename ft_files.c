/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:39:58 by yajallal          #+#    #+#             */
/*   Updated: 2023/01/09 17:36:15 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_infile(char *infile)
{
	if (access(infile, F_OK) < 0)
	{
		ft_perror(2, "%s : ERROR : file not found", infile);
		exit(0);
	}
	if (access(infile, R_OK) < 0)
	{
		ft_perror(2, "%s : ERROR -> Read Permission", infile);
		exit(0);
	}
}

void	ft_outfile(char *outfile)
{
	if (access(outfile, W_OK) < 0)
	{
		ft_perror(2, "%s : ERROR : file not found", outfile);
		exit(1);
	}
}

void	ft_checkx(char *cmd)
{
	if (access(cmd, X_OK) < 0)
	{
		ft_perror(2, "%s : ERROR -> Execute Permission", cmd);
		exit(126);
	}
}
