//
// Created by AD on 8/1/2026.
//

#include "url_extractor/UrlExtractor.hpp"
#include <ada.h>


UrlExtractor::UrlExtractor(std::string_view x) : url(){}

auto UrlExtractor::extractURL() const -> UrlData::ExtractedPart {
    const UrlData::ExtractedPart parts;
    auto result = ada::parse<ada::url>(UrlExtractor::url);
    ada::url u = result.value();
    return parts;
}
