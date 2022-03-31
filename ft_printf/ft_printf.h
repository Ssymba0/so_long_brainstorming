/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabri <isabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:07:07 by isabri            #+#    #+#             */
/*   Updated: 2022/03/31 18:56:22 by isabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int		ft_strlen(char *s);	
int		ft_printf(const char *s, ...);
void	ft_putchar(char c, int *ret);
void	ft_putstr(char *s, int *ret);
void	ft_putnbr_d(int n, int *ret);
void	ft_putnbr_i(int n, int *ret);
void	ft_putnbr_u(unsigned int n, int *ret);
void	ft_putnbr_hexl(unsigned int n, int *ret);
void	ft_putnbr_hexu(unsigned int n, int *ret);
void	ft_putaddr(void *n, int *ret);
#endif
