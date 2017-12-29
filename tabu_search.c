#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/***** METHOD DEFINITIONS *****/
int *new_one_dim_arr(int);
int *new_two_dim_arr(int, int);

int cost_board(int *, int *, int *, int, int, int);
void generate_queens(int *, int *, int *, int, int, int);
void print_board(int *, int, int);

int *new_one_dim_arr(int x)
{
	int *arr = (int *)calloc(x, sizeof(int));

	if(arr == NULL)
	{
		/* calloc failed */
		exit(-1);
	}

	return arr;
}

int *new_two_dim_arr(int x, int y)
{
	int *arr = (int *)calloc(x * y, sizeof(int));

	if(arr == NULL)
	{
		/* calloc failed */
		exit(-1);
	}

	return arr;
}

int cost_board(int *board, int *queen_loc_row, int *queen_loc_col, int r, int c, int n_queens)
{
	int *domination_board = new_two_dim_arr(r, c);
	int highest_cost = r * c;
	int i, j, k, total_cost = 0;

	for(i = 0; i < n_queens; i++)
	{
		for(j = 0; j < c; j++)
		{
			*(domination_board + *(queen_loc_row + i)*c + j) = 2;
		}

		for(k = 0; k < r; k++)
		{
			*(domination_board + k*c + *(queen_loc_col + i)) = 2;
		}

		j = *(queen_loc_row + i);
		k = *(queen_loc_col + i);
	}

	print_board(domination_board, r, c);
}

void generate_queens(int *board, int *queen_loc_row, int *queen_loc_col, int r, int c, int n_queens)
{
	int i, gen_row, gen_col;

	for(i = 0; i < n_queens; i++)
	{
		gen_row = rand() % r;
		gen_col = rand() % c;

		while(1 == *(board + gen_row*c + gen_col))
		{
			gen_row = rand() % r;
			gen_col = rand() % c;
		}

		*(board + gen_row*c + gen_col) = 1;
		*(queen_loc_row + i) = gen_row;
		*(queen_loc_col + i) = gen_col;
	}
}

void print_board(int *board, int r, int c)
{
	int i, j;

	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("%i ", *(board + i*c + j));
		}
		printf("\n");
	}
}







//test
void modify_values(int *arr)
{
	*(arr + 1) = 5;
}






int main(int argc, char *argv[])
{
	srand(time(NULL));
	int r = atoi(argv[1]);
	int c = atoi(argv[2]);
	int n_queens = atoi(argv[3]);

	int *initial_board = new_two_dim_arr(r, c);
	int *initial_queen_loc_row = new_one_dim_arr(n_queens);
	int *initial_queen_loc_col = new_one_dim_arr(n_queens);

	generate_queens(initial_board, initial_queen_loc_row, initial_queen_loc_col, r, c, n_queens);
	cost_board(initial_board, initial_queen_loc_row, initial_queen_loc_col, r, c, n_queens);
	printf("\n");
	print_board(initial_board, r, c);
/*
	int *d = new_one_dim_arr(5);
	int *s = new_two_dim_arr(5,5);

	*(d + 1) = 1;
	*(d + 2) = 2;
	*(d + 3) = 3;
	*(d + 4) = 4;

	*(s + 1*5 + 3) = 4;

	int i;
	for(i = 0; i < 5; i++)
	{
		printf("%i\n", *(d + i));
	}

	int j;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			printf("%i ", *(s + i*5 + j));
		}
		printf("\n");
	}

	modify_values(d);

	for(i = 0; i < 5; i++)
	{
		printf("%i\n", *(d + i));
	}
*/

	return 0;
}
