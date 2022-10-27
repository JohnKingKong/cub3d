/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:17:32 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/26 19:20:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup2(const char *s)
{
	char	*cs;
	int		i;

	i = 0;
	cs = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!cs)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
	{
		cs[i] = s[i];
		i++;
	}
	cs[i] = '\0';
	return (cs);
}
