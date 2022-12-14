/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:44:06 by jmorneau          #+#    #+#             */
/*   Updated: 2022/10/25 12:06:53 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{	
		if (num < 10)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num - 10 + 'a', 1);
	}
}

int	ft_printf_ptr(unsigned long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write (1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
