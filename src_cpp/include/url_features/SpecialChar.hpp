//
// Created by AD on 7/29/2026.
//

#ifndef URLS_BASE_SPECIALCHAR_HPP
#define URLS_BASE_SPECIALCHAR_HPP

#include <string_view>
#include <array>
#include "data_container/CharIndex.hpp"

namespace  SpecialChar {
    auto valid_char_count(std::string_view part) -> std::array<size_t, UrlData::count>;
    auto dot_count(std::string_view part) -> int;
    auto hyphen_count(std::string_view part) -> int;
    auto hash_count(std::string_view part) -> int;
    auto percent_count(std::string_view part) -> int;
    auto slash_count(std::string_view part) -> int;
    auto at_sign_count(std::string_view part) -> int;
    auto ampersand_count(std::string_view part) -> int;
    auto equal_count(std::string_view part) -> int;
    auto question_count(std::string_view part) -> int;
    auto strange_char_count(std::string_view part) -> int;
}


#endif //URLS_BASE_SPECIALCHAR_HPP