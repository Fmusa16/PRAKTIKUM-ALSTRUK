#include <iostream>

using namespace std;

class Node {
public:
    char data;  
    Node *left;
    Node *right;

    Node() {
        data = 0;
        left = right = NULL;
    }
    Node(char data) { 
        this->data = data;
        left = right = NULL;
    }
};
class Tree {
public:
    Node *root;


    void inOrderAritmatika(Node *root) ;
    int heightNodeAritmatika(Node *root) ;
    bool isPerfectBinaryAritmatika(Node *root, int tinggi, int level);
    
};

int main(){
    Node *root = new Node('+');
    root->left = new Node('*'); root->right = new Node('-');
    root->left->left = new Node('9'); root->left->right = new Node('6');
    root->right->left = new Node('8'); root->right->right = new Node('5');
    Tree T;
    int tinggi;
    cout << "In-order : "; T.inOrderAritmatika(root);

    tinggi = T.heightNodeAritmatika(root);
    cout << "\nTinggi tree (mulai dari 1): " << tinggi << endl;
    cout << "\nApakah tree ini perfect binary? " << (T.isPerfectBinaryAritmatika(root, tinggi, 0) ? "Ya" : "Tidak") << endl;

    Node *akar = new Node('*');
    akar->left = new Node('4'); akar->right = new Node('/');
    akar->right->left = new Node('6'); akar->right->right = new Node('2');
    Tree pohon;
    int tinggiPohon;
    cout << "\n\nIn-order : "; pohon.inOrderAritmatika(akar);
    tinggiPohon = pohon.heightNodeAritmatika(akar);
    cout << "\nTinggi tree (mulai dari 1): " << tinggiPohon << endl;
    cout << "\nApakah tree ini perfect binary? " << (pohon.isPerfectBinaryAritmatika(akar, tinggiPohon, 0) ? "Ya" : "Tidak") << endl;
    return 0;
}




        /*
        Node *root = new Node(20);
        root->left = new Node(15);
        root->left->left = new Node(12);
        root->left->right = new Node(17);
        root->right = new Node(25);
        root->right->left = new Node(27);

        Tree pohon;
        cout << "Pre-order : ";
        pohon.preOrder(root);
        cout << endl;
        cout << "In-order : ";
        pohon.inOrder(root);
        cout << endl;
        cout << "Post-order : ";
        pohon.postOrder(root);
        cout << endl;
        cout << "Height of tree: " << pohon.heightNode(root) << endl;
        cout << "Level order traversal: " << endl;
        pohon.levelOrder(root);
        cout << endl;
       cout << "Insert 22 into the tree." << endl;
        root = pohon.insertBinaryRoot(root, 22);
*/


/*
        Node * root;
Tree T;
root = NULL;
root =T.insertBinaryRoot(root, 20);
root = T.insertBinaryRoot(root, 15); root = T.insertBinaryRoot(root, 25);
root = T.insertBinaryRoot(root, 12); root = T.insertBinaryRoot(root, 17);
root = T.insertBinaryRoot(root, 27); root = T.insertBinaryRoot(root, 30);
root = T.insertBinaryRoot(root, 22); root = T.insertBinaryRoot(root, 10);
root = T.insertBinaryRoot(root, 18); root = T.insertBinaryRoot(root, 28);
cout << "Pre-order : "; T.preOrder(root);
cout << "\nin-order : "; T.inOrder(root);
cout << "\nPost-order : "; T.postOrder(root);
int tinggi = T.heightNode(root);
cout << "\nTinggi tree (mulai dari 1): " << tinggi ;

int hitungNode = T.hitungNode(root);
cout << "\nJumlah node : " << hitungNode;

cout << "\nLevel order : " << endl;
T.levelOrder(root);
return 0;
    }
*/
    
    void Tree::inOrderAritmatika(Node *root) {
        if (root != NULL) {
        bool isOp = (root->data == '*' || root->data == '+'|| root->data == '-' || root->data == '/');
        if (isOp) cout << "(";
        inOrderAritmatika(root->left);
        cout << root->data << " ";
        inOrderAritmatika(root->right);
        if (isOp) cout << ")";
    }
}
   
int Tree::heightNodeAritmatika(Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = heightNodeAritmatika(root->left);
        int rightHeight = heightNodeAritmatika(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}




bool Tree::isPerfectBinaryAritmatika(Node *root, int tinggi, int level) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) {
        return (tinggi == level + 1);
    }
    if (root->left == NULL || root->right == NULL) {
        return false;
    }
    return isPerfectBinaryAritmatika(root->left, tinggi, level + 1) &&
           isPerfectBinaryAritmatika(root->right, tinggi, level + 1);
}