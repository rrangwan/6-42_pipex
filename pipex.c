/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:22:11 by rrangwan          #+#    #+#             */
/*   Updated: 2022/05/02 13:56:56 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char *s, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = 0;
	cmd = ft_split(s, ' ');
	path = ft_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
		ft_error ("Unable to find path", 1);
	}
	if (execve(path, cmd, envp) == -1)
		ft_error ("command not found", 127);
}

void	ft_child(int *fd, char **argv, char **envp)
{
	int		file1;

	file1 = open(argv[1], O_RDONLY, 0777);
	if (file1 < 0)
		ft_error ("Unable to open File1", 1);
	close(fd[0]);
	dup2(fd[1], 1);
	dup2(file1, 0);
	ft_exec(argv[2], envp);
}

void	ft_parent(int *fd, char **argv, char **envp)
{
	int		file2;

	file2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (file2 < 0)
		ft_error("Unable to open File2", 1);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(file2, 1);
	ft_exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error ("Error with Pipe", 1);
		pid = fork();
		if (pid == -1)
			ft_error ("Error with Fork", 1);
		if (pid == 0)
			ft_child(fd, argv, envp);
		ft_parent(fd, argv, envp);
	}
	else
		ft_error ("Wrong arguments.\"./pipex file1 cmd1 cmd2 file2\"", 1);
	return (1);
}
