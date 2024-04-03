# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Chelsisdeo A.P Sanenek</p>
<p align="center">2311110016</p>

## Dasar Teori

1. Konsep dasar Sorting


Pengurutan (Sorting) adalah proses pengurutan data yang sebelumnya disusun secara acak sehingga tersusun secara teratur menurut aturan tertentu.

Berdasarkan data terurutnya, algoritma sorting dibagi menjadi dua jenis, yaitu:
- Ascending; pengurutan dari terkecil hingga terbesar. Contoh: a, b, c, d, e.
- Descending; pengurutan dari nilai terbesar hingga terkecil. Contoh: e, d, c, b, a

2. Insertion sort

Salah satu algoritma sorting yang paling  sederhan aadalahinsertion  sort.InsertionSort disebut-sebut  sebagai   metode pertengahan. Artinya, metode inimemilikikecepatan rata-rataantarametode  primitif(bubbledan  selection)  dan modern (merge  dan  quick).[1]

### -> pseudocode
```
for i = 1 to n-1
set j = i
set t = a[j]
repeat while j > 0 and a[j-1] > t
move a[j-1] to right
end repeat
set a[j] = t
end for
```
### Prosedur insertion sort dalam C++
``` c++
void insertion_sort(int arr[], int length) {
int i, j ,tmp;
for (i = 1; i < length; i++) {
 j = i;
while (j > 0 && arr[j - 1] > arr[j]) {
 tmp = arr[j];
 arr[j] = arr[j - 1];
 arr[j - 1] = tmp;
 j--;
 }//end of while loop
}//end of for loop
}
```

###  Contoh 
``` c++
#include <iostream>
using namespace std;
void insertion_sort(int arr[], int length) {
 int i, j ,tmp;
 for (i = 1; i < length; i++) {
 j = i;
 while (j > 0 && arr[j - 1] > arr[j]) {
 tmp = arr[j];
 arr[j] = arr[j - 1];
 arr[j - 1] = tmp;
 j--;
 }//end of while loop
 }//end of for loop
}
void print_array(int a[], int length) {
 for(int i=0; i<length; i++) {
 cout << a[i] << "\t";
 }
 cout << endl;
}
int main() {
 int length = 6;
 int a[length] = {22, 10, 15, 3, 8, 2};
 insertion_sort(a, length);
 print_array(a, length);
}
```

3. Bubble sort

Algoritma Bubble Sort adalah algoritma yang terinspirasi dari gelembung sabun yang
berada pada permukaan air. Karena berat jenis gelembung sabun lebih ringan daripada berat
jenis air, maka gelembung sabun akan terapung ke atas permukaan. Apabila kita menginginkan
larik terurut naik, maka elemen larik yang paling kecil diapungkan ke atas melalui proses
pertukaran atau bisa disebutkan bahwa arah perbandingan dilakukan dari belakang.
Studi kasus diberikan urutan bilangan adalah seperti berikut:
59   20     56  90  3    40  14  78  3  -1 [2]

 ### Contoh Prosedur Bubble Sort dalam bahasa C++
 ``` c++
 #include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tap;

    while (not_sorted){
        not_sorted = false;
        j++;
        for(int i = 0; i < length - j; j++){
            if(arr[i] > arr[i + 1]){
                tap = arr[i];
                arr[i] = arr[i +1];
                arr[i + 1] = tap;
                not_sorted = true;
            }// end off it 
        }// end for loop
        
    }// end of while loop
}// end of buble short 

void print_array(double a[], int length) {

    for(int i=0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main(){
    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};

    cout << "urutan bilangan sebelum sorting : " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\n urutan bilangan setelah sortiing: " << endl;
    print_array(a, length);
}

```

4. Selection sort

Selection Sort merupakan salah satu algoritma pengurutan yang sederhana.
Ide dasarnya adalah melakukan beberapa kali pass untuk melakukan penyeleksian
elemen struktur data. Untuk sorting ascending (menaik) elemen yang paling kecil
di antara elemen-elemen yang belum urut, disimpan indeksnya, kemudian
dilakukan pertukaran nilai elemen dengan indeks yang disimpan tersebut dengan
elemen yang paling depan yang belum urut. Sebaliknya, untuk sorting descending
(menurun) elemen yang paling besar yang disimpan indeksnya kemudian ditukar.
Selection Sort diakui karena kesederhanaan algoritmanya dan performanya lebih
bagus dari pada algoritma lain yang lebih rumit dalam situasi tertentu.[3]

### Contoh prosedur selection sort
``` c++
void selectSort(int arr[], int n) {
 int pos_min,temp;
for (int i=0; i < n-1; i++) {
 pos_min = i;
for (int j=i+1; j < n; j++) {
 if (arr[j] < arr[pos_min])
 pos_min=j;
}
 if (pos_min != i) {
 temp = arr[i];
 arr[i] = arr[pos_min];
 arr[pos_min] = temp;
 }
}
}
```

## Guided 1

### 1. Bubble sort

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tap;

    while (not_sorted){
        not_sorted = false;
        j++;
        for(int i = 0; i < length - j; j++){
            if(arr[i] > arr[i + 1]){
                tap = arr[i];
                arr[i] = arr[i +1];
                arr[i + 1] = tap;
                not_sorted = true;
            }// end off it 
        }// end for loop
        
    }// end of while loop
}// end of buble short 

void print_array(double a[], int length) {

    for(int i=0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main(){
    int length = 6;
    double a[] = {5.7, 8.3, 7.5, 90.5, 34.9, 78.1 , 67.9};

    cout << "urutan bilangan sebelum sorting : " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\n urutan bilangan setelah sortiing: " << endl;
    print_array(a, length);
}

```
### output guided 1
![Screenshot 2024-03-30 150116](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/d985e774-df17-4ab9-af5a-f7cee4dfc868)

Algoritma digunakan digunakan untuk mengurutkan array bilangan desimal secara menaik. Fungsi bubble_sort melakukan iterasi melalui array dan bertukar posisi antara dua elemen jika elemen sebelumnya lebih besar dari elemen setelahnya, terus-menerus hingga tidak ada lagi pertukaran yang terjadi, menandakan bahwa array sudah terurut.

## Guided 2 
2. Insertion sort

```c++
#include <iostream>

using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for(i=1; i < length; i++){
        j = i;

        while (j > 0 && arr[j - 1 ] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }// end of while loop
    }// end of for loop
}

void print_array(char a[], int length){
    for(int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}


int main() {
    int length = 7;
    char a[length] = {'l', 'i', 'c', 'h','t', 'i', 'n'};

    cout << "urutan karakter sebelum sorting : " << endl;
    print_array(a, length);

    cout << "\n urutan karakter setelah sorting: " << endl;
    print_array(a, length);

}

```
### output guided 2
![Screenshot 2024-03-30 151418](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/5e4aa148-35b3-4ebc-bec8-b29e4817b467)

Program ini menggunakan algoritma pengurutan penyisipan (insertion sort) untuk mengurutkan array karakter dalam urutan menurun.

## Unguided 1

#### 1.  Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! 

```C++
#include <iostream>

using namespace std;

void selection_sort(double arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            double temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }
    }
}

void print_array(double a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 5;
    double ips[] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "IPS mahasiswa sebelum sorting : " << endl;
    print_array(ips, length);

    selection_sort(ips, length);

    cout << "\nIPS mahasiswa setelah sorting: " << endl;
    print_array(ips, length);

    return 0;
}

```
#### Output unguided 1:
![Screenshot 2024-03-30 153307](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/5c610f45-3394-4bad-9a93-1fc4e6caa017)

#### penjelasan 

Algoritma Selection Sort memiliki kompleksitas waktu O(n^2), di mana 'n' adalah jumlah elemen dalam array. Ini karena algoritma tersebut menggunakan dua loop bersarang. Di dalam loop pertama, algoritma memilih elemen terbesar dari sisa array dan memindahkannya ke posisi yang sesuai. Untuk setiap iterasi dari loop pertama, loop kedua digunakan untuk mencari elemen terbesar di sisa array. Proses ini diulangi sampai seluruh array diurutkan.


#### Full code Screenshot:
![Screenshot (142)](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/05cc4003-504c-4e24-b6a3-0f2df291a842)

### Unguided 2


#### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort! 

``` c++
#include <iostream>
#include <string>

using namespace std;

void bubble_sort(string arr[], int length) {
    bool not_sorted = true;
    int j = 0;
    string temp;

    while (not_sorted) {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                not_sorted = true;
            }
        }
    }
}

void print_array(string a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 10;
    string names[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Nama sebelum pengurutan: " << endl;
    print_array(names, length);

    bubble_sort(names, length);

    cout << "\nNama setelah pengurutan: " << endl;
    print_array(names, length);

    return 0;
}

```
#### Output unguided 2
![Screenshot 2024-03-30 155333](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/3900338b-364d-45bd-b8b5-234ab66c04c7)

#### penjelasan 

Program tersebut menggunakan algoritma Bubble Sort untuk mengurutkan array nama-nama warga secara alfabet. Algoritma Bubble Sort memiliki kompleksitas waktu O(n^2), di mana 'n' adalah jumlah elemen dalam array, karena melibatkan dua loop bersarang. Output program menampilkan nama-nama warga sebelum dan setelah diurutkan secara alfabet. Proses pengurutan dilakukan dengan membandingkan setiap pasangan nama dan menukar posisi jika nama sebelumnya lebih besar dari nama setelahnya, terus-menerus hingga tidak ada lagi pertukaran yang terjadi.

#### FUll code screenshoot
![Screenshot 2024-03-30 155311](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/0e3f8d78-6da9-47e0-beab-ab22d7359dc4)

## Unguided 3

#### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)! 

``` c++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    char characters[n];
    // meminta pengguna memasukkan karakter
    for (int i = 0; i < n; ++i) {
        cout << "Karakter ke-" << i + 1 << " : ";
        cin >> characters[i];
    }
    // Sorting secara menaik (ascending)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (characters[i] > characters[j]) {
                char temp = characters[i];
                characters[i] = characters[j];
                characters[j] = temp;
            }
        }
    }
    // Menampilkan hasil ascending
    cout << "\nUrutan karakter setelah ascending sort :\n";
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << "\t";
    }
    cout << endl;
    // Sorting secara menurun (descending)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (characters[i] < characters[j]) {
                char temp = characters[i];
                characters[i] = characters[j];
                characters[j] = temp;
            }
        }
    }
    // Menampilkan hasil descending
    cout << "\nUrutan karakter setelah descending sort:\n";
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << "\t";
    }
    cout << endl;

    return 0;
}

```
### output unguided 3
![Screenshot 2024-03-30 164142](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/28a5632d-bc86-43d6-84dc-d1fd979e7aa2)


### penjelasan 
Program C++ di atas menerima masukan jumlah karakter (n) dan karakter-karakter dari pengguna, lalu mengurutkan karakter-karakter tersebut secara menaik (ascending) dan menurun (descending) menggunakan algoritma Bubble Sort. Algoritma Bubble Sort memiliki kompleksitas waktu O(n^2) dalam kasus terburuk karena melibatkan dua pengulangan bersarang, masing-masing berjalan sebanyak 'n' kali. Hasilnya, program menampilkan urutan karakter sebelum dan sesudah pengurutan dalam waktu O(n) untuk setiap tahap, di mana 'n' adalah jumlah karakter yang dimasukkan pengguna. Jadi, secara keseluruhan, program tersebut memiliki kompleksitas waktu O(n^2), tetapi operasi menampilkan hasil memiliki kompleksitas waktu O(n) untuk setiap tahap.

### Full code ss 
![Screenshot 2024-03-30 164259](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/734bb19b-367e-4033-80c2-800732758168)


## Kesimpulan
Hari ini, saya telah mempelajari tentang teknik sorting, di mana saya memahami bagaimana algoritma seperti Bubble Sort dapat digunakan untuk mengurutkan data dalam urutan menaik atau menurun. Melalui pembahasan ini, saya memahami pentingnya pemahaman tentang kompleksitas waktu algoritma dalam memilih teknik sorting yang efisien untuk penyelesaian masalah tertentu.

## Referensi
[1] Setyantoro, D., & Hasibuan, R. A. (2020). Analisis dan Perbandingan Kompleksitas Algoritma Exchange Sort dan Insertion Sort untuk Pengurutan Data menggunakan Python. Jurnal Ilmiah Teknik Informatika (TEKINFO), 21(1), 48-56.

[2]Arifin, R. W., & Setiyadi, D. (2020). Algoritma Metode Pengurutan Bubble Sort dan Quick Sort Dalam Bahasa Pemrograman C++. INFORMATION SYSTEM FOR EDUCATORS AND PROFESSIONALS: Journal of Information System, 4(2), 178-187.

[3] Yovita, C. (2023). Penerapan Algoritma Naive Bayes dan Selection Sort Pada Penilaian Kuis Di Aplikasi Pembelajaran Pemrograman Java dan PHP (Doctoral dissertation, Fakultas Teknik, Universitas Islam Sumatera Utara).
