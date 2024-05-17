#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Book {
	int id;
	string title;
	float price;
	Book *next;
	Book *prev;
	
	public:
		friend class BookList;

		Book(int id, string title, float price, Book *next, Book *prev) {
			this->id = id;
			this->title = title;
			this->price = price;
			this->next = next;
			this->prev = prev;
		}
		
		void bookDetails() {
			cout << "ID : " << id << endl;
			cout << "Title : " << title << endl;
			cout << "Price : " << price << endl;
			cout << "--------------\n";
		}
};

class BookList{
	Book *head;
	Book *cursor;
	Book *last;
	
	public:
		BookList() {
			head = NULL;
			cursor = NULL;
			last = NULL;
		}
		
		~BookList() {
			Book *cur = head;
			while(head!=NULL) {
				head = cur->next;
				delete cur;
				cur = head;
			}
		}
		
		void setLast() {
			Book *cur = head;
			while(cur->next != NULL) {
				cur = cur->next;
			}
			last = cur;
		}
		
		void insert(Book *newBook) {
			Book *temp = new Book(newBook->id , newBook->title, newBook->price , NULL, NULL);
			if(!head) {
				head = temp;
				cursor = head;
				head->prev = NULL;
				head->next = NULL;
			}
			else {
				Book *cur = head;
				Book *previous;
				while(cur->next!=NULL) {
					previous = cur;
					cur = cur->next;
				} 
				cur->next = temp;
				temp->prev = cur;
				cursor = temp;
			}
			setLast();
		}
		//-------------------------------------
		void remove() {
			if(!head){
				cout << "Empty List\n";
			}
			else if(head->next == NULL) {	
				delete head;
				head = NULL;
				cursor = head;
				last = head;
			}
			else {
				if(cursor->next == NULL) {
					cursor = cursor->prev;
					cursor->next = NULL;
				}
				else {
					cursor->next->prev = cursor->prev;
					cursor->prev->next = cursor->next;
					cursor = cursor->prev;
				}
			}
			setLast();
		}
		
		void showStructureForward() const {
			if(!head) {
				cout << "Empty List\n";
			}
			else {
				Book *cur = head;
				while(cur!=NULL) {
					cur->bookDetails();
					cur = cur->next;
				}
			}
		}
		
		void showStructureBackward() const {
			if(!head) {
				cout << "Empty List\n";
			}
			
			else {
				Book *cur = last;
				while(cur!=NULL) {
					cur->bookDetails();
					cur = cur->prev;
				}
			}
		}
		
		bool isEmpty() {
			return !head;
		}		
		
		void gotoBeginning() {
			cursor = head;  
		}
		
		void search(string title) {
			Book* cur = head;
			bool status = false;
			while(cur!=NULL) {
				if(cur->title == title) {
					cur->bookDetails();
					status = true;
				}
				cur = cur->next;
			}
			if(!status) {
				cout << "STUDENT NOT FOUND\n";
			}
			setLast();
		}

		void replace(const Book *newStd) {
			Book *temp = new Book(newStd->id , newStd->title , newStd->price , NULL , NULL);
			Book *cur = cursor;
			cursor->id = newStd->id;
			cursor->title = newStd->title;
			cursor->price = newStd->price;
			setLast();
		}

		void gotoEnd() {
			cursor = last;
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
				cursor = cursor->prev;
				return true;
			}
		}

		Book getCursor() {
			return *cursor;
		}
};

int main(){
	fstream file;
	file.open("input.txt",ios::in);
	
	BookList obj;
	
	int id;
	string title;
	float price;
	
	while(true)
	{
		if(file.eof()) break;
		file >> id;
		file >> title;
		file >> price;
		Book *book = new Book(id,title,price,NULL,NULL);
		obj.insert(book);	
	}
	obj.showStructureForward();
	obj.gotoPrior();
	obj.remove();
	obj.showStructureForward();
	file.close();
}