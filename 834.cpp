class Solution {
public:
    int calc_size(std::vector<int>& num_of_nodes, vector<vector<int>> adj, int node, int parent_node){
        if(adj[node].size() == 1 && node!=0){
            num_of_nodes[node] = 1;
            return 1;
        }
        else{
            int num = 0;
            for(int i = 0;i<adj[node].size();++i){
                if(adj[node][i] != parent_node){
                    num+=calc_size(num_of_nodes, adj, adj[node][i], node);
                }              
            }
            num_of_nodes[node] = num + 1;
            return num + 1;  
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        std::vector<int> num_of_nodes(n);
        vector<vector<int>> adj(n);
        for(int i = 0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        calc_size(num_of_nodes, adj, 0, -1);
        for(int i = 0;i<num_of_nodes.size();++i){
            std::cout<<i<<" "<<num_of_nodes[i]<<"\n";
        }
        
        return {0};
    }
};
