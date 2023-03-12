#include <iostream>

unsigned arr[10] = {10, 170, 3, 5, 63, 70, 3, 767, 0, 45};

void swap(unsigned &lha, unsigned &rha) {
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void forward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (int i = begin_idx; i < end_idx; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void backward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (int i = end_idx; i > begin_idx; --i) {
        if (arr[i - 1] > arr[i]) {
            swap(arr[i - 1], arr[i]);
        }
    }
}

void shaker_sort(unsigned arr[], unsigned begin_idx, unsigned end_idx) {
    while (begin_idx < end_idx) {
        forward_step(arr, begin_idx, end_idx);
        end_idx -= 1;
        backward_step(arr, begin_idx, end_idx);
        begin_idx += 1;
    }
}

void check(unsigned arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            std::cout << "Incorrect" << std::endl;
            return;
        }
    }
    std::cout << "Correct" << std::endl;
    return;
}

int main() {
    int size = sizeof(arr) / sizeof(unsigned);
    unsigned begin_idx = 0, end_idx = size - 1;
    shaker_sort(arr, begin_idx, end_idx);
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    check(arr, size);
    return 0;
}