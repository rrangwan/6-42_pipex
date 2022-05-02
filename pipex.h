/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:22:02 by rrangwan          #+#    #+#             */
/*   Updated: 2022/03/14 13:11:29 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

char	*ft_path(char *cmd, char **envp);
void	ft_exec(char *s, char **envp);
void	ft_child(int *fd, char **argv, char **envp);
void	ft_parent(int *fd, char **argv, char **envp);
void	ft_error(char *s, int e);
int		ft_path_sub(char **envp);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif
