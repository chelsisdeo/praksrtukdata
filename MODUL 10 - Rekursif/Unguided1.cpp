#include <iostream>
using namespace std;

// int faktorial(int n) {
//     if (n == 0 || n == 1)
//         return 1;
//     else
//         return n * faktorial(n - 1);
// }

int main() {
    int bilangan;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    if (bilangan < 0) {
        cout << "Harap masukkan bilangan bulat positif." << endl;
    } else {
        int hasil = faktorial(bilangan);
        cout << "Faktorial dari " << bilangan << " adalah: " << hasil << endl;
    }

    return 0;
}
