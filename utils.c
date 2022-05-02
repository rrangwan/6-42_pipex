/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:22:26 by rrangwan          #+#    #+#             */
/*   Updated: 2022/03/14 13:09:32 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *s, int e)
{
	perror(s);
	exit (e);
}

int	ft_path_sub(char **envp)
{
	int		i;
	int		stop;

	i = 0;
	stop = 0;
	while (envp[i] && !stop)
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T')
			stop = 1;
		i++;
	}
	return (i - 1);
}

char	*ft_path(char *cmd, char **envp)
{
	int		i;
	char	**path;
	char	*ret_a;
	char	*ret;

	i = ft_path_sub(envp);
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		ret_a = ft_strjoin(path[i], "/");
		ret = ft_strjoin(ret_a, cmd);
		free (ret_a);
		if (access(ret, F_OK) == 0)
			return (ret);
		free(ret);
		i++;
	}
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	return (cmd);
}

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
