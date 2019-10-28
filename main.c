#include <mlx.h>
# include "libft/includes/libft.h"
#include <unistd.h>
typedef struct s_point
{
int y;
int x;
int z;
int color;
}			t_point;
/*void ft_putchar (char c)
{
write (1, &c, 1);
}


int deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}


int main (int argc , char ** argv)
//{
void *win_ptr;
void *mlx_ptr;
mlx_ptr = mlx_init();
win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
mlx_key_hook(win_ptr, deal_key, (void*) 0);
mlx_pixel_put(mlx_ptr, win_ptr, 251, 251, 0xFFFFFF);
mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
mlx_loop(mlx_ptr);*/

void ft_error (t_list **lst)
{
	write (1,"Error", 5); /* make clean lst*/

}
int get_color (char *str)
{
	if (str == NULL)
		return(16777215);
	str += 3;
	return(ft_atoi_base (str , 16));
}



size_t	ft_countwords(char *str, int y , t_list **lst)
{

 int x;
char **tmp;
t_list *tmplst;
t_point new;

x = -1;
tmp = ft_strsplit(str, ' ');

while (tmp[++x] != '\0')
{
	new.color = get_color (ft_strchr(tmp[x], ','));
	new.x = x;
	new.y = y;
	new.z = atoi(tmp[x]);
	tmplst = ft_lstnew(&new, sizeof(t_list));
	ft_lstadd(lst, tmplst);
printf ("%s",tmp[x]);
}
	printf ("\n");
return (x);

}

void save_map (int fd) {
	int count;
	char *line;
	t_list **lst;
	int i;

	count = 0;
	i = 0;
	while (get_next_line(fd, &line) == 1) {
		if (count == 0)
			count = ft_countwords(line,count, &lst);
		else
		{
			(count == ft_countwords(line,count, &lst)) ? i++: ft_error(&lst);
		}
	}
}

int read_map (char *file)
{

	int fd;
	fd = open(file, O_RDONLY);
	if(fd == -1) {
		write(1, "Error", 5);
		exit(0);
	}
	save_map(fd);
close(fd);
}

int main (int argc , char ** argv)
{
	if (argc < 2)
		write(1, "Error", 5);
	read_map(argv[1]);
}