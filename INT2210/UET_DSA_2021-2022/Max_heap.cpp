#include <bits/stdc++.h>
using namespace std;

class Heap {
    int* a;
    int n; // Số lượng phần tử hiện tại trong heap

public:
    // Constructor
    Heap(int A[], int N) {
        a = new int[N];
        n = N; // Khởi tạo n với giá trị N
        for (int i = 0; i < n; i++) {
            a[i] = A[i];
        }
        Build_Heap(); // Xây dựng heap từ mảng
    }

    // Destructor
    ~Heap() {
        delete[] a;
    }

    // Trả về chỉ số của phần tử cha
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Trả về chỉ số của con trái
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // Trả về chỉ số của con phải
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // Phương thức Heapify
    void Heapify(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;

        if (largest != i) {
            swap(a[i], a[largest]);
            Heapify(largest);
        }
    }

    // Xây dựng heap từ mảng
    void Build_Heap() {
        for (int i = n / 2 - 1; i >= 0; i--) {
            Heapify(i);
        }
    }

    // In mảng heap ra màn hình
    void Print_Heap() {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl; // Thêm dòng kết thúc
    }

    // Xóa phần tử tối đa (phần tử gốc)
    void Delete_Max() {
        if (n <= 0) {
            cout << "Heap is empty, cannot delete max." << endl;
            return;
        }
        // Hoán đổi phần tử gốc với phần tử cuối cùng
        swap(a[0], a[n-1]);
        n--; // Giảm kích thước heap sau khi xóa

        // Thực hiện Heapify từ nút gốc
        Heapify(0);
    }
};

int main() {
    int keys[] = {10, 5, 30, 20, 15, 40, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    Heap h(keys, n);

    cout << "Heap (Max-Heap) is:" << endl;
    h.Print_Heap();

    cout << "Heap after delete Max: " << endl;
    h.Delete_Max();
    h.Print_Heap();

    return 0;
}
