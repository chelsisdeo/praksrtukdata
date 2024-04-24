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
