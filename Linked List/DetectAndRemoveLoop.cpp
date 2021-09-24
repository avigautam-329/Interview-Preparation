#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};

// Function to detect and delete a loop.

// Method 1: Using hashing.
Node* removeLoop(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	unordered_map<Node* , int> elemPos;
	
	Node* prev = head;
	
	
	Node* temp = head->next;
	while(temp != NULL){
		
		elemPos[prev] = prev->data;
		if(elemPos.find(temp) != elemPos.end()){
			prev->next = NULL;
			return head;
		}
		
		prev = temp;
		temp = temp->next;
	}
	
	return head;
}


// Method 2: Using flyod's cycle detection algorithm.
// T.C = O(N)
// S.C = O(1)
Node* removeLoop(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	Node* slow = head;
	Node* fast = head;
	
	// Detect if there is a cycle or not.
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		
		
		// If this condition hits, it means that the pointers are now pointing to a node which is present in the loop.
		if(slow == fast){
			break;
		}
	}
	
	// Now we have to check for 1 condition.
	// Which is , is our low pointer pointing to the head pointer or not.
	if(low == head){
		// In this case, we can just move the fast pointer forward by one and check each time if it's next is pointing to low or not.
		while(fast->next != low){
			fast = fast->next;
		}
		
		fast->next == NULL;
	}else if(slow == fast){
		// In this case , we will place a pointer at temp and move the temp and fast pointer ahead by 1.
		// Each time checking if it's next is pointing towards the same node or not.
		
		Node* temp = head;
		while(temp->next != fast->next){
			temp = temp->next;
			fast = fast->next;
		}
		
		fast->next = NULL;
	}
	return head;
}


// To take the input.
Node* createLL(int k){
	int data;
	cin >> data;
	
	Node* head = NULL;
	Node* tail = NULL;
	
	while(data != -1){
		Node* newNode = new Node(data);
		
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		
		tail->next = newNode;
		tail = newNode;
		
		cin >> data;
	}
	

	// To create a loop in the linked list.
	if(k != 0){
		int cnt = 0;
		Node *temp = head;
		while(cnt < k){
			cnt++;
			temp = temp->next;
		}
		
		tail->next = temp;	
	}

	return head;
}

int main(){

	// Position for looping in Linked list.
	int n;
	cin >> n;
	
	Node* head = createLL(n);
	
	// Function to detect and remove the loop in the linked list.
	head = removeLoop(head);
	
	Node* temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return 0;
}
