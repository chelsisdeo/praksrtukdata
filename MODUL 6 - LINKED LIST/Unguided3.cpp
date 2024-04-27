#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Inisialisasi map data
    map<string, int> data = {
        {"Farrel", 2330001},
        {"Denis", 2330003}
    };

    // a) Tambahkan data berikut diantara Farrel dan Denis
    data["Wati"] = 2330004;

    // b) Hapus data Denis
    data.erase("Denis");

    // c) Tambahkan data berikut di awal
    data.insert(data.begin(), make_pair("Owi", 2330000));

    // d) Tambahkan data berikut di akhir
    data["David"] = 23300100;

    // e) Ubah data Udin menjadi data berikut
    data["Idin"] = data["Udin"];
    data.erase("Udin");

    // f) Ubah data terkahir menjadi berikut
    auto last_iter = prev(data.end());
    data["Lucy"] = last_iter->second;
    data.erase(last_iter);

    // g) Hapus data awal
    data.erase(data.begin());

    // h) Ubah data awal menjadi berikut
    auto first_iter = data.begin();
    data["Bagas"] = first_iter->second;
    data.erase(first_iter);

    // i) Hapus data akhir
    data.erase(prev(data.end()));

    // j) Tampilkan seluruh data
    cout << "Seluruh Data:\n";
    for (const auto& entry : data) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}