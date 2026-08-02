//
// Created by AD on 7/14/2026.
//
#ifndef ENTROPY_HPP
#define ENTROPY_HPP

#include <string_view>

namespace  Entropy {
    auto Shannon_entropy(std::string_view text) -> double;
    auto len(std::string_view text) -> size_t;
}

#endif //ENTROPY_HPP