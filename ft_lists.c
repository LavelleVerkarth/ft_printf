/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:21:17 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/03 15:21:18 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfft.h"

void	ft_lstzero(t_list	*ret)
{
	ret->zero = 0;
	ret->minus = 0;
	ret->width = 0;
	ret->precision = -1;
	ret->point = 0;
	ret->minprec = 0;
	ret->charnull = 0;
	ret->final = 0;
}

t_list	*ft_lstnew(void)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->zero = 0;
	ret->minus = 0;
	ret->width = 0;
	ret->precision = -1;
	ret->point = 0;
	ret->minprec = 0;
	ret->charnull = 0;
	ret->final = 0;
	ret->vr = 0;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		n;

	if (!s1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n])
	{
		ret[i] = s2[n];
		n++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_putstr(char *s, int vr)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i < vr)
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*ft_mod_strjoin(char const *s1, int *vr, char const *s2, int scn)
{
	char	*ret;
	int		i;
	int		n;

	if (!s1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (*vr + ft_strlen(s2) + 2));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < *vr)
		ret[i] = s1[i];
	n = 0;
	while (s2[n])
	{
		ret[i] = s2[n++];
		if (scn && ret[i] == '\n')
			ret[i] = '\0';
		i++;
	}
	ret[i] = '\0';
	if (scn)
		i--;
	*vr = i;
	return (ret);
}
