#include<iostream>

using namespace std;

class stack{
	public:
		int size;
		char *arr;
		int top;
		int cnt;
		stack(int size){
			cnt = 0;
			this->size = size;
			arr = new char[size];
			int top = -1;
		}
		
		void push(char val){
			
			if(size - top <= 1)
				cout << "stack full" << endl;
				
			arr[++top] = val;
			cnt++;
			
		}
		
		char pop(){
			if(top == -1)
				return NULL;
			cnt--;
			return arr[top--];
		}
};

int main(){
	int size;
	
	cout << "Enter the size of stack ";
	cin >> size;
	
	stack st(size);
	bool flag = 0; 
	bool isValid = true;
	
 	for(int i=0; i<st.size; i++){
		cout << "Enter the character: ";
		char ch;
		cin >> ch;

		if(ch == 'a'){
		
			if(flag == true)
				isValid = false;
				
			st.push('a');
				
		}
				
		else if(ch == 'b'){
			
			flag = 1;
				
			char temp = st.pop();
			if(temp != 'a')
				isValid = false;
				
		}
			
		else{
			isValid = false;
			break;
		}
			
	}
		
	if(st.cnt != 0){
		cout << "String is invalid" << endl;
	}
	
	else if(!isValid)
		cout << "String is invalid" << endl;
		
	else	
		cout << "String is valid" << endl;
	
	return 0;
}
