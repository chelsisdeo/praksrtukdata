#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan kata menggunakan stack
string reverseWords(string sentence) {
    stack<string> wordStack;
    string word, reversedSentence;
    
    // Membagi kalimat menjadi kata-kata dan memasukkan ke dalam stack
    for (char c : sentence) {
        if (c == ' ') {
            wordStack.push(word);
            word = "";
        } else {
            word += c;
        }
    }
    wordStack.push(word); // Memasukkan kata terakhir
    
    // Mengeluarkan kata dari stack dan menyusunnya kembali
    while (!wordStack.empty()) {
        reversedSentence += wordStack.top() + " ";
        wordStack.pop();
    }
    
    // Menghapus spasi ekstra di akhir kalimat
    if (!reversedSentence.empty()) {
        reversedSentence.pop_back();
    }
    
    return reversedSentence;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    
    string reversedSentence = reverseWords(kalimat);
    
    cout << "Hasil: " << reversedSentence << endl;

    return 0;
}
