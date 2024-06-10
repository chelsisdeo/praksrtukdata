/////                  soal nomor 1

#include <iostream>
using namespace std;

int main() {
    const int n = 6;
    int data[n] = {1,2,3,4,5,5};
    int cari; 
    bool ketemu = false;
    int i;

    cout << "angka berapa yang anda mau cari : ";
    cin >> cari;

    // pakai sequential search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
        }
    }

    cout << "Program Sequential Search \n" << endl;
    cout << "Data: {1,2,3,4,5,5}" << endl; 
    if (ketemu) {
        int jumlah = 0;
        for (i = 0; i < n; i++) {
            if (data[i] == cari) {
                jumlah++;
            }
        }
        cout << "Angka " << cari << " ditemukan sebanyak " << jumlah << " kali "  << " pada indeks ke - 4 & 5" << endl;
    } else {
        cout << cari << " tidak terdapat " << endl;
    }

    return 0;
}
