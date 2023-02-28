#include <iostream>
#include <chrono>
#include <random>
#include <fstream>

int array[1000000];

void sumoftwo(int array[], int N, int key) {
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (array[i] + array[j] == -1) {
                return;
            }
        }
    }
    return;
}

int main()  {
    int key;
    unsigned seed = 1001;
    for (int N = 100; N < 1000000; N += 5000) {
        std::default_random_engine rng(seed);
	    std::uniform_int_distribution<unsigned> dstr(0, N);
	    for (int i = 0; i < N; i++) {
            array[i] = dstr(rng);
        }
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1; cnt != 0; --cnt) {
            key = dstr(rng);
            sumoftwo(array, N, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << N << " " << time_span.count() << std::endl;
        std::ofstream out("D:\\infa2sem\\lab1\\sumoftwo.txt", std::ios::app);
        if (out.is_open())
        {
            out << N << " " << time_span.count() << std::endl;
        }
        out.close();
    }
}