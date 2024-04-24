# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Chelsisdeo A.P Sanenek</p>
<p align="center">2311110016</p>

## Dasar Teori

## 1. Variabel

Analogi dari variabel adalah seperti sebuah wadah untuk menyimpan informasi dengan jenis tertentu. Cara kita mendeklarasikan variabel adalah dengan menuliskan tipe data diikuti oleh nama variabel, seperti contoh dengan "int berat", "string mata_kuliah", atau "char jenis_kelamin". Secara bawaan, sebuah variabel hanya bisa menampung satu nilai, seperti misalnya variabel "berat" yang hanya bisa menyimpan satu nilai berat seperti 175 kg; tidak bisa diisi dengan lebih dari satu nilai. Namun, jika kita ingin menyimpan lebih dari satu nilai, kita bisa mendeklarasikan variabel sebagai array dengan menuliskan tipe data diikuti oleh nama variabel dan jumlah data yang diinginkan, misalnya "tipe_data nama_variabel [banyak data]".


- Variabel lokal

variabel lokal adalah variabel otomatis yang disimpan langsung di tumpukan panggilan . Ini berarti bahwa ketika suatu fungsi rekursif memanggil dirinya sendiri, variabel lokal di setiap instance fungsi tersebut diberi alamat yang berbeda.

- variabel global

Variabel global adalah variabel yang dideklarasikan di luar semua fungsi atau blok kode, membuatnya dapat diakses dari mana pun dalam program tanpa batasan lingkup lokal.

## 2. struktur (struct)

Struct adalah tipe data bentukan yang berisi kumpulan variabel-variabel
yang bernaung dalam satu nama yang sama dan memiliki kaitan satu sama lain.
Berbeda dengan array hanya berupa kumpulan variabel yang bertipe data sama,
struct bisa memiliki variabel-variabel yang bertipe data sama atau berbeda,
bahkan bisa menyimpan variabel yang bertipe data array atau struct itu sendiri.[1]

(Klasifikasi data struct)

- Disusun oleh satu atau lebih field. Tiap field menyimpandatadari tipedasar tertentu atau dari tipe bentukan lain yang sudahdidefinisikansebelumnya. Nama rekaman ditentukan oleh pemrogram.[2]

- Bermanfaat untuk mengelompokkan sejumlah data dengan tipe data yang berlainan.[2]

### keyword yang digunakan untuk membuat/mendeklarasikan sebuah struktur yakni struct. Terdapat banyak format penulisan diantaranya :

``` c++
struct {
    string namaDepan;
    string namaBelakang;
    int usia;
    char jenis_kelamin;
}namaVariabelStrukA, namaVariabelStrukB;
```

``` c++
struct namaTipe{
    string namaDepan;
    string namaTengah;
    string namaBelakang;
}; struct namaTipe namaVariabelStrukA, namaVariabelStrukB;
```

``` c++
typedef struct {
    string namaDepan;
    string namaTengah;
    string namaBelakang;
}namaTipe;
namaTipe namaVariabelStrukA,namaVariabelStrukB;
```
 - ==> Tipe data struct yang telah dibuat (menggunakan cara 2 dan 3) menjadi tipe
data standar yang penggunaannya sama dengan tipe data standar lainnya. 


## Guided 1

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

``` c++

#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    
    buku favorit;

    favorit.judulBuku = "Atomic Habits";
    favorit.pengarang = "James clear";
    favorit.penerbit = "Gramedia Pustaka Utama";
    favorit.tebalHalaman = 352;
    favorit.hargaBuku = 102000;

    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}

```

### OUTPUT
![Screenshot 2024-04-23 085304](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/78baec0e-b53f-40a1-a0a5-980a1b18cff4)

Kodingan tersebut mendefinisikan sebuah struktur buku dengan lima atribut, seperti judul, pengarang, dan harga. Nilai-nilai atribut tersebut diisi untuk satu buku favorit, kemudian ditampilkan secara terstruktur menggunakan perintah cout. Outputnya adalah informasi tentang buku favorit, termasuk judul, pengarang, penerbit, jumlah halaman, dan harga buku.


## Guided 2 
### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.

![Screenshot 2024-04-22 044821](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/f3f85145-4bbb-4b83-a703-f24c0f5c5d30)

``` c++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kucing; // Tipe hewan darat -> Kucing
    kucing.jumlahKaki = 4;
    kucing.menyusui = true;
    kucing.suara = "Meong-Meong";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik atau racun";

    hewan beruang; // hewan beruang
    beruang.namaHewan = "beruang";
    beruang.jenisKelamin = "Jantan";
    beruang.caraBerkembangbiak = "Melahirkan";
    beruang.alatPernafasan = "Paru-paru";
    beruang.tempatHidup = "Hutan daerah pegunungan";
    beruang.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << beruang.namaHewan << endl;
    cout << "\tJenis kelamin : " << beruang.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << beruang.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << beruang.alatPernafasan << endl;
    cout << "\tTempat hidup : " << beruang.tempatHidup << endl;
    cout << "\tKarnivora : " << (beruang.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKucing" << endl;
    cout << "\tJumlah kaki : " << kucing.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kucing.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kucing.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```
### OUTPUT
![Screenshot 2024-04-23 085409](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/dabd523a-60db-42c1-9ebe-6e26140277e7)
Kodingan tersebut mendefinisikan struktur data untuk hewan, dengan detail tentang nama, jenis kelamin, cara berkembangbiak, alat pernafasan, tempat hidup, dan status Karnivora. Selain itu, ada struktur tambahan untuk hewan darat dan hewan laut, yang masing-masing menyimpan informasi spesifik tentang hewan-hewan tersebut. Dalam outputnya, informasi tentang tiga hewan berbeda (beruang, kucing, dan ikan) ditampilkan dengan rapi, termasuk detail tentang masing-masing jenis hewan dan atribut-atribut yang relevan.

## Unguided 1

#### 1.   Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.

#### Berikut adalah jawabannya

``` c++
#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam array variabel favorit
    for (int i = 0; i < 5; ++i) {
        favorit.judulBuku[i] = "Atomic Habits";
        favorit.pengarang[i] = "James Clear";
        favorit.penerbit[i] = "Gramedia Pustaka Utama";
        favorit.tebalHalaman[i] = 352;
        favorit.hargaBuku[i] = 102000;
    }

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "\tData ke-" << i+1 << endl;
        cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i] << endl;
        cout << endl;
    }
 
    return 0;
}

```

### Output 
![Screenshot (154)](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/00d22248-4f81-4425-86f2-24201c70de92)


### penjelasan
Dalam kode di atas, setiap item dalam struct buku telah diubah menjadi array yang berukuran 5. Data kemudian dimasukkan ke dalam array tersebut menggunakan loop, dan selanjutnya ditampilkan dengan loop lainnya. Semua informasi dari setiap buku (dalam hal ini, buku favorit) akan ditampilkan secara terpisah 

### Full code ss
![Screenshot (155)](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/5262590f-ddc8-4b33-b307-fcc6f159223c)

### Unguided 2

#### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

``` C++
#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit sebagai array dengan 5 elemen
    buku favorit[5];

    // Mengisi data ke dalam setiap elemen array favorit
    for (int i = 0; i < 5; ++i) {
        favorit[i].judulBuku = "Atomic Habits";
        favorit[i].pengarang = "James Clear";
        favorit[i].penerbit = "Gramedia Pustaka Utama";
        favorit[i].tebalHalaman = 352;
        favorit[i].hargaBuku = 102000;
    }

    // Menampilkan informasi buku favorit
    for (int i = 0; i < 5; ++i) {
        cout << "\tBuku Favorit Saya " << i+1 << endl;
        cout << "\tJudul Buku : " << favorit[i].judulBuku << endl;
        cout << "\tPengarang : " << favorit[i].pengarang << endl;
        cout << "\tPenerbit : " << favorit[i].penerbit << endl;
        cout << "\tTebal Halaman: " << favorit[i].tebalHalaman << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit[i].hargaBuku << endl << endl;
    }
 
    return 0;
}

```
### Output 
![Screenshot 2024-04-23 090320](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/a7e38c38-104a-40b9-8fce-7380a9688450)

### Penjelasan
kodingan ini menampilkan array favorit dideklarasikan dengan 5 elemen. Kemudian, data diisi ke setiap elemen array menggunakan loop for. Setelah itu, loop for lainnya digunakan untuk menampilkan informasi dari setiap buku favorit yang disimpan dalam array favorit.

### Full code ss
![Screenshot 2024-04-23 090243](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/4837f617-9710-46fa-8d9e-076a0d1ba2ea)

## Kesimpulan
Pembelajaran hari ini tentang struktur data dalam pemrograman mengilustrasikan konsep penting dalam pengorganisasian dan manipulasi data. Melalui penggunaan struct, kita dapat merepresentasikan entitas kompleks seperti mahasiswa atau barang dengan cara yang terstruktur dan terorganisir. Hal ini tidak hanya memungkinkan akses dan manipulasi data yang efisien melalui operator ".", tetapi juga membantu dalam penghematan penggunaan memori dengan mengelompokkan data yang terkait bersama-sama. Dengan pemahaman yang mendalam tentang penggunaan struct, pengembang dapat meningkatkan keefektifan dalam menulis kode program dan memperluas kemampuan untuk mengelola data dengan cara yang lebih sistematis dan terstruktur.
## Referensi
[1] Triase, T. (2020). Struktur Data: Diktat Edisi Revisi.

[2] Dwi Rahmatya, M. (2020). Tipe Data Array Dan Struct.

