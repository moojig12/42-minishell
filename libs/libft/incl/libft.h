/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:27:21 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 21:05:50 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h> // size_t, NULL, printf
# include <unistd.h> // write, read
# include <stdlib.h> // size_t, NULL, malloc, free
# include <limits.h> // INT_MAX, INT_MIN
# include <stdarg.h> // va_start, va_arg, va_copy, va_end
# include <fcntl.h> // open, O_RDONLY

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// ----------------------------------------------------------------
// libft - mandatory Libc function
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

// libft - mandatory not in libc
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// libft bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ----------------------------------------------------------------
// ft_printf
int		ft_printf(const char *fmt, ...);
int		ft_printf_format(char type, va_list args);
int		ft_printf_char(int c);
int		ft_printf_str(char *str);
int		ft_printf_ptr(void *ptr);
int		ft_printf_ptr_len(void *ptr);
int		ft_printf_int(int nb);
int		ft_printf_unsigned(unsigned long nb, int base, char *digits);

// // for ft_printf bonus list 
// typedef struct s_flags
// {
// 	int	spec;
// 	int	width;
// 	int	left;
// 	int	zero;
// 	int	star;
// 	int	precision;
// 	int	hash;
// 	int	space;
// 	int	plus;
// }		t_flags;

// ----------------------------------------------------------------
// get_next_line
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_parse_buff(char *buff, long length);
char	*gnl_load_lines(long fd, char *buff);
char	*get_next_line(long fd);

// // for get_next_line bonus
// typedef struct s_list
// {
// 	char			*str_buf;
// 	struct s_list	*next;
// }	t_list;

#endif
