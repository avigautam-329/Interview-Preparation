#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// First lets create the TrieNode.
class TrieNode{
	public:
		char data;
		TrieNode** children;
		bool isTerminal;
		
		TrieNode(char val){
			this->data = val;
			this->children = new TrieNode*[26];
			for(int i = 0; i < 26; i++){
				this->children[i] = NULL;
			}
			this->isTerminal = false;
		}
};

// Next we need to create a Trie class where we implement all the major functions.
class Trie{
	TrieNode* root;
	int countOfWords;
	
	bool insertWord(TrieNode* currNode, string word){
		
		// Base case.
		if(word.size() == 0){
			if(!currNode->isTerminal){
				currNode->isTerminal = true;
				return true;
			}
			return false;
		}
		
		// Now we need to insert the word in the children array, soo we need to figure out its index first.
		int idx = word[0] - 'a';
		TrieNode* childNode;
		
		if(currNode->children[idx] != NULL){
			childNode = currNode->children[idx];
		}else{
			// If the node doesn't exist, then we have to create one and insert it into the children array.
			childNode = new TrieNode(word[0]);
			currNode->children[idx] = childNode;
		}
		
		// Then we need to recursiely call the function to add the rest of the characters in the tries.
		return insertWord(childNode , word.substr(1));
	}
	
	bool hasChildren(TrieNode* currNode){
		for(int i = 0; i < 26; i++){
			if(currNode->children[i] != NULL){
				return true;
			}
		}
		
		return false;
	}
	
	
	bool searchNode(TrieNode* currNode, string word){
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
		
		return searchNode(currNode->children[idx] , word.substr(1));
	}
	
	TrieNode* searchPatternEnding(TrieNode* currNode, string pattern){
		if(pattern.size() == 0){
			return currNode;
		}
		
		int idx = pattern[0] - 'a';
		TrieNode* childNode;
		if(currNode->children[idx] != NULL){
			childNode = currNode->children[idx];
		}else{
			return NULL;
		}
		
		return searchPatternEnding(childNode, pattern.substr(1));
	}
	
	void printAllPossibleWords(TrieNode* currNode, string completeWord){
		if(currNode->isTerminal){
			// We will print the complete word we have found.
			cout << completeWord << endl;
			if(!this->hasChildren(currNode)){
				return;
			}	
		}

		
		for(int i = 0; i < 26; i++){
			if(currNode->children[i] != NULL){
				printAllPossibleWords(currNode->children[i] , completeWord + currNode->children[i]->data);
			}
		}
		
		return;
	}
	
	public:
		Trie(){
			this->root = new TrieNode('\0');
			this->countOfWords = 0;
		}
		
		// This is the function that is visible to the user and will be used to add a word.
		// We need to create a helperFunction for inserting the word actually.
		void insertWord(string word){
			if(insertWord(this->root , word)){
				this->countOfWords++;
			}
		}
		
		bool searchNode(string word){
			return searchNode(this->root, word);
		}
		
		void autoComplete(vector<string> words, string pattern){
			// First we need to insert the words into the tries.
			for(int i = 0; i < words.size(); i++){
				this->insertWord(words[i]);
			}
			
			// I think the steps are:
			// 1. First search the ending of the pattern in the trie and recieve the address of the end.
			// 2. If the node is a terminal then we will print that pattern as an output as well.
			// 3. Check for all the possible words which are bifercating from the end of the pattern node.
			
			TrieNode* endingNodeAdd = searchPatternEnding(this->root , pattern);
			if(endingNodeAdd == NULL){
				cout << "No such pattern exists." << endl;
				return;
			}
			
			printAllPossibleWords(endingNodeAdd, pattern);
			return;
		}
};

int main(){
	Trie t1;
	
	int n;
	cin >> n;
	
	vector<string> words;
	for(int i = 0; i < n; i++){
		string word;
		cin >> word;
		words.push_back(word);
	}
	
	string pattern;
	cin >> pattern;
	
	t1.autoComplete(words, pattern);
	return 0;
}
