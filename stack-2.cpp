//Stack (tumpukan buku)-singlelinkedlist

#include <iostream>
#include <string>
using namespace std;

class NodeBuku {
public:
    string judul;
    string pengarang;
    int tahunTerbit;
    NodeBuku *next;

    NodeBuku(string judul, string pengarang, int tahunTerbit) {
        this->judul = judul;
        this->pengarang = pengarang;
        this->tahunTerbit = tahunTerbit;
        next = NULL;
    }
};

class StackBuku {
private:
    NodeBuku *top;
public:
    StackBuku() {
        top = NULL;
    }
    bool isEmpty() {
        return top == NULL;
    }
    void push(string judul, string pengarang, int tahunTerbit) {
        NodeBuku *newNode = new NodeBuku(judul, pengarang, tahunTerbit);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (! isEmpty()){
        NodeBuku *temp = top;
        top = top->next;
        if(top->next ==NULL);
        delete temp;
    }
}
   
    void cetak() {
        if (isEmpty()) {
            cout << "{Kosong|Kosong}" << endl;
            return;
        }
        NodeBuku *temp = top;
        while (temp != NULL) {
            cout << "[Judul: " << temp->judul
                 << " | Pengarang: " << temp->pengarang
                 << " | Tahun Terbit: " << temp->tahunTerbit << "]";
            if (temp == top) {
                cout << " \t top";
            }
            cout << endl;
            if (temp->next != NULL) {
                cout << "\t|\n\t\\/" << endl;
            }
            temp = temp->next;
        }
    }
};


int main() {
    cout<< "Stack (Tumpukan) Buku -single Linekedlist" << endl;
    StackBuku stack;
    stack.push("Kukira Kau Obat Ternyata Patah Hati Terhebat", "Ade Rima Miranti", 2024);
    stack.push("Yang Katanya Cemara", "Vania Winola", 2023);
    stack.push("Nanti Juga Sembuh Sendiri", "HeloBagas", 2022);
    stack.cetak();
    return 0;

}
