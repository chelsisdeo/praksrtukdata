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
