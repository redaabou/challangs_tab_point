#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void removeEvenNumbers(int arr[], int n) {
    int oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            arr[oddCount] = arr[i];
            oddCount++;
        }
    }

    for (int i = oddCount; i < n; i++) {
        arr[i] = 0;
    }
}

int stringLength(char *str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }

    return length;
}

void toUpperCase(char *str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        str++;
    }
}

int main() {
    // Tri par sélection
    int numbers[] = {3, 1, 7, 9, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    selectionSort(numbers, size);
    printArray(numbers, size);

    // Suppression des nombres pairs
    int numbers2[10];
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        numbers2[i] = rand() % 100;
    }

    removeEvenNumbers(numbers2, 10);
    printArray(numbers2, 10);

    // Calcul de la taille d'une chaîne de caractères
    char str[] = "Hello, world!";
    int length = stringLength(str);
    printf("Length: %d\n", length);

    // Conversion en majuscules
    char str2[] = "Hello, world!";
    toUpperCase(str2);
    printf("Uppercase: %s\n", str2);

    return 0;
}