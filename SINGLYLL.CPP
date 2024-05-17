#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Student {
	int id;
	string name;
	float cgpa;
	Student *next;
	
	public:
		friend class StudentList;
		
		Student(int id, string name, float cgpa, Student *next) {
			this->id = id;
			this->name = name;
			this->cgpa = cgpa;
			this->next = next;
		}
		
		void studentDetails() {
			cout << "ID : " << id << endl;
			cout << "Name : " << name << endl;
			cout << "CGPA : " << cgpa << endl;
			cout << "--------------\n";
		}
};

class StudentList{
	Student *head;
	Student *cursor;
	
	public:
		StudentList() {
			head = NULL;
			cursor = NULL;
		}
		
		~StudentList() {
			Student *cur = head;
			while(head!=NULL) {
				head = cur->next;
				delete cur;
				cur = head;
			}
		}
		
		void insert(const Student *newStd) {
			Student *temp = new Student(newStd->id , newStd->name, newStd->cgpa , NULL);
			if(!head) {
				head = temp;
				cursor = head;
			}
			else {
				Student *cur = head;
				while(cur->next!=NULL) {
					cur = cur->next;
				} 
				cur->next = temp;
				cursor = cur;
			}
		}
		//-------------------------------------
		void remove(int id) {
			if(!head){
				cout << "Empty List\n";
			}
			else if(head->id == id) {	
				Student *temp = head->next;
				if(cursor == head) {
					cursor = head->next;
				}
				delete head;
				head = temp;
			}
			else {
				Student *cur = head;
				Student *prev;
				while(cur!=NULL) {
					if(cur->id == id) {
						if(cur->next == NULL) {
							cursor = head;
						}
						else {
							
						}
					
					break;
				}
				prev = cur;
				cur = cur->next;
			}
			prev->next = cur->next;
			}
		}
		
		void showStructure() const {
			if(!head) {
				cout << "Empty List\n";
			}
			else {
				Student *cur = head;
				while(cur!=NULL) {
					cur->studentDetails();
					cur = cur->next;
				}
			}
		}
		
		bool isEmpty() {
			return !head;
		}		
		
		void gotoBeginning() {
			cursor = head;  
		}
		
		void search(float cgpa) {
			Student* cur = head;
			bool status = false;
			while(cur!=NULL) {
				if(cur->cgpa == cgpa) {
					cur->studentDetails();
					status = true;
				}
				cur = cur->next;
			}
			if(!status) {
				cout << "STUDENT NOT FOUND\n";
			}
		}

		void replace(const Student *newStd) {
			Student *temp = new Student(newStd->id , newStd->name , newStd->cgpa, NULL);
			Student *cur = head;
			bool status = false;
			while(cur!=NULL) {
				if(temp->id == cur->id) {
					status = true;
					cur->name = temp->name;
					cur->cgpa = temp->cgpa;
				}
				cur = cur->next;
			}
			if(!status) {
				cur = head;
				while(cur->next != NULL) {
					cur = cur->next;
				}
				cur->next = temp;
				cursor = cur->next;
			}
		}

		void gotoEnd() {
			Student *cur = head;
			while(cur->next != NULL) {
				cur = cur->next;
			}
			cursor = cur;
		}
		
		bool gotoNext() {
			if(cursor->next == NULL) {
				return false;
			}
			else {
				cursor = cursor->next;
				return true;
			}
		}

		bool gotoPrior() {
			if(cursor == head) {
				return false;
			}
			else {
				Student *cur = head;
				Student *prev;
				
				while(cur!=cursor) {
					prev = cur;
					cur = cur->next;
				}
				cursor = prev;
				return true;
			}
		}

		Student getCursor() {
			return *cursor;
		}
};

int main(){
	fstream file;
	file.open("input.txt",ios::in);
	StudentList obj;
	
	int id;
	char name[30];
	float cgpa;
	
	
	file >> id;	
	file.getline(name, 30);
	file >> cgpa;
	
		
	cout << id << endl;
	cout << name << endl;
	cout << cgpa << endl;
	Student *one = new Student(id,name,cgpa,NULL);
	obj.insert(one);
	

	obj.showStructure();
	file.close();
}