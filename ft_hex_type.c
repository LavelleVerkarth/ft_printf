/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:20:06 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/05 12:20:07 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfft.h"

char	*ft_translete_hex(int hex)
{
	int		h;
	int		i;
	char	*rhex;

	h = hex;
	i = 0;
	while (h > 0)
	{
		h /= 16;
		i++;
	}
	rhex = malloc(sizeof(char) + (i + 1));
	if (!rhex)
		return (NULL);
	rhex[i] = '\0';
	while (--i >= 0)
	{
		h = hex % 16;
		if (h >= 10)
			rhex[i] = 87 + h;
		else
			rhex[i] = '0' + h;
		hex /= 16;
	}
	return (rhex);
}

char	*ft_translete_neg_hex(int hex)
{
	int		h;
	int		i;
	char	*rhex;

	i = 8;
	rhex = ft_strdup("80000000");
	while (--i > 0)
	{
		h = hex % 16;
		if (h >= 10)
			rhex[i] = 87 + h;
		else
			rhex[i] = '0' + h;
		hex /= 16;
	}
	h = (hex + 8) % 16;
	if (h >= 10)
		rhex[i] = 87 + h;
	else
		rhex[i] = '0' + h;
	hex /= 16;
	return (rhex);
}

char	*ft_hex_type(t_list *specif, int hex)
{
	char	*ret;

	if (hex == 0)
		ret = ft_int_type(specif, hex);
	else if (hex > 0)
		ret = ft_translete_hex(hex);
	else
		ret = ft_translete_neg_hex(hex + 2147483648);
	if (specif->precision > 0 && !specif->minprec)
		ret = ft_int_type_precision(ret, specif->precision);
	if (specif->width > 0 && specif->zero
		&& ((specif->precision <= 0 && !specif->point) || specif->minprec))
		ret = ft_int_type_precision(ret, specif->width);
	else if (specif->width > 0)
		ret = ft_int_type_width(ret, specif);
	return (ret);
}

char	*ft_Hhex_type(t_list *specif, int hex)
{
	char	*ret;
	int		i;

	ret = ft_hex_type(specif, hex);
	i = 0;
	while (ret[i])
	{
		if (ret[i] >= 97 && ret[i] <= 122)
			ret[i] = ret[i] - 32;
		i++;
	}
	return (ret);
}
