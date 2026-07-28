# Đề xuất Kiến trúc OOP cho Hệ thống Phân loại URL

Dựa trên "The Ultimate Blueprint" và hiện trạng dự án (có phần Python Feature Extraction cũ và C++ đang được xây dựng ở `src_v2`), dưới đây là đề xuất cấu trúc Lập trình Hướng đối tượng (OOP) toàn diện. Cấu trúc này chia tách rõ ràng trách nhiệm giữa C++ (CPU - Tiền xử lý, Lọc, Trích xuất đặc trưng) và Python/CUDA (GPU - Deep Learning, Machine Learning, MLOps).

---

## 1. Khối C++ Core (High-Speed CPU Engine)
Khối này chịu trách nhiệm toàn bộ quá trình tiền xử lý, lọc O(1) và trích xuất đặc trưng bằng các thuật toán phức tạp trên CPU. Nên đóng gói thành một thư viện chia sẻ (shared library) và bind sang Python qua `pybind11`.

### Namespace `url_core` (Thực thể & Tiền xử lý)
*   `class URL`:
    *   **Thuộc tính**: `std::string raw_url`, `std::string domain`, `std::string path`, `bool is_obfuscated`, v.v.
    *   **Phương thức**: `parse()`, `get_domain()`, `get_path()`.
*   `class Deobfuscator`:
    *   **Trách nhiệm**: Giải mã đệ quy.
    *   **Phương thức**: `static std::string decode_base64()`, `static std::string decode_hex()`, `static std::string normalize()`. (Sử dụng Smart Pointers để quản lý bộ nhớ nội bộ).
*   `class AsyncUnshortener`:
    *   **Trách nhiệm**: Xử lý các URL rút gọn bất đồng bộ (sử dụng C++ ASIO hoặc libcurl).
    *   **Phương thức**: `std::string unshorten(const std::string& short_url)`.

### Namespace `url_filter` (Trạm kiểm soát O(1))
*   `class IFilter` (Interface):
    *   **Phương thức thuần ảo**: `virtual bool check(const URL& url) = 0;`
*   `class TrieFilter : public IFilter`:
    *   **Trách nhiệm**: Kiểm tra Whitelist/Blacklist qua cây Trie.
    *   **Phương thức**: `build_trie()`, `check(const URL& url) override`.
*   `class BloomFilter : public IFilter`:
    *   **Trách nhiệm**: Chặn URL rác siêu tốc.
    *   **Thuộc tính**: Mảng bit, danh sách các hàm băm tự viết.
    *   **Phương thức**: `add()`, `check(const URL& url) override`.

### Namespace `url_feature` (Trích xuất đặc trưng & Thuật toán CP)
*   `class IFeatureExtractor` (Interface):
    *   **Phương thức thuần ảo**: `virtual std::vector<float> extract(const URL& url) = 0;`
*   `class StatisticalExtractor : public IFeatureExtractor`:
    *   **Trách nhiệm**: Trích xuất các đặc trưng thống kê như độ dài (length), entropy, tỷ lệ ký tự, số ký tự lặp lại liên tiếp.
*   `class FlagExtractor : public IFeatureExtractor`:
    *   **Trách nhiệm**: Đánh giá các cờ (boolean) như: sử dụng IP thay vì domain, cổng (port) bất thường, https/http, có phải dịch vụ rút gọn URL, chứa các từ khóa đáng ngờ (e.g., login, bank, verify).
*   `class TyposquattingExtractor : public IFeatureExtractor`:
    *   **Trách nhiệm**: Bắt các lỗi cố tình đánh máy sai (Typosquatting) và giả mạo hình học (Homoglyphs) bằng thuật toán cao cấp.
    *   **Phương thức**:
        *   `float weighted_damerau_levenshtein(const std::string& s1, const std::string& s2)`
        *   `void length_filtering_hash()`
        *   `float dp_on_trie_search()` (Duyệt DFS trên Trie kết hợp mảng DP 1D và Early Exit/Chặt nhánh).
*   `class FeatureOrchestrator`:
    *   **Trách nhiệm**: Quản lý danh sách các `IFeatureExtractor`. Nó sẽ lặp qua tất cả các lớp Extractor con để lấy đặc trưng và `concat` (gộp) lại thành một Feature Vector duy nhất. Giúp dễ dàng bật/tắt từng nhóm đặc trưng để thử nghiệm (Ablation Study).

### Namespace `url_binding` (Giao tiếp C++ & Python)
*   `class PybindWrapper`:
    *   **Trách nhiệm**: Sử dụng `pybind11` để tạo module Python (ví dụ `url_engine`). Expose class `URL` và các `Extractor` để Python có thể gọi trực tiếp.

---

## 2. Khối Python / CUDA (Brain & MLOps Engine)
Phần này sẽ kế thừa kiến trúc thư mục `src` hiện tại nhưng được nâng cấp toàn diện, chuyên biệt hóa cho việc huấn luyện mô hình và tự động hóa.

### Module `data_pipeline` (Thu thập & Quản lý Dữ liệu)
*   `class BaseCrawler` (Abstract Class):
    *   `def fetch()`, `def parse()`.
*   `class BenignCrawler(BaseCrawler)` / `class IntelCrawler(BaseCrawler)`:
    *   **Trách nhiệm**: Crawl dữ liệu từ các whitelist/blacklist bằng BFS/DFS, gọi API.
*   `class DatabaseManager`:
    *   **Trách nhiệm**: Quản trị PostgreSQL.
    *   **Phương thức**: `execute_parameterized_query()`, `bulk_insert()`, `fetch_training_data()`.

### Module `models.deep_learning` (Khai phá đặc trưng ẩn - GPU CUDA)
*   `class DeepFeatureMiner(torch.nn.Module)`:
    *   **Trách nhiệm**: Mạng Nơ-ron chạy trên GPU (PyTorch/CUDA) để tự động học pattern ẩn từ URL (có thể là Character-level CNN hoặc LSTM/Transformer nhỏ).
    *   **Phương thức**: `forward()`, `get_embeddings()`.

### Module `models.ensemble` (Rừng mô hình - Stacked Ensemble)
*   `class BaseModelForest`:
    *   **Trách nhiệm**: Tập hợp khoảng 20 mô hình (Random Forest, XGBoost, LightGBM) chia làm 4 nhóm chuyên sâu (Phishing, Malware, Spam, Benign).
    *   **Phương thức**: `fit_base_models()`, `predict_base_models()`.
*   `class MetaLearner`:
    *   **Trách nhiệm**: Khối Lớp 1 trong Stacked Ensemble, nhận đầu vào là dự đoán của `BaseModelForest` và đặc trưng từ `DeepFeatureMiner` để đưa ra quyết định cuối cùng.
*   `class ClassifierPipeline`:
    *   **Trách nhiệm**: Class điều phối, gom C++ Extractor, GPU DeepFeatureMiner và CPU BaseModelForest lại thành một luồng Predict duy nhất.

### Module `mlops.optimization` (Tự động hóa & Siêu tham số)
*   `class HyperparameterTuner`:
    *   **Trách nhiệm**: Tích hợp Bayesian Optimization (Optuna).
    *   **Phương thức**: `optimize_base_models()`, `optimize_meta_learner()`.
*   `class PipelineController`:
    *   **Trách nhiệm**: Luồng tiến hóa tự động MLOps.
    *   **Phương thức**:
        *   `remove_duplicates()`
        *   `stratified_group_kfold()` (chia Fold theo Domain để chống rò rỉ dữ liệu).
        *   `trigger_retrain()`
        *   `evaluate_f1_score()`

---

## 3. Quy trình Tích hợp và Mở rộng
1.  **Giai đoạn 1**: Cấu trúc lại mã Python hiện hành (`src`) vào `data_pipeline` và `models`. Viết lại hoàn toàn `feature_extraction.py` bằng C++ (chuyển qua `LexicalExtractor` trong `src_v2`).
2.  **Giai đoạn 2**: Implement khối C++ cốt lõi (Deobfuscator, Filter, FuzzySearchExtractor với DP & Trie), sử dụng C++17 hoặc C++20.
3.  **Giai đoạn 3**: Dùng `pybind11` biên dịch khối C++ thành module `url_engine` và import vào Python.
4.  **Giai đoạn 4**: Xây dựng khối Deep Learning trên GPU bằng PyTorch và ghép nối vào `MetaLearner`.
5.  **Giai đoạn 5**: Thiết lập DB PostgreSQL và các đoạn script chạy tự động (Cron job) trong `PipelineController` để tạo thành một hệ thống ML tuần hoàn (MLOps).
