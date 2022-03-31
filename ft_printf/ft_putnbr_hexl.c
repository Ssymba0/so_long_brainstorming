/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:43:33 by isabri            #+#    #+#             */
/*   Updated: 2021/12/02 18:53:25 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexl(unsigned int n, int *ret)
{
	if (n >= 16)
	{
		ft_putnbr_hexl(n / 16, ret);
		ft_putnbr_hexl(n % 16, ret);
	}
	else if (n < 16)
	{
		if (n < 16 && n > 9)
			ft_putchar(n + 87, ret);
		else if (n < 10)
			ft_putchar(n + 48, ret);
	}
}
