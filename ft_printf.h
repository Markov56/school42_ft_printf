#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags
{
	int	width;
	int	precision;
	int	minus;
	int	zero;
    int	plus;
    int	space;
    int	hash;
    char type;
}	t_format;
#endif