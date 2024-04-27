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