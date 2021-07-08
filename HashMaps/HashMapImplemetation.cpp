#include<bits/stdc++.h>
#include<cstring>
using namespace std;

// This is the template class that we will use for the node in the bucket array.
template <typename T>
class MapNode{
	public:
		string key;
		T value;
		MapNode *next;
		
		MapNode(string key, T value){
			
			this->key = key;
			this->value = value;
			this->next = NULL;
		}
		
		// Now we will create a destructor which will call itself recrusively to delete every node in the linked list.
		// To do this we will call delete on the next pointer.
		~MapNode(){
			delete next;
		}
};

template typename<T>
class ourMap{
	
	// This is the bucket array.
	// We will initialise it in the constructor.
	MapNode<>** buckets;
	
	// This size is for the number of key value pairs in our map structure.
	int count;
	
	// This is for the size of the bucket array.
	int numBuckets;
	
	int getBucketIndex(string key){
		// First we need to get the hashcode.("Base of p method")
		int hashCode;
		
		// This is the value which is being multiplied with the ASCII value of the current element of the string.
		int currentCoeff = 1;
		for(int i = key.length() - 1; i >= 0; ++i){
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % this->numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff % this->numBuckets;
		}
		
		// This returns the compressed hashCode.(Bucket Index)
		return hashCode % this->numBuckets;
		
	}
	
	public:
		
		ourMap(){
			count = 0;
			numBuckets = 5;
			buckets = new MapNode<T>*[numBuckets];
			
			//Since we can't leave garbage addresses in the bucket array. Soo we initialise it with NULL.
			for(int i = 0; i < numBuckets; ++i){
				this->buckets[i] = NULL;
			}
		}
		
		// This function is to return the size of the Map.
		int size(){
			return count;
		}
		
		
		// We need a function to insert the key value pairs.
		void insert(string key, T value){
			int bucketIndex = getBucketIndex(key);
			
			MapNode<T> *head = buckets[bucketIndex];
			
			// This will check for the key, if present it will update it's value.
			while(head != NULL){
				if(head->key = key){
					head->value = value;
					break;
				}
				
				head = head->next;
			}
			
			// If not present;
			MapNode<T> *head = buckets[bucketIndex];
			
			MapNode<int> *node(key, value);			
			node->next = head;
			buckets[bucketIndex] = node;
			
			++count;			
		}
		
		
		
		
		~ourMap(){
			
			// We will first call delete on the linked list at each index of the bucket.
			for(int i = 0; i < numBuckets; ++i){
				delete this->buckets[i];
			}
			
			// Then finally clear the memory space occupied by the bucket array.
			delete [] buckets;
		}
	
};
