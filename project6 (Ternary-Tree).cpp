#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node *middle;
};

class TernaryTree {
private:
    Node *root;
    void insert_h(int,  Node *);
    int degree_one_nodes_count_h(Node *);
    int leaf_count_h(Node *);
    void traverse_LMRW_h(Node *);

public:
    void insert(int);
    void construct_tree(int A[], int n);
    void traverse_LMRW();
    int degree_one_nodes_count();
    int leaf_count();


    TernaryTree() {
        root = NULL;
    }
};

void TernaryTree::insert_h(int value, Node *leaf) {
    if(value < leaf -> data) {
        if(leaf -> left != NULL)
            insert_h(value, leaf->left);
        else {
            leaf -> left = new Node;
            leaf -> left -> data = value;
            leaf -> left -> left = NULL;
            leaf -> left -> right = NULL;
            leaf -> left -> middle = NULL;
        }
    }
    else if(value == leaf -> data) {
        if (leaf -> middle != NULL)
            insert_h(value, leaf -> right);
        else {
            leaf -> middle = new Node;
            leaf -> middle -> data = value;
            leaf -> middle -> middle = NULL;
            leaf -> middle -> left = NULL;
            leaf -> middle -> right = NULL;
        }
    }
    else if(value > leaf -> data) {
        if(leaf -> right != NULL)
            insert_h(value, leaf -> right);
        else {
            leaf -> right = new Node;
            leaf -> right -> data = value;
            leaf -> right -> left = NULL;
            leaf -> right -> right = NULL;
            leaf -> right -> middle = NULL;
        }
    }
}

void TernaryTree::insert(int value){
    if(root == NULL){
        root = new Node;
        root -> data = value;
        root -> left = NULL;
        root -> right = NULL;
        root -> middle = NULL;
    }
    else
        insert_h(value, root);
}

void TernaryTree::construct_tree(int A[], int n){
    for (int i = 0; i < n; i++){
        insert(A[i]);
    }
}


int TernaryTree::degree_one_nodes_count_h(Node *currentNode){
    static int count = 0;
    if (currentNode != NULL) {
        if ((currentNode -> left != NULL) and (currentNode -> middle == NULL) and (currentNode -> right == NULL)) {
            count += 1;
        }
        else if ((currentNode -> left == NULL) and (currentNode -> middle != NULL) and (currentNode -> right == NULL)) {
            count += 1;
        }
        else if ((currentNode -> left == NULL) and (currentNode -> middle == NULL) and (currentNode -> right != NULL)) {
            count += 1;
        }
        degree_one_nodes_count_h(currentNode -> left);
        degree_one_nodes_count_h(currentNode -> middle);
        degree_one_nodes_count_h(currentNode -> right);
    }
    return count;
}

int TernaryTree::degree_one_nodes_count(){
    return degree_one_nodes_count_h(root);

}

int TernaryTree::leaf_count_h(Node *currentNode){
    static int count = 0;
    if (currentNode != NULL) {
        if ((currentNode -> left == NULL) and (currentNode -> middle == NULL) and (currentNode -> right == NULL))
            count += 1;
        leaf_count_h(currentNode -> left);
        leaf_count_h(currentNode -> middle);
        leaf_count_h(currentNode -> right);
    }
    return count;
}

int TernaryTree::leaf_count(){
    return leaf_count_h(root);

}

void TernaryTree::traverse_LMRW_h(Node *currentNode) {
    if (currentNode != NULL){
        traverse_LMRW_h(currentNode -> left);
        traverse_LMRW_h(currentNode -> middle);
        traverse_LMRW_h(currentNode -> right);
        cout << currentNode -> data << endl;
    }

}

void TernaryTree::traverse_LMRW() {
    traverse_LMRW_h(root);
}

int main() {
    int A[14] = {7,4,2,2,3,1,8,4,0,6,5,9,4,6};
    int n = sizeof(A)/sizeof(A[0]);
    TernaryTree T;
    T.construct_tree(A, n);
    T.traverse_LMRW();
    cout << T.leaf_count() << endl;
    cout << T.degree_one_nodes_count() << endl;
    return 0;
}