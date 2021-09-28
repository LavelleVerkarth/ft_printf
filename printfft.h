/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:24:26 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/03 14:24:28 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFFT_H
# define PRINTFFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
	int				minus;
	int				zero;
	unsigned int	width;
	unsigned int	precision;
	int				point;
	int				minprec;
	int				charnull;
	int				final;
	int				vr;
}				t_list;
int		ft_printf(const char *str, ...);
t_list	*ft_lstnew(void);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_int_type(t_list *specif, int di);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_unsigned_int_type(t_list *specif, unsigned int u);
char	*ft_char_type(t_list *specif, char c);
char	*ft_int_type_precision(char *ret, int p);
char	*ft_int_type_width(char *ret, t_list *specif);
char	*ft_string_type(t_list *specif, char *c);
char	*ft_hex_type(t_list *specif, int hex);
char	*ft_Hhex_type(t_list *specif, int hex);
char	*ft_poiner_type(t_list *specif, unsigned long long hex);
void	ft_putstr(char *s, int vr);
char	*ft_mod_strjoin(char const *s1, int *vr, char const *s2, int scn);
void	ft_lstzero(t_list	*ret);
char	*ft_parse_type(const char **str, t_list *specif, va_list ap);

#endif
