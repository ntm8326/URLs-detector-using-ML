# LightGBM - Hyperparameter Tuning

#ml

## Các hyperparameters quan trọng

### Objective & Boosting

| Parameter | Giá trị trong project | Mô tả |
|-----------|----------------------|-------|
| `objective` | `multiclass` | |
| `num_class` | `4` | |
| `boosting_type` | `gbdt` | |

### Tree Structure

| Parameter | Giá trị trong project | Mô tả |
|-----------|----------------------|-------|
| `max_depth` | `5` | |
| `num_leaves` | `24` | |
| `min_data_in_leaf` | `50` | |

### Training

| Parameter | Giá trị trong project | Mô tả |
|-----------|----------------------|-------|
| `n_estimators` | `4000` | |
| `learning_rate` | `0.025` | |
| `early_stopping_rounds` | `100` | |

### Sampling & Regularization

| Parameter | Giá trị trong project | Mô tả |
|-----------|----------------------|-------|
| `colsample_bytree` | `0.75` | |
| `subsample` | `0.8` | |
| `reg_alpha` | `0.1` | |
| `reg_lambda` | `1.0` | |
| `class_weight` | `balanced` | |

## Chiến lược tuning


### Tại sao `max_depth=5` và `num_leaves=24`?


### Tại sao `learning_rate` thấp + `n_estimators` cao?


### Tại sao dùng `class_weight=balanced`?


### Vai trò của Early Stopping


## Liên kết
- [[LightGBM]]
- [[Overfitting và Underfitting]]
- [[Regularization - L1 và L2]]
- [[Class Imbalance và cách xử lý]]
