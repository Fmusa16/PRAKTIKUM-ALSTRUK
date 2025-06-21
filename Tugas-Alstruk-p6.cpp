//start header.h 
#include <iostream> 
using namespace std; 
class Node{ 
    public: 
    int data; 
    Node *next; 
 
    Node(){   //konstruktor default 
        data = 0; 
        next = NULL; 
 
    } 
    Node(int data){ //konstruktor inputan 
        this->data = data; 
        //data atribut diisi dengan inputan data 
        //this digunakan karena nama variable atribut dan var.inputan sama 
        //Node(int value){, maka data = value; 
        this->next = NULL; 
    } 
}; 
class Linkedlist{ 
private: 
    Node *head; //pointer yg selalu di Node pertama 
    Node *tail; //pointer yg selalu di Node terakhir 
 
public: 
    Linkedlist(){ //konstruktor default 
        head = NULL; 
        tail = NULL; 
    } 
    void insertDepan(int value); 
    void cetak(); 
    void insertBelakang(int value); 
}; 
 
//start pustaka.cpp 
void Linkedlist::insertDepan(int value){ 
    Node *temp = new Node(value); //konstruktor inputan 
 
    if(head == NULL){ //jika list kosong 
    head = temp; 
    tail = temp; 
    }else{ 
        temp->next = head; 
        head = temp; 
    } 
} 
void Linkedlist::cetak(){ 
    Node *temp = new Node; 
    temp = head; 
    while(temp != NULL){ 
        //cout << temp->data << " "; 
        if(temp->next != NULL){ //jika tidak di node terakhir 
            cout << "[" << temp->data << "|" << temp-> next << "] --> "; 
        }else{ //jika di note terakhir 
            cout << "[" << temp->data << "|" << temp->next << "]"; 
            //di cpp, jika mencetak NULL, maka akan tampil 0 
        } 
        temp = temp->next; 
    } 
    cout <<  endl; 
} 
void Linkedlist::insertBelakang(int value){ 
    Node *temp = new Node(value); //konnstruktor default 
    temp->data = value; 
 
    if(head == NULL){ //jika list kosong 
        head = temp; 
        tail = temp; 
 
    }else{ 
     tail->next = temp; 
     tail = temp; 
    } 
} 
 
//start main.cpp 
int main() 
{ 
    cout << "Single Linked List Manual" << endl; 
    Node *head = new Node; //memanggil konstruktor default 
    head->data = 100; 
    head->next = new Node; //memanggil konstruktor default 
    head->next->data = 84; 
    head->next->next = new Node(5); //memanggil konstruktor inputan 
 
    //proses cetak 
    Node *temp = new Node; 
    temp = head; 
    while(temp != NULL){ 
        cout << temp->data << " "; 
        temp = temp->next; 
    } 
    cout << endl; 
 
    cout << "\nSingle Linked List menggunakan class Linkedlist" << endl; 
    Linkedlist sll; 
    cout << "insertDepan(100)\n"; 
    sll.insertDepan(100); 
    sll.cetak(); 
    cout << "\ninsertDepan(1)\n"; 
    sll.insertDepan(1); 
    sll.cetak(); 
    cout << "\ninsertBelakang(5)\n"; 
    sll.insertBelakang(5); 
    sll.cetak(); 
 
    return 0; 
} 
