# <h1 align="center">Laporan Praktikum Modul STACK</h1>
<p align="center">Chelsisdeo A.P Sanenek</p>

## Dasar Teori

Kumpulan items yang teratur dimana items baru akan dimasukkan ke dan sebuah items akan dikeluarkan dari satu ujung yang sama,yaitu dari TOP sebuah stack.Strukturdata linier dimana hanya bagian TOP-nya saja yang bisa diakses.Bersifat LIFO = Last In First Out.Bisa diimplementasikan menggunakan array atau Linked List.

- Ilustrasi Stack
Terdapat dua buah kotak yang ditumpuk,kotak yang satu akan ditumpuk diatas kotak yang lainnya.Jika kemudian stack 2 kotak tadi,ditambah kotak ketiga,keempat,kelima,dan seterusnya,maka akan diperoleh sebuah stack kotak yang terdiri dari N kota.[1]

Operasi pada stack melibatkan beberapa fungsi dasar yang dapat dilakukan pada struktur data ini. Berikut adalah beberapa operasi umum pada stack:

- Push (Masukkan): Menambahkan elemen ke dalam tumpukan pada posisi paling atas atau ujung.
- Pop (Keluarkan): Menghapus elemen dari posisi paling atas atau ujung tumpukan.
- Top (Atas): Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa menghapusnya.
- IsEmpty (Kosong): Memeriksa apakah tumpukan kosong atau tidak
- IsFull (Penuh): Memeriksa apakah tumpukan penuh atau tidak (terutama pada implementasi tumpukan dengan kapasitas terbatas).
- Size (Ukuran): Mengembalikan jumlah elemen yang ada dalam tumpukan.
- Peek (Lihat): Melihat nilai atau elemen pada posisi tertentu dalam tumpukan tanpa menghapusnya.
- Clear (Hapus Semua): Mengosongkan atau menghapus semua elemen dari tumpukan.
- Search (Cari): Mencari keberadaan elemen tertentu dalam tumpukan.


## Guided 1



```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty(){
    return (top == 0);
}

void pushArrayBuku(string data){
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku(){
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        top--;
        arrayBuku[top] = "";
    }
}

void peekArrayBuku(int posisi){
    if(isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top - 1;
        for(int i = 1; i < posisi; i++) {
            index--;
        }
        cout << "posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack(){
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top - 1;
        for (int i = 1; i < posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku(){
    top = 0;
}

void cetakArrayBuku(){
    if(isEmpty()){
        cout << "Tidak ada data yang dapat dicetak" << endl;
    } else {
        for(int i = top - 1; i >= 0; i--){
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur data");
    pushArrayBuku("Matematika diskrit");
    pushArrayBuku("Dasar multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa German");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data telah dihapus: " << top << endl;
    cetakArrayBuku();
    
    return 0;
}

```
adalah contoh implementasi stack menggunakan array. Fungsi-fungsi seperti pushArrayBuku, popArrayBuku, dan peekArrayBuku digunakan untuk mengelola data dalam stack. Misalnya, pushArrayBuku menambahkan data ke dalam stack, popArrayBuku menghapus data dari stack, dan peekArrayBuku menampilkan data pada posisi tertentu dalam stack. Selain itu, ada fungsi lain seperti isFull, isEmpty, countStack, changeArrayBuku, dan destroyArrayBuku yang membantu mengelola stack. Semua ini memungkinkan programmer untuk mengatur data dengan efisien dalam struktur stack

### Output 
![Screenshot 2024-05-02 214150](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/d7632280-3b27-4fbd-a4bf-319c4cb07299)


## Unguided 

### 1.Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

![Screenshot 2024-05-03 022626](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/970c9e80-f5a8-4894-ae48-81931af57eb6)




```C++
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


```
#### Output:

![Screenshot 2024-05-03 023633](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/7e18ea28-3c20-42f5-870f-9642b2e8bcb3)

#### penjelasan

cara kerja program:

- Program menggunakan stack dari C++ STL untuk membuat stack karakter.
- Kalimat dimasukkan ke dalam stack setelah dibersihkan dari spasi dan diubah menjadi huruf kecil.
- Program membalik kalimat dengan mengeluarkan karakter dari stack dan menyusunnya kembali.
- Kalimat asli dan kalimat yang dibalik dibandingkan. Jika keduanya sama, maka kalimat tersebut adalah palindrom; jika tidak, maka bukan palindrom.
- Hasilnya akan dicetak sesuai dengan kondisi palindrom atau bukan.

#### Full code Screenshot:

![Screenshot 2024-05-03 023842](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/d9cba19a-d1e4-4c00-8ed3-7ffe9ec40456)



### 2.Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

![Screenshot 2024-05-03 022634](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/6d362266-c98f-49b8-b734-613b262a3d59)

```C++
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


```
#### Output:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/d0e6f465-7010-48bd-8d30-77f47cef596c)


#### Penjelasan

Program membuat sebuah stack dari tipe data string.
Kalimat dimasukkan ke dalam stack dengan membagi kalimat menjadi kata-kata.Setiap kata dimasukkan ke dalam stack.Kemudian, program mengeluarkan kata dari stack dan menyusunnya kembali dalam urutan terbalik.Setelah semua kata telah diambil dari stack, program menggabungkan kembali kata-kata tersebut dalam urutan terbalik menjadi sebuah kalimat.Hasilnya akan dicetak sebagai keluaran program.

#### Full code Screenshot:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/f8f2b4e5-3a07-440d-b3a5-f3bba3b98dd3)


## Kesimpulan

Pada pelajaran hari ini, kami mempelajari konsep dasar struktur data stack, terutama prinsip Last In First Out (LIFO) yang menjadi landasan utama. Kami menjelajahi operasi dasar seperti push, pop, dan peek, serta pentingnya manajemen memori dalam implementasinya. Pelajaran ini memberikan pemahaman yang kokoh tentang stack dan relevansinya dalam pengembangan perangkat lunak.

## Referensi
[1] Sari, Ranita. "PENGERTIAN STACK (TUMPUKAN." (2018).
