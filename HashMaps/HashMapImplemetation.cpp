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

template <typename T>
class ourMap{
	
	// This is the bucket array.
	// We will initialise it in the constructor.
	MapNode<T>** buckets;
	
	// This size is for the number of key value pairs in our map structure.
	int count;
	
	// This is for the size of the bucket array.
	int numBuckets;
	
	int getBucketIndex(string key){
		// First we need to get the hashcode.("Base of p method")
		int hashCode = 0;
		
		// This is the value which is being multiplied with the ASCII value of the current element of the string.
		int currentCoeff = 1;
		for(int i = key.length() - 1; i >= 0; --i){
			hashCode += (key[i] * currentCoeff);
			hashCode = hashCode % this->numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff % this->numBuckets;
		}
		
		// This returns the compressed hashCode.(Bucket Index)
		return hashCode % this->numBuckets;
		
	}
	
	// We will create a new nucket array of twice the size and assign all the keys again.
	void rehash(){
		
		MapNode<T> **temp = buckets;
		
		// Now we can assign the new array to the buckets.
		this->buckets = new MapNode<T>*[2 * this->numBuckets];
		for(int i = 0; i < 2 * this->numBuckets; ++i){
			buckets[i] = NULL;
		}
		
		int oldBucketsCount = this->numBuckets;
		this->numBuckets *= 2;
		
		//Initialize the count back to zero.
		this->count = 0;
		
		// Now we will traverse the old bucket list by list and assign each key to the new bucket again.
		
		for(int j = 0 ; j < oldBucketsCount; ++j){
			MapNode<T> *head = temp[j];
			while(head != NULL){
				
				string key = head->key;
				T value = head->value;
				
				this->insert(key, value);
				
				head = head->next;
			}
		}
		
		// Once we have copied all the new elements, then we can delete the old array pointed by temp.
		for(int i = 0 ; i < oldBucketsCount; ++i){
			MapNode<T> *head = temp[i];
			delete head;
		}
		
		delete [] temp;
		
	}
	
	public:
		
		ourMap(){
			this->count = 0;
			this->numBuckets = 5;
			this->buckets = new MapNode<T>*[numBuckets];
			
			//Since we can't leave garbage addresses in the bucket array. Soo we initialise it with NULL.
			for(int i = 0; i < numBuckets; ++i){
				this->buckets[i] = NULL;
			}
		}
		
		// This function is to return the size of the Map.
		int size(){
			return this->count;
		}
		
		
		// We need a function to insert the key value pairs.
		void insert(string key, T value){
			
			int bucketIndex = getBucketIndex(key);
			
			MapNode<T> *head = buckets[bucketIndex];
			
			// This will check for the key, if present it will update it's value.
			while(head != NULL){
				if(head->key == key){
					head->value = value;
					break;
				}
				
				head = head->next;
			}
			
			// If not present;
			head = buckets[bucketIndex];
			
			MapNode<int> *node = new MapNode<T>(key, value);
			
			node->next = head;
			buckets[bucketIndex] = node;
			
			++count;
			
			double loadFactor = (1.0 * this->count)/ this->numBuckets;
			if(loadFactor > 0.7){
				this->rehash();
			}			
		}
		
		T remove(string key){
			
			int bucketIndex = getBucketIndex(key);
			
			// Create the node's which we are going to use.
			MapNode<T> *prev = NULL;
			MapNode<T> *head = buckets[bucketIndex];
			
			while(head != NULL){
				if(head->key == key){
					
					// In this inner if statement we check wether the key is at the start of LL or not.
					if(prev == NULL){
						buckets[bucketIndex] = head->next;
					}else{
						prev->next = head->next;
					}
					
					T value = head->value;
					head->next = NULL;
					delete head;
					count--;
					return value;
				}
				prev = head;
				head = head->next;
			}
			
			// If the element was not found.
			return 0;
			
		}
		
		T getValue(string key){
			
			int bucketIndex = getBucketIndex(key);
			MapNode<int> *head = this->buckets[bucketIndex];
			
			while(head != NULL){
				if(head->key == key){
					return head->value;
				}
				head = head->next;
			}
			return -1;
		}
		
		// To print the load Factor at any point.
		double getLoadFactor(){
			return (1.0 * this->count)/ this->numBuckets;
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


int main(){
	
	ourMap<int> myMap;
	
	// To create the keys and values to be inserted and insert them in the process.
	// Print the load factor after each insertion.
	for(int i = 0; i < 10; ++i){
		
		// This part is to create a key.
		char c = '0' + i;
		string key = "abc";
		key = key + c;
		
		// For value
		int value = i + 1;
		myMap.insert(key,value);
		cout << myMap.getLoadFactor() << endl;
	}
	
	cout << myMap.size() << endl;
	
	myMap.remove("abc2");
	myMap.remove("abc7");
	
	cout << "Now the size has become: " << myMap.size() << endl;
	
	for(int i = 0 ; i < 10; ++i){
		char c = '0' + i;
		string key = "abc";
		key = key + c;
		
		cout << key << " : " << myMap.getValue(key) << endl;
	}
	
	cout << "The final size is: " << myMap.size() << endl;
	return 0; 
}
