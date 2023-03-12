#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

unsigned arr[2000];

void swap(unsigned &lha, unsigned &rha) {
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void stepsort(unsigned arr[], int size, int step, int &counter, bool &sorted) {
    for (int i = 0; i + step < size; i++) {
        if (arr[i] > arr[i + step]) {
            swap(arr[i], arr[i + step]);
            counter++;
            sorted = false;
        }
    }
}

void hairbrush_sort(unsigned arr[], int size, int &counter) {
    bool sorted = false;
    int step = size;
    while (not sorted) {
        step /= 2;
        if (step == 0 or step == 1) {
            step = 1;
            sorted = true;
        }
        stepsort(arr, size, step, counter, sorted);
    }
}

int main() {
    int counter = 0, time = 0;
    unsigned seed = 1001;
    std::ofstream out("hairbrush.txt", std::ios::app);
    out << "N " << "time " << "swaps" << std::endl;
    for (int N = 100; N < 2000; N += 10) {
        counter = 0;
        time  = 0;
        for (unsigned cnt = 100; cnt > 0; --cnt) {
            std::default_random_engine rng(seed);
            std::uniform_int_distribution<unsigned> dstr(0, N);
            for (int i = 0; i < N; i++) {
                arr[i] = dstr(rng);
            }
            auto begin = std::chrono::steady_clock::now();
            hairbrush_sort(arr, N, counter);
            auto end = std::chrono::steady_clock::now();
            auto time_span =
            std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            time += time_span.count();
        }
        out << N << " " << time / 100 << " " << counter / 100 << std::endl;
    }
    return 0;
}