/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:43:56 by gylim             #+#    #+#             */
/*   Updated: 2023/07/15 18:22:35 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>

# ifndef LL_TYPE
#  define LL_TYPE

typedef long long		t_ll;

# endif

/* get_next_line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (1024)
# elif BUFFER_SIZE < 1
#  error Buffer size must be at least 1.
# endif

char	*get_next_line(int fd);
char	*duplicate(const char *src);
char	*split(char **storage);
int		append(char **original, char *addition);

/* ft_printf */
# define HEX_UPPER ("0123456789ABCDEF")
# define HEX_LOWER ("0123456789abcdef")
# define DECIMAL ("0123456789")
# define NULL_PROMPT ("(null)")
# define ERROR (-1)
# define SUCCESS (0)
# define FALSE (0)
# define TRUE (1)
# define DEC_INT_MAX (10)
# define HEX_INT_MAX (8)
# define HEX_LONG_MAX (16)
# define NIBBLE (4)

int		ft_printf(int fd, const char *str, ...);
int		ft_write(int fd, const void *buf, size_t count);
int		print_addr(int fd, void *addr);
int		print_char(int fd, char ch);
int		print_hex(int fd, unsigned int nbr, char *base);
int		print_nbr(int fd, int nbr);
int		print_str(int fd, char *str);
int		print_uint(int fd, unsigned int nbr);

/* libft - mandatory part */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);

int		ft_atoi(const char *str);
t_ll	ft_atoll(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	**ft_split2(const char *s, const char *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* libft - bonus part */
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
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
