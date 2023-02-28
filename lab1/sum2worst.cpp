#include <iostream>
#include <chrono>
#include <random>
#include <fstream>

int array[1000000];

void sum2(int array[], int N, int key) {
    int l = 0, r = N - 1;
    while (l != r) {
        if ((array[l] + array[r]) < key) {
            l++;
        }
        else if ((array[l] + array[r]) >= key) {
            r--;
        }
    }
}

int main()  {
    int key;
    unsigned seed = 1001;
    for (int i = 0; i < 1000000; i++) {
        array[i] = i;
    }
    for (int N = 100; N < 1000000; N += 5000) {
        std::default_random_engine rng(seed);
	    std::uniform_int_distribution<unsigned> dstr(0, 2 * N);
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 200; cnt != 0; --cnt) {
            key = dstr(rng);
            sum2(array, N, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << N << " " << time_span.count() << std::endl;
        std::ofstream out("D:\\infa2sem\\lab1\\sum2worst.txt", std::ios::app);
        if (out.is_open())
        {
            out << N << " " << time_span.count() << std::endl;
        }
        out.close();
    }
}