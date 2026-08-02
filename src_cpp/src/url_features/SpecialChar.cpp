//
// Created by AD on 7/29/2026.
//
#include <string_view>
#include <array>
#include "url_features/SpecialChar.hpp"
#include "data_container/CharIndex.hpp"
#include "data_container/ExtractedPart.hpp"

auto SpecialChar::valid_char_count(std::string_view part) -> std::array<size_t, UrlData::count> {
    std::array<size_t, UrlData::count> result {0};
    if (part.empty()) return result;

    size_t freq[256] = {0};
    for (char c : part) {
        ++freq[static_cast<unsigned char>(c)];
    }
    result[static_cast<size_t>(UrlData::CharIndex::dot)] = freq['.'];
    result[static_cast<size_t>(UrlData::CharIndex::hash)] = freq['#'];
    result[static_cast<size_t>(UrlData::CharIndex::percent)] = freq['%'];
    result[static_cast<size_t>(UrlData::CharIndex::hyphen)] = freq['-'];
    result[static_cast<size_t>(UrlData::CharIndex::slash)] = freq['/'];
    result[static_cast<size_t>(UrlData::CharIndex::at_sign)] = freq['@'];
    result[static_cast<size_t>(UrlData::CharIndex::ampersand)] = freq['&'];
    result[static_cast<size_t>(UrlData::CharIndex::equal)] = freq['='];
    result[static_cast<size_t>(UrlData::CharIndex::question)] = freq['?'];

    return result;
}
auto SpecialChar::dot_count(std::string_view part) -> int {
    if (part.empty()) return 0;
    int count {0};
    for (char c : part) {
        if (c == '.') {
            count++;
        }
    }
    return count;
}
auto SpecialChar::hyphen_count(std::string_view part) -> int {
    if (part.empty()) return 0;
    int count {0};
    for (char c : part) {
        if (c == '-') {
            count++;
        }
    }
    return count;
}
auto SpecialChar::hash_count(std::string_view part) -> int {
    if (part.empty()) return 0;
    int count {0};
    for (char c : part) {
        if (c == '#') {
            count++;
        }
    }
    return count;
}
auto SpecialChar::percent_count(std::string_view part) -> int {
    if (part.empty()) return 0;
    int count {0};
    for (char c : part) {
        if (c == '%') {
            count++;
        }
    }
    return count;
}
auto SpecialChar::ampersand_count(std::string_view part) -> int {
    if (part.empty()) return 0;
    int count {0};
    for (char c : part) {
        if (c == '&') {
            count++;
        }
    }
    return count;
}
auto SpecialChar::slash_count(std::string_view part) -> int {
    if (part.empty()) return 0;
    int count {0};
    for (char c : part) {
        if (c == '/') {
            count++;
        }
    }
    return count;
}
auto SpecialChar::at_sign_count(std::string_view part) -> int {
    if (part.empty()) return 0;
    int count {0};
    for (char c : part) {
        if (c == '@') {
            count++;
        }
    }
    return count;
}
auto SpecialChar::equal_count(std::string_view part) -> int {
    if (part.empty()) return 0;
    int count {0};
    for (char c : part) {
        if (c == '=') {
            count++;
        }
    }
    return count;
}
auto SpecialChar::question_count(std::string_view part) -> int {
    if (part.empty()) return 0;
    int count {0};
    for (char c : part) {
        if (c == '?') {
            count++;
        }
    }
    return count;
}
auto SpecialChar::strange_char_count(std::string_view part) -> int {
    return 0;
}
