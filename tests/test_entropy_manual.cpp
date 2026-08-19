//
// Created by AD on 7/27/2026.
//

#include <algorithm>
#include <iostream>
#include <cassert>
#include <cmath>
#include "url_features/StaticFeatures/Entropy.hpp"
#include <chrono>
#include <vector>
#include <numeric>
#include <stdexcept>

int main() {
    int n;
    std::cout << "The number of measured rounds: " << "\n";
    if (!(std::cin >> n ) || n <= 0) {
        std::cerr << "Please enter a positive integer!.\n";
        return 1;
    }

    std::vector<long long> times;
    times.reserve(n);

    for (int i = 0; i < n; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        std::string url = "https://87khq5gx.ravabetensani.site/?ublib=ca0a10e1-15b1-489c-a27f-7703d460170c";
        double feature1 = Entropy::Shannon_entropy(url);
        size_t feature2 = Entropy::len(url);

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>( end - start);
        times.push_back(elapsed.count());
    }
    const double avg = std::accumulate(times.begin(), times.end(), 0.0) / n;

    auto [minRT, maxRT] = std::minmax_element(times.begin(), times.end());

    std::cout << "Avg time: " << avg << " microseconds\n";
    std::cout << "Fastest: " << *minRT << " microseconds\n";
    std::cout << "Slowest: " << *maxRT << " microseconds\n";

    std::cout << Entropy::len("");
    return 0;
}