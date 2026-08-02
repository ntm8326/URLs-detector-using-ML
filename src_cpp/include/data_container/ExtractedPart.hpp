//
// Created by AD on 7/31/2026.
//

#ifndef URLS_BASE_EXTRACTEDPART_HPP
#define URLS_BASE_EXTRACTEDPART_HPP

#include <string_view>
namespace UrlData {
    struct ExtractedPart {
        std::string_view scheme;
        std::string_view netloc;
        std::string_view path;
        std::string_view params;
        std::string_view query;
        std::string_view fragment;
        std::string_view username;
        std::string_view password;
        std::string_view port;
        std::string_view subdomain;
        std::string_view domain;
        std::string_view suffix;
    };
}


#endif //URLS_BASE_EXTRACTEDPART_HPP