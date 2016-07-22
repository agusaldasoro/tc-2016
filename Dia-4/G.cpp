#include <vector>
#include <iostream>
#include <set>
#include <stack>
using namespace std;

int main(){
	
	int n;
	int caseNumber = 0;
	while(cin >> n){
		caseNumber++;
		if(n == 0)break;
		vector<vector<int> > adjList(2*n+1);
		for(int i = 0; i < n; ++i){
			int x, y;
			cin >> x >> y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		
		int raiz = 1;
		vector<int> low(2*n+1, -1);
		vector<int> depth(2*n+1, -1);
		stack<int> dfsStack;
		stack<pair<int,int>> edgeStack;
		vector<set<int>> componentesBiconexas;
		vector<int> mark(2*n+1, 0);
		vector<bool> articulationPoint(2*n+1, false);
		if(adjList[raiz].size() > 1){
			articulationPoint[raiz] = true;
		} 
		depth[raiz] = 0;
		low[raiz] = 0;
		dfsStack.push(raiz);
		vector<bool> pushed(2*n, false);
		pushed[raiz] = true;
		while(!dfsStack.empty()){
			auto father = dfsStack.top();

			mark[father] = 1;
			low[father] = depth[father];
			for(auto node : adjList[father]){
				if(!pushed[node]){
					dfsStack.push(node);
					depth[node] = depth[father] + 1;
					pushed[node] = true;
				}
				if(mark[node] == 1){
					if(low[father] > low[node]){
						low[father] = low[node];
					}
				}
				if(low[node] >= depth[father] ){
					articulationPoint[father] = true;
				}
			}
			if(father == dfsStack.top()){
				mark[father] = 2;
				set<int> biconexMember;
				dfsStack.pop();
				if(father != raiz){
					int otherPoint = dfsStack.top();
					if(low[father] >= depth[otherPoint]){
						while(!edgeStack.empty() && edgeStack.top() != make_pair(otherPoint, father)){
							auto a = edgeStack.top();
							biconexMember.insert(a.first);
							biconexMember.insert(a.second);
							edgeStack.pop();
						}
						edgeStack.pop();
						componentesBiconexas.push_back(biconexMember);
						cout << biconexMember.size() << endl;
					}
				}else{
					break;
				}

				
			}else{
				edgeStack.push(make_pair(father, dfsStack.top()));
			}
			
		}
		cout << "Case " << caseNumber << ": ";
		int k = 0;
		int acum = 1;
		
		int cantidadDeEscapes =  componentesBiconexas.size();
		cout << cantidadDeEscapes << endl;
		for(auto componente : componentesBiconexas){
			int count = 0;
			for(auto v : componente){ 
				if(articulationPoint[v]){
					count++;
				}
			}
			if(componente.size() - count != 0){
				acum *= componente.size() - count;
			} else{
				cantidadDeEscapes--;
			}
		}
		cout << cantidadDeEscapes << " " << acum << endl;
	}
}
