#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {
    constexpr size_t N = 100'000'000;

    vector<int> v(N, 1);

    long long sum = 0;

    for (size_t stride = 1; stride <= 1024; stride *= 2) {

        auto start = high_resolution_clock::now();

        for (size_t offset = 0; offset < stride; ++offset) {
            for (size_t i = offset; i < N; i += stride) {
                sum += v[i];
            }
        }

        auto end = high_resolution_clock::now();

        cout << "stride = "
             << stride
             << " time = "
             << duration_cast<milliseconds>(end - start).count()
             << " ms\n";
    }

    cout << sum << '\n';
}