# <h1 align="center">Laporan Praktikum Modul PRIORITY QUEUE DAN HEAPS</h1>
<p align="center">Chelsisdeo A.P Sanenek</p>

## Dasar Teori

Priority queue adalah jenis queue yang mengatur elemen berdasarkan nilai
prioritasnya. Elemen dengan nilai prioritas lebih tinggi umumnya akan diambil
sebelum elemen dengan nilai prioritas lebih rendah.

Dalam priority queue, setiap elemen memiliki nilai prioritas yang terkait dengannya.
Ketika menambahkan elemen ke antrian, elemen tersebut dimasukkan ke dalam posisi
berdasarkan nilai prioritasnya. Misalnya, jika menambahkan elemen dengan nilai
prioritas tinggi ke priority queue, elemen tersebut mungkin dimasukkan di dekat
bagian depan antrian, sementara elemen dengan nilai prioritas rendah mungkin
dimasukkan di dekat bagian belakang.

Pada Priority Queue mempunyai tiga operasi yaitu top, pop, dan push. Operasi top adalah untuk
mengetahui nilai yang mempunyai prioritas paling tinggi pada priority queue. Operasi pop adalah
mengeluarkan nilai yang mempunyai prioritas tertinggi pada priority queue. Operasi push adalah
menginputkan elemen baru pada priority queue.[1]

Struktur data heap adalah sebuah objek array yang dapat divisualisasikan dengan sebuah complete binary tree.[2]

Heap memiliki kelebihan dalam hal kecepatan operasi. Menambah atau menghapus
elemen dalam heap hanya membutuhkan waktu O(log N), sedangkan mencari elemen
minimum/maksimum hanya membutuhkan waktu konstan.


## Guided 
### 1.

```C++
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
    // Example usage:
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Max element: " << getMax() << std::endl;
    std::cout << "Extracted max: " << extractMax() << std::endl;
    std::cout << "Max element after extraction: " << getMax() << std::endl;

    changePriority(2, 49);
    std::cout << "Max element after priority change: " << getMax() << std::endl;

    return 0;
}


```
Kode tersebut mengimplementasikan struktur data max-heap dalam C++. Array H menyimpan elemen-elemen heap, dan heapSize melacak ukuran heap. Fungsi parent, leftChild, dan rightChild digunakan untuk menghitung indeks elemen induk dan anak dari suatu elemen. Fungsi shiftUp dan shiftDown bertanggung jawab untuk memulihkan properti heap setelah elemen baru ditambahkan atau elemen diubah. Fungsi insert menambahkan elemen baru ke heap, sementara extractMax menghapus dan mengembalikan elemen maksimum (elemen root). Fungsi changePriority mengubah nilai prioritas elemen tertentu, dan getMax mengembalikan elemen maksimum tanpa menghapusnya. Fungsi main menunjukkan penggunaan dasar dari operasi heap ini dengan memasukkan beberapa elemen, mengekstraksi maksimum, dan mengubah prioritas elemen.


## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.

```C++
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

```
#### Output:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/effd7f13-932a-4e4d-8f4d-b4980a66a149)

Pengguna diminta untuk memasukkan jumlah elemen yang ingin dimasukkan, kemudian memasukkan setiap elemen satu per satu. Kode ini juga menyediakan fungsi untuk menampilkan elemen maksimum, mengambil elemen maksimum, dan mengubah prioritas elemen tertentu dalam heap, memungkinkan interaksi dan modifikasi heap sesuai dengan input pengguna.

#### Full code Screenshot:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/72a03adf-b060-4b26-a787-1aa87b9f95c1)

## Kesimpulan
Saya telah mempelajari tentang priority queue dan heaps. Priority queue adalah struktur data yang mirip dengan queue, tetapi elemennya memiliki prioritas, di mana elemen dengan prioritas tertinggi akan diambil terlebih dahulu. Heap adalah salah satu implementasi priority queue yang efisien, khususnya dalam operasi memasukkan elemen baru, mengambil elemen dengan prioritas tertinggi, dan mengubah prioritas elemen.

## Referensi
[1] Sholeh, I. (2021). Penerapan Decrease And Conquer Untuk Memanajemen Tugas Kuliah Informatika. JURNAL TEKNIK INFORMATIKA DAN SISTEM INFORMASI, 1(2), 1-10.

[2] Situmorang, H. (2016). Simulasi Pengurutan Data dengan Algoritma Heap Sort. Jurnal Mahajana Informasi, 1(2), 20-30.
