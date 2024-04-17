/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almedetb <almedetb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:03:14 by almedetb          #+#    #+#             */
/*   Updated: 2024/01/28 14:47:21 by almedetb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_conversions(va_list ar, char ch);
int	ft_putchar(char ch);
int	ft_putstr(char *str);
int	ft_putuint(unsigned int n);
int	ft_putnbr(int n);
int	ft_puthex(unsigned int n, char ch);
int	ft_putpointer(unsigned long n);
int	ft_lenpointer(unsigned long n);

#endif