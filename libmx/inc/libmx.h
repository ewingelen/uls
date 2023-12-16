#ifndef LIBMX_H
#define LIBMX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

#ifdef __MACH__

#include <malloc/malloc.h>

#else

#include <malloc.h>

#define malloc_size malloc_usable_size
#endif

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

int mx_arr_element_index(char **arr, const char *element);

int mx_arr_size(char **arr);

int mx_atoi_positive(const char *str);

int mx_binary_search(char **arr, int size, const char *s, int *count);

int mx_bubble_sort(char **arr, int size);

int mx_count_char(const char *s, char c);

int mx_count_substr(const char *str, const char *sub);

int mx_count_words(const char *str, char c);

t_list *mx_create_node(void *data);

char *mx_del_extra_spaces(const char *str);

void mx_del_intmatrix(int ***matrix, int row_count);

void mx_del_list(t_list *head);

int **mx_dup_int_matrix(int **src, int rows, int columns);

void mx_del_strarr(char ***arr);

void mx_del_strarr_without_content(char ***arr);

void mx_del_strmatrix(char ****matrix, int row_count);

char *mx_file_to_str(const char *file);

void mx_foreach(int *arr, int size, void (*f)(int));

int mx_get_char_index(const char *str, char c);

char **mx_get_file_lines(const char *file_name);

int mx_get_substr_index(const char *str, const char *sub);

unsigned long mx_hex_to_nbr(const char *hex);

bool mx_isdigit(char c);

bool mx_isalpha(char c);

int mx_isprint(char c);

char *mx_itoa(int number);

bool mx_list_contains(t_list *head, char *str);

int mx_list_size(t_list *list);

void *mx_memccpy(void *restrict dst,
                 const void *restrict src,
                 int c,
                 size_t n);

void *mx_memchr(const void *s, int c, size_t n);

int mx_memcmp(const void *s1, const void *s2, size_t n);

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);

void *mx_memmem(const void *big,
                size_t big_len,
                const void *little,
                size_t little_len);

void *mx_memmove(void *dst, const void *src, size_t len);

void *mx_memrchr(const void *s, int c, size_t n);

void *mx_memset(void *b, int c, size_t len);

char *mx_nbr_to_hex(unsigned long nbr);

void mx_pop_back(t_list **head);

void mx_pop_front(t_list **head);

double mx_pow(double n, unsigned int pow);

void mx_print_error(const char *s);

void mx_print_strarr(char **arr, const char *delim);

ssize_t mx_file_len(const char *file);

void mx_print_unicode(wchar_t c);

void mx_printchar(char c);

void mx_printint(int n);

void mx_printstr(const char *s);

void mx_push_back(t_list **list, void *data);

void mx_push_front(t_list **list, void *data);

int mx_quicksort(char **arr, int left, int right);

int mx_read_line(char **lineptr, size_t buf_size, char delim, int fd);

void *mx_realloc(void *ptr, size_t size);

char *mx_replace_substr(const char *str,
                        const char *sub,
                        const char *replace);

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

int mx_sqrt(int x);

int mx_str_contains(const char *s, char c);

bool mx_str_only_alpha(const char *str);

bool mx_str_only_digit(const char *str);

void mx_str_reverse(char *s);

char *mx_strcat(char *restrict s1, const char *restrict s2);

int mx_strcmp(const char *s1, const char *s2);

char *mx_strcpy(char *dst, const char *src);

void mx_strdel(char **str);

char *mx_strdup(const char *s1);

char *mx_strjoin(const char *s1, const char *s2);

int mx_strlen(const char *s);

int mx_strncmp(const char *s1, const char *s2, size_t n);

char *mx_strncpy(char *dst, const char *src, int len);

char *mx_strndup(const char *s1, size_t n);

char *mx_strnew(int size);

char **mx_strsplit(const char *s, char c);

char *mx_strstr(const char *haystack, const char *needle);

char *mx_strtrim(const char *str);

void mx_swap_char(char *s1, char *s2);

#endif
