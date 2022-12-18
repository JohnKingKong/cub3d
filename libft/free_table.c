/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:29:07 by jmorneau          #+#    #+#             */
/*   Updated: 2022/12/18 14:37:53 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_free_chartable(char **table)
{
	int	i;

	i = 0;
	while (table && table[i])
	{
		free(table[i]);
		i++;
	}
	free(table[i]);
		free(table);
}
