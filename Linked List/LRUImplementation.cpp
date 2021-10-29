#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

// First we will create a Doubly Linked List Node class.
class DLLNode{
  public:
    int key;
    int value;
    DLLNode* next;
    DLLNode* prev;
    
    DLLNode(int key , int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache
{
    private:
        // In this private section, we will create the head and tail of the DLL and also create the hashmap.
        DLLNode* head;
        DLLNode* tail;
        
        unordered_map<int , DLLNode*> keyPosition;
        int maxCapacity;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->head = new DLLNode(INT_MAX ,INT_MAX);
        this->tail = new DLLNode(INT_MAX, INT_MAX);
        head->next = tail;
        tail->prev = head;
        
        //keyPosition = new unordered_map<int , DLLNode*>;
        
        this->maxCapacity = cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(keyPosition.find(key) != keyPosition.end()){
            DLLNode* newNode = new DLLNode(key , keyPosition[key]->value);
            // THis means that the given key is present.
            DLLNode* lastPresent = keyPosition[key];
            
            // Now we have to delete this occurence from our cache and add the new occurence.
            lastPresent->prev->next = lastPresent->next;
            lastPresent->next->prev = lastPresent->prev;
            
            lastPresent->next = NULL;
            lastPresent->prev = NULL;
            
            // We also have to delete this node's address from the haspmap.
            keyPosition.erase(key);
            delete lastPresent;
            
            // Now we have to insert the new node next to head.
            newNode->prev = head;
            newNode->next = head->next;
            head->next->prev = newNode;
            head->next = newNode;
            
            keyPosition[key] = newNode;
            
            return newNode->value;
        }
        
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // Whenever a new element enter's the DLL, we need to check 2 things.
        //  1. Is the node available in our cache(using hashmap).
        //  2. If it is not available and whether there is space in our cache or not.
        
        
        DLLNode* newNode = new DLLNode(key , value);
        
        // First lets check if the cache has this element or not.
        if(keyPosition.find(key) != keyPosition.end()){
            // THis means that the given key is present.
            DLLNode* lastPresent = keyPosition[key];
            
            // Now we have to delete this occurence from our cache and add the new occurence.
            lastPresent->prev->next = lastPresent->next;
            lastPresent->next->prev = lastPresent->prev;
            
            lastPresent->next = NULL;
            lastPresent->prev = NULL;
            
            // We also have to delete this node's address from the haspmap.
            keyPosition.erase(key);
            delete lastPresent;
            
            // Now we have to insert the new node next to head.
            newNode->prev = head;
            newNode->next = head->next;
            head->next->prev = newNode;
            head->next = newNode;
            
            keyPosition[key] = newNode;
        }else{
            // If the element is not found.
            // We have to check whether we have space in the cache or not.
            if(keyPosition.size() < this->maxCapacity){
                // Soo we just insert the newNode next to head.
                newNode->prev = head;
                newNode->next = head->next;
                head->next->prev = newNode;
                head->next = newNode;
                
                keyPosition[key] = newNode;
            }else if(keyPosition.size() == this->maxCapacity){
                // We will remove the key value pair next to tail and then insert newNode at the start.
                DLLNode* last = this->tail->prev;
                
                last->prev->next = this->tail;
                tail->prev = last->prev;
                
                last->next = NULL;
                last->prev = NULL;
                
                keyPosition.erase(last->key);
                delete last;
                
                newNode->prev = head;
                newNode->next = head->next;
                head->next->prev = newNode;
                head->next = newNode;
                
                keyPosition[key] = newNode;
                
            }
        } 
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
