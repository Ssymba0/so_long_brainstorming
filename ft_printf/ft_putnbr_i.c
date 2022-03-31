/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:39:40 by isabri            #+#    #+#             */
/*   Updated: 2021/12/02 18:42:11 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_i(int n, int *ret)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		*ret += 11;
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', ret);
		ft_putnbr_i(n, ret);
	}
	else if (n >= 10)
	{
		ft_putnbr_i(n / 10, ret);
		ft_putnbr_i(n % 10, ret);
	}
	else
	{
		ft_putchar(n + 48, ret);
	}
}
