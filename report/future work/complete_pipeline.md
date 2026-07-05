# Tổng Hợp Pipeline Phân Loại URL Độc Hại (Kiến Trúc Nâng Cấp 5 Lớp)

Dựa trên những hạn chế của hệ thống phân tích tĩnh thuần túy, báo cáo đề xuất một **Kiến trúc nâng cấp 5 lớp (5-Layer Architecture)** kết hợp cả phân tích tĩnh, phân tích động và hệ chuyên gia. Giai đoạn Suy luận (Online Inference) được thiết kế lại hoàn toàn thành một quy trình phân tầng, trong khi giai đoạn Huấn luyện (Offline Training) được mở rộng để xây dựng hệ đa mô hình (Ensemble).

Dưới đây là tổng hợp quy trình đầu-cuối (end-to-end) cho kiến trúc nâng cấp này.

---

## 1. Giai Đoạn Chuẩn Bị và Huấn Luyện (Offline)

Thay vì chỉ huấn luyện một mô hình duy nhất, hệ thống mới chuẩn bị dữ liệu và huấn luyện **4 mô hình chuyên gia** độc lập.

*   **Làm sạch và Tổng hợp dữ liệu:** Kết hợp dữ liệu từ Kaggle và URLhaus, loại bỏ các mẫu trùng lặp URL.
*   **Xây dựng CSDL Hỗ trợ:** Cập nhật liên tục Danh sách trắng (Whitelist) gồm các domain uy tín, danh sách TLD độc hại, và danh sách các hosting miễn phí thường bị lạm dụng.
*   **Huấn luyện Hệ đa mô hình (Multi-model ML):** Chia dữ liệu bằng Stratified Group K-Fold (chống trùng lặp domain) và huấn luyện 4 mô hình:
    *   *Mô hình A (Ký tự đặc biệt):* Chuyên nhận diện các dấu hiệu giả mạo qua phân phối các ký tự `@`, `-`, `.`, `/`, `%`.
    *   *Mô hình B (Độ dài & Entropy):* Phát hiện domain sinh bằng thuật toán (DGA) và payload mã hóa qua entropy Shannon.
    *   *Mô hình C (Thông tin Động):* Đánh giá rủi ro dựa trên dữ liệu DNS, chứng chỉ SSL và tuổi domain WHOIS.
    *   *Mô hình D (Từ khóa & Chỉ báo):* Phát hiện TLD đáng ngờ, hosting miễn phí và từ khóa nhạy cảm.

## 2. Pipeline Suy Luận 5 Lớp (Online)

Khi một URL mới đi vào hệ thống, nó sẽ trải qua quy trình lọc 5 lớp tuần tự. Quy trình này tối ưu hóa tài nguyên bằng cách phân giải các URL phức tạp và cho phép "kết thúc sớm" với các domain an toàn.

### Lớp 1: Chuẩn hóa & Giải mã hóa (Normalization & De-obfuscation)
*   Chuẩn hóa giao thức (scheme) và loại bỏ khoảng trắng thừa.
*   Giải mã đệ quy percent-encoding (`%xx`).
*   Phát hiện và vô hiệu hóa các thủ thuật che giấu (double-encoding, unicode normalization, mã hóa IP dưới dạng octal/hex/decimal).

### Lớp 2: Mở rút gọn & Phân giải (Unshorten & Resolve Redirects)
*   Phát hiện các dịch vụ rút gọn URL (ví dụ: `bit.ly`, `tinyurl.com`).
*   Thực hiện HTTP requests để lần theo chuỗi chuyển hướng (follow redirects) nhằm tìm ra URL đích thực.
*   Áp dụng giới hạn số lần redirect (max redirects) để phòng chống tấn công lặp vô hạn (Redirect Loop).

### Lớp 3: Khớp chính xác Danh sách trắng (Strict Exact-Match Whitelist)
*   So khớp chính xác domain đích (vừa được phân giải ở Lớp 2) với cơ sở dữ liệu Whitelist.
*   🚀 **Kết thúc sớm (Early Exit):** Nếu domain khớp hoàn toàn với một domain uy tín, hệ thống lập tức trả về kết quả **Benign (An toàn)** và dừng lại. Bước này khắc phục lỗi nhận diện nhầm các URL ngắn của hệ thống cũ và tối ưu hiệu năng đáng kể.

### Lớp 4: Trích xuất Đặc trưng & Phát hiện Typosquatting
*(Chỉ áp dụng cho các URL không nằm trong Whitelist)*
*   Tính toán 63 đặc trưng số học từ cấu trúc URL.
*   Sử dụng thuật toán Levenshtein kết hợp phân tích ngữ âm để phát hiện Typosquatting (tên miền viết nhái các thương hiệu lớn). Gắn cờ cảnh báo sớm nếu phát hiện sự tương đồng cao.

### Lớp 5: Trình quét Học máy đa mô hình (Multi-model ML Scanner)
*   Đưa các đặc trưng tĩnh và động của URL vào **4 mô hình chuyên gia (A, B, C, D)** đã huấn luyện ở Giai đoạn 1.
*   Sử dụng kỹ thuật **Ensemble (Weighted Averaging / Stacking)** để tổng hợp dự đoán từ 4 mô hình con.
*   Trả về kết quả phân loại cuối cùng (Benign, Defacement, Malware, hoặc Phishing) cho người dùng.

---

## Sơ Đồ Pipeline 5 Lớp

```mermaid
flowchart TD
    subgraph Giai_Doan_Offline[Giai Đoạn Huấn Luyện & Chuẩn Bị (Offline)]
        DB[(Dữ liệu Kaggle & URLHaus)] --> FeatEng[Tiền xử lý & Trích xuất Đặc trưng]
        FeatEng --> TrainA[Huấn luyện Mô hình A]
        FeatEng --> TrainB[Huấn luyện Mô hình B]
        FeatEng --> TrainC[Huấn luyện Mô hình C]
        FeatEng --> TrainD[Huấn luyện Mô hình D]
        WL[(Cập nhật CSDL Whitelist/TLD)]
    end

    subgraph Giai_Doan_Online[Pipeline Suy Luận 5 Lớp (Online)]
        Input[URL đầu vào từ người dùng] --> L1
        
        L1[<b>Lớp 1</b>: Chuẩn hóa & Giải mã hóa] --> L2
        L2[<b>Lớp 2</b>: Mở rút gọn & Phân giải Redirect] --> L3
        
        L3{<b>Lớp 3</b>: Khớp chính xác Whitelist?}
        L3 -- Có (Khớp) --> EarlyExit([Kết quả: Benign - An toàn])
        
        L3 -- Không --> L4[<b>Lớp 4</b>: Trích xuất 63 đặc trưng & Typosquatting]
        
        L4 --> L5_A[Mô hình A: Ký tự đặc biệt]
        L4 --> L5_B[Mô hình B: Độ dài & Entropy]
        L4 --> L5_C[Mô hình C: Dữ liệu Động DNS/SSL]
        L4 --> L5_D[Mô hình D: Từ khóa & Chỉ báo]
        
        L5_A --> Ensemble[<b>Lớp 5</b>: Tổng hợp kết quả - Ensemble]
        L5_B --> Ensemble
        L5_C --> Ensemble
        L5_D --> Ensemble
        
        Ensemble --> FinalOutput([Kết quả: Defacement / Malware / Phishing / Benign])
    end

    %% Mũi tên liên kết
    TrainA -. Tải mô hình .-> L5_A
    TrainB -. Tải mô hình .-> L5_B
    TrainC -. Tải mô hình .-> L5_C
    TrainD -. Tải mô hình .-> L5_D
    WL -. Tra cứu .-> L3
```

Kiến trúc 5 lớp này giải quyết triệt để các hạn chế của phân tích tĩnh thuần túy, có khả năng bóc trần các lớp ngụy trang tinh vi của mã độc, giảm thiểu cảnh báo sai (False Positive) cho các domain phổ biến và linh hoạt thích ứng với các mối đe dọa mới nhờ hệ thống đa mô hình.
