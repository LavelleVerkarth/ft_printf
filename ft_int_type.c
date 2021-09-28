/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:04:06 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/04 15:04:07 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfft.h"

char	*ft_int_type_precision(char *ret, int p)
{
	char	*pret;
	int		i;

	if (ft_strlen(ret) > (size_t)p)
		return (ret);
	i = 0;
	if (ret[i] == '-')
		i++;
	pret = malloc(sizeof(char)* (p + 1 + i));
	if (!pret)
		return (NULL);
	pret[0] = ret[0];
	pret[p + i] = '\0';
	p = p - ft_strlen(ret) + i;
	while (i < p)
		pret[i++] = '0';
	while (ret[++i - 1 - p])
	{
		if (ret[i - 1 - p] == '-')
			pret[i - 1] = '0';
		else
			pret[i - 1] = ret[i - 1 - p];
	}
	free(ret);
	return (pret);
}

char	*ft_int_type_width(char *ret, t_list *specif)
{
	char	*wret;
	int		i;
	char	*tmp;

	if (ft_strlen(ret) > specif->width)
		return (ret);
	i = specif->width - ft_strlen(ret);
	wret = malloc(sizeof(char) * (i + 1));
	if (!wret)
		return (NULL);
	wret[i] = '\0';
	while (--i >= 0)
		wret[i] = ' ';
	if (specif->minus)
		tmp = ft_strjoin(ret, wret);
	else
		tmp = ft_strjoin(wret, ret);
	free(wret);
	free(ret);
	return (tmp);
}

void	ft_neg_uns_int_type(unsigned int u, char **ret, t_list *specif)
{
	char	*tmp;
	char	c[2];

	if (u > 2147483647)
	{
		tmp = ft_itoa(u / 10);
		c[0] = (u % 10) + '0';
		c[1] = '\0';
		*ret = ft_strjoin(tmp, c);
		free(tmp);
	}
	else
		*ret = ft_itoa(u);
	if (specif->precision > 0 && !specif->minprec)
		*ret = ft_int_type_precision(*ret, specif->precision);
}

char	*ft_unsigned_int_type(t_list *specif, unsigned int u)
{
	char	*ret;
	int		z;

	z = 1;
	if (u == 0 && specif->minprec)
		ret = ft_strdup("0");
	else if (u == 0 && specif->precision == 0 && specif->point != 0 && z--)
		ret = ft_strdup("");
	else
		ft_neg_uns_int_type(u, &ret, specif);
	if (specif->width > 0 && specif->zero && z
		&& ((specif->precision <= 0 && !specif->point) || specif->minprec))
		ret = ft_int_type_precision(ret, specif->width);
	else if (specif->width > 0)
		ret = ft_int_type_width(ret, specif);
	return (ret);
}

char	*ft_int_type(t_list *s, int di)
{
	char	*ret;
	int		i[2];

	i[0] = 1;
	i[1] = 0;
	if (di == 0 && s->minprec)
		ret = ft_strdup("0");
	else if (di == 0 && s->precision == 0 && s->point != 0 && i[0]--)
		ret = ft_strdup("");
	else
	{
		if (di < 0)
			i[1]++;
		ret = ft_itoa(di);
		if (s->precision > 0 && !s->minprec)
			ret = ft_int_type_precision(ret, s->precision);
	}
	if (s->width && s->zero && i[0]
		&& ((s->precision <= 0 && !s->point) || s->minprec))
		ret = ft_int_type_precision(ret, s->width - i[1]);
	else if (s->width > 0)
		ret = ft_int_type_width(ret, s);
	return (ret);
}
