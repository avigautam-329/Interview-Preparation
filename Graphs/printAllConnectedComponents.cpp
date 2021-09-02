#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int>* bfs(int **graph, int v, int srcNode, bool *visited){
	queue<int> pendingVertices;
	pendingVertices.push(srcNode);
	visited[srcNode] = true;
	
	vector<int>* res = new vector<int>;
	res->push_back(srcNode);
	
	while(!pendingVertices.empty()){
		int currVertex = pendingVertices.front();
		pendingVertices.pop();
		
		for(int i = 0; i < v; i++){
			if(graph[currVertex][i] == 1 && !visited[i]){
				pendingVertices.push(i);
				res->push_back(i);
				visited[i] = true;
			}
		}
	}
	
	return res;
}

int main(){
	int v , e;
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
	
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}
	
	vector<vector<int>*> allComponents;
	for(int i = 0 ; i < v; i++){
		if(!visited[i]){
			allComponents.push_back(bfs(graph , v , i, visited));
			sort(allComponents.at(allComponents.size() - 1)->begin(), allComponents.at(allComponents.size() - 1)->end());
			for(int i = 0; i < allComponents.at(allComponents.size() - 1)->size(); i++){
				cout << allComponents.at(allComponents.size() - 1)->at(i) << " ";
			}
			cout << endl;	
		}
	}
	
	for(int i = 0; i < v; i++){
		if(!visited[i]){
			cout << i << endl;
		}
	}
	
	return 0;
}
