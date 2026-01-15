#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <conio.h>
#include <math.h>
#define CLASSES 4      
#define PARALLELS 11   

int main() {

    setlocale(LC_ALL, "RUS");
    int a[CLASSES][PARALLELS];

    printf("Введите количество учеников:\n");
    printf("Строки — классы (А–Г), столбцы — параллели (1–11)\n");

    for (int i = 0; i < CLASSES; i++) {
        for (int j = 0; j < PARALLELS; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nТаблица численности:\n");
    printf("       ");
    for (int p = 1; p <= PARALLELS; p++) {
        printf("%4d", p);
    }
    printf("\n");

    for (int i = 0; i < CLASSES; i++) {
        printf("Класс %c", 'A' + i);
        for (int j = 0; j < PARALLELS; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    int max_sum = 0;
    int max_parallel = 0;

    for (int j = 0; j < PARALLELS; j++) {
        int sum = 0;
        for (int i = 0; i < CLASSES; i++) {
            sum += a[i][j];
        }

        if (j == 0 || sum > max_sum) {
            max_sum = sum;
            max_parallel = j;
        }
    }

    printf("\nСамая большая параллель: %d-я\n", max_parallel + 1);
    printf("Численность: %d учеников\n", max_sum);

    return 0;
}
