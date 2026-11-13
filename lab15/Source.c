#define _CRT_SECURE_NO_WARNINGS
#define MAX_COL 100
#define MAX_ROW 100
#define XMIN -10
#define XMAX 10
#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

void task1(void);
void full_array(int* ptr_arr, int row, int col);
void put_array(int* ptr_arr, int row, int col, int width);
int el_penultimate_col(int* ptr_arr, int col);
int find_min_el(int* ptr_arr, int col, int user_row);
int find_max_el(int* ptr_arr, int row, int user_col);
int find_diagonal_el(int* ptr_arr, int row, int col, int diagonal_element);
void task2(void);
void rand_full_array(int* ptr_arr, int row, int col);
void transpose(int* ptr_arr, int row, int col);
double arithmetic_mean(int* ptr_arr, int col); 
int count_pair_row(int* ptr_arr, int row, int col);
int count_pair_col(int* ptr_arr, int row, int col);
int count_pair_all(int* ptr_arr, int row, int col);
int coordinates_max_element_1(int* ptr_arr, int row, int col);
int coordinates_max_element_2(int* ptr_arr, int row, int col);


int main(void) {

	setlocale(LC_CTYPE, "RUS");

	int user_choise;

	printf("Выберите задание: ");
	scanf("%d", &user_choise);
	printf("\n");

	switch (user_choise) {
	case 1: task1(); break;
	case 2: task2(); break;
	default: printf("Такого задания нет\n"); break;
	}

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
	put_array((int*)arr, row, col, MAX_COL);
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

void put_array(int* ptr_arr, int row, int col, int width) {

	for (int i = 0; i <= col; i++) {

		printf(" | %10d | ", i);

	}

	printf("\n");

	for (int r = 0; r < row; r++) {

		printf(" | %10d | ", r + 1);

		for (int c = 0; c < col; c++) {

			printf(" | %10d | ", *(ptr_arr + r * width + c));

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

void task2(void) {

	int array[7][7];

	rand_full_array((int*)array, 7, 7);

	printf("Исходный массив:\n");
	put_array((int*)array, 7, 7, 7);

	transpose(array, 7, 7);

	printf("Транспонированный массив:\n");
	put_array((int*)array, 7, 7, 7);
	
	printf("Cреднее арифметическое элементов четвертой строки, кратных трем: %f\n", arithmetic_mean(array, 7));
	printf("Число пар одинаковых соседних элементов, расположенных в одной строке: %d\n", count_pair_row(array, 7, 7));
	printf("Число пар одинаковых соседних элементов, расположенных в одном столбце: %d\n", count_pair_col(array, 7, 7));
	printf("Число пар одинаковых соседних элементов, расположенных в одной строке и в одном столбце: %d\n", count_pair_all(array, 7, 7));
	printf("Координаты максимального элемента: (%d, %d)\n", coordinates_max_element_1(array, 7, 7), coordinates_max_element_2(array, 7, 7));

}

void rand_full_array(int* ptr_arr, int row, int col) {

	int stime;
	long ltime;

	ltime = time(NULL);
	stime = (unsigned)ltime / 2;
	srand(stime);

	for (int r = 0; r < row; r++) {

		for (int c = 0; c < col; c++) {

			*(ptr_arr + r * 7 + c) = XMIN + (XMAX - XMIN) * rand() / RAND_MAX;
		}
	}
}



void transpose(int* ptr_arr, int row, int col) {

	for (int r = 0; r < row; r++) {

		for (int c = r + 1; c < col; c++) {

			int temp = *(ptr_arr + 7 * r + c);
			*(ptr_arr + 7 * r + c) = *(ptr_arr + 7 * c + r);
			*(ptr_arr + 7 * c + r) = temp;

		}

	}

}

double arithmetic_mean(int* ptr_arr, int col) {

	double res = 0;
	double count = 0;

	for (int c = 0; c < col; c++) {

		if (*(ptr_arr + 7 * 3 + c) % 3 == 0) { 

			res += *(ptr_arr + 7 * 3 + c);
			count += 1;

		}

	}

	if (count == 0) return -1;
	return res / count;
}

int count_pair_row(int* ptr_arr, int row, int col) {

	int count = 0;

	for (int r = 0; r < row; r++) {

		for (int c = 0; c < col - 1; c++) {

			if (*(ptr_arr + 7 * r + c) == *(ptr_arr + 7 * r + c + 1)) count += 1;
		}
	}

	return count;
}

int count_pair_col(int* ptr_arr, int row, int col) {

	int count = 0;

	for (int r = 0; r < row - 1; r++) {

		for (int c = 0; c < col; c++) {

			if (*(ptr_arr + 7 * r + c) == *(ptr_arr + 7 * (r + 1) + c)) count += 1;
		}
	}

	return count;
}

int count_pair_all(int* ptr_arr, int row, int col) {

	return count_pair_row(ptr_arr, 7, 7) + count_pair_col(ptr_arr, 7, 7);
}

int coordinates_max_element_1(int* ptr_arr, int row, int col) {
	int max_el = INT_MIN;
	int coord;

	for (int r = 0; r < row; r++) {

		for (int c = 0; c < col; c++) {

			if (*(ptr_arr + r * 7 + c) >= max_el) { max_el = *(ptr_arr + r * 7 + c); coord = r; }
		}
	}

	return coord + 1;
}

int coordinates_max_element_2(int* ptr_arr, int row, int col) {
	int max_el = INT_MIN;
	int coord;

	for (int r = 0; r < row; r++) {

		for (int c = 0; c < col; c++) {

			if (*(ptr_arr + r * 7 + c) >= max_el) { max_el = *(ptr_arr + r * 7 + c); coord = c; }
		}
	}

	return coord + 1;
}