// lab15_Петрушев.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

void printArray(double arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void sortDescending(double arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortEvenOddIndexes(double arr[], int size) {
    
    int evenSize = (size + 1) / 2;
    int oddSize = size / 2;

    double* evenElements = new double[evenSize];
    double* oddElements = new double[oddSize];

    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            evenElements[evenCount++] = arr[i];
        }
        else {
            oddElements[oddCount++] = arr[i];
        }
    }

    sortDescending(evenElements, evenCount);
    sortDescending(oddElements, oddCount);

    evenCount = 0;
    oddCount = 0;
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            arr[i] = evenElements[evenCount++];
        }
        else {
            arr[i] = oddElements[oddCount++];
        }
    }

    delete[] evenElements;
    delete[] oddElements;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    std::cout << "Введіть кількість елементів масиву: ";
    std::cin >> n;

    double* arr = new double[n];
    std::cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Початковий масив: ";
    printArray(arr, n);

    sortEvenOddIndexes(arr, n);

    std::cout << "Відсортований масив: ";
    printArray(arr, n);

    delete[] arr;

    return 0;
}