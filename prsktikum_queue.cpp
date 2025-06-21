#include <iostream>
using namespace std;

class NodeHokage {
public:
    string nama;
    NodeHokage *next;
    NodeHokage(string nama) {
        this->nama = nama;
        next = NULL;
    }
};

class Queue {
private:
    NodeHokage *head, *tail;
    int kapasitas;
public:
    Queue() {
        head = tail = NULL;
        kapasitas = 100;
    }
    Queue(int kapasitas) {
        head = tail = NULL;
        this->kapasitas = kapasitas;
    }
    bool isEmpty() {
        return head == NULL;
    }
    bool isFull() {
        return panjangQ() >= kapasitas;
    }
    int panjangQ() {
        int cnt = 0;
        NodeHokage *cur = head;
        while (cur) {
            cnt++;
            cur = cur->next;
        }
        return cnt;
    }
    void enqueue(string nama) {
        if (isFull()) {
            cout << "Maaf,Kapasitas Penuh" << endl;
            return;
        }
        NodeHokage *Hokage = new NodeHokage(nama);
        if (isEmpty()) {
            head = tail = Hokage;
        } else {
            tail->next = Hokage;
            tail = Hokage;
        }
    }
    void dequeue() {
        if (!isEmpty()) {
            if (panjangQ() == 1) {
                delete head;
                head  = NULL;
                tail = NULL;
            } else {
                NodeHokage *temp = head;
                head = head->next;
                delete temp;
                if (head == NULL) tail = NULL;
            }
        }
    }
    void dequeueBelakang() {
        if (!isEmpty()) {
            if (panjangQ() == 1) {
                delete head;
                head = NULL;
                tail = NULL;
            } else {
                NodeHokage *cur = head;
                while (cur->next != tail) cur = cur->next;
                delete tail;
                tail = cur;
                tail->next = NULL;
            }
        }
    }
    void enqueuePriority(string nama) {
        if (isFull()) {
            dequeueBelakang();
        }
        NodeHokage *Hokage = new NodeHokage(nama);
        Hokage->next = head;
        head = Hokage;
        if (tail == NULL) tail = Hokage;
    }
    string peek() {
        if (!isEmpty()) return head->nama;
        return "";
    }
    void cetak() {
        if (isEmpty()) {
            cout << "Queue kosong" << endl;
            return;
        }
        NodeHokage *cur = head;
        cout << "[";
        while (cur) {
            cout << cur->nama;
            if (cur->next) cout << " <- ";
            cur = cur->next;
        }
        cout << "]" << endl;
    }
};

int main(){
    Queue hokage(3);
    hokage.enqueue("sasuke");
    hokage.enqueue("sakura");
    hokage.cetak();
    hokage.enqueuePriority("naruto");
    hokage.cetak();
    cout <<"Calon Hokage Urutan Pertama Adalah: " << hokage.peek() << endl;
    hokage.enqueue("Boruto");
    hokage.enqueuePriority("kakashi");
    hokage.cetak();
    return 0;
}