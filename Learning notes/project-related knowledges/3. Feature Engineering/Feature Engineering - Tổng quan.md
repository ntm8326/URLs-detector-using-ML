# Feature Engineering - Tổng quan

#feature

## Feature Engineering là gì?


## Tại sao Feature Engineering quan trọng?


## Phân loại Feature Engineering

### Feature Extraction (trích xuất)


### Feature Transformation (biến đổi)


### Feature Selection (chọn lọc)


## Các nhóm đặc trưng trong project (57 features)

| Nhóm | Số lượng | Mô tả |
|------|----------|-------|
| Nhóm 1 | 13 | URL Parts Existence |
| Nhóm 2 | 6 | Length Features |
| Nhóm 3 | 6 | Shannon Entropy |
| Nhóm 4 | 11 | Special Characters |
| Nhóm 5 | 16 | Lexical / String Analysis |
| Nhóm 6 | 5 | Đặc trưng bổ sung |

## Pipeline trích xuất đặc trưng

```
Raw URL → Normalize → Extract Parts → Compute Features → Feature Vector
```

## Liên kết
- [[Nhóm 1 - URL Parts Existence]]
- [[Nhóm 2 - Length Features]]
- [[Nhóm 3 - Shannon Entropy]]
- [[Nhóm 4 - Special Characters]]
- [[Nhóm 5 - Lexical và String Analysis]]
- [[Nhóm 6 - Các đặc trưng bổ sung]]
- [[Feature Importance Analysis]]
