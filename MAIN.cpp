#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int data) : data(data), next(NULL), prev(NULL) {}
};

class DoubleLinkedList {
private:
    Node *head, *tail;
public:
    DoubleLinkedList() : head(NULL), tail(NULL) {}

    void insertDepan(int value) {
        Node *temp = new Node(value);
        if (!head) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void insertBelakang(int value) {
        Node *temp = new Node(value);
        if (!tail) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void cetak() {
        Node *temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void hapusDepan() {
        if (!head) return;
        Node *temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void hapusBelakang() {
        if (!tail) return;
        Node *temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    int hitungNode() {
        int count = 0;
        Node *temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool searchData(int value) {
        Node *temp = head;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    void insertMid(int value) {
        int n = hitungNode();
        int mid = (n + 1) / 2;
        insertPos(value, mid + 1);
    }

    void hapusMid() {
        int n = hitungNode();
        int mid = (n + 1) / 2;
        deletePos(mid + 1);
    }

    void midKeHead() {
        int n = hitungNode();
        if (n < 2) return;
        int mid = (n + 1) / 2;
        Node *curr = head;
        for (int i = 1; i < mid; i++) curr = curr->next;
        if (curr == head) return;
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        if (curr == tail) tail = curr->prev;
        curr->prev = NULL;
        curr->next = head;
        head->prev = curr;
        head = curr;
    }

    void midKeTail() {
        int n = hitungNode();
        if (n < 2) return;
        int mid = (n + 1) / 2;
        Node *curr = head;
        for (int i = 1; i < mid; i++) curr = curr->next;
        if (curr == tail) return;
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        if (curr == head) head = curr->next;
        curr->next = NULL;
        curr->prev = tail;
        tail->next = curr;
        tail = curr;
    }

    void insertPos(int value, int pos) {
        if (pos <= 1) {
            insertDepan(value);
            return;
        }
        int n = hitungNode();
        if (pos > n) {
            insertBelakang(value);
            return;
        }
        Node *temp = new Node(value);
        Node *curr = head;
        for (int i = 1; i < pos - 1 && curr; i++) curr = curr->next;
        temp->next = curr->next;
        temp->prev = curr;
        if (curr->next) curr->next->prev = temp;
        curr->next = temp;
        if (temp->next == NULL) tail = temp;
    }

    void deletePos(int pos) {
        if (pos <= 1) {
            hapusDepan();
            return;
        }
        int n = hitungNode();
        if (pos > n) {
            hapusBelakang();
            return;
        }
        Node *curr = head;
        for (int i = 1; i < pos && curr; i++) curr = curr->next;
        if (!curr) return;
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        if (curr == head) head = curr->next;
        if (curr == tail) tail = curr->prev;
        delete curr;
    }
};