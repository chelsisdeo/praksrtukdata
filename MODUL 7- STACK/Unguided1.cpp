#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(string sentence) {
    stack<char> charStack;
    string cleanSentence;
    
    // Menghapus spasi dan mengubah huruf menjadi lowercase
    for (char c : sentence) {
        if (!isspace(c)) {
            cleanSentence += tolower(c);
        }
    }
    
    // Memasukkan karakter ke dalam stack
    for (char c : cleanSentence) {
        charStack.push(c);
    }
    
    string reversedSentence;
    
    // Mengeluarkan karakter dari stack dan menyusunnya kembali
    while (!charStack.empty()) {
        reversedSentence += charStack.top();
        charStack.pop();
    }
    
    // Membandingkan kalimat asli dan kalimat yang dibalik
    return cleanSentence == reversedSentence;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    
    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }
    
    return 0;
}
