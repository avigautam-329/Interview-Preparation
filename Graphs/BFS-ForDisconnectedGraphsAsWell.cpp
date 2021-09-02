#include<iostream>
#include<queue>
using namespace std;

void bfsHelper(int **edges, int noOfVertices, int startIdx, bool *visited){
	queue<int> pendingVertices;
	pendingVertices.push(startIdx);
	
	visited[startIdx] = true;
	
	while(!pendingVertices.empty()){
		int currVertex = pendingVertices.front();
		pendingVertices.pop();
		
		cout << currVertex << " ";
		
		for(int i = 0; i < noOfVertices; i++){
			if(edges[currVertex][i] == 1){
				if(!visited[i]){
					pendingVertices.push(i);
					visited[i] = true;
				}
			}
		}
	}
}

void bfs(int **edges, int noOfVertices){
	bool *visited = new bool[noOfVertices];
	for(int i = 0; i < noOfVertices; i++){
		visited[i] = false;
	}
	
	for(int i = 0; i < noOfVertices; i++){
		if(!visited[i]){
			bfsHelper(edges, noOfVertices, i , visited);
		}
	}
}

int main(){
	int noOfVertices, noOfEdges;
	cin >> noOfVertices >> noOfEdges;
	
	int **edges = new int*[noOfVertices];
	for(int i = 0; i < noOfVertices; i++){
		edges[i] = new int[noOfVertices];
		for(int j = 0; j < noOfVertices; j++){
			edges[i][j] = 0;
		}
	}
	
	for(int i = 0; i < noOfEdges; i++){
		int srcNode, dstNode;
		cin >> srcNode >> dstNode;
		edges[srcNode][dstNode] = 1;
		edges[dstNode][srcNode] = 1;
	}
	
	bfs(edges , noOfVertices);
	
	return 0;
}
