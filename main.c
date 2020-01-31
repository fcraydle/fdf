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

typedef struct s_mlx
{

}				t_mlx;
typedef struct s_map
{
	int  len;
	int  str;
	int k;
}				t_map;


int deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}




t_list *ft_rev_list(t_list **lst) {
	t_list *start;
	t_list *last;
	t_list *tmp;
	t_list *ret;

	last = *lst;
	start = *lst;

	while (last->next != NULL)
		last = last->next;
	tmp = last;
	ret = tmp;
	while (start != last) {
		start = start->next;
		if (start->next == last) {
			tmp->next = start;
			tmp = tmp->next;
			start = *lst;
			last = tmp;
		}
	}
	tmp->next = *lst;
tmp = tmp->next;

tmp->next = NULL;
return (ret);
}

void ft_make_paint(t_list **lst, t_map *map) {

	t_list *start;
	t_point *go;
	int i;
	int hight;
	int with;
	int pointx;
	int pointy;
	start = ft_rev_list(lst);
	i = 0;
	with = 0;
	pointx = 0;
	hight = 0;
	pointy= 0;
	void *win_ptr;
	void *mlx_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_key_hook(win_ptr, deal_key, (void *) 0);
while (start)
{
		while (i != map->k)
		{
			go = start->content;
			mlx_pixel_put(mlx_ptr, win_ptr, go->x + i + pointx, go->y + pointy, go->color);
			mlx_pixel_put(mlx_ptr, win_ptr, go->x + pointx, go->y + i + pointy, go->color);
			i++;
		}
	if (hight == map->str) {
		i = 0;
		while (i != map->k) {
			mlx_pixel_put(mlx_ptr, win_ptr, go->x + i + pointx , go->y + pointy + map->k , go->color);
			i++;
		}
	}

	with++;
	pointx = map->k + pointx;
	if (with  == map->len)
	{
		while (i != 0)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, go->x + pointx, go->y + i + pointy, go->color);
			i--;
		}
			with = 0;
			pointx = 0;
			pointy = map->k + pointy;
			hight++;
		}
	start= start->next;
	i = 0;
	}

	mlx_loop(mlx_ptr);

}
void ft_error (t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_memdel(&(*lst)->content);
		ft_memdel((void **)lst);
		*lst = next;
	}
	write (1,"Error", 5);
	/* make clean lst*/
	exit(1);

}
int get_color (char *str)
{
	if (str == NULL)
		return(16777215);
	str += 3;
	return(ft_atoi_base(str , 16));
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
	new.color = get_color(ft_strchr(tmp[x], ','));
	new.x = x;
	new.y = y;
	new.z = atoi(tmp[x]);
	tmplst = ft_lstnew(&new, sizeof(t_point));
	ft_lstadd(lst, tmplst);
//printf ("%s",tmp[x]);
}
return (x);

}

void save_map (int fd)
{
	t_map map;
	int count;
	char *line;
	t_list lst;
	int y;

	count = 0;
	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (count == 0)
			count = ft_countwords(line, y++, &lst);
		else
			(count == ft_countwords(line,y, &lst)) ? y++: ft_error(&lst);
	}
	map.len = count;
	map.str = (y - 1);
	map.k = 20;
ft_make_paint(&lst, &map);
}

void read_map (char *file)
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
	if (argc < 2) {
		write(1, "Error", 5);
		exit(1);
	}
	read_map(argv[1]);
}