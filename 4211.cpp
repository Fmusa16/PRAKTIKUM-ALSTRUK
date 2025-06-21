//Stack (tumpukan buku)-singlelinkedlist

#include <iostream>

using namespace std;
class NodeBuku {
    public:
    string judul;   
    string pengarang;
    int tahunTerbit;
    Node*next;

    NodeBuku(string judul, string pengarang, int tahunTerbit){
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
        bool isEmpty() ;
        void push(string judul, string pengarang, int tahunTerbit) {
            NodeBuku *newNode = new NodeBuku(judul, pengarang, tahunTerbit);
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if (top == NULL) {
                std::cout << "Stack is empty." << std::endl;
                return;
            }
            NodeBuku *temp = top;
            top = top->next;
            delete temp;
        }

        void cetak() {
            NodeBuku *current = top;
            while (current != NULL) {
                std::cout << "Judul: " << current->judul 
                          << ", Pengarang: " << current->pengarang 
                          << ", Tahun Terbit: " << current->tahunTerbit << std::endl;
                current = current->next;
            }
        }
};

int main(){
     cout<< "Stack Buku" << endl;
    StackBuku stack;
    stack.push("Buku A", "Pengarang A", 2020);
    stack.push("Buku B", "Pengarang B", 2021);
    stack.push("Buku C", "Pengarang C", 2022);
    stack.cetak();
    return 0;

}

        