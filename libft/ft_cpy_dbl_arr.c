/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_dbl_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:18:00 by anonymous         #+#    #+#             */
/*   Updated: 2022/10/31 14:16:35 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	len_dbl_array(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

char	**ft_cpy_dbl_arr(char **matrix)
{
	char	**retour;
	size_t	len_array;
	int		i;

	i = 0;
	len_array = len_dbl_array(matrix);
	retour = ft_calloc(len_array + 1, sizeof(char *));
	while (matrix[i])
	{
		retour[i] = ft_strdup2(matrix[i]);
		i++;
	}
	return (retour);
}
