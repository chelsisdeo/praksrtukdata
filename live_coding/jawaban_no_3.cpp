/////                soal nomor 3

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
            } 
        }
        
    }
}

void print_array(double a[], int length) {

    for(int i=0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main(){
    int length = 4;
    double a[] = {5,1,4,2,8};
    cout << "masukkan deret angka : " << endl;
    cin >> double;

    bubble_sort(a, length);

    cout << "\n urutan bilangan setelah sortiing: " << endl;
    print_array(a, length);
}
