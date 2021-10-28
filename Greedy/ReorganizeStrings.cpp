/*
Given a string with repeated characters, the task is to rearrange characters in a string so that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.

if possible -> print 1.
if not possible -> print 0.
*/


#include <iostream>
#include <cstring>
#include <unordered_map>
#include <queue>
using namespace std;

class keyChar{
  public:
    char x;
    int count;
};

struct comparator{
    bool operator()(keyChar* a, keyChar* b){
        return a->count < b->count;
    }
};

string getRearrangedString(string word){
    // First step is to find the frequencies of the characters.
    unordered_map<char , int> freq;
    
    for(int i = 0; i < word.size(); i++){
        freq[word[i]]++;
    }
    
    // Next is to build the max priority queue.
    priority_queue<keyChar*, vector<keyChar*>, comparator> pq;
    for(auto x:freq){
        keyChar *temp = new keyChar;
        temp->x = x.first;
        temp->count = x.second;
        
        pq.push(temp);
    }
    
    string res = "";
    
    while(pq.size() > 1){
        keyChar* current = pq.top(); pq.pop();
        keyChar* next = pq.top(); pq.pop();
        
        //cout << current->count << " " << next->count << endl;
        
        res += current->x;
        res += next->x;
        
        current->count = current->count - 1;
        next->count = next->count - 1;
        
        //cout << current->count << " " << next->count << endl;
        
        if(current->count > 0){
            pq.push(current);
        }
        
        if(next->count > 0){
            pq.push(next);
        }
    }
    
    if(!pq.empty()){
        if(pq.size() == 1){
            if(pq.top()->count > 1){
                return "0";
            }else if(pq.top()->count == 1){
                return "1";
            }
        }else{
            return "0"; 
        }
    }
    return "1";
}


int main() {
	int t;
	cin >> t;
	
	while(t--){
		string word;
		cin >> word;
	    
	    string res = getRearrangedString(word);
	    
	    cout << res << endl;
	    
	}
	return 0;
}
