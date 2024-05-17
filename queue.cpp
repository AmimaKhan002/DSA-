#include <iostream>
using namespace std;

template <class T>
class Queue{
	T *data;
	int front;
	int rear;
	int maxSize;
	public:
		Queue(int maxSize=5){
			this->maxSize=maxSize;
			front=rear=-1;
			data = new T[maxSize];
		}
		
		T getFront(){
			if(!isEmpty())	
			return data[front];
			else 
			throw("Queue is Empty\n");
		}
		
		T getRear(){
			if(!isEmpty())	return data[rear];
			else throw("Queue is Empty\n");
		}
		
		bool isEmpty(){
			return front==-1;
		}
		
		bool isFull(){
			return (rear+1)%maxSize==front;
		}
		
		void clear(){
			front = rear = -1;
		}
		
		void enQueue(const T item){
			if(!isFull()){
				if(rear==-1)	
				front=0;
				rear=(rear+1)%maxSize;
				data[rear] = item;
			}
			else
				cout << "Queue is Full\n";
		}
		
		void deQueue(){
			if(!isEmpty()){
				if(front==rear)	
				front = rear =-1;
			else
				front=(front+1)%maxSize;
			}
			else 
				cout << "Queue is Empty\n";
		}
		
		void showStructure(){
			if(isEmpty())	return;
			cout << "Front->";
			for(int i=front;i<=rear;i++){
				cout << "\t" << data[i];
				if(rear==i)	cout << " <-rear";
				cout << endl;
			}
				cout << "\n------------------------"  << endl;
		}
		
		~Queue(){
			delete [] data;
			data = 0;
		}
};

int main(){
	Queue <int> obj;
	
	try{
		cout << obj.getFront() << endl;
	}catch(const char *ch){
		cout << ch;
	}
	obj.showStructure();
	obj.enQueue(10);
	obj.enQueue(20);
	obj.enQueue(30);
	obj.showStructure();
	obj.deQueue();
	obj.deQueue();
	obj.showStructure();
	obj.clear();
	obj.enQueue(1);
	obj.enQueue(2);
	obj.showStructure();
}