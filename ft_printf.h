#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags
{
	int	width;
	int	precision;
	int	flag_minus;
	int  flag_zero;
    int  flag_plus;
    int  flag_space;
    int  flag_hash;
    char type;
}	t_format;
#endif