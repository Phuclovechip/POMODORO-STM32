# 🍅 POMODORO STM32 – HỆ THỐNG QUẢN LÝ THỜI GIAN

## 👨‍💻 Tác giả

**Trần Lê Xuân Phúc**

## 1. Giới thiệu dự án

**POMODORO STM32** là dự án xây dựng hệ thống quản lý thời gian sử dụng vi điều khiển STM32, lấy ý tưởng từ phương pháp Pomodoro.

Dự án được tạo ra với mục đích hỗ trợ người dùng quản lý thời gian học tập và làm việc một cách khoa học, nâng cao khả năng tập trung và hình thành thói quen làm việc có kế hoạch.

Thông qua dự án, tôi mong muốn kết hợp kiến thức lập trình nhúng với việc giải quyết một vấn đề thực tế trong cuộc sống, đồng thời nâng cao kỹ năng thiết kế và phát triển hệ thống nhúng.

## 2. Mục tiêu dự án

- Xây dựng một thiết bị quản lý thời gian dựa trên vi điều khiển STM32.
- Áp dụng phương pháp Pomodoro vào việc quản lý thời gian học tập và làm việc.
- Rèn luyện kỹ năng lập trình Embedded C.
- Tìm hiểu cách cấu hình và điều khiển các ngoại vi trên STM32.
- Xây dựng chương trình theo hướng module hóa, dễ bảo trì và mở rộng.

## 3. Công nghệ và công cụ sử dụng

### Phần cứng
- Vi điều khiển: STM32F103C6T6A.

### Phần mềm
- STM32CubeMX: Cấu hình vi điều khiển và các ngoại vi.
- Keil MDK: Môi trường lập trình và biên dịch.
- Ngôn ngữ lập trình: Embedded C.
- Thư viện: STM32 HAL.

## 4. Cấu trúc dự án

```text
POMODORO-STM32/
│
├── Core/                  # Chương trình chính
│   ├── Inc/               # Các file header
│   └── Src/               # Các file source
│
├── Drivers/               # Thư viện HAL và CMSIS
│
├── LIB/                   # Các thư viện do người phát triển xây dựng
│
├── MDK-ARM/               # Project dành cho Keil MDK
│
├── POMODORO_TIME.ioc      # File cấu hình STM32CubeMX
├── .mxproject             # Thông tin project CubeMX
├── .gitignore             # Các file không đưa lên GitHub
└── README.md              # Tài liệu giới thiệu dự án
```

## 5. Phương pháp quản lý thời gian Pomodoro

Phương pháp Pomodoro chia thời gian học tập và làm việc thành các khoảng tập trung xen kẽ với thời gian nghỉ ngơi.

Chu trình cơ bản:

1. Tập trung làm việc trong 25 phút.
2. Nghỉ ngắn trong 5 phút.
3. Lặp lại chu trình.
4. Sau 4 chu trình, nghỉ dài khoảng 15–30 phút.

## 6. Kiến thức và kỹ năng đạt được

Thông qua quá trình thực hiện dự án, tôi hướng đến việc củng cố và phát triển các kiến thức:

- Lập trình nhúng với ngôn ngữ C.
- Làm việc với vi điều khiển STM32.
- Cấu hình GPIO và các ngoại vi bằng STM32CubeMX.
- Xây dựng và sử dụng các thư viện điều khiển ngoại vi.
- Tổ chức chương trình theo hướng module hóa.
- Kỹ năng kiểm tra, gỡ lỗi và phát triển firmware.

## 7. Định hướng phát triển

Trong tương lai, dự án có thể được mở rộng với các tính năng:

- Tùy chỉnh thời gian làm việc và nghỉ ngơi.
- Cải thiện giao diện hiển thị.
- Bổ sung các chế độ quản lý thời gian khác nhau.
- Tối ưu chương trình và cấu trúc firmware.
- Phát triển thêm các tính năng hỗ trợ người dùng quản lý công việc.

## 8. Lời kết

POMODORO STM32 không chỉ là một dự án thực hành lập trình nhúng mà còn là cơ hội để tôi vận dụng kiến thức đã học vào việc xây dựng một sản phẩm có tính ứng dụng thực tế.

Tôi hy vọng sẽ tiếp tục phát triển dự án, bổ sung thêm tính năng và hoàn thiện kỹ năng thiết kế hệ thống nhúng trong quá trình học tập.

---

**Người thực hiện: Trần Lê Xuân Phúc**

*Dự án học tập và phát triển cá nhân – Embedded Systems.*
