/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:00:51 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/05 21:00:52 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfft.h"

char	*ft_translete_point(unsigned long long hex)
{
	int		h;
	int		i;
	char	*rhex;
	char	*tmp;

	rhex = ft_strdup("00000000000000000000");
	if (!rhex)
		return (NULL);
	i = 20;
	while (--i >= 0)
	{
		h = hex % 16;
		if (h >= 10)
			rhex[i] = 87 + h;
		else
			rhex[i] = '0' + h;
		hex /= 16;
	}
	i = 0;
	while (rhex[i] == '0')
		i++;
	tmp = ft_strdup(&rhex[i]);
	free(rhex);
	return (tmp);
}

char	*ft_poiner_type(t_list *specif, unsigned long long hex)
{
	char	*ret;
	char	*tmp;

	if (!hex)
		specif->final = 1;
	if (hex == 0)
		ret = ft_strdup("0");
	else
		ret = ft_translete_point(hex);
	if (specif->precision > 0 && !specif->minprec)
		ret = ft_int_type_precision(ret, specif->precision);
	tmp = ft_strjoin("0x", ret);
	free(ret);
	ret = tmp;
	if (specif->precision == 0 && specif->point && specif->final)
	{
		free(ret);
		ret = ft_strdup("0x");
	}
	if (specif->width > 0 && specif->zero && !specif->precision)
		ret = ft_int_type_precision(ret, specif->width);
	else if (specif->width > 0)
		ret = ft_int_type_width(ret, specif);
	return (ret);
}
