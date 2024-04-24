#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kucing; // Tipe hewan darat -> Kucing
    kucing.jumlahKaki = 4;
    kucing.menyusui = true;
    kucing.suara = "Meong-Meong";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik atau racun";

    hewan beruang; // hewan beruang
    beruang.namaHewan = "beruang";
    beruang.jenisKelamin = "Jantan";
    beruang.caraBerkembangbiak = "Melahirkan";
    beruang.alatPernafasan = "Paru-paru";
    beruang.tempatHidup = "Hutan daerah pegunungan";
    beruang.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << beruang.namaHewan << endl;
    cout << "\tJenis kelamin : " << beruang.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << beruang.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << beruang.alatPernafasan << endl;
    cout << "\tTempat hidup : " << beruang.tempatHidup << endl;
    cout << "\tKarnivora : " << (beruang.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKucing" << endl;
    cout << "\tJumlah kaki : " << kucing.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kucing.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kucing.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}