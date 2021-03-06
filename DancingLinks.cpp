#include "DancingLinks.h"

typedef struct map
{

	int row, col, quad, key, numb;

	struct map* left, * right, * up, * down;
}map;

typedef struct stack
{
	struct map* ptr;
	struct stack* next;
}stack;


void push(stack** top_ptr, map* ptr)
{
	stack* new_ptr = NULL;

	new_ptr = (stack*)malloc(sizeof(stack));

	if (new_ptr != NULL)
	{
		memset(new_ptr, 0x00, sizeof(stack));
		new_ptr->ptr = ptr;
		new_ptr->next = *top_ptr;
		*top_ptr = new_ptr;
	}
}

void pop(stack** top_ptr)
{
	stack* temp_ptr = NULL;

	if (*top_ptr != NULL)
	{
		temp_ptr = (*top_ptr);
		(*top_ptr) = (*top_ptr)->next;

		free(temp_ptr);
	}
}

void in(map** start_ptr, int row, int col, int key, int numb, int quad, int mode)
{
	map* new_ptr = NULL, * prev_ptr = NULL, * cur_ptr = *start_ptr;

	new_ptr = (map*)malloc(sizeof(map));

	if (new_ptr != NULL)
	{
		memset(new_ptr, 0x00, sizeof(map));

		new_ptr->row = row;
		new_ptr->col = col;
		new_ptr->key = key;
		new_ptr->numb = numb;
		new_ptr->quad = quad;
		new_ptr->right = NULL;
		new_ptr->down = NULL;
		new_ptr->left = NULL;
		new_ptr->up = NULL;

		if (mode == 1)
		{
			new_ptr->right = *start_ptr;
			*start_ptr = new_ptr;
			if (cur_ptr != NULL)
				cur_ptr->left = new_ptr;
		}
		else
		{
			new_ptr->quad = (*start_ptr)->quad;
			new_ptr->up = *start_ptr;
			if (((*start_ptr)->down) != NULL)
			{
				(*start_ptr)->down->up = new_ptr;
				new_ptr->down = (*start_ptr)->down;
				(*start_ptr)->down = new_ptr;
			}
			else
			{
				(*start_ptr)->down = new_ptr;
			}
			*start_ptr = new_ptr;
		}
	}
}

void findcol(map** start_ptr, int row, int col, int key, int quad, int numb)
{

	if (key == 0)
	{

		if (start_ptr != NULL)
			while (((*start_ptr)->key) != key)
			{
				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}

		if (start_ptr != NULL)
			while (((*start_ptr)->row) != row)
			{

				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}

		if (start_ptr != NULL)
			while (((*start_ptr)->col) != col)
			{

				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}
	}

	else if (key == 1)
	{

		if (start_ptr != NULL)
			while (((*start_ptr)->key) != key)
			{
				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}

		if (start_ptr != NULL)
			while (((*start_ptr)->row) != row)
			{
				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}

		if (start_ptr != NULL)
			while (((*start_ptr)->numb) != numb)
			{

				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}
	}

	else  if (key == 2)
	{

		if (start_ptr != NULL)
			while (((*start_ptr)->key) != key)
			{

				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}

		if (start_ptr != NULL)
			while (((*start_ptr)->col) != col)
			{
				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}

		if (start_ptr != NULL)
			while (((*start_ptr)->numb) != numb)
			{
				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}
	}

	else if (key == 3)
	{

		if (start_ptr != NULL)
			while (((*start_ptr)->key) != key)
			{
				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}

		if (start_ptr != NULL)
			while (((*start_ptr)->quad) != quad)
			{
				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}

		if (start_ptr != NULL)
			while (((*start_ptr)->numb) != numb)
			{
				if ((*start_ptr)->right == NULL)
				{
					*start_ptr = NULL;
					return;
				}
				*start_ptr = (*start_ptr)->right;
			}
	}
}

void movecol(map** start_ptr, int row, int col, int quad, int num, stack** point, int check)
{
	map* temp_ptr = NULL, * add_ptr = NULL, * new_ptr = NULL;
	int i = 0, key = 0, n = 0;

	if ((((*start_ptr)->left) == NULL) && ((*start_ptr)->right) == NULL)
	{
		if (check == 1)
		{
			push(point, *start_ptr);
		}
		(*start_ptr) = NULL;
	}

	else
	{

		while (key < 4)
		{
			if (*start_ptr == NULL)
				break;

			findcol(start_ptr, row, col, key, quad, num);

			if (*start_ptr != NULL)
			{
				temp_ptr = (*start_ptr);

				if (check == 1)
				{
					push(point, *start_ptr);
				}

				{
					if ((((*start_ptr)->left) == NULL) && ((*start_ptr)->right) == NULL)
						(*start_ptr) = NULL;

					else if (((*start_ptr)->left) == NULL)
						(*start_ptr)->right->left = NULL;

					else if (((*start_ptr)->right) == NULL)
						(*start_ptr)->left->right = NULL;

					else
					{
						(*start_ptr)->right->left = ((*start_ptr)->left);
						(*start_ptr)->left->right = ((*start_ptr)->right);
					}
				}

				temp_ptr = temp_ptr->down;

				while (temp_ptr != NULL)
				{

					add_ptr = temp_ptr;

					while ((add_ptr->left) != NULL)
					{
						add_ptr = add_ptr->left;
					}

					while (add_ptr != NULL)
					{
						if (check == 1)
						{
							push(point, add_ptr);
						}

						if ((add_ptr->down) == NULL)
							add_ptr->up->down = NULL;

						else
						{
							add_ptr->down->up = add_ptr->up;
							add_ptr->up->down = add_ptr->down;
						}

						add_ptr = add_ptr->right;

					}

					temp_ptr = temp_ptr->down;
				}
			}
			key++;

		}

		if ((*start_ptr) != NULL)
		{
			while ((*start_ptr)->up != NULL)
				*start_ptr = (*start_ptr)->up;

			while ((*start_ptr)->left != NULL)
				*start_ptr = (*start_ptr)->left;
		}
	}
}

void removecol(stack** start_ptr_list)
{
	while ((*start_ptr_list) != NULL)
	{

		if ((*start_ptr_list)->ptr->down != NULL)
			(*start_ptr_list)->ptr->down->up = (*start_ptr_list)->ptr;

		if ((*start_ptr_list)->ptr->up != NULL)
			(*start_ptr_list)->ptr->up->down = (*start_ptr_list)->ptr;

		if ((*start_ptr_list)->ptr->left != NULL)
			(*start_ptr_list)->ptr->left->right = (*start_ptr_list)->ptr;

		if ((*start_ptr_list)->ptr->right != NULL)
			(*start_ptr_list)->ptr->right->left = (*start_ptr_list)->ptr;

		pop(start_ptr_list);
	}
}

int dance(map* ptr, int as, int **matr)
{

	stack* stack = NULL;
	map* temp_ptr = ptr, * add_ptr = ptr;
	int i = 0, j = 0, k = 0;
	if (ptr == NULL)
	{
		if (as == 1)
			return FAILURE;


		return SUCCESS;
	}

	while (add_ptr != NULL)
	{
		if (add_ptr->down == NULL)
			return FAILURE;

		add_ptr = add_ptr->right;

	}



	while (ptr->left != NULL)
		ptr = ptr->left;

	temp_ptr = ptr->down;
	while (temp_ptr != NULL)
	{


		i = temp_ptr->row;
		j = temp_ptr->col;
		k = temp_ptr->numb;
		matr[i][j] = k;


		movecol(&ptr, i, j, ptr->quad, k, &stack, 1);


		if (dance(ptr, as + 1, matr) == SUCCESS)
		{
			return SUCCESS;
		}

		else
		{
			temp_ptr = temp_ptr->down;

			matr[i][j] = 0;

			removecol(&stack);
			while (ptr->left != NULL)
				ptr = ptr->left;

		}
	}

	return FAILURE;
}

int algo_start(int **Matrix)
{
	float start = 0, finish = 0;

	int N = P * P;

	map* ptr = NULL;
	int i = 0, j = 0, k = 0, numb = 0, mode = 1, quad = 0, s = 0;

	{

		j = 0;
		i = 0;
		k = 3;
		for (quad = N; quad > 0; quad--)
		{
			for (numb = N; numb > 0; numb--)
			{
				in(&ptr, i, j, k, numb, quad, mode);
			}
		}



		i = 0;
		k = 2;
		for (j = N - 1; j > -1; j--)
		{
			for (numb = N; numb > 0; numb--)
			{
				quad = ((i) / P) * P + (j) / P + 1;
				in(&ptr, i, j, k, numb, quad, mode);
			}
		}



		j = 0;
		k = 1;
		for (i = N - 1; i > -1; i--)
		{
			for (numb = N; numb > 0; numb--)
			{
				quad = ((i) / P) * P + (j) / P + 1;
				in(&ptr, i, j, k, numb, quad, mode);
			}
		}



		k = 0;
		for (i = N - 1; i > -1; i--)
		{
			for (j = N - 1; j > -1; j--)
			{
				quad = ((i) / P) * P + (j) / P + 1;
				in(&ptr, i, j, k, numb, quad, mode);
			}
		}

	}


	mode++;


	map* temp_ptr = NULL, * new_ptr = ptr, * add_ptr = NULL;

		k = 0;
		quad = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				for (numb = N; numb > 0; numb--)
				{
					add_ptr = NULL;
					ptr = new_ptr;
					findcol(&ptr, i, j, k, quad, numb);

					temp_ptr = ptr;

					in(&temp_ptr, i, j, k, numb, 0, mode);

				}
			}
		}


		k = 1;
		quad = 0;
		for (i = 0; i < N; i++)
		{
			for (numb = N; numb > 0; numb--)
			{
				for (j = N - 1; j > -1; j--)
				{
					add_ptr = NULL;
					ptr = new_ptr;
					findcol(&ptr, i, j, k, quad, numb);

					temp_ptr = ptr;

					in(&temp_ptr, i, j, k, numb, 0, mode);
				}
			}
		}


		k = 2;
		quad = 0;
		for (j = 0; j < N; j++)
		{
			for (numb = N; numb > 0; numb--)
			{
				for (i = N - 1; i > -1; i--)
				{
					add_ptr = NULL;
					ptr = new_ptr;
					findcol(&ptr, i, j, k, quad, numb);

					temp_ptr = ptr;

					in(&temp_ptr, i, j, k, numb, 0, mode);

				}
			}
		}


		k = 3;
		for (quad = 1; quad < N + 1; quad++)
		{
			for (numb = 1; numb < N + 1; numb++)
			{

				add_ptr = NULL;
				ptr = new_ptr;
				findcol(&ptr, 0, 0, k, quad, numb);

				temp_ptr = ptr;
				for (i = 0; i < N; i++)
				{
					for (j = 0; j < N; j++)
					{

						s = ((i) / P) * P + (j) / P + 1;
						if (s == temp_ptr->quad)
						{
							in(&temp_ptr, i, j, k, numb, quad, mode);

						}
					}
				}
			}
		}


	while (ptr->left != NULL)
		ptr = ptr->left;

		i = 0;
		while (ptr->key != 1)
		{
			temp_ptr = ptr;
			temp_ptr = temp_ptr->down;
			while (temp_ptr != NULL)
			{
				new_ptr = temp_ptr;
				for (k = 1; k < 4; k++)
				{


					add_ptr = ptr;
					while (add_ptr->key != k)
						add_ptr = add_ptr->right;


					if (k == 1)
					{
						while (add_ptr->row != temp_ptr->row)
							add_ptr = add_ptr->right;
					}



					if (k == 2)
					{
						while (add_ptr->col != temp_ptr->col)
							add_ptr = add_ptr->right;
					}

					if (k == 3)
					{
						while (add_ptr->quad != temp_ptr->quad)
							add_ptr = add_ptr->right;
					}

					while (add_ptr->numb != temp_ptr->numb)
						add_ptr = add_ptr->right;


					add_ptr = add_ptr->down;
					while (add_ptr->row != ptr->row)
						add_ptr = add_ptr->down;


					while (add_ptr->col != ptr->col)
						add_ptr = add_ptr->down;

					new_ptr->right = add_ptr;
					add_ptr->left = new_ptr;
					new_ptr = add_ptr;
				}
				temp_ptr = temp_ptr->down;
			}
			ptr = ptr->right;
			i++;
		}


	while (ptr->left != NULL)
		ptr = ptr->left;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{

			if (Matrix[i][j] != 0)
			{

				quad = ((i) / P) * P + (j) / P + 1;
				if (ptr != NULL)
					findcol(&ptr, i, j, 0, 0, Matrix[i][j]);
				if (ptr != NULL)
					movecol(&ptr, i, j, ptr->quad, Matrix[i][j], NULL, 0);
				if (ptr != NULL)
					while (ptr->left != NULL)
						ptr = ptr->left;
			}

		}
	}

	s = dance(ptr, 1, Matrix);

	return s;
}
