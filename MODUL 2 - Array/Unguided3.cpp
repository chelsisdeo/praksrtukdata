#include <iostream>
using namespace std;

int main() {
    int n, i;
    double sum = 0;
    cout << "Masukkan panjang array: ";
    cin >> n;
    int array[n];

    cout << "Masukkan " << n << " angka\n";
    for (i = 0; i < n; i++) {
        cout << "Array ke-" << (i + 1) << ": ";
        cin >> array[i];
        sum += array[i]; // Menambahkan nilai untuk perhitungan rata-rata
    }

    int maks = array[0];
    int min = array[0]; // Menginisialisasi nilai minimum dengan nilai pertama dalam array
    int maks_lokasi = 0;
    int min_lokasi = 0;

    for (i = 1; i < n; i++) {
        if (array[i] > maks) {
            maks = array[i];
            maks_lokasi = i;
        }
        if (array[i] < min) {
            min = array[i];
            min_lokasi = i;
        }
    }

    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << (maks_lokasi + 1) << endl;
    cout << "Nilai minimum adalah " << min << " berada di Array ke " << (min_lokasi + 1) << endl;
    cout << "Rata-rata adalah " << sum / n << endl;

    return 0;
}
