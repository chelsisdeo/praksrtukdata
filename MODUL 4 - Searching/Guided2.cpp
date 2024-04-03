#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

void binarysearch();

int main() {
    binarysearch();
    return 0;
}

void binarysearch() {
    int cari, awal, tengah, akhir, temp, min;
    int data[7] = {12, 11, 8, 34, 33, 5, 87};

    cout << "Masukkan angka yang dicari: ";
    cin >> cari;

    awal = 0;
    akhir = 6;

    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (data[tengah] == cari) {
            cout << "Angka " << cari << " ditemukan di indeks " << tengah << endl;
            break;
        } else if (data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (awal > akhir) {
        cout << "Angka " << cari << " tidak ditemukan." << endl;
    }
}
