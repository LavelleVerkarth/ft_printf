/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:20:40 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/05 09:20:53 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfft.h"

char	*ft_char_type_precision(char *ret, int prec)
{
	char	*pret;
	int		i;

	pret = malloc(sizeof(char) * (prec + 1));
	if (!pret)
		return (NULL);
	pret[prec] = '\0';
	i = -1;
	while (++i < prec)
		pret[i] = ret[i];
	free(ret);
	return (pret);
}

char	*ft_char_type(t_list *specif, char c)
{
	char	*str;

	if (c == '\0')
	{
		c = '\n';
		specif->charnull++;
	}
	if (c == 0)
		specif->width--;
	str = malloc(sizeof(char) + 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	if (specif->width > 0 && specif->zero)
		str = ft_int_type_precision(str, specif->width);
	else if (specif->width > 0)
		str = ft_int_type_width(str, specif);
	return (str);
}

char	*ft_string_type(t_list *specif, char *c)
{
	char	*ret;

	if (!c)
		ret = ft_strdup("(null)");
	else
		ret = ft_strdup(c);
	if (specif->precision <= 0 && specif->point)
	{
		free(ret);
		ret = ft_strdup("");
	}
	if (specif->precision > 0 && !specif->minprec
		&& specif->precision < ft_strlen(ret))
		ret = ft_char_type_precision(ret, specif->precision);
	if (specif->width > 0 && specif->zero)
		ret = ft_int_type_precision(ret, specif->width);
	else if (specif->width > 0)
		ret = ft_int_type_width(ret, specif);
	return (ret);
}
