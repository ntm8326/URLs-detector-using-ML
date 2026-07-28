# Levenshtein Distance

#math #feature

## Định nghĩa

> Số phép biến đổi tối thiểu (insert, delete, substitute) để chuyển chuỗi A thành chuỗi B


## Công thức Dynamic Programming


## Normalized Similarity

$$\text{similarity} = 1 - \frac{\text{distance}}{\max(|A|, |B|)}$$


## Tối ưu hóa trong project

### Threshold-based filtering

> `threshold = max(1, floor(len(data) / 7))`


### Length-difference pruning


### `rapidfuzz` library — tại sao dùng thay vì tự implement?


### `score_cutoff` parameter


## Ứng dụng trong phát hiện Typosquatting


## Liên kết
- [[Typosquatting]]
- [[Nhóm 5 - Lexical và String Analysis]]
