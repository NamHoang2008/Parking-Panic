# Parking-Panic
Game này được tạo ra bởi tbradm. Bạn có thể chơi game này trên Roblox.

---

- VẤN ĐỀ:

  Cho một ma trận 8 x 8 ô, ma trận con 6 x 6 được bao quanh bởi bức tường. Trong ma trận có:
  
  - `-1` - Bức tường.
  - `0` - Ô trống.
  - `[1, n + 1]` - Xe ô tô được đánh số thứ tự.
    - Số thứ tự không được trùng với các xe ô tô khác.
    - Mang độ dài k, k > 1.
    - Chỉ được nằm ngang `hoặc` dọc.

  ---

  Bạn có thể chọn bất kì chiếc xe nào và di chuyển nó thông qua 2 hướng:
  
  - Nếu chiếc xe nằm `ngang` thì di chuyển qua hướng `Trái` và `Phải`.
  - Nếu chiếc xe nằm `dọc` thì di chuyển qua hướng `Trên` và `Xuống`.
  
  Một chiếc xe chỉ được phép di chuyển nếu vị trí tiếp theo của nó là `Ô trống`.
 
  ---

  Xe ô tô số 1 bị mắc kẹt, phía trước của nó là `lối thoát` bị chắn bởi nhiều loại xe ô tô khác nhau.

  **Hãy tìm ra `bất kì` nước đi ngắn nhất nào để dời những chiếc xe sao cho xe ô tô số 1 thoát ra được.**

  - Nước đi cho xe ra khỏi lối thoát `không` cần phải tính.
  - Ta chắc chắn rằng vấn đề này `luôn luôn` có cách giải.
  
---

**VÍ DỤ 1:**

**ĐẦU VÀO:** [[-1,-1,-1,-1,-1,-1,-1,-1],[-1, 0, 7, 7, 7, 0, 8,-1],[-1, 6, 6, 0, 0, 0, 8,-1],[-1, 0, 0, 2, 0, 0, 3,-1],[ 0, 5, 0, 2, 1, 1, 3,-1],[-1, 5, 0, 2, 0, 0, 3,-1],[-1, 5, 0, 0, 0, 4, 4,-1],[-1,-1,-1,-1,-1,-1,-1,-1]]

**ĐẦU RA:** [[7,[R,1]],[6,[R,3]],[2,[U,1]],[5,[U,3]],[4,[L,1]],[3,[D,1]],[8,[D,1]],[7,[R,1]],[2,[U,1]],[1,[L,3]]]

**MINH HOẠ:**

![](https://github.com/NamHoang2008/Parking-Panic/blob/main/gifs/EXAMPLE1.gif)

---

**VÍ DỤ 2:**

**ĐẦU VÀO:** [[-1,-1,-1,-1,-1,-1,-1,-1],[-1, 0, 6, 6, 4, 5, 5,-1],[-1, 7, 7, 0, 4, 0, 0,-1],[-1, 8, 9, 0, 2, 2, 2,-1],[ 0, 8, 9,10, 0, 1, 1,-1],[-1, 8, 0,10, 0, 0, 3,-1],[-1,11,11,11, 0, 0, 3,-1],[-1,-1,-1,-1,-1,-1,-1,-1]]

**ĐẦU RA:** [[7,[R,1]],[8,[U,2]],[9,[D,1]],[1,[L,1]],[3,[U,1]],[11,[R,2]],[9,[D,1]],[11,[R,1]],[10,[D,1]],[1,[L,3]]]

**MINH HOẠ:** 

![](https://github.com/NamHoang2008/Parking-Panic/blob/main/gifs/EXAMPLE2.gif)

---

