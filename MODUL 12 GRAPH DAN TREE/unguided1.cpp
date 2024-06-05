#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk merepresentasikan graf
struct Graph {
    vector<string> simpul;
    vector<vector<int>> bobot;
};

int main() {
    int jumlahSimpul;
    
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    
    // Membuat objek graf
    Graph graf;
    graf.simpul.resize(jumlahSimpul);
    graf.bobot.resize(jumlahSimpul, vector<int>(jumlahSimpul));
    
    cout << "Silahkan masukkan nama simpul" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i+1 << " : ";
        cin >> graf.simpul[i];
    }
    
    cout << "Silahkan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << graf.simpul[i] << "-->" << graf.simpul[j] << " = ";
            cin >> graf.bobot[i][j];
        }
    }
    
    // Menampilkan tabel bobot
    cout << "\t";
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << graf.simpul[i] << "\t";
    }
    cout << endl;
    
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << graf.simpul[i] << "\t";
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << graf.bobot[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
