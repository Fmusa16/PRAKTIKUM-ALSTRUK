#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node() {
        data = 0;
        left = right = NULL;
    }
     Node(int data) {
        this->data =data;
        left = right = NULL;
    }
};
class Tree {
public:
    Node *root;

    void preOrder(Node *root) ;
    void inOrder(Node *root) ;
    void postOrder(Node *root) ;
    int heightNode(Node *root) ;
    void printCurrentLevel(Node *root, int level) ;
    void levelOrder(Node *root) ;
    Node *insertBinaryRoot(Node *root, int nilai) ;
    int hitungNode(Node *root) ;



       
    };
    int main(){
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

    void Tree::preOrder(Node *root) {
        if (root != NULL) {//Data->left->right
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
    void Tree::inOrder(Node *root) {
        if (root != NULL) {//left->Data->right
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
    void Tree::postOrder(Node *root) {
        if (root != NULL) {//left->right->Data
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int Tree::heightNode(Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = heightNode(root->left);
        int rightHeight = heightNode(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}
int Tree::hitungNode(Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + hitungNode(root->left) +
         hitungNode(root->right);
    }
}
void Tree::printCurrentLevel(Node *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        cout << root->data << " ";
    } else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
void Tree::levelOrder(Node *root) {
    int h = heightNode(root);
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
        cout << endl;
    }
}



Node* Tree::insertBinaryRoot(Node *root, int nilai) {
    if (root == NULL) {
        root= new Node(nilai);
    }
    if (nilai < root->data) {
        root->left = insertBinaryRoot(root->left, nilai);
    } else if (nilai > root->data) {
        root->right = insertBinaryRoot(root->right, nilai);
    }
    return root;
}