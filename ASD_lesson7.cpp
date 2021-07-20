#include <iostream>
#include <ctime>

size_t* initArray(size_t* arr, const size_t SIZE) {
    arr = new size_t[SIZE];
    return arr;
}

void fillArray(size_t* arr, const size_t SIZE, const size_t BORDER) {
    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = (rand() % BORDER + 1);
    }
}

void printArray(size_t* arr, const size_t SIZE, const size_t WIDTH) {
    for (size_t i = 0; i < SIZE; i++) {
        std::cout.width(WIDTH);
        std::cout << arr[i];
    }
}

bool checkLenArray(const size_t SIZE) {
    return (SIZE <= 10) ? 1 : 0;
}

size_t medianArray(size_t* arr, const size_t SIZE) {
    size_t median = 0;

    /// <summary>
    /// 
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="SIZE"></param>
    /// <returns></returns>

    return median;
}

int main()
{
    srand(time(0u));

    const size_t SIZE = 100;
    const size_t BORDER = 100;
    const size_t WIDTH = 5;


    size_t* arr = nullptr;
    arr = initArray(arr, SIZE);
    fillArray(arr, SIZE, BORDER);
    printArray(arr, SIZE, WIDTH);

    

    return 0;
}

