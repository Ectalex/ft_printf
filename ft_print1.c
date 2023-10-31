/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:35:22 by albriffa          #+#    #+#             */
/*   Updated: 2023/10/31 10:28:51 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printc(char c, size_t len)
{
	len = ft_putchar_fd(c, 1, len);
	return (len);
}

size_t	ft_prints(char *str, size_t len)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (len + 6);
	}
	while (str[i])
	{
		len = ft_putchar_fd(str[i], 1, len);
		i++;
	}
	return (len);
}

size_t	ft_printd(int i, size_t len)
{
	size_t	n;
	char	*str;

	n = 0;
	str = ft_itoa(i);
	while (str[n])
	{
		len = ft_putchar_fd(str[n], 1, len);
		n++;
	}
	free(str);
	return (len);
}

size_t	ft_printu(unsigned long i, size_t len)
{
	size_t	n;
	char	*str;

	n = 0;
	if (i == 0)
	{
		write (1, "0", 1);
		return (len + 1);
	}
	str = ft_utoa(i);
	if (str == NULL)
	{
		write (1, "0", 1);
		return (len + 1);
	}
	while (str[n])
	{
		len = ft_putchar_fd(str[n], 1, len);
		n++;
	}
	free(str);
	return (len);
}
