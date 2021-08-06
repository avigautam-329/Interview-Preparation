#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if(head1 == NULL){
		return head2;
    }
    
    if(head2 == NULL){
        return head1;
    }
    
    Node* finalHead = NULL;
    Node* finalTail = NULL;
    
    while(head1 != NULL && head2 != NULL){
    	if(head1->data < head2 -> data){
    		if(finalHead == NULL){
    			finalHead = head1;
    			finalTail = head1;
			}else{
				finalTail->next = head1;
				finalTail = head1;
			}
			head1 = head1->next;
		}else{
    		if(finalHead == NULL){
    			finalHead = head2;
    			finalTail = head2;
			}else{
				finalTail->next = head2;
				finalTail = head2;
			}
			head2 = head2->next;
		}
	}
	
	while(head1 != NULL){
		finalTail->next = head1;
		finalTail = head1;
		head1 = head1->next;
	}
	
	while(head2 != NULL){
		finalTail->next = head2;
		finalTail = head2;
		head2 = head2->next;
	}
	
	return finalHead;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
