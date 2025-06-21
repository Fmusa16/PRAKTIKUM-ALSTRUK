#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class DoubleLinkedList{
private:
    Node *head;
    Node *tail;

public:
    DoubleLinkedList(){
        head = NULL;
        tail = NULL;
    }
void insertDepan(int value);
void cetak();
void insertBelakang(int value);
void hapusDepan();
void hapusBelakang();
int hitungNode();
bool searchData(int k);
void midKetail(int n);
void insertmid(int value,int n);
void deletemid(int n);
void insertPos(int value, int posisi, int n);
void deletePos(int posisi, int n);
void midKeHead(int n);
};

int main(){
    DoubleLinkedList dll;
    cout << "========= DoubleLinkedList =========" << endl;
    dll.insertDepan(1);
    dll.cetak();
    cout<<endl;

    dll.insertDepan(5);
    dll.cetak();
    cout<<endl;

    dll.insertDepan(9);
    dll.cetak();
       cout<<endl;

    dll.insertBelakang(7);
    dll.cetak();
       cout<<endl;

    cout << endl;
    cout << "\nDLL searchData():\n";
    cout << "Apakah ada Angka 1? " << dll.searchData(1) << endl;
    cout << "Apakah ada Angka 56? " << dll.searchData(56) << endl;

    dll.hapusDepan();
    dll.cetak();
       cout<<endl;

    dll.hapusBelakang();
    dll.cetak();
       cout<<endl;

    dll.hapusDepan();
    dll.cetak();
       cout<<endl;
    dll.hapusBelakang();
    dll.cetak();
         cout<<endl;
   

    dll.insertBelakang(4);
    dll.cetak();
       cout<<endl;

    dll.insertBelakang(3);
    dll.cetak();
       cout<<endl;
    dll.insertBelakang(1);
    dll.cetak();
       cout<<endl;
    
       
    dll.insertmid(5,3);
    dll.cetak();
    cout << endl;

     dll.deletemid(3);
    dll.cetak();
    cout << endl;

    dll.midKeHead(dll.hitungNode());
    dll.cetak();
    cout << endl;

    dll.midKetail(dll.hitungNode());
    dll.cetak();
    cout << endl;

    

    dll.insertPos(6, 2, 4);
    dll.cetak();
    cout << endl;

    dll.deletePos(3,5);
    dll.cetak();
    cout << endl;

   
//kalau mau ganti urutannya tinggal ubah aja posisinya misal (midke tail posisinya setelah delete)
    

  return 0;
}

void DoubleLinkedList::insertDepan(int value){
    cout << endl;
    cout << "DLL insertDepan " << "(" << value << ")" << ":" ;
    Node *temp = new Node(value);
    if(head==NULL){
        head = temp;
        tail = temp;
    }else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    cout << endl;
}

void DoubleLinkedList::cetak(){
    Node *temp = head;

    while(temp != NULL){
        cout << "[" << temp->prev << "| " << temp->data << " |" << temp->next << "]";

        if(temp->next != NULL)
            cout << "<-- -->";
            temp = temp->next;
    }
    cout << endl;
}

void DoubleLinkedList::insertBelakang(int value){
    cout << endl;
    cout << "\nDLL insertBelakang("<< value <<"):";
    Node *temp = new Node(value);
    if(tail == NULL){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    cout << endl;
}

 void DoubleLinkedList::hapusDepan(){
    cout << endl;
    cout << "\nDLL hapusDepan():\n";
    if(head != NULL){
        Node *temp = head;
        head = head->next;

        delete temp;
        head->prev = NULL;
    }
 }

 void DoubleLinkedList::hapusBelakang(){
    cout << endl;
    cout << "\nDLL hapusBelakang():\n";
    if(head != NULL){
        Node *temp = tail;
        if(head == tail){ // hanya satu node
            head = NULL;
            tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }
 }

int DoubleLinkedList::hitungNode(){
    cout << endl;
    cout << "\nDLL hitungNode():\n";
    int s = 0;
    Node *current = head;

    while(current != NULL){
        s++;
        current = current->next;
    }
    return s;
 }

bool DoubleLinkedList::searchData(int k){
    bool found = false;
    Node *current = head;

    while(current != NULL){
        if(current->data == k){
            found = true;
            break;
        }
        current = current->next;
    }
    return found;
}

void DoubleLinkedList::midKetail(int n){
    cout << endl;
    cout << "DLL midKetail():";
    if (head!=NULL){
        int mid=(n+1)/2;
        Node *current = head;
        for (int i=1; i<mid; i++){
            current = current->next;
        }
        Node *before = current->prev;
        Node *after = current->next;
        if(before) before->next = after;
        if(after) after->prev = before;
        if(current == head) head = after;
        if(current == tail) return;
        current->prev = tail;
        current->next = NULL;
        tail->next = current;
        tail = current;
    }
    cout << endl;
}
void DoubleLinkedList::insertmid(int value, int n){
    cout << endl;
    cout << "DLL insertmid(" << value << "):";
    if (head == NULL || n <= 1) {
        insertDepan(value);
    } else {
        int mid = (n + 1) / 2;
        Node *current = head;
        for(int i = 1; i < mid; i++){
            current = current->next;
        }
        Node *temp = new Node(value);
        temp->next = current;
        temp->prev = current->prev;
        if(current->prev) current->prev->next = temp;
        current->prev = temp;
        if(mid == 1) head = temp;
    }
    cout << endl;
}

void DoubleLinkedList::deletemid(int n) {
    cout << endl;
    cout << "DLL deletemid(" << 5 << "):";
    if (head != NULL) {
        int mid = (n + 1) / 2;
        Node *current = head;
        for (int i = 1; i < mid; i++) {
            current = current->next;
        }
        Node *before = current->prev;
        Node *after = current->next;
        if (before) before->next = after;
        if (after) after->prev = before;
        if (current == head) head = after; // Update head if necessary
        delete current;
    }
    cout << endl;
}
void DoubleLinkedList::insertPos(int value, int posisi, int n){
    cout << endl;
    cout << "DLL insertPos("<<value<<" , "<<posisi<<" , "<<n<<"):";
    if (posisi == 1){
        insertDepan(value);
    } else if (posisi == n+1) {
        insertBelakang(value);
    } else if (posisi >1 && posisi <= n){
        Node *temp = new Node(value);
        Node *current = head;
        for (int i = 1; i < posisi-1; i++) {
            current = current->next;
        }
        temp->next = current->next;
        if(current->next) current->next->prev = temp;
        current->next = temp;
        temp->prev = current;
    }
    cout << endl;
} 
void DoubleLinkedList::deletePos(int posisi, int n){
    cout << endl;
    cout << "DLL deletePos( " << posisi << " , " << n << "):";
    if (posisi == 1) {
        hapusDepan();
    } else if (posisi == n) {
        hapusBelakang();
    } else if (posisi > 1 && posisi < n) {
        Node *current = head;
        for (int i = 1; i < posisi; i++) {
            current = current->next;
        }
        if(current->prev) current->prev->next = current->next;
        if(current->next) current->next->prev = current->prev;
        delete current;
    }
    cout << endl;
}

void DoubleLinkedList::midKeHead(int n){
    cout << endl;
    cout << "DLL midKeHead:";
    if (head != NULL) {
        int mid= (n + 1) / 2;
        Node *current = head;
        for (int i = 1; i < mid; i++) {
            current = current->next;
        }
        Node *before = current->prev;
        Node *after = current->next;
        before->next = after;
        after->prev = before;
        current->prev = NULL;
        current->next = head;
        head->prev = current;
        head = current;
    }
}