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

Node* createLL(){
	Node* head = NULL;
	Node* tail = NULL;
	
	int data;
	cin >> data;
	
	while(data != -1){
		Node *newNode = new Node(data);
		
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		
		tail->next = newNode;
		tail = newNode;
		
		cin >> data;
	}
	return head;
}

// Method 1: A play on the constraints.
// T.C = O(N)
// S.C = O(1)

/*
Since the number of nodes can be in the range 10^4, soo we can easily check for it in 1ms.
*/

bool isLoop(Node* head){
	if(head == NULL || head->next == NULL){
		return false;
	}
	
	// Maximum number of elemnts that can be present.
	int maxCount = 1e4;
	int currCount = 0;
	
	Node* temp = head;
	while(temp != NULL && currCount < maxCount){
		currCount++;
		temp = temp->next;
	}
	
	if(currCount == maxCount){
		return true;
	}
	return false;
}

// Method 2: Using a hashmap to store the address of the nodes.
// T.C = O(N)
// S.C = O(N)
bool isLoop(Node* head){
	if(head == NULL || head->next == NULL){
		return false;
	}
	
	unordered_map<Node* , int> address;
	
	Node* temp = head;
	while(temp != NULL){
		if(address.find(temp) != address.end()){
			return true;
		}
		
		address[temp] = temp->data;
		temp = temp->next;
	}
	
	return false;
}

// Method 3: Using Slow and Fast Pointers.(Floyd’s Cycle-Finding Algorithm)
// T.C : O(N)
// S.C : O(1)
/*
If the slow and fast pointers meet at any point of time , then there is a loop present in the linked list.
*/

bool isLoop(Node* head){
    if(head == NULL || head->next == NULL){
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    	
    while(fast != NULL && fast->next != NULL){
    	slow = slow->next;
    	fast = fast->next->next;
    		
    	if(slow == fast){
    		return true;
    	}
    }
    	
}

int main(){
	Node* head = createLL();
	
	bool isLoop = detectLoop(head);
	if(isLoop){
		cout << "Loop is present" << endl;
	}else{
		cout << "Loop is not present." << endl;
	}
	return 0;
}
