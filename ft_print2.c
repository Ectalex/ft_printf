/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:58:05 by albriffa          #+#    #+#             */
/*   Updated: 2023/10/31 10:37:46 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hex(unsigned long long number, unsigned int base, size_t len, char x)
{
	char					*hexa;
	unsigned long long		n;

	n = number;
	if (x == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	while (n >= 16)
	{
		n /= base;
		len++;
	}
	if (number >= base)
		ft_hex((number / base), base, len, x);
	len = ft_putchar_fd(hexa[number % base], 1, len);
	return (len);
}

size_t	ft_printp(unsigned long long nu, unsigned int b, size_t l, size_t n)
{
	char					*hexa;
	unsigned long long		k;

	k = nu;
	hexa = "0123456789abcdef";
	if (nu == 0)
	{
		write (1, "(nil)", 5);
		return (l + 3);
	}
	if (n == 0)
	{
		write (1, "0x", 2);
		n++;
	}
	if (nu >= b)
		l = ft_printp((nu / b), b, l, 1);
	l = ft_putchar_fd(hexa[nu % b], 1, l);
	return (l);
}
