#include <iostream>
#include <chrono>
#include <random>
#include <fstream>

int array[1000000];
int score[1000000]{};

int perebor(int array[], int N, int x) {
    for (int i = 0; i < N; i++) {
        if (array[i] == x) {
            score[i]++;
            return i;
        }
    }
    return -1;
}

void swap(int &i, int &j)
{
	int tmp; 
	tmp = i;
    i = j;
    j = tmp;
}

int main()  {
    int key;
    int a;
    unsigned seed = 1001;
    for (int N = 100; N < 1000000; N += 5000) {
        std::default_random_engine rng(seed);
	    std::uniform_int_distribution<unsigned> dstr(0, N);
	    for (int i = 0; i < N; i++) {
            array[i] = dstr(rng);
        }
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000; cnt != 0; --cnt) {
            key = dstr(rng);
            a = perebor(array, N, key);
            if (a != -1 and a != 0 and score[a] > score[a - 1]) {
                swap(array[a], array[a - 1]);
                swap(score[a], score[a - 1]);
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << N << " " << time_span.count() << std::endl;
        std::ofstream out("D:\\infa2sem\\lab1\\stratCravn.txt", std::ios::app);
        if (out.is_open())
        {
            out << N << " " << time_span.count() << std::endl;
        }
        out.close();
    }
}