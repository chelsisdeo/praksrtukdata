#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int data[n] = {7, 4, 2, 3, 5, 4, 10, 9, 6, 19};
    int cari = 5;
    bool ketemu = false;
    int i;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "Data: {7, 4, 2, 3, 5, 4, 10, 9, 6, 19}" << endl;
    if (ketemu) {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
