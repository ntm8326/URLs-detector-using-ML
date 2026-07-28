# Nhận xét Báo cáo kỹ thuật phân loại URL độc hại (MLreport_v2.tex)

> [!NOTE]
> Bài nhận xét này phân tích chi tiết báo cáo kỹ thuật phân loại URL độc hại dựa trên phiên bản `MLreport_v2.tex`, đánh giá các điểm mạnh, điểm yếu và gợi ý chỉnh sửa thuật ngữ.

## 1. Điểm nổi bật (Strengths)

- **Cấu trúc bài bản, chuẩn kỹ thuật:** Báo cáo tuân thủ chặt chẽ cấu trúc của một tài liệu khoa học/kỹ thuật (Abstract, Giới thiệu cơ sở lý thuyết, Phương pháp, Pipeline, Kết quả, Hạn chế và Hướng phát triển).
- **Trình bày trực quan, chuyên nghiệp:** Khai thác rất tốt LaTeX (đặc biệt là gói `tikz` để vẽ kiến trúc, pipeline, và sơ đồ URL). Code snippet được bọc trong `lstlisting` gọn gàng, có syntax highlight.
- **Độ chi tiết và phân tích sâu sắc:**
  - Phần *Feature Engineering* (Kỹ thuật đặc trưng) mô tả rõ 63 đặc trưng và có lý giải bảo mật (Security rationale) cho việc tại sao lại sử dụng chúng. Đây là điểm sáng nhất của bài.
  - Phân tích rất rõ lỗ hổng "Data leakage" ở cấp độ domain và đưa ra giải pháp **Stratified Group K-Fold**.
- **Tầm nhìn hệ thống tốt:** Phần 11 đề xuất "Kiến trúc pipeline 5 lớp" rất xuất sắc, vạch ra được cách kết hợp giữa các module quy tắc (rules/whitelist), giải mã (de-obfuscation) và các mô hình ML chuyên biệt (Ensemble).

## 2. Điểm thiếu sót và cần cải thiện (Areas for Improvement)

> [!WARNING]
> Phần Kết quả đánh giá (Section 8.5) đang hoàn toàn trống số liệu chi tiết.

- **Thiếu minh chứng thực nghiệm trong Phần 8.5:** Báo cáo liệt kê sẽ có "Precision, recall, $F_1$-score", "Ma trận nhầm lẫn", "SHAP" nhưng lại... không hề có bất kỳ bảng biểu hay hình ảnh nào hiển thị các chỉ số này. Cần bổ sung ngay:
  - Bảng tổng hợp Classification Report cho 4 lớp.
  - Hình ảnh Confusion Matrix.
  - Hình ảnh SHAP summary plot (hoặc Feature Importance plot).
- **Mô tả Dataset chưa đầy đủ:** Phần 4.1 có nhắc đến "sự mất cân bằng lớp ở mức trung bình" nhưng không đưa ra tỷ lệ % hay số lượng cụ thể cho từng lớp (Benign, Phishing, Malware, Defacement). Người đọc cần biểu đồ tròn hoặc bảng phân phối.
- **Thiếu Baseline (Mô hình đối chứng):** Báo cáo chỉ trình bày kết quả của mô hình LightGBM ($93.46\%$) mà không so sánh với các thuật toán khác (như Random Forest, Logistic Regression) hoặc nghiên cứu trước đó để cho thấy sự vượt trội.

## 3. Góp ý về cách dùng từ và diễn đạt (Phrasing & Vocabulary)

Một số cụm từ nên được tinh chỉnh để báo cáo đọc mượt mà và chuẩn văn phong học thuật tiếng Việt hơn:

- *Mục 3:* "Bốn loại mối đe dọa loại trừ lẫn nhau" $\rightarrow$ Sửa thành: **"Bốn lớp mối đe dọa độc lập (mutually exclusive)"** hoặc **"Bốn nhóm mối đe dọa phân biệt"**.
- *Mục 5.2:* "vị trí mạng" (khi dịch chữ `netloc`) $\rightarrow$ Sửa thành: **"định danh máy chủ (netloc)"** hoặc giữ nguyên **`netloc`**. "Vị trí mạng" dễ gây hiểu nhầm sang network location trong hạ tầng mạng.
- *Mục 8.4:* "ngân sách tối đa" (dịch từ maximum budget) $\rightarrow$ Sửa thành: **"số vòng lặp tối đa"** hoặc **"ngưỡng giới hạn vòng lặp"**.
- *Mục 8.5:* "không trùng lặp domain" $\rightarrow$ Sửa thành: **"đảm bảo không có sự trùng lặp tên miền (domain overlap) giữa hai tập"**.
- *Mục 10:* "cận dưới chặt cho khả năng tổng quát hóa" (tight lower bound) $\rightarrow$ Cụm này khá nặng về toán. Sửa thành: **"phản ánh khách quan và sát thực tế nhất khả năng tổng quát hóa của mô hình"**.
- *Nhiều chỗ:* "Kỹ thuật đặc trưng" $\rightarrow$ Tuy đúng nghĩa đen của *Feature Engineering*, nhưng trong ngành AI ở VN thường dùng luôn từ **"Trích xuất đặc trưng (Feature Extraction/Engineering)"** hoặc giữ nguyên tiếng Anh.
- *Nhiều chỗ:* "artifact" $\rightarrow$ Có thể dùng từ **"các tệp cấu phần của mô hình"** hoặc **"các thành phần lưu trữ"**.

## 4. Hành động tiếp theo (Next Steps)

> [!TIP]
> Bạn nên ưu tiên bổ sung các biểu đồ và bảng kết quả vào Section 8.5. Nếu bạn đã có dữ liệu xuất ra từ code (như `classification_report.csv`, hình ảnh confusion matrix), bạn có thể chèn trực tiếp các bảng/ảnh đó vào file LaTeX.
