#include "url_features/StaticFeatures/Entropy.hpp"
#include <string_view>
#include <cmath>
#include <cstddef>

auto Entropy::Shannon_entropy(const std::string_view text) -> double {
    const size_t n = text.length();
    if (n == 0) return 0;

    size_t freq[256] = {0};
    for (const char c : text) {
        ++freq[static_cast<unsigned char>(c)];
    }

    double c_sum {0};
    for (const size_t i : freq) {
        if (i > 0) {
            const size_t a {i};
            c_sum += a * log2(a);
        }
    }
    return log2(static_cast<double>(n)) - c_sum / n;
}
auto Entropy::len(const std::string_view text) -> size_t {
    return text.length();
}

