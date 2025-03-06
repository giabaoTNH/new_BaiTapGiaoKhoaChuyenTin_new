# Tổng kết ngày 4/3/2025
### Bài nào tốn nhiều thời gian nhất:

Nếu xếp theo thứ tự thì có lẽ:
1. 4.38
2. 4.40
3. 4.39

### Lý do chậm:

- Bài 4.38:
	- Mới gặp dạng này lần đầu
	- không biết công thức truy hồi như thế nào. 
	- Không biết bài toán con nhỏ nhất. 
	- Không biết trường hợp cơ sở. 
	- Gặp dạng ma trận nên sợ.
- Bài 4.40:
	- Áp dụng ý tưởng từ bài 4.38 (Tìm bài toán con nhỏ nhất) nên nhanh hơn một chút.
	- Hơi khó, vì phải biến đổi $$(a-b)^2$$ thành $$(a^2 - 2*a*b + b^2)$$ để tối ưu O(n) thành O(1).
- Bài 4.39:
	- Bài này dễ vì đã gặp dạng tính tổng một dãy con không liên tiếp nhiều rồi. Tuy nhiên vẫn còn chậm vì đặc biệt là bài này tính tổng theo cách: Phần tử thứ 2, 5, 8, ... (Nói chung là chia dư cho 3 ra 2) thì sẽ nhân với -1.
	- Còn lại thì đây là bài qhd lấy dãy con có tổng lớn nhất cơ bản.

### Rút kinh nghiệm:
- Trong những tấm hình vừa nãy.

### 🔥 Cách cải thiện sau hôm nay:

1. Dạng bài toán quy hoạch động mới:

- Khi gặp bài lạ, thử nghĩ xem có thể chuyển về bài quen thuộc nào không?
Nếu chưa rõ công thức truy hồi → Thử giải tay với các test nhỏ để nhận ra quy luật.
Dạng bài cần tối ưu công thức:

- Đừng chỉ chấp nhận O(n), hãy tự hỏi có cách nào đưa về O(1) không? Như bài 4.40, em đã làm đúng khi biến đổi công thức.
Bài toán dạng QHĐ trên dãy số:

2. Bài 4.39 em nói "đã gặp dạng này nhiều rồi" → Vậy có cách nào nhận diện nhanh hơn không?
- Nếu gặp bài nâng cao của dạng này, liệu có bị bí không?
### 💡 Bước tiếp theo:

- Làm thêm 1-2 bài quy hoạch động nữa để củng cố cách tìm bài toán con nhỏ nhất và công thức truy hồi.
Dành 10 phút viết lại những dạng bài mình đã giải hôm nay vào sổ tay (nếu chưa có thì tạo luôn).
- Nghỉ ngơi, ngày mai còn chiến tiếp! 🚀
