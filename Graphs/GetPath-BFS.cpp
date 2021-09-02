#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int>* bfs(int **graph, int v , int srcNode, int dstNode){
	// First step is to create the visited array.
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}
	
	// Now we will create the queue and also add the srcNode into it and mark it as visited.
	queue<int> pendingVertices;
	pendingVertices.push(srcNode);
	visited[srcNode] = true;
	
	// Now in order we can trace back the path, we will use an unordered map.
	unordered_map<int , int> pathTracing;
	
	// We will create a vector as well to put the nodes into if we find a path.
	vector<int> *res = NULL;
	
	while(!pendingVertices.empty()){
		int currVertex = pendingVertices.front();
		pendingVertices.pop();
		
		for(int i = 0; i < v; i++){
			if(graph[currVertex][i] == 1 && !visited[i]){
				// Now as i was inserted into the queue because of currVertex, soo, we shall put this information into our map.
				pathTracing[i] = currVertex;
				pendingVertices.push(i);
				visited[i] = true;
				
				// We also have to check whether i is equal to the dstNode or not.
				if(i == dstNode){
					// We should retrace the path to the startVertex.
					res = new vector<int>;
					int current = dstNode;
                    res->push_back(current);
					while(current != srcNode){
						
						current = pathTracing[current];
                        res->push_back(current);
					}
					return res;
				}
			}
		}
	}
	
	return res;
}


int main(){
	int v, e;
	cin >> v >> e;
	
	int **graph = new int*[v];
	for(int i = 0; i < v; i++){
		graph[i] = new int[v];
		for(int j = 0; j < v; j++){
			graph[i][j] = 0;
		}
	}
	
	for(int i = 0; i < e; i++){
		int srcNode, dstNode;
		cin >> srcNode >> dstNode;
		graph[srcNode][dstNode] = 1;
		graph[dstNode][srcNode] = 1;
	}
	
	int srcVertex , endVertex;
	cin >> srcVertex >> endVertex;
	
	vector<int> *res = bfs(graph, v , srcVertex , endVertex);
	if(res != NULL){
		for(int i = 0; i < res->size(); i++){
			cout << res->at(i) << " ";
		}
	}
	return 0;
}
