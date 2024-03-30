// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Masukkan jumlah angka dalam array: ";
//     cin >> n;

//     // Untuk deklarasi jumlah angka dalam array
//     int angka[n];

//     // Meminta user untuk memasukkan angka apa saja ke dalam data array
//     cout << "Data Array : ";
//     for (int i = 0; i < n; ++i) {
//         cin >> angka[i];
//     }


//     // Menampilkan angka genap
//     cout << "Nomor Genap  : ";
//     for (int i = 0; i < n; ++i) {
//         if (angka[i] % 2 == 0) {
//             cout << angka[i] << ", ";
//         }
//     }
//     cout << endl;

//     // Menampilkan angka ganjil
//     cout << "Nomor Ganjil : ";
//     for (int i = 0; i < n; ++i) {
//         if (angka[i] % 2 != 0) {
//             cout << angka[i] << ", ";
//         }
//     }
//     cout << endl;
//     return 0;
// }


#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tap;

    while (not_sorted){
        not_sorted = false;
        j++;
        for(int i = 0; i < length - j; j++){
            if(arr[i] > arr[i + 1]){
                tap = arr[i];
                arr[i] = arr[i +1];
                arr[i + 1] = tap;
                not_sorted = true;
            }// end off it 
        }// end for loop
        
    }// end of while loop
}// end of buble short 
