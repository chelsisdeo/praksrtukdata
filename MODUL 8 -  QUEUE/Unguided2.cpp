#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

const int maksimalQueue = 5;

class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    bool isFull() {
        return (count == maksimalQueue);
    }

    bool isEmpty() {
        return (count == 0);
    }

    void enqueueAntrian(string nama, string nim) {
        if (isFull()) {
            cout << "Antrian Penuh" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data.nama = nama;
        newNode->data.nim = nim;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    int countQueue() {
        return count;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        cout << "Data antrian mahasiswa: " << endl;
        int i = 1;
        while (temp != nullptr) {
            cout << i << ". Nama: " << temp->data.nama << ", NIM: " << temp->data.nim << endl;
            temp = temp->next;
            i++;
        }
    }

    ~Queue() {
        clearQueue();
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueueAntrian("Andi", "12345");
    myQueue.enqueueAntrian("Maya", "67890");
    myQueue.viewQueue();
    cout << "Jumlah antrian = " << myQueue.countQueue() << endl;
    myQueue.dequeueAntrian();
    myQueue.viewQueue();
    cout << "Jumlah antrian = " << myQueue.countQueue() << endl;
    myQueue.clearQueue();
    myQueue.viewQueue();
    cout << "Jumlah antrian = " << myQueue.countQueue() << endl;
    return 0;
}
