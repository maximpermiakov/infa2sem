#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <cmath>

unsigned arr[2000];
unsigned bin[20];
unsigned hib[20];
unsigned fib[20];

void swap(unsigned &lha, unsigned &rha) {
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void shell_sort(unsigned arr[], unsigned gaps[], int size, int gapssize, int &counter) {
    for (int i = 0; i < gapssize; i++) {
        for (int j = gaps[i]; j < size; j++) {
            int tmp = arr[j];
            int k;
            for (k = j; k >= gaps[i] && arr[k - gaps[i]] > tmp; k -= gaps[i]) {
                swap(arr[k], arr[k - gaps[i]]);
                counter++;
            }
        }
    }
}

int fibseq(int N) {
    int i;
    fib[0] = 1;
    fib[1] = 1;
    for (i = 2; fib[i - 2] + fib[i - 1] <= N; i++) {
        fib[i] = fib[i - 2] + fib[i - 1];
    }
    for (int j = 0; j < (i / 2); j++) {
        swap(fib[j], fib[i - j - 1]);
    }
    return i;
}

int hibseq(int N) {
    int i;
    hib[0] = 1;
    for (i = 1; pow(2, i + 1) - 1 <= N; i++) {
        hib[i] = pow(2, i + 1) - 1;
    }
    for (int j = 0; j < (i / 2); j++) {
        swap(hib[j], hib[i - j - 1]);
    }
    return i;
}

int binseq(int N) {
    int i;
    bin[0] = N;
    for (i = 1; bin[i - 1] > 1; i++) {
        bin[i] = bin[i - 1] / 2;
    }
    return i;
}

void measurement(int N, unsigned arr[], unsigned gaps[], int gapssize, std::string filename) {
    int counter = 0;
    int time = 0;
    unsigned seed = 1001;
    std::ofstream out(filename, std::ios::app);
    if (N == 100) {
        out << "N " << "time " << "swaps" << std::endl;
    }
    for (unsigned cnt = 1000; cnt > 0; --cnt) {
        std::default_random_engine rng(seed);
	    std::uniform_int_distribution<unsigned> dstr(0, N);
        for (int i = 0; i < N; i++) {
            arr[i] = dstr(rng);
        }
        auto begin = std::chrono::steady_clock::now();
        shell_sort(arr, fib, N, gapssize, counter);
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        time += time_span.count();
    }
    out << N << " " << time / 1000 << " " << counter / 1000 << std::endl;
}

int main() {
    int binsize = 0, hibsize = 0, fibsize = 0;
    for (int N = 100; N < 2000; N += 10) {
        binsize = binseq(N);
        hibsize = hibseq(N);
        fibsize = fibseq(N);
        measurement(N, arr, bin, binsize, "bin.txt");
        measurement(N, arr, hib, hibsize, "hib.txt");
        measurement(N, arr, fib, fibsize, "fib.txt");
    }
    return 0;
}