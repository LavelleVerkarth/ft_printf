/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 23:09:01 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/07 23:09:03 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfft.h"

char	*ft_parse_type(const char **str, t_list *specif, va_list ap)
{
	char	*ret;

	if (**str == 'd' || **str == 'i')
		ret = ft_int_type(specif, va_arg(ap, int));
	else if (**str == 'u')
		ret = ft_unsigned_int_type(specif, va_arg(ap, unsigned int));
	else if (**str == 'c')
		ret = ft_char_type(specif, va_arg(ap, int));
	else if (**str == 's')
		ret = ft_string_type(specif, va_arg(ap, char *));
	else if (**str == 'p')
		ret = ft_poiner_type(specif, va_arg(ap, unsigned long long));
	else if (**str == 'x')
		ret = ft_hex_type(specif, va_arg(ap, int));
	else if (**str == 'X')
		ret = ft_Hhex_type(specif, va_arg(ap, int));
	else if (**str == '%')
		ret = ft_char_type(specif, '%');
	else
		return (ft_strdup(""));
	(*str)++;
	return (ret);
}
