#include <iostream>
using namespace std;

class Queue{
    private:
    int front;
    int rear;
    int size;
    int* arr;
    
    public:
    // constructor
    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    // push operation.
    void push(int element){
        if(size - rear > 1){
            if(front == -1)
                front++;
            arr[++rear] = element;
        }

        else    
            cout <<"Queue full"<<endl;
    }

    // pop operation.
    void pop(){
        if(front == -1)
            cout << "Queue empty" << endl;

        else{
            front++;
            if(front > rear)
                front = rear = -1;
        }
    }

    void Rear(){
        if(front == -1)
            cout << "Queue empty" <<endl;
        else{
            cout << arr[rear] << endl;
        }
    }
    // front operation.
    void Front(){
        if(front == -1)
            cout << "Queue empty" <<endl;
        
        else
            cout << arr[front] << endl;

    }

    // empty check operation.
    bool empty(){
        return (front == -1);
    }

    // destructor
    ~Queue(){
        delete []arr;
    }
};

int main(){
    Queue q(5);

    cout << "Queue empty? ->" << q.empty() << endl;

    q.push(1);
    q.Front();
    q.Rear();
    cout<<endl;

    q.push(2);
    q.Front();
    q.Rear();
    cout<<endl;

    q.push(3);
    q.Front();
    q.Rear();
    cout<<endl;

    q.pop();
    q.Front();
    q.Rear();

    q.pop();
    q.pop();
    q.pop();
    return 0;
}