# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	long			nb;
	long			pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;