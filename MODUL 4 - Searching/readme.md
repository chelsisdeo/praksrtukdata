# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">CHELSISDEO A.P SANENEK</p>
<p align="center">2311110016</p>

## Dasar Teori

Pencarian  merupakan  proses yang  fundamental  dalam  pengolahan data.  Pencarian  beruntun  (SequentialSearching)     adalah     proses membandingkan  setiap  elemen  larik satu per satu secara beruntun, mulai dari elemen pertama sampai dengan elemen yang  dicari  ditemukan  atau  seluruh elemen sudah diperiksa.[1]

- sequential search

Teknik   pencarian   dengan   metode   sequential   adalah   sebuah   teknik   pencarian   yang membandingkan   setiap   elemen   data   dengan   data   yang   dicari.   Pencarian   dilakukan   dengan membandingkan sebuah elemen data yang dicari dengan elemen pertama sampai dengan terakhir jika  data  yang  dicari  ditemukan  maka  pencarian  akan  dihentikan.  Sequential  search  disebut juga sebagai  metode  pencarian  urut  adalah  metode  pencarian  yang  paling  mudah. [2]

Konsep Sequential Search yaitu:

• Membandingkan setiap elemen pada array satu per satu secara
berurut

• Proses pencarian dimulai dari indeks pertama hingga indeks terakhir

• Proses pencarian akan berhenti apabila data ditemukan. Jika hinggaakhir array data masih juga tidak ditemukan, maka proses pencarian tetap akan dihentikan

• Proses perulangan pada pencarian akan terjadi sebanyak jumlah N elemen pada array

- Binary search 

Binary Search termasuk ke dalam interval search, dimana algoritma ini merupakan algoritma pencarian pada array/list dengan elemen terurut. Pada metode ini, data harus diurutkan terlebih dahulu dengan cara data dibagi menjadi dua bagian (secara logika), untuk setiap tahap pencarian.

Binary Search (pencarian biner) dapat dilakukan
jika data sudah dalam keadaan urut. Dengan kata
lain, apabila data belum dalam keadaan urut,
pencarian biner tidak dapat dilakukan. Dalam
kehidupan sehari-hari, sebenarnya kita juga sering
menggunakan pencarian biner.[3]

Konsep Binary Search:
• Data diambil dari posisi 1 sampai posisi akhir N

• Kemudian data akan dibagi menjadi dua untuk mendapatkan posisi data tengah

• Selanjutnya data yang dicari akan dibandingkan dengan data yang berada di posisi tengah, apakah lebih besar atau lebih kecil.

• Apabila data yang dicari lebih besar dari data tengah, maka dapat dipastikan bahwa data yang dicari kemungkinan berada di sebelah kanan dari data tengah. Proses pencarian selanjutnya akan
dilakukan pembagian data menjadi dua bagian pada bagian kanan dengan acuan posisi data tengah akan menjadi posisi awal untuk pembagian tersebut.

• Apabila data yang dicari lebih kecil dari data tengah, maka dapat
dipastikan bahwa data yang dicari kemungkinan berada di sebelah
kiri dari data tengah. Proses pencarian selanjutnya akan dilakukan
pembagian data menjadi dua bagian pada bagian kiri. Dengan acuan
posisi data tengah akan menjadi posisi akhir untuk pembagian
selanjutnya.

• Apabila data belum ditemukan, maka pencarian akan dilanjutkan
dengan kembali membagi data menjadi dua

• Namun apabila data bernilai sama, maka data yang dicari langsung
ditemukan dan pencarian dihentikan

## Guided 1

### 1. Sequential search

```C++
#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int data[n] = {7, 4, 2, 3, 5, 4, 10, 9, 6, 19};
    int cari = 5;
    bool ketemu = false;
    int i;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "Data: {7, 4, 2, 3, 5, 4, 10, 9, 6, 19}" << endl;
    if (ketemu) {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}

```

### Output 
![Screenshot 2024-04-03 145821](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/1e79c7f3-2fc0-49ea-90c1-6d2c02d89a18)


Kode di atas adalah implementasi dari algoritma Sequential Search dalam bahasa pemrograman C++. Program ini mencari nilai tertentu dalam sebuah array yang telah ditentukan sebelumnya. Array tersebut kemudian dicari menggunakan algoritma pencarian sekuensial. Jika nilai yang dicari ditemukan dalam array, program akan mencetak pesan yang menyatakan bahwa nilai tersebut ditemukan bersama dengan indeks pertamanya di dalam array. Namun, jika nilai yang dicari tidak ditemukan dalam array, program akan mencetak pesan bahwa nilai tersebut tidak ditemukan. Setelah mencetak pesan, program kemudian mengakhiri eksekusi.

## Guided 2

### 2. Binary search
``` c++
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

void binarysearch();

int main() {
    binarysearch();
    return 0;
}

void binarysearch() {
    int cari, awal, tengah, akhir, temp, min;
    int data[7] = {12, 11, 8, 34, 33, 5, 87};

    cout << "Masukkan angka yang dicari: ";
    cin >> cari;

    awal = 0;
    akhir = 6;

    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (data[tengah] == cari) {
            cout << "Angka " << cari << " ditemukan di indeks " << tengah << endl;
            break;
        } else if (data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (awal > akhir) {
        cout << "Angka " << cari << " tidak ditemukan." << endl;
    }
}

```
### output
![Screenshot 2024-04-03 151547](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/555a355c-b0c2-4428-8702-040401b0ff69)

Kode di atas adalah implementasi algoritma pencarian biner dalam C++ untuk mencari nilai tertentu dalam array yang sudah terurut. Setelah meminta input dari pengguna, program mencari nilai tersebut dalam array menggunakan algoritma pencarian biner. Namun, terdapat konflik nama dengan fungsi bawaan C++ seperti std::min, sehingga nama variabel min diganti menjadi minIndex. Selain itu, fungsi std::data() juga digunakan dalam kode tersebut.


## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void binarySearch(const string& sentence, char target);

int main() {
    string sentence;
    char target;

    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    // Memastikan kalimat dalam huruf kecil untuk pencarian yang konsisten
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

    cout << "Masukkan huruf yang dicari: ";
    cin >> target;
    
    binarySearch(sentence, target);

    return 0;
}

void binarySearch(const string& sentence, char target) {
    int left = 0;
    int right = sentence.size() - 1;
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;

        if (sentence[middle] == target) {
            cout << "Huruf " << target << " ditemukan di indeks " << middle << endl;
            return;
        } else if (sentence[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    cout << "Huruf " << target << " tidak ditemukan dalam kalimat." << endl;
}

```
#### Output:
![Screenshot 2024-04-03 152404](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/035395f9-9734-4591-a6b2-e43099433fb5)


kodingan di atas merupakan kodingan untuk mencari huruf dari kalimat yang telah di inputkan oleh user,dalam hal ini saya menginput kan kalimat "praktikum deo gacor" dan mencari huruf 'e' dan kemudian telah di temukan kalau huruf e terdapat di indeks 11

#### Full code Screenshot:
![Screenshot (149)](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/7f7ab52b-7f59-4c34-ba39-d1493aae4c0d)

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

``` c++ 
#include <iostream>
#include <string>
using namespace std;

int main() {
    string kalimat;
    int jumlahVokal = 0;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    for (char karakter : kalimat) {
        if (karakter == 'a' || karakter == 'A' ||
            karakter == 'e' || karakter == 'E' ||
            karakter == 'i' || karakter == 'I' ||
            karakter == 'o' || karakter == 'O' ||
            karakter == 'u' || karakter == 'U') {
            jumlahVokal++;
        }
    }

    cout << "Jumlah huruf vokal dalam kalimat tersebut: " << jumlahVokal << endl;

    return 0;
}

```

### Output
![Screenshot 2024-04-03 153420](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/6cea06d8-a82a-4cd0-abb1-f1504ce03a30)

kodingan di atas merupakan kodingan untuk mencari dan menentukan jumlah huruf vokal dari kalimat yang di input user dalam hal ini saya menginputkan kalimat "lebaran kok ngelaprak" dan kemudian terdeteksi bahwa terdapat 7 huruf vokal dari kodingan tersebut.

### FULL CODE SS
![Screenshot (150)](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/30a3476b-1dc7-43e7-95e3-1e4ad3c4c196)

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

``` c++
#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari; 
    bool ketemu = false;
    int i;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
        }
    }

    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "Data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl; 
    if (ketemu) {
        int jumlah = 0; // tambahkan variabel untuk menyimpan jumlah angka yang ditemukan
        for (i = 0; i < n; i++) {
            if (data[i] == cari) {
                jumlah++;
            }
        }
        cout << "\nAngka " << cari << " ditemukan sebanyak " << jumlah << " kali." << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}


```

### Output 
  
![Screenshot 2024-04-03 155145](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/abd2c34e-49f7-405d-9ff7-d4e172b4f8ad)

Kodingan di atas merupakan kodingan sequential search untuk mencari jumlah angka yang terdapat dalam kodingan yang sudah di masukkan, dan untuk kodingan ini saya menginputkan sendiri atau user menginputsendiri angka yang ingin di cari dalam soal yang di minta adalah angka '4' dan kemudian telah di temukan bahwa angka '4' di temukan sebanyak "4" kali.

### Full code ss
![Screenshot (151)](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/1fcbee2d-ae60-4f62-ace7-d9dc69fc7b8e)


## Kesimpulan
Kesimpulan dari pembelajaran praktikum struktur data hari ini dan laprak mengenai modul searching, saya dapat mengetahui bahwa ada 2 metode searching yaitu sequential search dan binary search, 2 metode tersebut memiliki fungsi yang berbeda tergantung dari kemauan kita atau kepentingan kita menggunakan yang mana.

## Referensi
[1] Samsir, S. (2022). Perancangan aplikasi kamus bahasa Batak menggunakan metode searching. INFORMATIKA, 10(3), 138-150.

[2] Nasution, H. F., Suranti, D., & Fredricka, J. (2023). Application of sequential searching method in searching case data at the office Prosecutor's office. Jurnal Komputer Indonesia, 2(2), 79-90.

[3] Syahputra, G. (2016). Implementasi Teknik Binary Search Pada Kamus Indonesia-Batak Toba. Journal Of Informatic Pelita Nusantara, 1(1).
