#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Struktur data untuk setiap mahasiswa
struct Mahasiswa {
    string nim;
    double nilai;
};

// Hash table untuk menyimpan data mahasiswa
unordered_map<string, Mahasiswa> dataMahasiswa;

// Fungsi untuk menambahkan data mahasiswa
void tambahData(string nim, double nilai) {
    Mahasiswa mhs;
    mhs.nim = nim;
    mhs.nilai = nilai;
    dataMahasiswa[nim] = mhs;
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
void hapusData(string nim) {
    dataMahasiswa.erase(nim);
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
Mahasiswa cariDataByNIM(string nim) {
    if (dataMahasiswa.find(nim) != dataMahasiswa.end()) {
        return dataMahasiswa[nim];
    } else {
        Mahasiswa notFound;
        notFound.nim = "Tidak ditemukan";
        notFound.nilai = -1.0;
        return notFound;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
void cariDataByNilai(double minNilai, double maxNilai) {
    cout << "Data mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << ":" << endl;
    for (const auto& pair : dataMahasiswa) {
        if (pair.second.nilai >= minNilai && pair.second.nilai <= maxNilai) {
            cout << "NIM: " << pair.second.nim << ", Nilai: " << pair.second.nilai << endl;
        }
    }
}

int main() {
    // Contoh penggunaan
    tambahData("2311110016", 95.5);
    tambahData("2311110078", 85.5);
    tambahData("2311110001", 55.5);
    

    cout << "Data mahasiswa dengan NIM 2311110016: ";
    Mahasiswa mhs = cariDataByNIM("2311110016");
    cout << "NIM: " << mhs.nim << ", Nilai: " << mhs.nilai << endl;

    cout << "Data mahasiswa dengan NIM 2311110078: ";
    mhs = cariDataByNIM("2311110078");
    cout << "NIM: " << mhs.nim << ", Nilai: " << mhs.nilai << endl;

    cariDataByNilai(80.0, 90.0);

    return 0;
}
