#include <iostream>
#include <fstream>
using namespace std;

class Student{
    int stdID;
    string name;
    float fee;
    Student *left;
    Student *right;
public:
    Student(int stdID,string name,float fee) {
        this->stdID = stdID;
        this->name = name;
        this->fee = fee;
        left = NULL;
        right = NULL;
    }

    ~Student(){
        delete left;
        delete right;
        left = NULL;
        right = NULL;
    }

    void show() {
        cout << stdID << '\n';
        cout << name << '\n';
        cout << fee << '\n' << '\n';
    }

    friend class StudentBST;
};

class StudentBST{
    Student *root;

    void displayInOrder(Student *root){
        if(root!=NULL){
            displayInOrder(root->left);
            root->show();
            displayInOrder(root->right);
        }
    }

    void displayPreOrder(Student *root){
        if(root!=NULL){
            root->show();
            displayPreOrder(root->left);
            displayPreOrder(root->right);
        }
    }

    void displayPostOrder(Student *root)
    {
        if(root!=NULL){
            displayPostOrder(root->left);
            displayPostOrder(root->right);
            root->show();
        }
    }

    bool search(int stdID, Student *root)
    {
        if (root == NULL)
            return false;
        else if (root->stdID == stdID){
            root->show();
            return true;
        }
        else if (root->stdID > stdID){
            return search(stdID,root->left);
        }
        else{
            return search(stdID,root->right);
        }
    }

    void destroy(Student *root) {
        if(root!=NULL) {
            destroy(root->left);
            destroy(root->right);
            free(root);
        }
    }

public:
    StudentBST(){
        root = NULL;
    }

    ~StudentBST(){
        destroy();
    }

    bool insert(int stdID, string name, float fee) {
        Student *newNode =  new Student(stdID,name,fee);
        Student *curNode = root;
        Student *preNode = NULL;
        bool status = true;

        while(curNode!=NULL) {
            preNode = curNode;

            if(curNode->stdID > stdID)
                curNode = curNode->left;
            else
                curNode = curNode->right;      
        }

        if(preNode == NULL) 
            root = newNode;
        else if(preNode->stdID > stdID)
            preNode->left = newNode;
        else if(preNode->stdID < stdID)
            preNode->right = newNode;
        else                            //if data already exists    
            status = false;
        
        return status;
    }

    bool isEmpty() {
        return !root;
    }

    void displayInOrder() {
        displayInOrder(root);
    }

    void displayPreOrder() {
        displayPreOrder(root);
    }

    void displayPostOrder() {
        displayPostOrder(root);
    }

    bool search(int stdID) {
        return search(stdID,root);
    }

    void destroy(){
        destroy(root);
        root = nullptr;
    }
};

int main() {
    fstream file;
    file.open("input.txt", ios::in);

    StudentBST obj;

    int stdID;
    string name;
    float fee;

    while(true){
        if(file.eof()) break;
        file >> stdID;
        file >> name;
        file >> fee;
        obj.insert(stdID,name,fee);
    }    
    
    obj.displayInOrder();
    obj.displayPreOrder();
    obj.displayPostOrder();
}