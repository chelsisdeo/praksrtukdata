#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah angka dalam array: ";
    cin >> n;

    // Untuk deklarasi jumlah angka dalam array
    int angka[n];

    // Meminta user untuk memasukkan angka apa saja ke dalam data array
    cout << "Data Array : ";
    for (int i = 0; i < n; ++i) {
        cin >> angka[i];
    }


    // Menampilkan angka genap
    cout << "Nomor Genap  : ";
    for (int i = 0; i < n; ++i) {
        if (angka[i] % 2 == 0) {
            cout << angka[i] << ", ";
        }
    }
    cout << endl;

    // Menampilkan angka ganjil
    cout << "Nomor Ganjil : ";
    for (int i = 0; i < n; ++i) {
        if (angka[i] % 2 != 0) {
            cout << angka[i] << ", ";
        }
    }
    cout << endl;
    return 0;
}
