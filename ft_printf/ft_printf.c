/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:10:31 by isabri            #+#    #+#             */
/*   Updated: 2021/12/11 03:02:21 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(va_list ap, int *ret, char format)
{
	if (format == ' ')
		return ;
	else if (format == 'c')
		ft_putchar(va_arg(ap, int), ret);
	else if (format == 's')
		ft_putstr(va_arg(ap, char *), ret);
	else if (format == 'd')
		ft_putnbr_d(va_arg(ap, int), ret);
	else if (format == 'i')
		ft_putnbr_i(va_arg(ap, int), ret);
	else if (format == 'u')
		ft_putnbr_u(va_arg(ap, unsigned int), ret);
	else if (format == 'x')
		ft_putnbr_hexl(va_arg(ap, unsigned int), ret);
	else if (format == 'X')
		ft_putnbr_hexu(va_arg(ap, unsigned int), ret);
	else if (format == 'p')
		ft_putaddr(va_arg(ap, void *), ret);
	else if (format == '%')
		ft_putchar('%', ret);
	else
		ft_putstr(&format, ret);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		ret;

	va_start(args, s);
	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			check_format(args, &ret, s[++i]);
		}
		else
			ft_putchar(s[i], &ret);
		if (s[i])
			i++;
	}
	va_end(args);
	return (ret);
}
