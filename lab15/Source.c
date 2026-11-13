#define _CRT_SECURE_NO_WARNINGS
#define MAX_COL 100
#define MAX_ROW 100
#include <stdio.h>
#include <locale.h>
#include <limits.h>

void task1(void);
void full_array(int* ptr_arr, int row, int col);
void put_array(int* ptr_arr, int row, int col);
int el_penultimate_col(int* ptr_arr, int col);
int find_min_el(int* ptr_arr, int col, int user_row);
int find_max_el(int* ptr_arr, int row, int user_col);
int find_diagonal_el(int* ptr_arr, int row, int col, int diagonal_element);
void task2(void);

int main(void) {

	setlocale(LC_CTYPE, "RUS");

	task1();
	//task2();

	return  0;
}

void task1(void) {

	int row, col;
	int arr[MAX_ROW][MAX_COL];
	int user_col, user_row, diagonal_element;

	printf("Введите количество строк массива: ");
	scanf("%d", &row);
	printf("\n");
	printf("Введите количество столбцов массива: ");
	scanf("%d", &col);

	full_array((int*)arr, row, col);
	put_array((int*)arr, row, col);
	printf("%d\n", el_penultimate_col((int*)arr, col));

	printf("Введите строку: ");
	scanf("%d", &user_row);
	printf("\n");

	printf("%d - минимальный в заданной строке\n", find_min_el((int*)arr, col, user_row - 1));

	printf("Введите столбец: ");
	scanf("%d", &user_col);
	printf("\n");

	printf("%d - максимальный в указанном столбце\n", find_max_el((int*)arr, row, user_col - 1));

	printf("Введите элемент: ");
	scanf("%d", &diagonal_element);
	printf("\n");

	printf("Элемент на диагонали (1 - да, 0 - нет): %d\n", find_diagonal_el((int*)arr, row, col, diagonal_element));

}

void full_array(int* ptr_arr, int row, int col) {

	for (int r = 0; r < row; r++) {

		for (int c = 0; c < col; c++) *(ptr_arr + r * MAX_COL + c) = (c + 1) * 1000 + (r + 1);

	}

}

void put_array(int* ptr_arr, int row, int col) {

	for (int i = 0; i <= col; i++) {

		printf(" | %10d | ", i);

	}

	printf("\n");

	for (int r = 0; r < row; r++) {

		printf(" | %10d | ", r + 1);

		for (int c = 0; c < col; c++) {

			printf(" | %10d | ", *(ptr_arr + r * MAX_COL + c));

		}

		printf("\n");
	}
}

int el_penultimate_col(int* ptr_arr, int col) {

	int element;

	element = *(ptr_arr + col - 2);

	return element;
}

int find_min_el(int* ptr_arr, int col, int user_row) {

	int min_el = INT_MAX;

	for (int c = 0; c < col; c++) {

		if (*(ptr_arr + MAX_COL * user_row + c) < min_el) min_el = *(ptr_arr + MAX_COL * user_row + c);

	}

	return min_el;
}

int find_max_el(int* ptr_arr, int row, int user_col) {

	int max_el = INT_MIN;

	for (int r = 0; r < row; r++) {

		if (*(ptr_arr + MAX_COL * r + user_col) > max_el) max_el = *(ptr_arr + MAX_COL * r + user_col);

	}

	return max_el;
}

int find_diagonal_el(int* ptr_arr, int row, int col, int diagonal_element) {

	int min_row_col;

	if (col <= row) min_row_col = col;
	else min_row_col = row;

	for (int i = 0; i < min_row_col; i++) {
		if (*(ptr_arr + i * MAX_COL + i) == diagonal_element) return 1;
	}

	return 0;
}