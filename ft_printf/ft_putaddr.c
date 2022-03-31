/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:49:27 by isabri            #+#    #+#             */
/*   Updated: 2021/12/11 03:03:06 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putaddr_hexl(unsigned long n, int *ret)
{
	if (n >= 16)
	{
		ft_putaddr_hexl(n / 16, ret);
		ft_putaddr_hexl(n % 16, ret);
	}
	else if (n < 16)
	{
		if (n < 16 && n > 9)
			ft_putchar(n + 87, ret);
		else if (n < 10)
			ft_putchar(n + 48, ret);
	}
}

void	ft_putaddr(void *n, int *ret)
{
	unsigned long	l;

	l = (unsigned long)n;
	ft_putstr("0x", ret);
	ft_putaddr_hexl(l, ret);
}
