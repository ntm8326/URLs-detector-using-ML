//
// Created by AD on 7/30/2026.
//
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <numeric>
#include <algorithm>
#include "url_features/StaticFeatures/SpecialChar.hpp"
#include "data_container/CharIndex.hpp"
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
        int feature1 = SpecialChar::dot_count(url);
        int feature2 = SpecialChar::hyphen_count(url);
        int feature3 = SpecialChar::hash_count(url);
        int feature4 = SpecialChar::ampersand_count(url);
        int feature5 = SpecialChar::at_sign_count(url);
        int feature6 = SpecialChar::slash_count(url);
        int feature7 = SpecialChar::percent_count(url);
        int feature8 = SpecialChar::equal_count(url);
        int feature9 = SpecialChar::question_count(url);
        auto counts = SpecialChar::valid_char_count(url);



        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>( end - start);
        times.push_back(elapsed.count());
    }
    const double avg = std::accumulate(times.begin(), times.end(), 0.0) / n;

    auto [minRT, maxRT] = std::minmax_element(times.begin(), times.end());

    std::cout << "Avg time: " << avg << " microseconds\n";
    std::cout << "Fastest: " << *minRT << " microseconds\n";
    std::cout << "Slowest: " << *maxRT << " microseconds\n";

    return 0;
}