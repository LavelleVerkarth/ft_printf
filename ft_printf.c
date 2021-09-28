/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:27:59 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/03 14:28:00 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfft.h"

void	ft_parse_averwap(int ver, t_list *specif, int wap)
{
	if (ver)
	{
		if (wap < 0)
		{
			specif->minus++;
			specif->zero = 0;
			wap = -wap;
		}
		specif->width = wap;
	}
	else
	{
		if (wap < 0)
		{
			specif->minprec++;
			wap = -wap;
		}
		specif->precision = wap;
	}
}

void	ft_parse_atoi_printf(char **str, t_list *specif, va_list ap, int ver)
{
	int	wap;

	if (**str == '*')
	{
		wap = va_arg(ap, unsigned int);
		(*str)++;
	}
	else
	{
		wap = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
		{
			specif->final++;
			(*str)++;
		}
	}
	ft_parse_averwap(ver, specif, wap);
}

char	*ft_parse(const char **str, va_list ap, t_list *specif)
{
	*str += 1;
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
		{
			specif->minus++;
			specif->zero = 0;
		}
		else if (**str == '0' && specif->minus == 0)
			specif->zero++;
		(*str)++;
	}
	ft_parse_atoi_printf((char **)str, specif, ap, 1);
	if (**str == '.')
	{
		specif->point++;
		(*str)++;
	}
	ft_parse_atoi_printf((char **)str, specif, ap, 0);
	return (ft_parse_type(str, specif, ap));
}

void	ft_preparse(va_list ap, char **ret, t_list *s, const char **str)
{
	char	*tmp;
	char	c[2];
	char	*tmp2;

	c[1] = '\0';
	if (**str == '%')
	{
		ft_lstzero(s);
		tmp2 = ft_parse(str, ap, s);
		tmp = ft_mod_strjoin(*ret, &s->vr, tmp2, s->charnull);
		free(tmp2);
		s->vr += s->charnull;
	}
	else
	{
		c[0] = *str[0];
		tmp = ft_mod_strjoin(*ret, &s->vr, c, 0);
		*str += 1;
	}
	free(*ret);
	*ret = tmp;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*ret;
	t_list	*specif;
	int		vr;

	specif = ft_lstnew();
	if (specif)
	{
		vr = 0;
		ret = ft_strdup("");
		va_start(ap, str);
		while (*str)
			ft_preparse(ap, &ret, specif, &str);
		va_end(ap);
		ft_putstr(ret, specif->vr);
		free(ret);
	}
	vr = specif->vr;
	free(specif);
	return (vr);
}
