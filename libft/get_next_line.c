/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:35:07 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/17 13:15:25 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*extra_buffer(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = ft_calloc(ft_strlen(str) + 1000, 1);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	free (str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	t_u			u;
	char		character;
	char		*buffer;

	u.i = 0;
	u.j = 1;
	buffer = ft_calloc(1000, sizeof(char));
	while (1)
	{
		u.j = read(fd, &character, 1);
		if (!u.j)
			break ;
		buffer[u.i++] = character;
		if (character == '\n')
			break ;
		if (u.i > (u.i / 1000) * 1000)
			buffer = extra_buffer(buffer);
	}
	if ((!buffer[u.i - 1] && !u.j) || u.j == -1)
	{
		free (buffer);
		return (NULL);
	}
	buffer[u.i] = '\0';
	return (buffer);
}
