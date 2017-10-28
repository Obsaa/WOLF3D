/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 05:11:45 by oabdalha          #+#    #+#             */
/*   Updated: 2017/10/27 02:33:58 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <locale.h>
# include <stdarg.h>
# include <limits.h>

# define BUFF_SIZE 4096

# define F_T (**format)
# define L_S (F_T == 'c' || F_T == 's' || F_T == 'p' || F_T == '%')
# define F_SPEC (F_T == 'C' || F_T == 'S' || DIG_MOD || L_S)

# define L_MOD (F_T == 'h' || F_T == 'l' || F_T == 'z' || F_T == 'j')

# define L_MOD1 ((F_T + 1) == 'h' || (F_T + 1) == 'l')

# define NUM_MOD (F_T >= '0' && F_T <= '9')

# define FLG_MOD (F_T == '-' || F_T == '0' || F_T == ' ' || F_M)
# define F_M (F_T == '#' || F_T == '+')

# define DIG_MOD (D_M || D_M1)
# define D_M1 (F_T == 'X' || F_T == 'D' || F_T == 'O' || F_T == 'U')
# define D_M (F_T == 'i' || F_T == 'o' || F_T == 'd' || F_T =='u' || F_T == 'x')

# define ALL_MOD (L_MOD || FLG_MOD || F_T == '.' || F_T == '*' || N_M)
# define N_M ((F_T >= '0' && F_T <= 9))

typedef struct		s_plchdr
{
	char			k;
	intmax_t		sf;
	intmax_t		width;
	intmax_t		len;
	intmax_t		size;
	intmax_t		plus;
	intmax_t		minus;
	intmax_t		p;
	intmax_t		p_width;
	intmax_t		hash;
	intmax_t		neg;
	intmax_t		base;
	intmax_t		null;
	intmax_t		z;
}					t_plchdr;
/*
**   --------------------  build.c  --------------------
*/
t_plchdr			*init_res(t_plchdr *res);
/*
**   -------------------  ft_printf.c  -----------------
*/
int					ft_printf(char const *format, ...);
int					search_format(char **format, va_list ap);
void				search_flg_mod(char **format, va_list ap, t_plchdr *res);
void				print_format(char **format, t_plchdr *res);
/*
**   ------------------  conversion2.c  ----------------
*/
void				char_conv(char **format, t_plchdr *res, va_list ap);
void				str_conv(char **format, t_plchdr *res, va_list ap);
void				dec_conv(char **format, t_plchdr *res, va_list ap);
intmax_t			get_int(t_plchdr *res, va_list ap);
char				*base_conv(t_plchdr *res, va_list ap);
/*
**   -------------------  conversion.c  ---------------
*/
void				uint_conv(char **format, t_plchdr *res, va_list ap);
void				uint_oct_conv(char **format, t_plchdr *res, va_list ap);
void				uint_hex_conv(char **format, t_plchdr *res, va_list ap,
									char c);
void				pointer_adress(char **format, t_plchdr *res, va_list ap);
/*
**   -----------------  functionfinder.c  -------------
*/
void				function_hndlr(char **format, va_list ap, t_plchdr *res);
void				flag_finder(char **format, t_plchdr *res);
/*
**   -------------------  lengthmod.c  -----------------
*/
char				length_mod_ck(char **format, t_plchdr *res);
void				h_mod(char **format, t_plchdr *res);
void				ll_mod(char **format, t_plchdr *res);
void				z_mod(char **format, t_plchdr *res);
void				j_mod(char **format, t_plchdr *res);
/*
**   -------------------  widthmod.c  ------------------
*/
void				width_mod(char **format, va_list ap, t_plchdr *res);
void				put_width_spc(char **format, char *s, t_plchdr *res);
char				**get_width_len(char **format, t_plchdr *res);
char				**perc_width(char **format, t_plchdr *res);
void				put_str(char *str, int len);
/*
**   -------------------  flagmod.c  -------------------
*/
void				hash_handler(char **format, t_plchdr *res);
char				**minus_flag(char **format, t_plchdr *res);
char				**plus_flag(char **format, t_plchdr *res);
char				**zero_flag(char **format, t_plchdr *res);
void				space_flag(char **format, char *s, t_plchdr *res);
/*
**   -------------------  percisionmod.c  --------------
*/
char				**perc_num(char **format, t_plchdr *res, va_list ap);
void				put_perc(char **format, char *str, t_plchdr *res);
int					percision_mod(char **format, t_plchdr *res, char *s, int n);
void				perc_p_mod(t_plchdr *res, char *s, char **format);
char				*perc_p_join(char *s, t_plchdr *res);
/*
**	--------------------	printf.c	----------------
*/
void				neg_flg_width(char **format, t_plchdr *res, char *s, int n);
void				pos_flg_width(char **format, t_plchdr *res, char *s, int n);
void				print_edge(char **format, t_plchdr *res, char *s, int n);
char				*edge_num_mod(t_plchdr *res, char **s, int *n);
void				edge_p_width(char **format, char *s, t_plchdr *res);
/*
**	--------------------	printf2.c	----------------
*/
void				width_flg(char **format, t_plchdr *res, char *s, int n);
void				width_flg_2(char **format, t_plchdr *res, char *s, int n);
char				*width_num(char **format, t_plchdr *res, char **s, int n);
int					ft_printf(char const *format, ...);

int					get_next_line(int const fd, char **line);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
size_t				ft_count_unint_len(uintmax_t n, int base);
size_t				ft_count_int_len(intmax_t n, int base);
char				*ft_strndup(const char *s1, size_t len);
char				*ft_u_itoa_bs(uintmax_t value, int base);
void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *lit, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(intmax_t value, int base);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strnew(size_t size);
char				*ft_strrev(char *str);
int					ft_charcont(int n);
int					ft_isspace(int c);
void				ft_swap_char(char *a, char *b);
const char			*ft_find_next(const char *str, char c, int skip);
int					ft_str_count_splits(const char *str, char seps);
char				**ft_tabledel(char **ret, int len);

#endif
