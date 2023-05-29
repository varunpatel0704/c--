// write a program to perform insertion and deletion in a stack using 
// push and pop operations and also display the stack after that.


#include <stdio.h>

int top = -1;
int arr[100];

bool isFull(int stklen, int *top){
	
	if(*top>=stklen-1)
		return 1;
	
	return 0;
	
}

bool isEmpty(int* top){
	if( (*top) != -1)
		return 0;
		
	return 1;
	
}

void pop(int arr[], int stklen, int* top){
	
	if(isEmpty(top)){
		printf("\nStack empty");
	}
	
	else{
		(*top)--;
        display(arr, stklen, top);
	}
}

void push(int arr[], int stklen, int* top, int element){
	
	if(isFull(stklen, top)){
		printf("\nStack full!");
	}
	
	else{	
		arr[++(*top)] = element;
        display(arr, stklen, top);
	}
	
}

void peep(int arr[], int* top){
	
	if(isEmpty(top))
		printf("\nStack is empty");
	else
		printf("Top element is %d", arr[*top]);
}   

void display(int arr[], int stklen, int* top){
	
    if (isEmpty(top))
    {
        printf("\nStack empty, nothing to display\n");
    }
    else{
        printf("\nprinting stack.......\n\n");
        
        for(int i = (*top) ; i>=0; i--){
            printf("%d ", arr[i]);		
        }
        printf(" <- top");
	}
    
}


int main(){

	int stklen;
	
    printf("Enter the length of array: ");
	scanf("%d", &stklen);
    
    int option;
	bool go = true;
    while(go){
        printf("\n*****Menu*****\n1. Push\n2. Pop\n3. Peep\n4. Display\nEnter your choice: ");
        scanf("%d", &option);
        
        int element;
        
        switch (option){
            
            case 1: 
                printf("\n\nEnter the element to be pushed ");
                scanf("%d", &element);
                push(arr, stklen, &top, element);
                break;
            
            case 2:
                pop(arr, stklen, &top);
                break;
                
            case 3: 
                peep(arr, &top);
                break;
            
            case 4: 
                display(arr, stklen, &top);
                break;
            
            default:
                printf("\n\nInvalid input! ");
        }
        printf("\n\nWant to continue?\nEnter 0 (false) /1 (true) \n");
        scanf("%d", &go);

	}
    return 0;
}