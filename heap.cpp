#include <iostream>
#include <cmath>
using namespace std;

int left(int i)
{
    return (2 * i + 1);
}

int right(int i)
{
    return (2 * i + 2);
}

int parent(int i)
{
    return (i - 1) / 2;
}



class Student
{
    int rollNo;
    double cgpa;

public:
    Student()
    {
        this->rollNo = 0;
        this->cgpa = 0;
    }

    friend class StudentMaxHeap;
};

class StudentMaxHeap
{
    Student *A;
    int curSize;
    int maxSize;

public:
    StudentMaxHeap(int size)
    {
        A = new Student[size];
        maxSize = size;
        curSize = 0;
    }

    bool isEmpty()
    {
        return !curSize;
    }

    bool isFull()
    {
        return curSize == maxSize;
    }

    bool insert(int rollNo, double cgpa)
    {
        if (curSize == maxSize)
            return false;
        A[curSize].cgpa = cgpa;
        A[curSize].rollNo = rollNo;
        int np = curSize;
        curSize++;

        while (np != 0 && A[parent(np)].cgpa < A[np].cgpa)
        {
            swap(A[parent(np)], A[np]);
            np = parent(np);
        }
        if (A[parent(np)].cgpa == A[np].cgpa && A[parent(np)].rollNo > A[np].rollNo)
        {
            swap(A[parent(np)], A[np]);
        }
        return true;
    }

    void displayStudentList() {
        for(int i=0;i<curSize;i++) {
            cout << "Roll No. "  << A[i].rollNo << endl;
            cout << "CGPA : " << A[i].cgpa << endl << endl;
        }
    }

    void levelOrder() {
       int power = 0;
       int j=1;
       for(int i=0; i<curSize ;i++,j++) {
        cout << A[i].rollNo << ' ' << A[i].cgpa << '\t';
        if(j==pow(2,power)) {
            cout << "Check";
            cout << '\n';
            j=0;
            power++;
        }
       }
    }

    bool remove(int &rollNo,double &cgpa) {
            if(isEmpty()) return false;
             
            cgpa = A[0].cgpa;
            rollNo = A[0].rollNo;
            A[0].cgpa = 0;
            A[0].rollNo = 0;
            maxHeapify(0);
            curSize--;
            return true;
        }

    void maxHeapify(int i)
    {
        int left_i = left(i);
        int right_i = right(i);
        int largest = i;

        if (left_i < curSize && A[left_i].cgpa > A[largest].cgpa)
            largest = left_i;

        if (right_i < curSize && A[right_i].cgpa > A[largest].cgpa)
            largest = right_i;

        if (largest != i)
        {
            swap(A[largest], A[i]);
            maxHeapify(largest);
        }
    }

    ~StudentMaxHeap() {
        delete [] A;
        A = nullptr;
        curSize = 0;
        maxSize = 0;
    }
};

void menu() {
    cout << '\n';
    cout << "1. Insert a new student\n";
    cout << "2. Remove (and display) the student with the Max CGPA\n";
    cout << "3. Display the list of students (Descending order of CGPA)\n";
    cout << "4. Display the list of students (Level-order traversal)\n";
    cout << "5. Exit\n";
}

int main()
{
    double cgpa;
    int rollNo;
    StudentMaxHeap obj(10);
    // obj.insert(1,3.2);
    // obj.insert(2,2.2);
    // obj.insert(3,4.2);
    // obj.insert(4,5.2);
    // obj.insert(5,6.2);
    // obj.insert(6,1.2);
    // obj.insert(7,0.2);
    // obj.insert(8,3.1);

    while(true) {
        menu();
        int choice;
        cout << "Enter your choice : ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter CGPA : ";
            cin >> cgpa;
            cout << "Enter Roll # : ";
            cin >> rollNo; 
            obj.insert(rollNo,cgpa);
        }
        else if(choice == 2) {
            obj.remove(rollNo,cgpa);
            cout << "CGPA : " << cgpa << endl;
            cout << "Roll No. " << rollNo << endl;
        }
        else if(choice == 3) {
            obj.displayStudentList();
        }
        else if(choice == 4) {
            obj.levelOrder();
        }
        else if(choice == 5) {
            return 0;
        }
        else {
            cout << "Invalid Input\n";
        }
    }
    return 0;
}
