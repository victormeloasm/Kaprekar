#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intToStr(int num, char str[]) {
    sprintf(str, "%04d", num);
}

int sortDesc(const void *a, const void *b) {
    return (*(char*)b - *(char*)a);
}

int sortAsc(const void *a, const void *b) {
    return (*(char*)a - (*(char*)b));
}

int kaprekarRoutine(int v) {
    char str[5];
    intToStr(v, str);
    int steps = 0;

    while (v != 0 && v != 6174) {
        steps++;

        intToStr(v, str);

        qsort(str, 4, sizeof(char), sortDesc);
        int d = atoi(str);

        qsort(str, 4, sizeof(char), sortAsc);
        int a = atoi(str);

        v = d - a;
    }

    return steps;
}

int main() {
    int totalSteps = 0;

    for (int i = 1; i <= 9999; i++) {
        totalSteps += kaprekarRoutine(i);
    }

    printf("Total steps: %d\n", totalSteps);
    return 0;
}
