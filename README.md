# Juno
# Giới thiệu
  * Họ và tên: Phạm Văn Sơn Dương
  * Mã sinh viên: 21020296
  * Bài tập cuối khóa(INT2215_1 - Lập trình nâng cao).
# 1. Hướng dẫn cài đặt
  1. Tải [Compiler](https://pie-cheque-188.notion.site/C-i-t-h-a-C-Windows-ef0a99a8dcae4dae86a39dc1cbc35980, "MinGW-W64") và cài đặt theo hướng dẫn.
  2. Mở cmd hoặc terminal/powershell và clone repo về máy bằng lệnh:
  > git clone https://github.com/DuongPVS/Juno.git
  3. Build bằng lệnh:
  > mingw32-make
  4. Để chạy chương trình nhập lệnh:
  > ./build/main.exe
# 2. Mô tả chung
  * Thông tin game:
    * Thể loại: Giải đố, phiêu lưu
    * Đồ họa: 2D
    * Chế độ: Chơi đơn
  * Juno là một trò chơi phiêu lưu giải đố theo phong cách đẩy thùng (Sokoban).
  * Người chơi sẽ phải di chuyển từ điểm xuất phát đến điểm kết thúc trong 1 số hữu hạn các bước di chuyển.
# 3. Các chức năng
  * Main Menu
    * New Game: Bắt đầu game lại từ màn 1.
    * Chapter Select: Chọn màn để chơi.
    * Exit: Thoát game.
  * Pause Menu
    * Resume: Tiếp tục game.
    * Skip Puzzle: Bỏ qua màn hiện tại để tới màn tiếp theo.
    * Music: Bật/Tắt nhạc khi chơi (Khi nhạc đang tắt thì phía dưới Music sẽ có "Mute").
    * Main Menu: Quay trở Main Menu.
  * Item
    * Các hòn đá sáng màu chặn đường (có thể đẩy được).
    * Các cạm bẫy (Khi đạp phải sẽ trừ thêm 1 bước di chuyển).
    * Chìa khóa (Để mở hòm).
    * Hòm chặn đường (Không thể đẩy, chỉ có thể vượt qua khi sở hữu chìa khóa).
    * Quái vật chặn đường (có thể đẩy, có thể tiêu diệt bằng cách đẩy vào các item khác).
  * Khi chơi
    * Người chơi dùng các nút điều hướng hoặc A, W, S, D để di chuyển.
    * Nhập ESC để mở Pause Menu.
    * Nhập R để reset màn chơi.
    * Nhập ENTER để chuyển sang màn tiếp theo khi đã di chuyển đến điểm đích.
    * Khi bắt đầu game nhạc nền sẽ tự động bật.
    * Khi bắt đầu một màn thì thời gian hiển thị sẽ chạy và sẽ ngừng chạy khi di chuyển được đến điểm đích.
    * Phía bên trái màn hình khi chơi hiển thị số bước mà mình còn có thể đi, khi nó về 'x' mà mình còn tiếp tục di chuyển thì game sẽ chạy một đoạn video ngắn để người chơi biết mình đã thua và màn chơi được bắt đầu lại.
    * Phía bên phải màn hình khi chơi hiển thị số thứ tự của màn chơi.
    * Khi đi đến điểm đích phía dưới màn hình sẽ hiển thị thông báo "Congratulations, you solved the puzzle!" và thời gian cũng như phím cần nhập để tiếp tục.
    * Khi hoàn thành đủ tất cả các màn thì game sẽ load hình ảnh "You win" kèm theo nhạc để tôn vinh người chơi trong khoảng 30s và sau đó chương trình sẽ tự tắt.
  * Video minh họa: https://www.youtube.com/watch?v=cMR3xJIB7OA
# 4. Các kỹ thuật lập trình được sử dụng trong chương trình
  * Mảng, con trỏ, cấu trúc, lớp.
  * Thư viện SDL2(hình ảnh, âm thanh).
  * Chia file, tổ chức code.
  * Sử dụng tính kế thừa.
  * Sử dụng ghi file để đọc vào map.
  * Xử lý thời gian, thao tác bàn phím, âm thanh, hình ảnh.
  * Dựa trên nguyên lý 10 khung hình/s mắt người có thể cảm thấy rằng việc 1 video chạy là liên tục để tạo 1 video ngắn.
# 5. Kết luận
  * Hướng phát triển:
    * Thêm tính năng chọn Screen resolution.
    * Cải tiến đồ họa.
    * Thêm nhiều các item với các chức năng độc đáo.
    * Thêm nhiều map mới để phong phú hơn về độ khó.
    * Tiếp tục cải tiến code.
    * Tạo một Easter egg (chi tiết ẩn trong game).
    * Tạo ra một cốt truyện nhằm hấp dẫn hơn.
    * Tạo Save Game.
    * Sử dụng AI cho các NPC.
  * Điểu tâm đắc:
    * Vì là game đầu tiên code nên có nhiều sai sót, bỡ ngỡ nhưng dù sao cũng đã hoàn thành được.
    * Học thêm được nhiều kỹ năng như sử dụng SDL2 tốt hơn, biết cách tổ chức class,…
