#include <stdio.h>
#include <stdlib.h>

typedef struct s_in
{
	int		x;
	int		y;
}			t_in;

typedef struct s_test
{
	int		a;
	t_in	b;
}			t_test;

void	set_info(t_test *test)
{
	test->a = 100;
	test->b.x = 200;
}

int	main(void)
{
	t_test *test;
	test = (t_test *)malloc(sizeof(t_test) * 1);
	// test->b = (t_in *)malloc(sizeof(t_in) * 1);
	set_info(test);
	printf("[a,b]=[%d,%d]\n", test->a, test->b.x);
}