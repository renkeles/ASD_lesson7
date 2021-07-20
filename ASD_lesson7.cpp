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
    std::cout << std::endl;
    for (size_t i = 0; i < SIZE; i++) {
        if (i % 10 == 0 && i > 0) std::cout << std::endl;
        std::cout.width(WIDTH);
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

bool checkLenArray(const size_t SIZE) {
    return (SIZE <= 10) ? 1 : 0;
}

void swap(size_t* a, size_t* b) {
    size_t tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(size_t* arr, const size_t SIZE){
    for(size_t i = 1; i < SIZE; i++){
        size_t k = i;
        while(k > 0 && arr[k - 1] > arr[k]){
            swap(&arr[k], &arr[k - 1]);
            k -= 1;
        }
    }
}

size_t medianArray(size_t* arr, const size_t SIZE) {

    size_t result = 0;
    size_t arMedianSize = 3;
    size_t *arMedian = new size_t[arMedianSize];
    arMedian[0] = arr[0];
    arMedian[1] = arr[SIZE / 2];
    arMedian[2] = arr[SIZE - 1];
    insertionSort(arMedian, arMedianSize);
    result = arMedian[1];
    delete[] arMedian;
    arMedian = nullptr;
    return result;
}

void quickSort(size_t* arr, const size_t SIZE) {
    if(checkLenArray(SIZE)){
        insertionSort(arr, SIZE);
    } else{
        size_t left = 0;
        size_t right = SIZE - 1;
        size_t median = medianArray(arr, SIZE);

        if(arr[0] == median){
            swap(&arr[0], &arr[SIZE / 2]);
        } else if(arr[SIZE - 1] == median){
            swap(&arr[SIZE - 1], &arr[SIZE / 2]);
        }

        do{
            while(arr[left] < median) left++;
            while(arr[right] > median) right--;

            if(left <= right){
                swap(&arr[left], &arr[right]);
                left++;
                right--;
            }
        }while(left <= right);

        if(right > 0) quickSort(arr, right + 1);
        if(left < SIZE) quickSort(&arr[left], SIZE - left);
    }

}

void bucketSort(size_t* arr, const size_t SIZE){
    const size_t bucket = 10;

    size_t buckets[bucket][SIZE + 1];
    for(size_t i = 0; i < bucket; i++){
        buckets[i][SIZE] = 0;
    }

    for(size_t digit = 1; digit < 100; digit *= 10){
        for(size_t i = 0; i < SIZE; i++){
            if(arr[i] % 2 == 0){
                size_t d = (arr[i] / digit) % bucket;
                size_t counter = buckets[d][SIZE];
                buckets[d][counter] = arr[i];
                counter++;
                buckets[d][SIZE] = counter;
                arr[i] = -1;
            }
        }
        size_t id = 0;
        for(size_t i = 0; i < bucket; ++i){
            for(size_t j = 0; j < buckets[i][SIZE]; ++j){
                while(arr[id] != -1) id++;
                arr[id] = buckets[i][j];
            }
            buckets[i][SIZE] = 0;
        }
    }
}

int main()
{
    srand(time(0u));

    const size_t SIZE = 100;
    const size_t BORDER = 99;
    const size_t WIDTH = 5;
    
    size_t* arr = nullptr;
    arr = initArray(arr, SIZE);
    fillArray(arr, SIZE, BORDER);
    printArray(arr, SIZE, WIDTH);
    bucketSort(arr, SIZE);
    printArray(arr, SIZE, WIDTH);
    quickSort(arr, SIZE);
    printArray(arr, SIZE, WIDTH);

    deInitArray(arr);
    return 0;
}

