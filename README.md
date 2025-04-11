# Triển khai Cây AVL bằng C++

Dự án này bao gồm việc triển khai một cây AVL, một loại cây tìm kiếm nhị phân tự cân bằng, bằng ngôn ngữ C++. Cây AVL đảm bảo rằng sự chênh lệch chiều cao giữa các cây con bên trái và bên phải của bất kỳ nút nào không vượt quá 1, duy trì độ phức tạp thời gian logarithmic cho các thao tác chèn, xóa và tìm kiếm.

## Tính năng

- **Chèn**: Thêm một nút mới đồng thời duy trì sự cân bằng của cây AVL.
- **Xóa**: Xóa một nút và cân bằng lại cây.
- **Tìm kiếm**: Tìm một nút với giá trị cụ thể.
- **Duyệt cây**:
  - Tiền thứ tự (Pre-order)
  - Trung thứ tự (In-order)
  - Hậu thứ tự (Post-order)
- **Thuộc tính cây**:
  - Chiều cao của cây
  - Số lượng nút nhánh (nút có một con)
  - Số lượng nút lá (nút không có con)
  - Số lượng nút có giá trị chẵn
  - Tổng giá trị của tất cả các nút
  - Giá trị lớn nhất và nhỏ nhất
  - Giá trị âm lớn nhất trong cây
  - Số lượng giá trị khác nhau
  - Tần suất của từng giá trị nút

## Hướng dẫn sử dụng

### Yêu cầu

- Trình biên dịch C++ hỗ trợ C++11 hoặc mới hơn.

### Cách sử dụng

1. Thêm tệp tiêu đề `AVLTree.h` vào dự án của bạn.
2. Tạo một đối tượng của lớp `AVLTree` với kiểu dữ liệu mong muốn.
3. Sử dụng các phương thức được cung cấp để tương tác với cây AVL.

### Ví dụ

```cpp
#include "AVLTree.h"
#include <iostream>
using namespace std;

int main() {
    AVLTree<int> tree;

    // Chèn các phần tử
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);

    // Hiển thị các cách duyệt cây
    cout << "Tiền thứ tự: ";
    tree.preOrder();

    cout << "Trung thứ tự: ";
    tree.inOrder();

    cout << "Hậu thứ tự: ";
    tree.postOrder();

    // Tìm kiếm một giá trị
    cout << "Tìm 15: " << (tree.search(15) ? "Tìm thấy" : "Không tìm thấy") << endl;

    // Thuộc tính cây
    cout << "Chiều cao của cây: " << tree.HighTree() << endl;
    cout << "Số lượng nút nhánh: " << tree.countBranch() << endl;
    cout << "Số lượng nút lá: " << tree.countLeaf() << endl;
    cout << "Tổng giá trị các nút: " << tree.SumOfTree() << endl;
    cout << "Giá trị lớn nhất: " << tree.findMax() << endl;
    cout << "Giá trị nhỏ nhất: " << tree.findMin() << endl;

    // Xóa một nút
    tree.remove(10);
    cout << "Sau khi xóa 10, Trung thứ tự: ";
    tree.inOrder();

    return 0;
}
```

### Ví dụ đầu ra

```
Tiền thứ tự: 10 5 20 15 
Trung thứ tự: 5 10 15 20 
Hậu thứ tự: 5 15 20 10 
Tìm 15: Tìm thấy
Chiều cao của cây: 3
Số lượng nút nhánh: 2
Số lượng nút lá: 2
Tổng giá trị các nút: 50
Giá trị lớn nhất: 20
Giá trị nhỏ nhất: 5
Sau khi xóa 10, Trung thứ tự: 5 15 20 
```

## Tác giả

- **MSSV**: 23110273
- **Họ tên**: Trương Nhất Nguyên

