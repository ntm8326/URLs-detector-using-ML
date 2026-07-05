# Regularization - L1 và L2

#math #ml

## Regularization là gì?


## L1 Regularization (Lasso)

$$\text{Loss} + \alpha \sum |w_i|$$


### Đặc điểm: Sparse weights (Feature Selection)


## L2 Regularization (Ridge)

$$\text{Loss} + \lambda \sum w_i^2$$


### Đặc điểm: Smooth weights


## L1 + L2 (Elastic Net)


## Trong LightGBM

| Parameter | Regularization | Giá trị trong project |
|-----------|---------------|----------------------|
| `reg_alpha` | L1 | 0.1 |
| `reg_lambda` | L2 | 1.0 |


## Tại sao cần Regularization trong project?


## Liên kết
- [[Overfitting và Underfitting]]
- [[LightGBM - Hyperparameter Tuning]]
- [[Gradient Boosting]]
