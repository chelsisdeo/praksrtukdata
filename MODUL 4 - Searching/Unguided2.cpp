#include <iostream>
#include <string>
using namespace std;

int main() {
    string kalimat;
    int jumlahVokal = 0;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    for (char karakter : kalimat) {
        if (karakter == 'a' || karakter == 'A' ||
            karakter == 'e' || karakter == 'E' ||
            karakter == 'i' || karakter == 'I' ||
            karakter == 'o' || karakter == 'O' ||
            karakter == 'u' || karakter == 'U') {
            jumlahVokal++;
        }
    }

    cout << "Jumlah huruf vokal dalam kalimat tersebut: " << jumlahVokal << endl;

    return 0;
}
