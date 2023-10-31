/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:23:18 by albriffa          #+#    #+#             */
/*   Updated: 2023/10/31 10:29:27 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_choice(const char format, va_list args, size_t len)
{
	if (format == 'c')
		len = ft_printc(va_arg(args, int), len);
	else if (format == 's')
		len = ft_prints(va_arg(args, char *), len);
	else if (format == 'p')
	{
		len = ft_printp(va_arg(args, unsigned long long), 16, len, 0);
		len += 2;
	}
	else if (format == 'd' || format == 'i')
		len = ft_printd(va_arg(args, int), len);
	else if (format == 'u')
		len = ft_printu(va_arg(args, unsigned int), len);
	else if (format == 'x')
		len = ft_hex(va_arg(args, unsigned int), 16, len, 'x');
	else if (format == 'X')
		len = ft_hex(va_arg(args, unsigned int), 16, len, 'X');
	else if (format == '%')
		len = ft_putchar_fd('%', 1, len);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = ft_choice(format[i + 1], args, len);
			len -= 2;
			i += 2;
		}
		else
		{
			len = ft_putchar_fd(format[i], 1, len);
			i++;
			len--;
		}
	}
	va_end(args);
	i += len;
	return (i);
}
/*
#include <limits.h>

int	main(void)
{
	int	i;
	int	j;

	i = printf(" %u \n", LONG_MIN);
	j = ft_printf(" %u \n", LONG_MIN);
	printf("%d\n", i);
	printf("%d", j);
}*/
