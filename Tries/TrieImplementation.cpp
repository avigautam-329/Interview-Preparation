#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class TrieNode{
	public:
		// Can I use a vector here instead ?
		char data;
		TrieNode **children;
		bool isTerminal;
		
		TrieNode(){
			// Initialize this with NULL as well.
			this->children = new TrieNode*[26];
			for(int i = 0; i < 26; i++){
				this->children[i] = NULL;
			}
			
			this->isTerminal = false;
		}
		
		TrieNode(char data){
			this->data = data;
			
			// Initialize this with NULL as well.
			this->children = new TrieNode*[26];
			for(int i = 0; i < 26; i++){
				this->children[i] = NULL;
			}
			
			this->isTerminal = false;
		}
};

class Trie{
	TrieNode* root;
	
	void insertWord(TrieNode* currNode, string word){
		if(word.size() == 0){
			currNode->isTerminal = true;
			return;
		}
		
		int idx = word[0] - 'a';
		TrieNode* childNode;
		
		// Although we dont need to consider the if part of these statements, we can replace it with root->children[idx] == NULL.
		if(currNode->children[idx] != NULL){
			
			// We have stored the addres of the child in the childNode, as we have to call recursion on it.
			childNode = currNode->children[idx];
		}else{
			childNode = new TrieNode(word[0]);
			currNode->children[idx] = childNode;
		}
		
		insertWord(childNode, word.substr(1));
	}
	
	bool searchWord(TrieNode* currNode, string word){
		if(word.size() == 0){
			if(currNode->isTerminal){
				return true;
			}
			return false;
		}
		
		int idx = word[0] - 'a';
		if(currNode->children[idx] == NULL){
			return false;
		}
		return searchWord(currNode->children[idx] , word.substr(1));
		
	}
	
	void removeWord(TrieNode* currNode, string word){
		if(word.size() == 0){
			currNode->isTerminal = false;
			return;
		}
		
		int idx = word[0] - 'a';
		
		if(currNode->children[idx] == NULL){
			return;
		}
		
		removeWord(currNode->children[idx] , word.substr(1));
		
		if(currNode->isTerminal == false){
			
			// We will check if the node has any children values or not.
			for(int i = 0; i < 26; i++){
				
				// If the current node has a child, then it means that the currNode is stil relevant.
				if(currNode->children[i] != NULL){
					return;
				}
			}
		}
		
		// If the loop goes on till the end.
		delete currNode->children[idx];
		currNode->children[idx] = NULL;
		//return;
	}
	
	public:
		
		// Always remember to initialize boii.
		Trie() {
			this->root = new TrieNode('\0');
		}
		void insertWord(string word){
			insertWord(this->root , word);
		}
		
		bool searchWord(string word){
			return searchWord(this->root , word);
		}
		
		void removeWord(string word){
			removeWord(this->root, word);
		}
};

int main(){
	
	Trie dict;
	dict.insertWord("and");
	dict.insertWord("are");
	dict.insertWord("bed");
	
	cout << dict.searchWord("are") << endl;
	
	dict.removeWord("are");
	cout << dict.searchWord("are") << endl;
	return 0;
}
