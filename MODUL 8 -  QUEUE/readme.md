# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Chelsisdeo A.P Sanenek</p>

## Dasar Teori
Queue adalah struktur data yang digunakan untuk menyimpan data dengan metode
FIFO (First-In First-Out),
Queue (Antrian): Struktur data linear
dimana penambahan komponen dilakukan
di satu ujung, sementara pengurangan
dilakukan di ujung lain.[1]

Implementasi queue dapat dilakukan dengan menggunakan array atau linked list.
Struktur data queue terdiri dari dua pointer yaitu front dan rear. Front/head adalah
pointer ke elemen pertama dalam queue dan rear/tail/back adalah pointer ke elemen
terakhir dalam queue.

Pada Queue, operasi tersebut dilakukan ditempat berbeda (melalui salah satu ujung) karena perubahan data selalu mengacu pada Head, maka hanya ada 1 jenis insert maupun delete. Prosedur ini sering disebut Enqueue dan Dequeue pada kasus Queue. Untuk Enqueue, cukup tambahkan elemen setelah elemen terakhir Queue, dan untuk Dequeue, cukup "geser"kan Head menjadi elemen selanjutnya.




## Guided 1

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        queueTeller[back] = data;
        back++;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}

```
### output
![image](https://github.com/chelsisdeo/Tugas_Teori_Strukdata/assets/161056340/5cc47b3f-b417-42c0-a7c6-212430ceeb36)

Code di atas adalah implementasi dari sebuah program sederhana untuk mengelola sebuah antrian menggunakan array.Program ini memiliki beberapa fungsi dasar untuk mengelola antrian, seperti menambahkan data ke antrian (enqueue), menghapus data dari antrian (dequeue), menghitung jumlah data dalam antrian, membersihkan seluruh antrian, dan menampilkan isi antrian.

## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list.


```C++
#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

const int maksimalQueue = 5;

class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    bool isFull() {
        return (count == maksimalQueue);
    }

    bool isEmpty() {
        return (count == 0);
    }

    void enqueueAntrian(string data) {
        if (isFull()) {
            cout << "Antrian Penuh" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    int countQueue() {
        return count;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        cout << "Data antrian teller: " << endl;
        int i = 1;
        while (temp != nullptr) {
            cout << i << ". " << temp->data << endl;
            temp = temp->next;
            i++;
        }
    }

    ~Queue() {
        clearQueue();
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueueAntrian("Andi");
    myQueue.enqueueAntrian("Maya");
    myQueue.viewQueue();
    cout << "Jumlah antrian = " << myQueue.countQueue() << endl;
    myQueue.dequeueAntrian();
    myQueue.viewQueue();
    cout << "Jumlah antrian = " << myQueue.countQueue() << endl;
    myQueue.clearQueue();
    myQueue.viewQueue();
    cout << "Jumlah antrian = " << myQueue.countQueue() << endl;
    return 0;
}

```
#### Output:
![image](https://github.com/chelsisdeo/Tugas_Teori_Strukdata/assets/161056340/156744f8-c1e9-4dce-8880-cddc7cb379a3)

Dalam implementasi ini, queue direpresentasikan sebagai sebuah linked list dengan setiap node yang memiliki data dan pointer ke node berikutnya. Fungsi-fungsi enqueue, dequeue, countQueue, clearQueue, dan viewQueue diimplementasikan untuk memanipulasi linked list

#### Full code Screenshot:
![image](https://github.com/chelsisdeo/Tugas_Teori_Strukdata/assets/161056340/7129024a-8507-45b3-a1cf-80e11c8c51ee)


### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

const int maksimalQueue = 5;

class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    bool isFull() {
        return (count == maksimalQueue);
    }

    bool isEmpty() {
        return (count == 0);
    }

    void enqueueAntrian(string nama, string nim) {
        if (isFull()) {
            cout << "Antrian Penuh" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data.nama = nama;
        newNode->data.nim = nim;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    int countQueue() {
        return count;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        cout << "Data antrian mahasiswa: " << endl;
        int i = 1;
        while (temp != nullptr) {
            cout << i << ". Nama: " << temp->data.nama << ", NIM: " << temp->data.nim << endl;
            temp = temp->next;
            i++;
        }
    }

    ~Queue() {
        clearQueue();
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueueAntrian("Andi", "12345");
    myQueue.enqueueAntrian("Maya", "67890");
    myQueue.viewQueue();
    cout << "Jumlah antrian = " << myQueue.countQueue() << endl;
    myQueue.dequeueAntrian();
    myQueue.viewQueue();
    cout << "Jumlah antrian = " << myQueue.countQueue() << endl;
    myQueue.clearQueue();
    myQueue.viewQueue();
    cout << "Jumlah antrian = " << myQueue.countQueue() << endl;
    return 0;
}

```
#### Output:
![image](https://github.com/chelsisdeo/Tugas_Teori_Strukdata/assets/161056340/88523790-de4b-4162-abcd-d7ca2b869fe5)

Dalam kode ini, saya menambahkan struktur Mahasiswa yang memiliki atribut nama dan nim. Kemudian, atribut data pada struktur Node diubah menjadi Mahasiswa. Fungsi enqueueAntrian juga diperbarui untuk menerima nama dan nim mahasiswa saat menambahkan elemen ke dalam antrian. Fungsi viewQueue juga diperbarui untuk menampilkan nama dan nim mahasiswa saat menampilkan isi antrian.


#### Full code Screenshot:
![image](https://github.com/chelsisdeo/Tugas_Teori_Strukdata/assets/161056340/6401bf96-9713-4215-a720-94e2c139ee20)


## Kesimpulan
Kesimpulannya, queue adalah struktur data yang penting dalam pemrograman karena prinsip FIFO-nya membantu dalam situasi di mana urutan pemrosesan data harus dijaga. Melalui operasi enqueue dan dequeue, elemen-elemen dapat dimasukkan dan dikeluarkan dari queue sesuai dengan urutan masuknya. Konsep penting seperti front, rear, isEmpty(), dan isFull() membantu dalam mengelola queue dengan efisien. 

## Referensi
[1] Arraffi, A. (2019). PENGERTIAN LINIER DALAM STRUKTUR DATA MAJEMUK.
