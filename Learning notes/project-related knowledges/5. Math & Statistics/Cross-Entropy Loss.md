# Cross-Entropy Loss

#math #ml

## Định nghĩa (Binary)

$$L = -[y \log(\hat{y}) + (1-y)\log(1-\hat{y})]$$

## Multi-class Cross-Entropy (Categorical)

$$L = -\sum_{c=1}^{C} y_c \log(\hat{y}_c)$$

## Ý nghĩa trực giác


## Tại sao dùng Cross-Entropy cho Classification?


## Cross-Entropy trong LightGBM

> `objective = "multiclass"` → dùng multi-class log loss


## Gradient và Hessian


## Custom Loss Function (đang phát triển)

> Tham khảo: `src/Optimizer/loss.c`, `src/Optimizer/loss.h`


## Liên kết
- [[Softmax Function]]
- [[Gradient Boosting]]
- [[LightGBM]]
