#include <iostream>
#include <fstream>
#include "stack"
using namespace std;

int len(string s){
	int i;
	for(i=0;s[i]!='\0';i++);	
	return i;
}

bool delimitersOk(const string &expression){
	stack <char> obj;
	bool status = true;
	int length = len(expression);
	for(int i=0;i<length;i++){
		if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{')
			obj.push(expression[i]);
		
		else if(expression[i]==']')
		{
			if(obj.empty())
			return false;
			else if(obj.top()=='[')	
			{
			status = true;
			obj.pop();
			}
			else status = false;
		}
		
		else if(expression[i]==')'){
			if(obj.empty())	return false;
			else if(obj.top()=='(')	{
			status = true;
			obj.pop();	
			}
			else status = false;
		}
		
		else if(expression[i]=='}'){
			if(obj.empty())	return false;
			else if(obj.top()=='{')	{
			status = true;
			obj.pop();	
			}
			else status = false;
		}
	}
	if(!obj.empty())	
	status = false;
	return status;
}

int main(){
	ifstream file("input.txt");
	int size;
	string s;
	file>>size;
	cout<< size <<endl;
	if(delimitersOk(s)) 
	cout << "Valid"<<endl;
	else 
	cout << "Invalid"<<endl;
		getline(file,s);	
	for(int i=0;i<size;i++){
		getline(file,s);
			cout << s << endl;
			if(delimitersOk(s)) 
			cout << "Valid"<<endl;
			else cout << "Invalid"<<endl;
		
	}
}