#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    char characters[n];
    // meminta pengguna memasukkan karakter
    for (int i = 0; i < n; ++i) {
        cout << "Karakter ke-" << i + 1 << " : ";
        cin >> characters[i];
    }
    // Sorting secara menaik (ascending)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (characters[i] > characters[j]) {
                char temp = characters[i];
                characters[i] = characters[j];
                characters[j] = temp;
            }
        }
    }
    // Menampilkan hasil ascending
    cout << "\nUrutan karakter setelah ascending sort :\n";
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << "\t";
    }
    cout << endl;
    // Sorting secara menurun (descending)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (characters[i] < characters[j]) {
                char temp = characters[i];
                characters[i] = characters[j];
                characters[j] = temp;
            }
        }
    }
    // Menampilkan hasil descending
    cout << "\nUrutan karakter setelah descending sort:\n";
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << "\t";
    }
    cout << endl;

    return 0;
}
