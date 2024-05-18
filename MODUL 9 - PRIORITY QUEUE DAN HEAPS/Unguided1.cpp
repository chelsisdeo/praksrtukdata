#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    if (heapSize < 0) {
        std::cerr << "Error: Heap is empty." << std::endl;
        return -1; // or some error value
    }
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    if (heapSize < 0) {
        std::cerr << "Error: Heap is empty." << std::endl;
        return -1; // or some error value
    }
    return H[0];
}

int main() {
    int n;
    std::cout << "Masukkan jumlah elemen: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int val;
        std::cout << "Masukkan elemen ke-" << i + 1 << ": ";
        std::cin >> val;
        insert(val);
    }

    std::cout << "Elemen maksimum: " << getMax() << std::endl;

    std::cout << "Mengambil elemen maksimum: " << extractMax() << std::endl;
    std::cout << "Elemen maksimum setelah pengambilan: " << getMax() << std::endl;

    int index, newPriority;
    std::cout << "Masukkan indeks elemen yang ingin diubah prioritasnya (0 hingga " << heapSize << "): ";
    std::cin >> index;
    std::cout << "Masukkan prioritas baru: ";
    std::cin >> newPriority;
    changePriority(index, newPriority);
    std::cout << "Elemen maksimum setelah perubahan prioritas: " << getMax() << std::endl;

    return 0;
}
