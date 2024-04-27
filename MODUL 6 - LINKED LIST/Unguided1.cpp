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
