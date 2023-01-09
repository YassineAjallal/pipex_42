/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:57:37 by yajallal          #+#    #+#             */
/*   Updated: 2023/01/09 23:21:54 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_child(int input, int *fd_pipe, char **av, char **envp)
{
	char	**cmd;
	char	*fpath;

	dup2(input, STDIN_FILENO);
	close(input);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	cmd = ft_quotes(av[2]);
	fpath = ft_cmdpath(cmd[0], envp);
	if (!fpath)
	{
		ft_perror(2, "pipex: %s: command not found\n", cmd[0]);
		exit(127);
	}
	ft_checkx(fpath);
	execve(fpath, cmd, envp);
}

void	ft_parent(int output, int *fd_pipe, char **av, char **envp)
{
	char	**cmd;
	char	*fpath;

	dup2(fd_pipe[0], STDIN_FILENO);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	dup2(output, STDOUT_FILENO);
	close(output);
	cmd = ft_quotes(av[3]);
	fpath = ft_cmdpath(cmd[0], envp);
	if (!fpath)
	{
		ft_perror(2, "pipex: %s: command not found\n", cmd[0]);
		exit(127);
	}
	ft_checkx(fpath);
	execve(fpath, cmd, envp);
	exit(0);
}

int	main(int ac, char **av, char **envp)
{
	int	fd_pipe[2];
	int	pid;
	int	input;
	int	output;

	if (ac != 5)
		ft_errors("we just need 5 arguments", 1);
	if (pipe(fd_pipe) < 0)
		ft_errors("pipe : ERROR -> piping error", 1);
	pid = fork();
	if (pid < 0)
		ft_errors("pipex: fork: forking error", 1);
	if (pid == 0)
	{
		input = open(av[1], O_RDONLY);
		if (input < 0)
			ft_errors("pipex: input: No such file or directory", 1);
		ft_infile(av[1]);
		ft_child(input, fd_pipe, av, envp);
	}
	output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output < 0)
		ft_errors("open : ERROR -> opening error", 1);
	ft_outfile(av[4]);
	ft_parent(output, fd_pipe, av, envp);
}
