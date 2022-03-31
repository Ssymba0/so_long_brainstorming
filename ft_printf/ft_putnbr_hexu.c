/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:48:27 by isabri            #+#    #+#             */
/*   Updated: 2021/12/04 02:41:56 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexu(unsigned int n, int *ret)
{
	if (n >= 16)
	{
		ft_putnbr_hexu(n / 16, ret);
		ft_putnbr_hexu(n % 16, ret);
	}
	else if (n < 16)
	{
		if (n < 16 && n > 9)
			ft_putchar(n + 55, ret);
		else if (n < 10)
			ft_putchar(n + 48, ret);
	}
}
