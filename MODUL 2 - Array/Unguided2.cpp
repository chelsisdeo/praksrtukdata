#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel untuk menyimpan ukuran array
    int x_size, y_size, z_size;

    // Masukkan ukuran array sepuasnyaa
    cout << "Masukkan ukuran array (x y z): ";
    cin >> x_size >> y_size >> z_size;

    // Deklarasikan array
    int arr[x_size][y_size][z_size];

    // Input elemen array
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output array
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << arr[x][y][z] << endl;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
