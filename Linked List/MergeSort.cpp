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

Node* merge(Node *head1, Node *head2){
	
    Node *finalHead = NULL;
    Node *finalTail = NULL;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
			if(finalHead == NULL){
                finalHead = head1;
                finalTail = head1;
            }else{
                finalTail->next = head1;
                finalTail = head1;
            }
            head1 =  head1->next;
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


Node *mergeSort(Node *head)
{
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }

	//Write your code here
    Node *part1 = NULL;
    Node *part2 = NULL;
    
    // This is for finding the mid point of the given linked list.
    Node *slow = head;
    Node *fast = head->next;
    
    while(fast != NULL && fast->next != NULL){
		slow = slow->next;
        fast = fast->next->next;
    }
    
    // We will break our linked list in using the slow pointer.
    part2 = slow->next;
    slow->next = NULL;
    part1 = head;
    
    part1 = mergeSort(part1);
    part2 = mergeSort(part2);
    
    Node *finalHead = NULL;
    finalHead = merge(part1, part2);
    return finalHead;
    
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}
