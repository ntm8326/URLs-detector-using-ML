# Nhóm 5 - Lexical và String Analysis

#feature

## Mô tả

> Phân tích chuỗi/lexical để phát hiện các pattern bất thường trong URL

## Danh sách Features

| Feature | Mô tả |
|---------|-------|
| `normalized_levenshtein_domain` | Levenshtein similarity giữa domain và whitelist |
| `normalized_levenshtein_subdomain` | Levenshtein similarity giữa subdomain và whitelist |
| `random_domain_check` | Consonant ratio của domain (phát hiện DGA) |
| `random_subdomain_check` | Consonant ratio của subdomain |
| `number_ratio_domain` | Tỷ lệ chữ số trong domain |
| `number_ratio_subdomain` | Tỷ lệ chữ số trong subdomain |
| `repeated_domain_check` | Tỷ lệ ký tự lặp liên tiếp trong domain |
| `repeated_path_check` | Tỷ lệ ký tự lặp liên tiếp trong path |
| `repeated_url_check` | Tỷ lệ ký tự lặp liên tiếp trong toàn URL |
| `longest_repeated_chain` | Chuỗi ký tự lặp liên tiếp dài nhất |
| `ip_domain` | Domain là địa chỉ IP |
| `suspicious_key_domain` | Keyword đáng ngờ trong domain |
| `suspicious_key_subdomain` | Keyword đáng ngờ trong subdomain |
| `suspicious_key_path` | Keyword đáng ngờ trong path |
| `suspicious_key_query` | Keyword đáng ngờ trong query |
| `shortened` | URL thuộc dịch vụ rút gọn |

## Trực giác (Intuition)


## Phân tích chi tiết từng feature


### Levenshtein-based features


### Consonant ratio (DGA detection)


### Digit ratio


### Repeated character ratio


### Suspicious keywords


## Liên kết
- [[Feature Engineering - Tổng quan]]
- [[Levenshtein Distance]]
- [[Typosquatting]]
- [[DGA - Domain Generation Algorithm]]
- [[URL Shortener - Rủi ro bảo mật]]
