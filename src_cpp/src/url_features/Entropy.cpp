#include "url_features/Entropy.hpp"
#include <string>
#include <cmath>

auto Entropy::Shannon_entropy(const std::string &text) -> double {
    const size_t n = text.length();
    if (n == 0) return 0;

    int freq[256] = {0};
    for (char c : text) {
        ++freq[static_cast<unsigned char>(c)];
    }

    double c_sum {0};
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            int a {freq[i]};
            c_sum += a * log2(a);
        }
    }
    return log2(static_cast<double>(n)) - c_sum / n;
}

auto Entropy::len(const std::string &text) -> size_t {
    return text.length();
}

