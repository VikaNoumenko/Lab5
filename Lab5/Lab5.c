#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>



void printArray(int *array, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            printf("%3d", array[row * columns + column]);
        }
        printf("\n");
    }
}

void firstAction(int *array, int size) {//заменили элементы столбца abs - значением
    for (int i = 0; i < size; i++) {
        array[i] = abs(array[i]);
    }
}

void secondAction(int *array, int size) {// вывели количество отрицательных элементов
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            count++;
        }
    }
    printf("Quanyity of negative elements: %d\n", count);
}

void function(void f(int *array, int size), int *array, int rows, int columns) {// для столбцов, у которых последний элмент имеет нечетное значение
    for (int row = 0; row < rows; row++) {
        if (array[row * columns + columns - 1] < 0) {
            f(&array[row * columns], columns);
        }
    }
}

int main(int argc, const char * argv[]) {
	setlocale(LC_ALL, "Rus");

	//как сделать рандом
	/*
	int  i, arrayOne[10], a = -5, b = 10;
	for (i = 0; i < 10; i++)
		arrayOne[i] = random(b - a + 1) + a;
	printf(" n Array: \n");
	for (i = 0; i < 10; i++)
		printf("%d", arrayOne[i]);
	*/
    int arrayOne[10][10] = {
        {1, -2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        {-1, 2, -3, 4, 5, 6, 7, 8, 9, 10 },
        {1, 2, 3, 4, 5, 6, 7, 8, 9, -10 },
        {1, 2, 3, 4, 5, 6, 7, 8, 9, -10 },
	    {-1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	    { 1, -2, 3, 4, 5, 6, 7, 8, 9, -10 },
	    { 1, 2, 3, 4, 5, 6, 7, -8, 9, 10 },
	    { 1, 2, 3, 4, 5, -6, 7, 8, 9, 10 },
	    { -1, 2, 3, -4, 5, 6, 7, 8, 9, -10 }
    };

    int arrayTwo[10][10] = {
        {-1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, -2, -3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        {1, -2, 3, -4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5,-6, -7, -8, 9, 10},
        {-1, 2, 3, -4, 5, 6, 7, 8, 9, 10},
        {-1, -2, -3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
	    { 1, -2, 3, 4, 5, 6, 7, 8, 9,-10 },
	    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
    };

    printf("FIRST ARRAY:\n");
    printArray(&arrayOne[0][0], 10, 10);

    printf("\nSECOND ARRAY:\n");
    printArray(&arrayTwo[0][0], 10, 10);

    function(secondAction, &arrayOne[0][0], 10, 10);
    function(firstAction, &arrayOne[0][0], 10, 10);

    printf("\n 1 array after intermediate function:\n");
    printArray(&arrayOne[0][0], 10, 10);

    function(secondAction, &arrayTwo[0][0], 10, 10);
    function(firstAction, &arrayTwo[0][0], 10, 10);

    printf("\n 2nd array after intermediate function:\n");
    printArray(&arrayTwo[0][0], 10, 10);
	_getch();
    return 0;
}
