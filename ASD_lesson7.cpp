#include <iostream>
#include <ctime>

size_t* initArray(size_t* arr, const size_t SIZE) {
    arr = new size_t[SIZE];
    return arr;
}

void deInitArray(size_t* arr) {
    delete[] arr;
    arr = nullptr;
}

void fillArray(size_t* arr, const size_t SIZE, const size_t BORDER) {
    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = (rand() % BORDER + 1);
    }
}

void printArray(size_t* arr, const size_t SIZE, const size_t WIDTH) {
    for (size_t i = 0; i < SIZE; i++) {
        if (i % 10 == 0 && i > 0) std::cout << std::endl;
        std::cout.width(WIDTH);
        std::cout << arr[i]; 
    }
}

bool checkLenArray(const size_t SIZE) {
    return (SIZE <= 10) ? 1 : 0;
}

size_t medianArray(size_t* arr, const size_t SIZE) {
    size_t median = 0;
    median = (arr[0] + arr[SIZE - 1] + (arr[SIZE / 2 - 1])) / 3;

    return median;
}

void swap(size_t* a, size_t* b) {
    size_t tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(size_t* arr, const size_t SIZE) {
    
    if (checkLenArray(SIZE)) {
        
    }
    else {
        for (size_t i = 0; i < SIZE; i++) {
            size_t median = medianArray(arr, SIZE);
            if (arr[0] < median) {
                swap(&arr[0], &median);
            }
            if (arr[SIZE - i - 1] >= median) {
                swap(&arr[SIZE - i - 1], &median);
            }
        }
    }
}

int main()
{
    srand(time(0u));

    const size_t SIZE = 50;
    const size_t BORDER = 99;
    const size_t WIDTH = 5;


    size_t* arr = nullptr;
    arr = initArray(arr, SIZE);
    fillArray(arr, SIZE, BORDER);
    printArray(arr, SIZE, WIDTH);
    quickSort(arr, SIZE);
    std::cout << std::endl;
    printArray(arr, SIZE, WIDTH);
        
    deInitArray(arr);
    return 0;
}



