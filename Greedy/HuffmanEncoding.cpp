#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<cstring>
using namespace std;

// Creating the node class for the huffman tree.
class Node{
	public:
		char data;
		int freq;
		Node* left;
		Node* right;
		
		Node(char data, int freq, Node* left = NULL, Node* right = NULL){
			this->data = data;
			this->freq = freq;
			this->left = left;
			this->right = right;
		}
		
		~Node(){
			delete left;
			delete right;
		}
};

// This is the structure to override the comparator function of the priority queue, and this is its correct code.
struct comparator{
	bool operator()(Node* l, Node* r){
		return l->freq > r->freq;
	}
};

Node* createHuffmanTree(unordered_map<char, int> freqMap){
	if(freqMap.size() == 0){
		return NULL;
	}
	
	// Now we need to make a min heap priority queue.
	priority_queue<Node*, vector<Node*>, comparator> pq;
	
	// Now we will insert all the charaters and it's frequencies in the queue.
	for(auto x:freqMap){
		Node* newNode = new Node(x.first, x.second);
		pq.push(newNode);
	}
	
	// This step is to create the final tree.
	while(pq.size() > 1){
		Node* leftChild = pq.top(); pq.pop();
		Node* rightChild = pq.top(); pq.pop();
		
		// We will create it's parent node and have its data as a default character.
		Node* root = new Node('$', leftChild->freq + rightChild->freq, leftChild, rightChild);
		
		pq.push(root);
	}
	
	Node* root = pq.top(); pq.pop();
	
	return root;
}

void preorder(Node* root, string temp, unordered_map<char, string> &encodedChar){
	if(root == NULL){
		return;
	}
	
	if(root->data != '$'){
		encodedChar[root->data] = temp;
	}
	
	preorder(root->left, temp + '0', encodedChar);
	preorder(root->right, temp + '1', encodedChar);
	
	return;
}

int main(){
	string fileStuff;
	getline(cin , fileStuff);
	
	unordered_map<char, int> freqMap;
	
	for(int i = 0; i < fileStuff.size(); i++){
		freqMap[fileStuff[i]]++;
	}
	
	
	//Calling the function to get the huffman tree node.
	Node* root = createHuffmanTree(freqMap);
	
	
	// Once we have the node, we will then get all the respective codes.
	// For that we will do a simple preorder traversal of the tree.
	unordered_map<char, string> encodedChar;
	preorder(root, "", encodedChar);
	
	// Now for printing all the codes.
	for(auto x:encodedChar){
		cout << x.first << " : " << x.second << endl;
	}
	
	return 0;
}
