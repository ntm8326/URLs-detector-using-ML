//
// Created by AD on 7/31/2026.
//

#ifndef URLS_BASE_CHARINDEX_HPP
#define URLS_BASE_CHARINDEX_HPP
#include <cstddef>

namespace UrlData {
    enum class CharIndex : std::size_t {
        dot,
        hyphen,
        hash,
        percent,
        slash,
        at_sign,
        ampersand,
        equal,
        question,
        COUNT
    };
    inline constexpr std::size_t count = static_cast<std::size_t>(CharIndex::COUNT);
}




#endif //URLS_BASE_CHARINDEX_HPP