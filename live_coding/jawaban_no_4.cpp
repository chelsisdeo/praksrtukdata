/// C. menghapus elemen pertama(head) dalam linked list

# void hapusdepan() {
    if (isEmpty == 0) {
        hapus = head;
        tail = head;

        if(hapus->next == head){
            head = NULL;
            tail = NULL;
            delete hapus;
        }else {
            while (tail->next != hapus){
                tail = tail ->next;
            }

            head = head->next;
            tail -> next = head;
            hapus -> next = NULL;
            delete hapus;
        }
    }else{
        cout << "list kosong" << endl;
    }
}

////    a .Menambahkan elemen di akhir linked list 

void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}


////     b. Mencetak semua elemen di dalam linked list

// Tambah Data didalam
void insertdalam(int data, int posisi) {
    
}
   
