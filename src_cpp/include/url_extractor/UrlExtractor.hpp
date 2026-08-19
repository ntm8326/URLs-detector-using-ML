//
// Created by AD on 8/1/2026.
//

#ifndef URLS_BASE_URLEXTRACTOR_HPP
#define URLS_BASE_URLEXTRACTOR_HPP
#include <string>
#include <utility>
#include <data_container/ExtractedPart.hpp>


class UrlExtractor {
private:
    std::string url;
public:
    explicit UrlExtractor(std::string_view x);
    [[nodiscard]] auto extractURL() const -> UrlData::ExtractedPart;
};


#endif //URLS_BASE_URLEXTRACTOR_HPP