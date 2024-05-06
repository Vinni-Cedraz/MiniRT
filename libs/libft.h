/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:41:49 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/17 14:20:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define INTMIN -2147483648
# define UPPER "0123456789ABCDEF"
# define LOWER "0123456789abcdef"
# define STR_LIMIT 4027

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

typedef const char		*t_constr;
typedef unsigned char	t_uc;
typedef unsigned int	t_uint;

typedef enum e_type
{
	INT,
	CHAR,
	FLOAT,
}						t_ype;

typedef void			(*t_function_ptr)(const void *a, const t_ype t);

typedef struct s_trings
{
	t_constr			a;
	t_constr			b;
	t_constr			c;
}						t_strings;

typedef struct s_ints
{
	int					a;
	int					b;
	int					c;
}						t_ints;

typedef struct s_tools
{
	size_t				abs;
	size_t				counter;
	size_t				len;
	size_t				size;
	size_t				half;
	size_t				baselen;
	size_t				sign;
}						t_ools;

typedef struct s_counters
{
	size_t				chars;
	size_t				counter;
	size_t				prntd;
	size_t				chckd;
	size_t				from_start;
	size_t				from_end;
}						t_counters;

typedef struct s_plit
{
	char				*end;
	char				*start;
	char				**words;
	size_t				count;
}						t_split;

typedef struct s_gnl
{
	char				*read;
	char				*line;
	char				*bfr_brk;
	char				*lnbrk;
	char				*aftbrk;
	char				*wth_all;
	size_t				bfrbrk_len;
	size_t				aftbrk_len;
	size_t				len;
}						t_gnl;

typedef struct s_read_one
{
	char				*buf;
	char				*read;
	char				*res;
	size_t				len;
	size_t				i;
	size_t				max;
}						t_read_one;

typedef struct s_imple_itoa
{
	int					len;
	char				buf[5];
}						t_buf;

// ASCII TYPE IDENTIFICATION FUNCTIONS:

// the ft_isdigit() function tests whether int c represents a character
// in the ascii table and returns 1 if it is, otherwise it returns 0.
int						ft_isdigit(int c);
// ft_isalnum - checks for an alphanumeric character and
// returns 0 or 1 (true or false) accordingly.
int						ft_isalnum(int c);
// the ft_isalpha function tests whether c is an alphabetic character or not
// and returns zero if it is not, and non-zero if it is.
int						ft_isalpha(int c);
// The ft_isascii() function tests for an ASCII character, which is any
// character between '\000' AND '\177' INCLUSIVE.
int						ft_isascii(int c);
// The ft_isprint function tests whether c represents a printable character
// in the ascii table.
int						ft_isprint(void *c);
// ft_toupper - converts a lower-case letter to the corresponding upper-case
int						ft_toupper(int c);
// ft_tolower - converts an upper-case letter to the corresponding lower-case
int						ft_tolower(int c);

// BYTE MANIPULATION FUNCTIONS:

// memset is the building block of the b_zero and calloc functions but it can
// write any unsigned char, (not only zero), given to it by an ascii number:
void					*ft_memset(void *b, int c, size_t len);
// ft_memcpy is like a strncpy but for bytes,
// it is the callers responsability to
// assure the memory areas do not overlap:
void					*ft_memcpy(void *dst, const void *src, size_t n);
// ft_memmove - copies n bytes from memory area src to memory area dst and it
// does not matter if the memory areas overlap, the function handles it.
// it is only useful when messing with members of the same array. Because that
// is the only case I can think of where the memory areas can overlap.
void					*ft_memmove(void *dst, const void *src, size_t len);
// ft_memchr searches for a c byte typecasted as an u_char on the first n chars
// of the string s:
void					*ft_memchr(const void *s, int c, size_t n);
// ft_memcmp compares n bytes of s1 and s2 and returns 0 if they are all equal
// or an int > 0 or int < 0 if s1 is smaller or bigger than s2, respectivelly:
int						ft_memcmp(const void *s1, const void *s2, size_t n);
// fills a memory area with n null bytes and returns nothing, the void area can
// be typecasted to any type of pointer:
void					ft_bzero(char *s, int n);

// STRING MANIPULATION FUNCTIONS:
// THE ONES THAT RETURN A NUMBER:

// ft_strlen returns the length of a string:
size_t					ft_strlen(const char *str);
// ft_strncmp is exatly like memcmp but string specific:
int						ft_strncmp(const char *s1, const char *s2, size_t n);
// ft_strlcpy copies n bytes from the null terminated string src to dst, but at
// most size - 1 bytes, null terminating the result. It returns the length of
// src, so if the return value is >= size, the output string has been truncated.
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
// ft_strlcat concatenates the null terminated src to the null terminated dst,
// but at most size - ft_strlen(dst) - 1,
size_t					ft_strlcat(char *dst, const char *src, size_t size);

// THE ONES THAT RETURN A POINTER TO A PRE-EXISTING MEMORY ADRESS:

// ft_strchr finds a (char) c in the s string and returns a pointer to it:
char					*ft_strchr(const char *s, int c);
// ft_strrchr finds (char)c in s, but it starts from the end of the string:
char					*ft_strrchr(const char *s, int c);
// ft_striteri receives a pointer to a function f on arg2 and iterates it on
// the elements of the string s starting from the s[(unsignedint)x] element
// (where x == arg 1 of function f) < x is an abstract example only >
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
// ft_strnstr searches len bytes for a substring in a string. If little is an
// empty string, big is returned; if little occurs nowhere in big, NULL is
// returned; otherwiwise a pointer to the first character of little is returned
char					*ft_strnstr(const char *big, const char *little,
							size_t len);

// THE ONES THAT RETURN A POINTER TO NEWLY ALLOCATED ADRESS:

// ft_strdup duplicates a string and returns a the address to the newly created
// and allocated string (the string it receives doesn't have to pre-exist, be
// allocated or initializied, such that -> ft_strdup("hello") is a valid call.
char					*ft_strdup(const char *s1);
// ft_strjoin allocates memory for the concatenation of two strings, joins
// them and returns a pointer to the new string.
char					*ft_strjoin(char const *s1, char const *s2);
// ft_substr searches thru len chars looking for the s[start] element and then
// creates a string that begins there and ends at the usual end of s. It works
// even if len is bigger than the new string's length, but if start is bigger
// than it should, it returns the adress to a null string:
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
// ft_calloc allocates (count * size) bytes and fils it with nulls, cleaning
// up the memory garbage and returning a pointer to the new memory area:
void					*ft_calloc(size_t count, size_t size);
// ft_strmapi does the same as ft_striteri but it returns a new string instead
// of modifying the existing one. The other difference is that it uses memmory
// allocation to create the new string and return its address:
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
// ft_strtrim receives a string and a set of chars, and it returns a new string
// after every char present in string set from the beggining and end of the
// string s:
char					*ft_strtrim(char const *s1, char const *set);
// ft_split receives a string and a set of chars, and it returns an array of
// strings, each one being a substring of s that is delimited by a char c:
t_split					*ft_split(char const *s, char c);

// OUTPUT MANIPULATION FUNCTIONS:

// ft_atoi converts a string to an int, it can handle negative numbers:
int						ft_atoi(const char *str);
// ft_itoa converts an int to a string, it can hangle negative numbers:
char					*ft_itoa(int n);
// ft_putchar_fd writes a char to a file descriptor:
size_t					ft_putchar_fd(char c, int fd);
// ft_putstr_fd writes a string to a file descriptor:
size_t					ft_putstr_fd(char *s, int fd);
// ft_putendl_fd writes a string to a file descriptor, and then a newline:
void					ft_putendl_fd(char *s, int fd);
// ft_putnbr_fd writes an int to a file descriptor:
void					ft_putnbr_fd(int n, int fd);
// just a putchar
size_t					ft_putchar(char c);

// EXTRA FUNCTIONS:

// ft_abs returns the absolute value of an int:
int						ft_abs(int n);
// ft_numlen returns the number of digits of an int:
int						ft_numlen(int n);
// ft_strrev reverses a string:
char					*ft_strrev(char *str, size_t strlen);
// ft_word_counter counts the number of words in a string:
int						ft_word_counter(char const *s, char c);
// ft_free_arr frees an array of strings:
void					ft_free_arr(char **arr, void **aux);
// ft_free_arr_size does the same but uses size instead of relying on NULLs
void					ft_free_arr_size(void **arr, uint size);
// ft_itoa_base converts an int to a string in a given base:
char					*ft_itoa_base(size_t n, char *base);
// ft_swap swaps two voids:
void					ft_swap(void *a, void *b, size_t size);
// ft_sort_int_tab sorts an int array:
void					ft_sort_int_tab(size_t *tab, size_t size);
// ft_rev_int_tab reverses an int array:
void					ft_rev_int_tab(size_t *tab, size_t size);
// ft_hexdump prints a hexdump of a file:
void					ft_hexdump(char *str);
// this is the classic ft_putstr:
size_t					ft_putstr(char *str);
// this is a function to measure if ft_calloc worked properly:
size_t					ft_memorylen(void *ptr, size_t size);
// this is ft_gnl (get next line):
char					*ft_gnl(int fd);
// this frees a t_split pointer:
void					ft_free_t_split(t_split *split);
// this is ft_atoi_base, it converts a string to an int in a given base:
int						ft_atoi_base(const char *str, int base);
// cheks if its an uppercase hex string:
int						ft_ishexup(char *s);
// hex low:
int						ft_ishexlow(char *s);
// returns positive if char is a whitespace ('\0' not seen as a whitespace):
int						is_whitespace(char c);
// randomize an array in place, has forbidden functions use carefully
void					ft_randomize_array(int *arr, int arr_size);
// atoi but returns a long
long					ft_atol(char *str);
// like a mini sprinf that only works for three strings
char					*ft_fmt_str(t_constr fm, t_constr s1, t_constr s2,
							t_constr s3);
// iterates linearly on a 2d array applying a given function
void					ft_2d_iter(void **a, int n, t_function_ptr funct,
							t_ype t);
// does what itoa does but without allocating memory in the heap
t_buf					ft_simple_itoa(int num);
// ft_atof converts a string to a float
double					ft_atof(const char *str);

#endif
