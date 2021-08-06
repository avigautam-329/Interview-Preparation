#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
    	if(next) 
	    delete next;
    }
};

Node* swapEveryPair(Node *head) {
    //write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }
	Node *curr1 = head;
    Node *curr2 = head->next;
    
    while(curr1 != NULL && curr2 != NULL){
		int temp = curr1->data;
        curr1->data = curr2->data;
        curr2->data = temp;
        
        
        // Since if i call curr->next->next but curr->next is pointing to null already, soo doing that would 
        // give an segmentation fault error.
        // Soo I need to check whether curr->next == NULL before trying to move the curr to next of curr->next.
        if(curr1->next != NULL){
            curr1 = curr1->next->next;
        }
        if(curr2->next != NULL){
            curr2 = curr2->next->next;
        }
    }
    
    return head;
}

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node*temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node* head = takeinput();
    head = swapEveryPair(head);
    print(head);
    delete head;
    return 0;
}
