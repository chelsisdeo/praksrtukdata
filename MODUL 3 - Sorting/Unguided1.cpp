#include <iostream>

using namespace std;

void selection_sort(double arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            double temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }
    }
}

void print_array(double a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 5;
    double ips[] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "IPS mahasiswa sebelum sorting : " << endl;
    print_array(ips, length);

    selection_sort(ips, length);

    cout << "\nIPS mahasiswa setelah sorting: " << endl;
    print_array(ips, length);

    return 0;
}
