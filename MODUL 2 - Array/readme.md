# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">CHelsisdeo A.P Sanenek</p>
<p align="center">2311110016
<p align="center">SD04-A

## Dasar Teori

Data array itu seperti rak buku di perpustakaan. Setiap buku memiliki nomor rak yang unik, dan Anda bisa mengambil buku tersebut dengan cepat karena Anda tahu di mana letaknya. Begitu juga dengan array, setiap elemen memiliki nomor indeks, dan Anda bisa mengakses nilai tersebut langsung dengan nomor indeksnya tanpa harus mencari satu per satu.

1. Array 1 Dimensi 

array yang terdiri dari satu baris dan banyak kolom atau satu
kolom dan banyak baris.  Cara pendeklarasian array 1 dimensi mirip dengan cara pendeklarasian variabel dengan
tipe data tertentu. Hanya terdapat penambahan tanda kurung siku (“[“ dan “]”) untuk
menunjukan jumlah maksimum data yang dapat ditampung oleh variabel array tersebut.[1]

2. Array 2 Dimensi 

Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang.[2]

3. Array multi Dimensi

Array multi-dimensi merupakan array yang mempunyai ukuran lebih dari dua. Bentuk 
pendeklarasian array sama saja dengan array dimensi satu maupun array dimensi dua.[3]

4.  Array 4 Dimensi 

Array 4 dimensi adalah struktur data dalam pemrograman yang memungkinkan penyimpanan dan pengelolaan data dalam empat dimensi. Ini berarti bahwa data disusun dalam bentuk tabel atau matriks yang memiliki empat tingkat indeks atau dimensi. Misalnya, dalam pemrograman gambar medis, array 4 dimensi dapat digunakan untuk merepresentasikan data citra dalam tiga dimensi (seperti gambar CT scan) dengan dimensi keempat yang mewakili perubahan citra dari waktu ke waktu. 

5. Array 5 Dimensi 

Array 5 dimensi adalah struktur data dalam pemrograman yang memungkinkan penyimpanan dan pengelolaan data dalam lima dimensi. Ini berarti bahwa data disusun dalam bentuk tabel atau matriks yang memiliki lima tingkat indeks atau dimensi.


## Guided 1

### 1. [Program input array 3 Dimensi]

```C++
#include <iostream>
using namespace std;

// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr [2][3][3];
    // Input elemen
    for (int x = 0; x < 2 ; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; x < 3; y++)
        {
            for (int z = 0; x < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2 ; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
## Output 

<img width="684" alt="Screenshot 2024-03-19 141627" src="https://github.com/chelsisdeo/praksrtukdata/assets/161056340/9d297f24-9604-4cbd-9ec5-a59a931580eb">

-> program di atas merupakan program untuk menginput array 3 dimensi

## Guided 2

### [Program mencari nilai maksimal pada array]
``` c++
#include <iostream>
using namespace std;
int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}

```
## Output 
<img width="588" alt="Screenshot 2024-03-19 142436" src="https://github.com/chelsisdeo/praksrtukdata/assets/161056340/9b57e37a-bd7a-4e3e-a9b7-4762bbd5eee8">

-> program di atas adalah program untuk mencari nilai makisimal dari suatu array,dengan penginputan yang di lakukan oleh user



## Unguided 1

#### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user]

![Screenshot 2024-03-20 134558](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/da77ae67-87ff-40ef-bc8c-ca7907b54392)

### Jawab unguided 1
1. 
``` c++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah angka dalam array: ";
    cin >> n;

    // Untuk deklarasi jumlah angka dalam array
    int angka[n];

    // Meminta user untuk memasukkan angka apa saja ke dalam data array
    cout << "Data Array : ";
    for (int i = 0; i < n; ++i) {
        cin >> angka[i];
    }


    // Menampilkan angka genap
    cout << "Nomor Genap  : ";
    for (int i = 0; i < n; ++i) {
        if (angka[i] % 2 == 0) {
            cout << angka[i] << ", ";
        }
    }
    cout << endl;

    // Menampilkan angka ganjil
    cout << "Nomor Ganjil : ";
    for (int i = 0; i < n; ++i) {
        if (angka[i] % 2 != 0) {
            cout << angka[i] << ", ";
        }
    }
    cout << endl;
    return 0;
}

```

### Output Unguided 1
![Screenshot 2024-03-22 145618](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/76348a7c-da63-452c-8f1a-cd42ba9e1102)

Code dan output di atas merupakan program untuk menampilkan angka genap dan ganjil dari angka yang sudah di masukkan sesuai dengan panjang array yang sudah di deklarasikan.


### Full code Screnshoot
![Screenshot (139)](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/b8f30f60-fab2-4239-8a08-6e0d1b586696)


## Unguided 2

#### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user]


##### jawab Unguided 2

``` c++
#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel untuk menyimpan ukuran array
    int x_size, y_size, z_size;

    // Masukkan ukuran array sepuasnyaa
    cout << "Masukkan ukuran array (x y z): ";
    cin >> x_size >> y_size >> z_size;

    // Deklarasikan array
    int arr[x_size][y_size][z_size];

    // Input elemen array
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output array
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    //  Untuk Tampilan array
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << arr[x][y][z] << endl;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}


```

### OUTPUT Unguided 2
![Screenshot 2024-03-20 144515](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/303341d2-6af0-4203-991f-0b48131f03cd)

Program ini memungkinkan pengguna untuk membuat array tiga dimensi sesuai ukuran yang diinginkan dan memasukkan nilai-nilainya. Kemudian, program menampilkan nilai-nilai tersebut dengan dua cara: pertama dengan menampilkan koordinat array, dan kedua hanya menampilkan nilai-nilai secara berurutan. Ini membantu pengguna untuk memahami struktur array tiga dimensi dan melihat nilai-nilai dalam format yang mudah dipahami.



### Full code screenshoot
![Screenshot (138)](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/e7375107-eb88-4cbc-9580-5fd09f2f3970)


## Unguided 3

#### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]


## JAWABAN Unguided 3
``` c++
#include <iostream>
using namespace std;
int main()
{
int maks, a, i = 1, lokasi;
cout << "Masukkan panjang array: ";
cin >> a;
int array[a];
cout << "Masukkan " << a << " angka\n";
for (i = 0; i < a; i++)
{
cout << "Array ke-" << (i) << ": ";
cin >> array[i];
}
maks = array[0];
for (i = 0; i < a; i++)
{
if (array[i] > maks)
{
maks = array[i];
lokasi = i;
}
}
cout << "Nilai maksimum adalah " << maks << " berada di Array
ke " << lokasi << endl;
}

```
#### Output Unguided 3

![Screenshot 2024-03-22 182742](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/4ec71858-a33b-4694-9eea-5c82eb624507)

Kode di atas merupakan kode untuk menampilkann nilai maksimum,minimum,dan rata-rata dari array yang di input kan oleh user, kode di atas merupakan MODIFIKASI dari kode di unguided 1.

#### Full code Screenshot:
![Screenshot (141)](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/be31ff15-1034-4509-b740-8c52b8cb4bc6)


## Kesimpulan
Dari pembelajaran berikut ini saya menyimpulkan bahwa array terbagi dari berbagai macam jenis dari 1 dimensi,2,3,4,hingga 5 dimensi, dan dari pembelajaran hari ini saya dapat mengetahui bahwa Array adalah struktur data yang berguna dalam pemrograman karena memungkinkan kita untuk menyimpan sekumpulan nilai dalam satu variabel. Dengan menggunakan array, kita dapat mengakses dan memanipulasi data secara efisien. Kesimpulannya, pemahaman tentang penggunaan array akan mempermudah kita dalam mengelola data dalam program dengan lebih efektif.

## Referensi dari jurnal. 
Junaedi, D. ARRAY 1 DIMENSI. [1]

Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++. [2]

Zusane Oematan, M. (2010). Array Multidimensi Dan Pointer.[3]
