#include <iostream>
#include <string>

using namespace std;

void bubble_sort(string arr[], int length) {
    bool not_sorted = true;
    int j = 0;
    string temp;

    while (not_sorted) {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                not_sorted = true;
            }
        }
    }
}

void print_array(string a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 10;
    string names[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Nama sebelum pengurutan: " << endl;
    print_array(names, length);

    bubble_sort(names, length);

    cout << "\nNama setelah pengurutan: " << endl;
    print_array(names, length);

    return 0;
}
