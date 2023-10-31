/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:56:26 by albriffa          #+#    #+#             */
/*   Updated: 2023/10/31 10:39:44 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
size_t		ft_strlen(const char *str);
char		*ft_itoa(int n);
char		*ft_utoa(unsigned int n);
size_t		ft_printc(char c, size_t len);
size_t		ft_prints(char *str, size_t len);
size_t		ft_printd(int i, size_t len);
size_t		ft_printu(size_t i, size_t len);
size_t		ft_hex(unsigned long long nu, unsigned int b, size_t l, char x);
size_t		ft_putchar_fd(char c, int fd, size_t len);
size_t		ft_printp(unsigned long long nu,
				unsigned int b, size_t l, size_t n);

#endif
