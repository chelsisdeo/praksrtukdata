# <h1 align="center">Laporan Praktikum Modul Hash Table </h1>
<p align="center">Chelsisdeo A.P Sanenek(2311110016)</p>

## Dasar Teori

Hash Table adalah Array dengan sel-sel yang ukuranya telah di tentukan dan dapat berisi data atau key yang memiliki kesamaan dengan data. Namun kita bisa juga mengganti tabel array dalam bentuk tabel sementara di mysql yang memiliki record–rocord dan primary key yang sesuai dengan data tersebut sebagai acuan untuk insert, update, delete, search, dan link.[1]

Sistem hash table bekerja dengan cara mengambil input kunci dan memetakkannya ke nilai indeks array menggunakan fungsi hash. Kemudian, data disimpan pada posisi indeks array yang dihasilkan oleh fungsi hash. Ketika data perlu dicari, input kunci dijadikan sebagai parameter untuk fungsi hash, dan posisi indeks array yang dihasilkan digunakan untuk mencari data. Dalam kasus hash collision, di mana dua atau lebih data memiliki nilai hash yang sama, hash table menyimpan data tersebut dalam slot yang sama dengan Teknik yang disebut chaining.

Hash table terdiri atas dua komponen, yaitu key dan
value. Key digunakan untuk mengakses data yang disimpan. Key bersifat unik dan biasanya berupa string yang penentuan nilai string tergantung dengan kasusnya. Hash table biasanya
direpresentasikan sebagai associative array.[2]



## Guided I

### 1. 
```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) { 
                cout << current->key << ": " << current->value << endl;
                current = current->next;             }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    
    // Deletion
    ht.remove(4);
    
    // Traversal
    ht.traverse();
    
    return 0;
}

```
Kode di atas menggambarkan implementasi hash table dalam bahasa C++. Hash table adalah struktur data yang memetakan kunci (key) ke nilai (value) dengan menggunakan fungsi hash. Dalam kode tersebut, kita memiliki fungsi hash sederhana (hash_func) yang menghitung indeks hash berdasarkan kunci. Setiap elemen dalam hash table direpresentasikan sebagai node (Node) yang memiliki atribut key, value, dan next (untuk menangani tabrakan hash). Operasi yang didukung meliputi penyisipan, pencarian, penghapusan, dan penelusuran.

### output
![Screenshot 2024-05-30 135915](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/ed1a48a6-5af1-4367-a8c8-acd3436f990c)



## Guided II

```c++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}

```
Pada kode di atas, kita memiliki fungsi hash sederhana (hash_func) yang menghitung indeks hash berdasarkan kunci. Setiap elemen dalam hash table direpresentasikan sebagai node (Node) yang memiliki atribut key, value, dan next (untuk menangani tabrakan hash). Operasi yang didukung meliputi penyisipan, pencarian, penghapusan, dan penelusuran. Contoh penggunaan juga diberikan di dalam fungsi main(). Kode kedua menggambarkan implementasi hash map dengan menggunakan vektor dalam bahasa C++.

### output 
![Screenshot 2024-05-30 140114](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/c53b7a5b-3d7c-453f-aee4-4a8628adf3bb)


## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
    a.	Setiap mahasiswa memiliki NIM dan nilai.
    b.	Program memiliki tampilan pilihan menu berisi poin C.
    c.	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Struktur data untuk setiap mahasiswa
struct Mahasiswa {
    string nim;
    double nilai;
};

unordered_map<string, Mahasiswa> dataMahasiswa;


void tambahData(string nim, double nilai) {
    Mahasiswa mhs;
    mhs.nim = nim;
    mhs.nilai = nilai;
    dataMahasiswa[nim] = mhs;
}


void hapusData(string nim) {
    dataMahasiswa.erase(nim);
}


Mahasiswa cariDataByNIM(string nim) {
    if (dataMahasiswa.find(nim) != dataMahasiswa.end()) {
        return dataMahasiswa[nim];
    } else {
        Mahasiswa notFound;
        notFound.nim = "Tidak ditemukan";
        notFound.nilai = -1.0;
        return notFound;
    }
}


void cariDataByNilai(double minNilai, double maxNilai) {
    cout << "Data mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << ":" << endl;
    for (const auto& pair : dataMahasiswa) {
        if (pair.second.nilai >= minNilai && pair.second.nilai <= maxNilai) {
            cout << "NIM: " << pair.second.nim << ", Nilai: " << pair.second.nilai << endl;
        }
    }
}

int main() {
    
    tambahData("2311110016", 95.5);
    tambahData("2311110078", 85.5);
    tambahData("2311110001", 55.5);
    

    cout << "Data mahasiswa dengan NIM 2311110016: ";
    Mahasiswa mhs = cariDataByNIM("2311110016");
    cout << "NIM: " << mhs.nim << ", Nilai: " << mhs.nilai << endl;

    cout << "Data mahasiswa dengan NIM 2311110078: ";
    mhs = cariDataByNIM("2311110078");
    cout << "NIM: " << mhs.nim << ", Nilai: " << mhs.nilai << endl;

    cariDataByNilai(80.0, 90.0);

    return 0;
}


```
#### Output:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/78a40088-9211-420e-a328-d224be1ebcad)

Kode di atas menggambarkan implementasi hash map (tabel hash) dalam bahasa C++. Kami menggunakan unordered_map untuk menyimpan data mahasiswa berdasarkan NIM dan nilai. Setiap elemen dalam tabel hash memiliki kunci (NIM) dan nilai (objek Mahasiswa). Operasi yang didukung meliputi penyisipan, pencarian berdasarkan NIM, penghapusan, dan pencarian berdasarkan rentang nilai.

#### Full code Screenshot:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/16540b32-83ff-4812-992f-4f6463093ba7)


## Kesimpulan
Kesimpulannya, hari ini saya telah mempelajari bahwa hash table adalah struktur data yang sangat efisien untuk penyimpanan dan pencarian data, menggunakan hash function untuk memetakan kunci ke lokasi penyimpanan, sehingga memungkinkan akses waktu konstan O(1) dalam banyak kasus.

## Referensi
[1] Syahrir, M., & Fatimatuzzahra, F. (2020). Association Rule Integrasi Pendekatan Metode Custom Hashing dan Data Partitioning untuk Mempercepat Proses Pencarian Frekuensi Item-set pada Algoritma Apriori. Matrik: Jurnal Manajemen, Teknik Informatika Dan Rekayasa Komputer, 20(1), 149-158.

[2] Kautsar, I., Wirayuda, K. R. S., & Wulandari, G. S. (2015). Analisis Performansi Metode Graph Decomposition Index pada Graph Database. eProceedings of Engineering, 2(1).
