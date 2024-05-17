#include <iostream>
using namespace std;

template <class T>
class Stack{
	T *data;
	int maxSize;
	int top;
	public:
		Stack(const int maxSize = 5){
			this->maxSize = maxSize;
			data = new T[maxSize];
			top = -1;
		}
		
		void push(const T newItem){
			if(top!=maxSize-1)
				data[++top] = newItem;
			else
				cout << "Stack Overflows"<<endl;
		}
		
		void pop(){
			if(top!=-1)
				top--;
			else
				cout << "Stack Underflows"<<endl;
		}
		
		void clear(){
			top = -1; 
		}
		
		T getTop () const {
			if(top!=-1)
				return data[top];
			else 
				cout<<"Stack is Empty"<<endl;
		}
		
		bool isEmpty() const{
			return top==-1;
		}
		
		bool isFull() const{
			return top==maxSize-1;
		}
		
		void showStructure() const{
			for(int i=top;i>=0;i--){
				if(i==top)	cout << "top-->";
				cout << "\t" << data[i] << endl;
			}
			cout << "-------------------------"<<endl;
		}
		
		~Stack(){
			delete [] data;
			data = 0;
		}
};

int main(){
	Stack <int> obj;
	obj.push(5);
	obj.push(8);
	obj.showStructure();	
	obj.push(11);
	obj.push(15);
	obj.push(18);
	obj.showStructure();	
	
	Stack <string> obj1(2);
	obj1.push("AMIMA KHAN");
	obj1.push("FIZA IQBAL");
	obj1.push("AHMED ARIF");
	obj1.showStructure();	
	
	Stack <float> obj2(3);
	obj2.pop();
	obj2.push(3.20);
	cout << "ELEMENT AT TOP OF THE STACK IS : " << obj2.getTop() << endl;
	obj2.push(3.33);
	obj2.push(99.8);
	obj2.showStructure();
}