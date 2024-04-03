#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void binarySearch(const string& sentence, char target);

int main() {
    string sentence;
    char target;

    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    // Memastikan kalimat dalam huruf kecil untuk pencarian yang konsisten
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

    cout << "Masukkan huruf yang dicari: ";
    cin >> target;
    
    binarySearch(sentence, target);

    return 0;
}

void binarySearch(const string& sentence, char target) {
    int left = 0;
    int right = sentence.size() - 1;
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;

        if (sentence[middle] == target) {
            cout << "Huruf " << target << " ditemukan di indeks " << middle << endl;
            return;
        } else if (sentence[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    cout << "Huruf " << target << " tidak ditemukan dalam kalimat." << endl;
}
