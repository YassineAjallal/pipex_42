/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:57:54 by yajallal          #+#    #+#             */
/*   Updated: 2023/01/09 23:01:21 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdarg.h>
# include "./libft/libft.h"

void	ft_perror(int fd, char *s, ...);

char	*ft_cmdpath(char *cmd, char **envp);
char	**ft_envp(char **envp);

void	ft_infile(char *infile);
void	ft_outfile(char *outfile);
void	ft_checkx(char *cmd);
char **ft_quotes(char *cmd);

void	ft_parent(int output, int *fd_pipe, char **av, char **envp);
void	ft_child(int input, int *fd_pipe, char **av, char **envp);

#endif
