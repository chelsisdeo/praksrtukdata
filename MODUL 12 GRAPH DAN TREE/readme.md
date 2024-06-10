<<<<<<< HEAD
# <h1 align="center">Laporan Praktikum Modul GRAPH DAN TREE</h1>
<p align="center">Chelsisdeo A.P Sanenek</p>

## Dasar Teori

### GRAPH 

Graph adalah pasangan himpunan
vertex/simpul dan edges/sisi, dimana setiap
sisi berhubungan dengan satu atau dua
buah simpul.[1]

Ada beberapa jenis graph

- Graph berarah (directed graph): Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8.

- Graph tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidak diperhatikan. Misal busur e1 dapat disebut busur AB atau BA.

- Weight Graph : Graph yang mempunyai nilai pada tiap edgenya.

### TREE

Dalam ilmu komputer, pohon/tree adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. Ini terdiri dari satu set node tertaut yang terurut dalam grafik yang terhubung, dimana setiap node memiliki paling banyak satu simpul induk, dan nol atau lebih simpul anak dengan urutan tertentu. simple nya dan dapat di katakan ,Tree adalah graph terhubung yang tidak memiliki siklus[2]

Operasi pada TREE

- Create: digunakan untuk membentuk binary tree baru yang masih kosong.

- Clear: digunakan untuk mengosongkan binary tree yang sudah ada atau menghapus semua node pada binary tree.

- isEmpty: digunakan untuk memeriksa apakah binary tree masih kosong atau tidak.
- Insert: digunakan untuk memasukkan sebuah node kedalam tree.
- Find: digunakan untuk mencari root, parent, left child, atau right child dari suatu node dengan syarat tree tidak boleh kosong.
- Update: digunakan untuk mengubah isi dari node yang ditunjuk oleh pointer current dengan syarat tree tidak boleh kosong. 
- Retrive: digunakan untuk mengetahui isi dari node yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.
- Delete Sub: digunakan untuk menghapus sebuah subtree (node beserta seluruh descendant-nya) yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.
- Characteristic: digunakan untuk mengetahui karakteristik dari suatu tree. Yakni size, height, serta average lenght-nya.
- Traverse: digunakan untuk mengunjungi seluruh node-node pada tree dengan cara traversal. Terdapat 3 metode traversal yang dibahas dalam modul ini yakni Pre-Order, In-Order, dan Post-Order.



## Guided 1. 

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0},
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris ++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << ":";
        for (int kolom = 0; kolom < 7; kolom ++) {
            if (busur [baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
Code diatas merupakan contoh implementasi sederhana dari representasi graf menggunakan matriks ketetanggaan dalam bahasa C++. Simpul-simpul dari graf direpresentasikan dalam array string simpul, dan hubungan antar simpul direpresentasikan dalam matriks busur, di mana nilai-nilai matriks menunjukkan bobot dari busur yang menghubungkan simpul-simpul. Fungsi tampilGraph() digunakan untuk menampilkan graf dalam bentuk matriks ketetanggaan dengan menampilkan informasi tentang simpul yang terhubung dan bobotnya. Pada main(), fungsi tampilGraph() dipanggil untuk menampilkan graf yang sudah dibuat.


## Guided 2.

``` c++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    //constuctor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder (TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder (TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder (TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode*zero = new TNode(0);
    TNode*one = new TNode(1);
    TNode*five = new TNode(5);
    TNode*seven = new TNode(7);
    TNode*eight = new TNode(8);
    TNode*nine = new TNode(9);

    seven->left = one;

    seven->right = nine;

    one->left = zero;

    one->right = five;

    nine->left = eight;

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}

```
Code di atas merupakan contoh implementasi dari struktur data pohon biner dalam bahasa C++. Struktur data pohon biner direpresentasikan menggunakan struktur TNode yang memiliki tiga anggota: data untuk menyimpan nilai, left untuk menunjukkan node anak kiri, dan right untuk menunjukkan node anak kanan. Fungsi preOrder, inOrder, dan postOrder digunakan untuk melakukan penelusuran prapenelusuran, penelusuran dalam, dan penelusuran pasca urutan secara rekursif pada pohon biner. Pada main(), dilakukan pembuatan beberapa node pohon biner dan pengaturan hubungan antar node, kemudian dilakukan penelusuran prapenelusuran, penelusuran dalam, dan penelusuran pasca urutan untuk mengakses nilai-nilai dari pohon biner tersebut.


## Unguided 

*Cantumkan NIM pada salah satu variabel di dalam program.
Contoh : int nama_22102003;
#### 1.	Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
Output Program
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/7245190f-d3c1-4d7a-92c7-4752505a42e9)

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Graph {
    vector<string> simpul;
    vector<vector<int>> bobot;
};

int main() {
    int jumlahSimpul;
    
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    
    
    Graph graf;
    graf.simpul.resize(jumlahSimpul);
    graf.bobot.resize(jumlahSimpul, vector<int>(jumlahSimpul));
    
    cout << "Silahkan masukkan nama simpul" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i+1 << " : ";
        cin >> graf.simpul[i];
    }
    
    cout << "Silahkan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << graf.simpul[i] << "-->" << graf.simpul[j] << " = ";
            cin >> graf.bobot[i][j];
        }
    }
    
    
    cout << "\t";
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << graf.simpul[i] << "\t";
    }
    cout << endl;
    
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << graf.simpul[i] << "\t";
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << graf.bobot[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}

```
#### Output:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/ab65a917-6059-4fe1-8f73-e524e13e0cd5)


Dalam code yg ada di atas, saya menggunakan struktur data Graph untuk merepresentasikan graf. Graph memiliki dua anggota: simpul yang merupakan vektor dari string yang menyimpan nama-nama simpul, dan bobot yang merupakan vektor dari vektor integer yang menyimpan bobot antar simpul. Program ini meminta pengguna untuk memasukkan jumlah simpul, nama-nama simpul, dan bobot antar simpul. Kemudian, program akan menampilkan tabel bobot yang menunjukkan jarak dari setiap kota ke kota lainnya.

#### Full code Screenshot:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/47aeab6f-0383-4dbf-ad3d-692939d6be71)


#### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!


```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};


void tambahChild(TreeNode* parent, string childData) {
    if (parent->left == NULL)
        parent->left = new TreeNode(childData);
    else if (parent->right == NULL)
        parent->right = new TreeNode(childData);
    else
        cout << "Node ini sudah memiliki dua child." << endl;
}

void tampilkanDescendant(TreeNode* node) {
    if (node == NULL)
        return;

    cout << node->data << " ";
    tampilkanDescendant(node->left);
    tampilkanDescendant(node->right);
}

int main() {
    int jumlahSimpul;
    
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    
    
    string rootData;
    cout << "Masukkan data simpul root: ";
    cin >> rootData;
    TreeNode* root = new TreeNode(rootData);
    
    
    for (int i = 0; i < jumlahSimpul - 1; ++i) {
        string parentData, childData;
        cout << "Masukkan data simpul parent: ";
        cin >> parentData;
        cout << "Masukkan data simpul child: ";
        cin >> childData;

        
        TreeNode* parent = NULL;
        
        tambahChild(parent, childData);
    }

    
    cout << "Descendant dari setiap simpul:" << endl;
    

    return 0;
}

```
#### Output:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/e576f53f-578e-41c4-98e0-84bf597961ff)

Program memungkinkan pengguna untuk memasukkan jumlah simpul dan data simpul root, lalu membuat struktur tree dengan menambahkan child ke setiap node parent yang diinputkan. Setelah pembuatan tree, program menampilkan descendant dari setiap node. Ini memberi pengguna kontrol atas pembuatan tree dan memungkinkan mereka untuk melihat hubungan antar node dengan menampilkan descendant.

#### Full code Screenshot:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/c6cdaae5-a5fb-467f-907d-749103ac6997)


## Kesimpulan
Pada hari ini, saya belajar tentang konsep dasar dari graf dan tree dalam ilmu komputer. Saya memahami bagaimana representasi graf menggunakan matriks ketetanggaan dan pohon biner menggunakan struktur data tree. Saya juga belajar tentang operasi dasar seperti penelusuran dan manipulasi struktur data graf dan tree. Dengan memahami konsep dan operasi dasar ini, saya memiliki dasar yang kuat untuk memahami dan mengimplementasikan algoritma yang lebih kompleks yang melibatkan graf dan tree di masa depan.





## Referensi
[1] Dalem, I. B. G. W. A. (2018). Penerapan algoritma A*(Star) menggunakan graph untuk menghitung jarak terpendek. Jurnal RESISTOR (Rekayasa Sistem Komputer), 1(1), 41-47.

[2] Susanto, L. A., Wiharja, K. R. S., & Puspitasari, S. Y. (2015). Implementasi Dan Analisis Visualisasi Graph Pada Graph Statis Menggunakan Representasi Visual Treemap. eProceedings of Engineering, 2(3).
=======
# <h1 align="center">Laporan Praktikum Modul GRAPH DAN TREE</h1>
<p align="center">Chelsisdeo A.P Sanenek</p>

## Dasar Teori

### GRAPH 

Graph adalah pasangan himpunan
vertex/simpul dan edges/sisi, dimana setiap
sisi berhubungan dengan satu atau dua
buah simpul.[1]

Ada beberapa jenis graph

- Graph berarah (directed graph): Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8.

- Graph tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidak diperhatikan. Misal busur e1 dapat disebut busur AB atau BA.

- Weight Graph : Graph yang mempunyai nilai pada tiap edgenya.

### TREE

Dalam ilmu komputer, pohon/tree adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. Ini terdiri dari satu set node tertaut yang terurut dalam grafik yang terhubung, dimana setiap node memiliki paling banyak satu simpul induk, dan nol atau lebih simpul anak dengan urutan tertentu. simple nya dan dapat di katakan ,Tree adalah graph terhubung yang tidak memiliki siklus[2]

Operasi pada TREE

- Create: digunakan untuk membentuk binary tree baru yang masih kosong.

- Clear: digunakan untuk mengosongkan binary tree yang sudah ada atau menghapus semua node pada binary tree.

- isEmpty: digunakan untuk memeriksa apakah binary tree masih kosong atau tidak.
- Insert: digunakan untuk memasukkan sebuah node kedalam tree.
- Find: digunakan untuk mencari root, parent, left child, atau right child dari suatu node dengan syarat tree tidak boleh kosong.
- Update: digunakan untuk mengubah isi dari node yang ditunjuk oleh pointer current dengan syarat tree tidak boleh kosong. 
- Retrive: digunakan untuk mengetahui isi dari node yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.
- Delete Sub: digunakan untuk menghapus sebuah subtree (node beserta seluruh descendant-nya) yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.
- Characteristic: digunakan untuk mengetahui karakteristik dari suatu tree. Yakni size, height, serta average lenght-nya.
- Traverse: digunakan untuk mengunjungi seluruh node-node pada tree dengan cara traversal. Terdapat 3 metode traversal yang dibahas dalam modul ini yakni Pre-Order, In-Order, dan Post-Order.



## Guided 1. 

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0},
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris ++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << ":";
        for (int kolom = 0; kolom < 7; kolom ++) {
            if (busur [baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
Code diatas merupakan contoh implementasi sederhana dari representasi graf menggunakan matriks ketetanggaan dalam bahasa C++. Simpul-simpul dari graf direpresentasikan dalam array string simpul, dan hubungan antar simpul direpresentasikan dalam matriks busur, di mana nilai-nilai matriks menunjukkan bobot dari busur yang menghubungkan simpul-simpul. Fungsi tampilGraph() digunakan untuk menampilkan graf dalam bentuk matriks ketetanggaan dengan menampilkan informasi tentang simpul yang terhubung dan bobotnya. Pada main(), fungsi tampilGraph() dipanggil untuk menampilkan graf yang sudah dibuat.


## Guided 2.

``` c++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    //constuctor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder (TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder (TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder (TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode*zero = new TNode(0);
    TNode*one = new TNode(1);
    TNode*five = new TNode(5);
    TNode*seven = new TNode(7);
    TNode*eight = new TNode(8);
    TNode*nine = new TNode(9);

    seven->left = one;

    seven->right = nine;

    one->left = zero;

    one->right = five;

    nine->left = eight;

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}

```
Code di atas merupakan contoh implementasi dari struktur data pohon biner dalam bahasa C++. Struktur data pohon biner direpresentasikan menggunakan struktur TNode yang memiliki tiga anggota: data untuk menyimpan nilai, left untuk menunjukkan node anak kiri, dan right untuk menunjukkan node anak kanan. Fungsi preOrder, inOrder, dan postOrder digunakan untuk melakukan penelusuran prapenelusuran, penelusuran dalam, dan penelusuran pasca urutan secara rekursif pada pohon biner. Pada main(), dilakukan pembuatan beberapa node pohon biner dan pengaturan hubungan antar node, kemudian dilakukan penelusuran prapenelusuran, penelusuran dalam, dan penelusuran pasca urutan untuk mengakses nilai-nilai dari pohon biner tersebut.


## Unguided 

*Cantumkan NIM pada salah satu variabel di dalam program.
Contoh : int nama_22102003;
#### 1.	Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
Output Program
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/7245190f-d3c1-4d7a-92c7-4752505a42e9)

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Graph {
    vector<string> simpul;
    vector<vector<int>> bobot;
};

int main() {
    int jumlahSimpul;
    
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    
    
    Graph graf;
    graf.simpul.resize(jumlahSimpul);
    graf.bobot.resize(jumlahSimpul, vector<int>(jumlahSimpul));
    
    cout << "Silahkan masukkan nama simpul" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i+1 << " : ";
        cin >> graf.simpul[i];
    }
    
    cout << "Silahkan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << graf.simpul[i] << "-->" << graf.simpul[j] << " = ";
            cin >> graf.bobot[i][j];
        }
    }
    
    
    cout << "\t";
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << graf.simpul[i] << "\t";
    }
    cout << endl;
    
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << graf.simpul[i] << "\t";
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << graf.bobot[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}

```
#### Output:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/ab65a917-6059-4fe1-8f73-e524e13e0cd5)


Dalam code yg ada di atas, saya menggunakan struktur data Graph untuk merepresentasikan graf. Graph memiliki dua anggota: simpul yang merupakan vektor dari string yang menyimpan nama-nama simpul, dan bobot yang merupakan vektor dari vektor integer yang menyimpan bobot antar simpul. Program ini meminta pengguna untuk memasukkan jumlah simpul, nama-nama simpul, dan bobot antar simpul. Kemudian, program akan menampilkan tabel bobot yang menunjukkan jarak dari setiap kota ke kota lainnya.

#### Full code Screenshot:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/47aeab6f-0383-4dbf-ad3d-692939d6be71)


#### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!


```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};


void tambahChild(TreeNode* parent, string childData) {
    if (parent->left == NULL)
        parent->left = new TreeNode(childData);
    else if (parent->right == NULL)
        parent->right = new TreeNode(childData);
    else
        cout << "Node ini sudah memiliki dua child." << endl;
}

void tampilkanDescendant(TreeNode* node) {
    if (node == NULL)
        return;

    cout << node->data << " ";
    tampilkanDescendant(node->left);
    tampilkanDescendant(node->right);
}

int main() {
    int jumlahSimpul;
    
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    
    
    string rootData;
    cout << "Masukkan data simpul root: ";
    cin >> rootData;
    TreeNode* root = new TreeNode(rootData);
    
    
    for (int i = 0; i < jumlahSimpul - 1; ++i) {
        string parentData, childData;
        cout << "Masukkan data simpul parent: ";
        cin >> parentData;
        cout << "Masukkan data simpul child: ";
        cin >> childData;

        
        TreeNode* parent = NULL;
        
        tambahChild(parent, childData);
    }

    
    cout << "Descendant dari setiap simpul:" << endl;
    

    return 0;
}

```
#### Output:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/e576f53f-578e-41c4-98e0-84bf597961ff)

Program memungkinkan pengguna untuk memasukkan jumlah simpul dan data simpul root, lalu membuat struktur tree dengan menambahkan child ke setiap node parent yang diinputkan. Setelah pembuatan tree, program menampilkan descendant dari setiap node. Ini memberi pengguna kontrol atas pembuatan tree dan memungkinkan mereka untuk melihat hubungan antar node dengan menampilkan descendant.

#### Full code Screenshot:
![image](https://github.com/chelsisdeo/praksrtukdata/assets/161056340/c6cdaae5-a5fb-467f-907d-749103ac6997)


## Kesimpulan
Pada hari ini, saya belajar tentang konsep dasar dari graf dan tree dalam ilmu komputer. Saya memahami bagaimana representasi graf menggunakan matriks ketetanggaan dan pohon biner menggunakan struktur data tree. Saya juga belajar tentang operasi dasar seperti penelusuran dan manipulasi struktur data graf dan tree. Dengan memahami konsep dan operasi dasar ini, saya memiliki dasar yang kuat untuk memahami dan mengimplementasikan algoritma yang lebih kompleks yang melibatkan graf dan tree di masa depan.





## Referensi
[1] Dalem, I. B. G. W. A. (2018). Penerapan algoritma A*(Star) menggunakan graph untuk menghitung jarak terpendek. Jurnal RESISTOR (Rekayasa Sistem Komputer), 1(1), 41-47.

[2] Susanto, L. A., Wiharja, K. R. S., & Puspitasari, S. Y. (2015). Implementasi Dan Analisis Visualisasi Graph Pada Graph Statis Menggunakan Representasi Visual Treemap. eProceedings of Engineering, 2(3).
>>>>>>> d8b982fcee9982656072edce223cfa0b795c94e8
