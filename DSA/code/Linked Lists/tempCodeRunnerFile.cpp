class Node{
    public:
    
    int data;
    Node* prev;
    Node* next;

    Node(){}
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
