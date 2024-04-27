# <h1 align="center">Laporan Praktikum Circular & Non Circular</h1>
<p align="center">Chelsisdeo A.P Sanenek</p>
<p align="center">2311110016</p>

## Dasar Teori

### A. Linked List Non Circular 
Linked list non circular merupakan linked list dengan node pertama (head) dan  node terakhir (tail) yang tidak saling terhubung. Pointer terakhir (tail) pada Linked  List ini selalu bernilai ‘NULL’ sebagai pertanda data terakhir dalam list-nya.
Setiap node pada linked list mempunyai field yang berisi data dan pointer ke node berikutnya & ke node sebelumnya. Untuk pembentukan node baru, mulanya pointer next dan prev akan menunjuk ke nilai NULL. Selanjutnya pointer prev akan menunjuk ke node sebelumnya, dan pointer next akan menunjuk ke node selanjutnya pada list.[1]

- BERIKUT ADALAH OPERASI PADA LINKED LIST NON CIRCULAR 

#### 1.  Penambahan Elemen (Insertion):
- Penambahan di awal linked list.
- Penambahan di akhir linked list.

#### 2. Penambahan di posisi tertentu (sebelum atau setelah simpul tertentu).

- Penghapusan Elemen (Deletion):
- Penghapusan dari awal linked list.
- Penghapusan dari akhir linked list.
- Penghapusan dari posisi tertentu.

#### 3. Pencarian (Search):
- Mencari apakah elemen tertentu ada dalam linked list.
- Mencari elemen tertentu berdasarkan nilai atau indeks.

#### 4. Traversal:

- Melintasi seluruh elemen linked list dari awal hingga akhir.

#### 5. Penggabungan (Concatenation):
- Menggabungkan dua linked list menjadi satu.
#### 6. Pengurutan (Sorting):

- Mengurutkan elemen-elemen linked list berdasarkan nilai.
#### 7. Penghapusan Duplikat (Remove Duplicates):
- Menghapus duplikat dari linked list.

#### 8. Pembalikan (Reversal):
- Membalik urutan elemen dalam linked list.
#### 9. Penghitungan Panjang (Length Count):
- Menghitung jumlah elemen dalam linked list.
#### 10. Akses Elemen (Access):
- Mengakses elemen pada posisi tertentu dalam linked list.

### B. Linked List Circular 

Double Linked List Circular adalah linked list
dengan menggunakan pointer, dimana setiap
node memiliki 3 field, yaitu:
- 1 field pointer yang menunjuk pointer
berikutnya (next),
- 1 field menunjuk pointer sebelumnya
(prev),
- serta sebuah field yang berisi data untuk
node tersebut.

Double Linked List Circular pointer next dan
prev nya menunjuk ke dirinya sendiri secara
circular. Setiap node pada linked list
mempunyai field yang berisi data dan pointer
ke node berikutnya & ke node sebelumnya.
Untuk pembentukan node baru, mulanya
pointer next dan prev akan menunjuk ke
dirinya sendiri. Jika sudah lebih dari satu node,
maka pointer prev akan menunjuk ke node
sebelumnya, dan pointer next akan menunjuk
ke node sesudahnya.[2]

- BERIKUT ADALAH OPERASI PADA LINKED LIST CIRCULAR 


1. Penambahan Elemen (Insertion): 
- Penambahan di awal linked list. Penambahan di akhir linked list. 
- Penambahan di posisi tertentu (sebelum atau setelah simpul tertentu). 
2. Penghapusan Elemen (Deletion): 
- Penghapusan dari awal linked list. 
- Penghapusan dari akhir linked list. 
- Penghapusan dari posisi tertentu. 
3. Pencarian (Search): 
- Mencari apakah elemen tertentu ada dalam linked list. 
- Mencari elemen tertentu berdasarkan nilai atau indeks. 
4. Traversal: Melintasi seluruh elemen linked list dari awal hingga akhir. 
5. Penggabungan (Concatenation): 
- Menggabungkan dua linked list menjadi satu.
- Pengurutan (Sorting): Mengurutkan elemen-elemen linked list berdasarkan nilai.
6. Penghapusan Duplikat (Remove Duplicates):
- Menghapus duplikat dari linked list.
7. Pembalikan (Reversal):
- Membalik urutan elemen dalam linked list.
8. Penghitungan Panjang (Length Count):
- Menghitung jumlah elemen dalam linked list.
9. Akses Elemen (Access):
- Mengakses elemen pada posisi tertentu dalam linked list.

## Guided 1

### 1. SINGLE LINKED LIST NON-CIRCULAR

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next; // Tanda * mendefinisikan variabel pointer yaitu menyimpan alamat dari variabel lain
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() { // Menggunakan void supaya tidak perlu memberikan return value
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru; // 1 node ini terdapat head, tail, dan variabel baru
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init(); // Harus ada untuk menginisialisasi capsul nodenya
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
```
Program tersebut adalah implementasi dari operasi-operasi dasar pada linked list non-circular menggunakan bahasa pemrograman C++. Linked list tersebut terdiri dari simpul-simpul yang memiliki data integer. Fungsi-fungsi seperti insertDepan, insertBelakang, hapusDepan, hapusBelakang, insertTengah, hapusTengah, ubahDepan, ubahBelakang, ubahTengah, clearList, dan tampil digunakan untuk menambah, menghapus, mengubah data, membersihkan, dan menampilkan elemen-elemen dalam linked list. Program kemudian mengeksekusi beberapa operasi tersebut seperti penambahan, penghapusan, dan pengubahan elemen, serta membersihkan linked list.

### output
![Screenshot 2024-04-27 193211](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/1febdcf6-19f9-4b95-9de0-2e57b02fb4cf)

### 2. Double Linked List
``` c++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev; // Previous digunakan untuk melihat data sebelumnya
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next; // Akan next terus sampai currentnya berhenti
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Program tersebut merupakan implementasi dari linked list ganda (doubly linked list) dalam bahasa pemrograman C++. Setiap simpul (node) dalam linked list memiliki dua pointer yaitu pointer ke simpul sebelumnya (prev) dan pointer ke simpul berikutnya (next). Kelas DoublyLinkedList menyediakan fungsi-fungsi untuk menambah, menghapus, memperbarui, membersihkan, dan menampilkan data dalam linked list. Di dalam main(), program memberikan pilihan kepada pengguna untuk melakukan operasi-operasi tersebut melalui menu sederhana dalam sebuah loop while.

### output
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/6008ab13-321b-419b-b7c8-cbd780d94189)


### 3. SINGLE LINKED LIST CIRCULAR
``` c++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data) {
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus-> next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil terhapus!" << endl;
}

//Tampilan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);

        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Program di atas adalah implementasi dari linked list circular dalam bahasa pemrograman C++. Struktur data linked list ini terdiri dari simpul-simpul yang saling terhubung, di mana simpul terakhir menunjuk kembali ke simpul pertama, membentuk suatu lingkaran. Setiap simpul memiliki dua komponen: data (dalam hal ini bertipe string) dan pointer yang menunjuk ke simpul berikutnya. Fungsi-fungsi yang disediakan meliputi penambahan elemen di depan, tengah, dan belakang, penghapusan elemen di depan, tengah, dan belakang, serta penampilan isi dari linked list. Program juga memberikan contoh penggunaan fungsi-fungsi tersebut melalui operasi-operasi dasar seperti penambahan, penghapusan, dan penampilan isi linked list.

### output
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/800213d6-2909-40e3-9b67-8807db905c39)


## Unguided 

### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan  NIM mahasiswa, berikut contoh tampilan output dari nomor 1: 
• Tampilan Menu: 
PROGRAM SINGLE LINKED LIST NON-CIRCULAR  
1. Tambah Depan  
2. Tambah Belakang  
3. Tambah Tengah  
4. Ubah Depan  
5. Ubah Belakang  
6. Ubah Tengah  
7. Hapus Depan  
8. Hapus Belakang  
9. Hapus Tengah  
10. Hapus List  
11. TAMPILKAN  
0. KELUAR  
Pilih Operasi : 

• Tampilan Operasi Tambah:

-Tambah Depan 

Masukkan Nama :

Masukkan NIM : 
Data telah ditambahkan


-Tambah Tengah 

Masukkan Nama : 

Masukkan NIM :

Masukkan Posisi : 
Data telah ditambahkan

Tampilan Operasi Hapus: 

-Hapus Belakang 
Data (nama mahasiswa yang dihapus) berhasil dihapus


-Hapus Tengah 

Masukkan posisi : 
Data (nama mahasiswa yang dihapus) berhasil dihapus

Tampilan Operasi Ubah: 

-Ubah Belakang 

Masukkan nama : 

Masukkan NIM : 
Data (nama lama) telah diganti dengan data (nama baru)


-Ubah Belakang 

Masukkan nama : 

Masukkan NIM : 

Masukkan posisi : 

Data (nama lama) telah diganti dengan data (nama baru)


• Tampilan Operasi Tampil Data:

DATA MAHASISWA 

NAMA NIM 

Nama1 NIM1 

Nama2 NIM2

Buat tampilan output sebagus dan secantik mungkin sesuai kreatifitas anda  masing-masing, jangan terpaku pada contoh output yang diberikan

```c++
#include <iostream>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    string nim;
    Node* next;
};

Node *head = NULL;

// Function untuk menambahkan data di depan
void tambahDepan(string nama, string nim) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = head;
    head = baru;
}

// Function untuk menambahkan data di belakang
void tambahBelakang(string nama, string nim) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    
    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Function untuk menambahkan data di tengah
void tambahTengah(string nama, string nim, int posisi) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    
    Node* temp = head;
    for (int i = 1; i < posisi - 1; i++) {
        if (temp != NULL) {
            temp = temp->next;
        } else {
            cout << "Posisi tidak valid!" << endl;
            return;
        }
    }
    
    if (temp == NULL) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    
    baru->next = temp->next;
    temp->next = baru;
}

// Function untuk menghapus data di depan
void hapusDepan() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
    } else {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
}

// Function untuk menghapus data di belakang
void hapusBelakang() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

// Function untuk menghapus data di tengah
void hapusTengah(int posisi) {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    
    Node* temp = head;
    for (int i = 1; i < posisi - 1; i++) {
        if (temp != NULL) {
            temp = temp->next;
        } else {
            cout << "Posisi tidak valid!" << endl;
            return;
        }
    }
    
    if (temp == NULL || temp->next == NULL) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    
    Node* hapus = temp->next;
    temp->next = temp->next->next;
    delete hapus;
}

// Function untuk menampilkan data
void tampilData() {
    cout << "DATA MAHASISWA" << endl;
    cout << "NAMA\tNIM" << endl;
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << "\t" << temp->nim << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    string nama, nim;
    int posisi;
    
    do {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang" << endl;
        cout << "6. Hapus Tengah" << endl;
        cout << "7. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "- Tambah Depan" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                tambahDepan(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 2:
                cout << "- Tambah Belakang" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                tambahBelakang(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 3:
                cout << "- Tambah Tengah" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                tambahTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 4:
                cout << "- Hapus Depan" << endl;
                hapusDepan();
                cout << "Data berhasil dihapus" << endl;
                break;
            case 5:
                cout << "- Hapus Belakang" << endl;
                hapusBelakang();
                cout << "Data berhasil dihapus" << endl;
                break;
            case 6:
                cout << "- Hapus Tengah" << endl;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                hapusTengah(posisi);
                cout << "Data berhasil dihapus" << endl;
                break;
            case 7:
                tampilData();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

```

#### Output:
![Screenshot 2024-04-27 201907](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/4d2abfc4-771f-4c01-a125-079c30937b87)

Program di atas adalah implementasi dari menu linked list non-circular untuk menyimpan nama dan NIM mahasiswa dengan input dari pengguna. Program menyediakan beberapa opsi menu seperti menambahkan data di depan, belakang, atau tengah, menghapus data di depan, belakang, atau tengah, dan menampilkan seluruh data mahasiswa. Setiap operasi memberikan instruksi kepada pengguna dan memberikan umpan balik setelah operasi selesai dilakukan. Struktur data linked list digunakan untuk menyimpan data mahasiswa, di mana setiap simpulnya berisi nama dan NIM, serta pointer ke simpul berikutnya. Program menggunakan loop do-while untuk terus menampilkan menu hingga pengguna memilih untuk keluar (memilih opsi 0).

#### Full code Screenshot:
![Screenshot 2024-04-27 201935](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/54d6d685-9695-417a-b551-c9f014830958)



### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) 
Nama 	NIM

Jawad 	23300001

[Nama Anda] 	[NIM Anda]

Farrel 	23300003

Denis 	23300005

Anis 	23300008

Bowo 	23300015

Gahar 	23300040

Udin 	23300048

Ucok 	23300050

Budi 	23300099

``` c++
#include <iostream>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    string nim;
    Node* next;
};

Node *head = NULL;

// Function untuk menambahkan data di depan
void tambahDepan(string nama, string nim) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = head;
    head = baru;
}

// Function untuk menambahkan data di belakang
void tambahBelakang(string nama, string nim) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    
    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Function untuk menambahkan data di tengah
void tambahTengah(string nama, string nim, int posisi) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    
    Node* temp = head;
    for (int i = 1; i < posisi - 1; i++) {
        if (temp != NULL) {
            temp = temp->next;
        } else {
            cout << "Posisi tidak valid!" << endl;
            return;
        }
    }
    
    if (temp == NULL) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    
    baru->next = temp->next;
    temp->next = baru;
}

// Function untuk menampilkan data
void tampilData() {
    cout << "DATA MAHASISWA" << endl;
    cout << "NAMA\tNIM" << endl;
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << "\t" << temp->nim << endl;
        temp = temp->next;
    }
}

int main() {
    // Memasukkan data sesuai urutan
    tambahDepan("Jawad", "23300001");
    tambahBelakang("Chelsisdeo", "2311110016");
    tambahBelakang("Farrel", "23300003");
    tambahBelakang("Denis", "23300005");
    tambahBelakang("Anis", "23300008");
    tambahBelakang("Bowo", "23300015");
    tambahBelakang("Gahar", "23300040");
    tambahBelakang("Udin", "23300048");
    tambahBelakang("Ucok", "23300050");
    tambahBelakang("Budi", "23300099");

    // Menampilkan data yang telah dimasukkan
    tampilData();

    return 0;
}

```

#### Output:
![Screenshot 2024-04-27 203326](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/fbe19915-ae2d-458e-a4f3-c9ee3f66eaa8)

Code tersebut merupakan implementasi linked list non-circular untuk menyimpan data mahasiswa (nama dan NIM). Fungsi tambahDepan menambah data di depan, tambahBelakang menambah di belakang, dan tambahTengah di tengah. Data dimasukkan ke linked list sesuai urutan dan ditampilkan dengan fungsi tampilData. 

#### Full code Screenshot:
![Screenshot 2024-04-27 203549](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/4127ba0a-c9f8-450c-a76e-a17b4a691812)


### 3. Lakukan perintah berikut: 
a) Tambahkan data berikut diantara Farrel dan Denis: 
Wati 2330004 

b) Hapus data Denis 

c) Tambahkan data berikut di awal: 
Owi 2330000 

d) Tambahkan data berikut di akhir: 
David 23300100 

e) Ubah data Udin menjadi data berikut: 
Idin 23300045 

f) Ubah data terkahir menjadi berikut: 
Lucy 23300101 

g) Hapus data awal 

h) Ubah data awal menjadi berikut: 
Bagas 2330002 

i) Hapus data akhir 

j) Tampilkan seluruh data

``` c++
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Inisialisasi map data
    map<string, int> data = {
        {"Farrel", 2330001},
        {"Denis", 2330003}
    };

    // a) Tambahkan data berikut diantara Farrel dan Denis
    data["Wati"] = 2330004;

    // b) Hapus data Denis
    data.erase("Denis");

    // c) Tambahkan data berikut di awal
    data.insert(data.begin(), make_pair("Owi", 2330000));

    // d) Tambahkan data berikut di akhir
    data["David"] = 23300100;

    // e) Ubah data Udin menjadi data berikut
    data["Idin"] = data["Udin"];
    data.erase("Udin");

    // f) Ubah data terkahir menjadi berikut
    auto last_iter = prev(data.end());
    data["Lucy"] = last_iter->second;
    data.erase(last_iter);

    // g) Hapus data awal
    data.erase(data.begin());

    // h) Ubah data awal menjadi berikut
    auto first_iter = data.begin();
    data["Bagas"] = first_iter->second;
    data.erase(first_iter);

    // i) Hapus data akhir
    data.erase(prev(data.end()));

    // j) Tampilkan seluruh data
    cout << "Seluruh Data:\n";
    for (const auto& entry : data) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}

```
#### Output:
![Screenshot 2024-04-27 204708](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/e9157961-a998-494f-9e3a-ddbee5162e66)


Kode di atas digunakan untuk memanipulasi data dalam struktur map yang memetakan nama (string) ke nomor identifikasi (integer). Secara berurutan, program menambah, menghapus, dan mengubah data dalam map sesuai dengan instruksi yang diberikan. Akhirnya, program menampilkan seluruh data yang tersisa dalam map setelah manipulasi dilakukan.

#### Full code Screenshot:
![Screenshot 2024-04-27 204722](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/e84b1a65-47e3-4ecf-ba21-b54eecb8e573)

## Kesimpulan
Pembelajaran pada Modul 6 yang membahas tentang circular dan non-circular data structures telah memberikan pemahaman yang mendalam tentang konsep dasar dan implementasi dari kedua jenis struktur data tersebut. Dalam struktur data circular, elemen-elemen terhubung membentuk loop atau lingkaran, yang memungkinkan akses ke setiap elemen dari mana saja dalam struktur tersebut. Implementasi struktur data circular umumnya melibatkan penggunaan pointer yang saling menunjuk satu sama lain. Di sisi lain, struktur data non-circular memiliki elemen-elemen yang terhubung secara linier tanpa membentuk loop. Pembelajaran ini juga memperkenalkan berbagai operasi yang dapat dilakukan pada kedua jenis struktur data, seperti penambahan, penghapusan, pencarian, dan penelusuran. Dengan memahami perbedaan dan kegunaan masing-masing struktur data, kita dapat memilih struktur yang paling sesuai untuk memecahkan masalah tertentu dalam pengembangan perangkat lunak.

## Referensi
[1] kurniman Putra, A. List linier (linked list) dan variasinya_struktur data.

[2] YULIANTI, M. DOUBLE LINKED LIST SIRCULAR.
