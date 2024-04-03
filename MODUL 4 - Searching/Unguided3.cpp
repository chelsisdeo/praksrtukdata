#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari; 
    bool ketemu = false;
    int i;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
        }
    }

    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "Data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl; 
    if (ketemu) {
        int jumlah = 0; // tambahkan variabel untuk menyimpan jumlah angka yang ditemukan
        for (i = 0; i < n; i++) {
            if (data[i] == cari) {
                jumlah++;
            }
        }
        cout << "\nAngka " << cari << " ditemukan sebanyak " << jumlah << " kali." << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
