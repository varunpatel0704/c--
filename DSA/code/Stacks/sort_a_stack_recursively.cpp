#include <iostream>
#include <stack>
using namespace std;

void InsertInSortedOrder(stack<int> &s, int element){
	if(s.empty()){
		s.push(element);
		return;
	}

	else if(s.top() < element){
		s.push(element);
		return;
	}

	// remove bigger elements temporarily
	int top = s.top();
	s.pop();

	// recursive call
	InsertInSortedOrder(s, element);

	// insert elements back
	s.push(top);
	
}

void sortStack(stack<int> &stack)
{
	// Write your code here

	//base case -> empty stack is already sorted.
	if(stack.empty()){
		return;
	}

	// remove all elements 
	int top = stack.top();
	stack.pop();
	sortStack(stack);

	// now insert all elements back in a sorted order.
	InsertInSortedOrder(stack, top);
}

int main(){
    
    return 0;
}