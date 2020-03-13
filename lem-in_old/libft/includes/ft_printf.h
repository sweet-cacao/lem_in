/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:55:10 by gstarvin          #+#    #+#             */
/*   Updated: 2020/02/20 17:22:01 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEARPRINTF_FT_PRINTF_H
# define CLEARPRINTF_FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../ft_str/libft.h"

typedef struct s_star		t_star;
typedef struct s_structlist	t_structlist;
typedef struct s_parse		t_parse;

struct						s_star
{
	int star_w;
	int star_p;
	int minus;
};

struct						s_parse
{
	int		i;
	int		end;
	int		sum;
	int		parse;
	t_star	star;
	int		fd;
	char	buff[100];
};

struct						s_structlist
{
	int zero;
	int hash;
	int min;
	int plus;
	int space;
	int width;
	int precision;
	int isp;
	int isw;
	int len_arg;
	int ilenarg;
	int fd;
};

void						set_func(char chr, t_structlist a);
void						print_pointer(const void *addr, int fd);
int							ft_printf(char *format, ...);
int							is_csp(char c);
int							is_dioux(char c);
int							first_flag(char c);
int							is_number(char c);
int							count_length(long long int n);

int							format_print_di(long long int arg,
									char *str, t_parse p);
int							format_print_c(char arg, char *str, t_parse p);
int							format_print_s(char *arg, char *str,
									t_parse p);
int							format_print_u(unsigned long long int arg,
		char *str, t_parse p);
int							format_print_p(void *arg, char *str, t_parse p);

void						ft_putstr_p(char *str, int precision, int fd);
t_structlist				zero_struct();
t_structlist				fill_struct(t_structlist a, int *i, char *str);
void						format_width_c(t_structlist a, int i);
int							ft_parse(va_list ap, char *walk, t_parse p);
void						ft_putnbr_long(long long int n, int fd);
void						ft_putnbr_long_u(unsigned long long int n, int fd);

void						ft_printoct(unsigned long long int n, int fd);
void						ft_printhex2(unsigned long long int n, char a,
		int fd);
int							count_hex(unsigned long long int n, char a);
int							count_oct(unsigned long long int n);
int							format_percent(char b, char *str, int start,
							t_parse parse);
void						format_width(t_structlist a, int len_arg);
t_structlist				flag_ignore(t_structlist a);
int							is_f(char c);
int							count_num(long long int arg, t_structlist a);
int							format_print_f(long double arg,
									char *str, t_parse p);
void						ft_float(long double num, t_structlist a);
void						ft_putnbr_unsigned_long(unsigned long long int n,
		int fd);
int							count_num_p(t_structlist a, void *arg);

t_star						star_func(va_list ap, char *format, int i, int end);
t_structlist				add_star(t_star star, t_structlist a);

void						format_p_is_precision(t_structlist *a, int i);
void						format_p_min(const void *arg,
		t_structlist *a, int i);
void						format_p_conditions_for_pre(const void *arg,
		t_structlist *a, int i);
t_structlist				format_p_zero(const void *arg,
		t_structlist *a, int i);
void						format_p_all_conditions(const void *arg,
		t_structlist *a, int i);

void						format_s_all_conditions(char *arg, t_structlist *a);

t_star						set_star_s(t_star star, char *format, int end);

t_structlist				format_di_with_perecision(long long int arg,
		t_structlist *a);
void						format_di_without_precision(long long int arg,
		t_structlist *a);
int							format_di_conditions(long long int arg,
		t_structlist *a);
int							format_di_for_zero(long long int arg,
		const char *str, int start, t_structlist *a);
void						format_di_extra(const char *str,
		t_structlist *a, int *i);
void						format_di_min(long long int arg, t_structlist *a);

t_structlist				format_choose_sign(long long int arg,
		t_structlist a);

t_structlist				count_num_u2(t_structlist *a, char b);
t_structlist				count_num_u1(t_structlist *a, char b);
int							count_num_u(t_structlist a, char b);
void						ft_printer(unsigned long long int arg, char a,
		int fd);
t_structlist				print_u_hash1(const char *str, int start,
		t_structlist *a);
t_structlist				print_u_isp1(const char *str, int start,
		t_structlist *a);
void						modif_lenarg(const char *str, int start,
		t_structlist *a);
t_structlist				print_u_isp2(const char *str, int start,
		t_structlist *a);
t_structlist				print_u_hash2(const char *str, int start,
		t_structlist *a);
void						write_hash(const char *str, int start,
		int fd);
t_structlist				print_u_hash3(const char *str, int start,
		t_structlist *a);
t_structlist				print_u_setlenarg(unsigned long long int arg,
		const char *str, int start, t_structlist *a);
t_structlist				print_u_no_min(const char *str, int start,
		t_structlist *a);
void						set_a(char *str, t_star *star,
		t_structlist *a, int *i);
void						print_u_check_min(unsigned long long int arg,
		const char *str, int start, t_structlist *a);
int							count_length_u(unsigned long long int n);

char						find_hex_upper(unsigned long long int n);
char						find_hex_lower(unsigned long long int n);

void						rounding(t_structlist *a, int count_pres,
		long double *num, int *last_dig);
unsigned long long int		rounding_for_count_f(long double num,
		int count_pres);
int							count_float(long double num, t_structlist a);
int							count_num_f(long double arg, t_structlist a);
t_structlist				format_choose_sign_f(long double arg,
		t_structlist a);
void						rounding_plus_one(long double *fr);
void						f_is_min(long double arg, t_structlist *a);
t_structlist				no_min_isp(long double arg, t_structlist *a);
t_structlist				no_min_no_isp(long double arg, t_structlist *a);
void						f_no_min(long double arg, t_structlist *a);
void						before_min(long double arg,
		t_structlist *a, int *num);
char						*ft_write_my(int flag, int fd, char c);
int							binary(long long int num, t_parse p);
size_t						nonprintable(t_parse p);
size_t						unix_timestamp(unsigned long long stamp, t_parse p);
void						write_prefix(t_structlist *a, char c);
t_parse						ft_printf_one(char *walk, t_parse *p);
int							ft_printf_two(t_parse *p);
int							ft_printf_three(t_parse *p);
int							ft_printf_four(t_parse *p);
int							skip(char *walk, t_parse p);
void						print_final(t_parse *p);
int							is_null(char *buff, int i);

#endif
