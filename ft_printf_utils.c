/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:48:53 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/03 14:48:54 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * i + 1);
	if (!copy)
		return (0);
	copy[i] = '\0';
	while (i >= 0)
	{
		copy[i] = s1[i];
		i--;
	}
	return (copy);
}

int	ft_atoi(const char *str)
{
	int				minus;
	int				i;
	long long int	sum;

	i = 0;
	minus = 1;
	sum = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		minus = -minus;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (minus * sum);
}

static char	*ft_itoa_part_two(int minus, int i, int n)
{
	char	*ret;

	ret = malloc((i + 1 + minus) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[i + minus] = '\0';
	while (--i >= 0)
	{
		ret[i + minus] = n % 10 + 48;
		n = n / 10;
	}
	if (minus)
		ret[0] = '-';
	return (ret);
}

char	*ft_itoa(int n)
{
	int		i;
	int		del;
	int		minus;

	minus = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n = -n;
		minus++;
	}
	del = n;
	while (del)
	{
		del = del / 10;
		i++;
	}
	return (ft_itoa_part_two(minus, i, n));
}
