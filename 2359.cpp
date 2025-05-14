class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int sz = edges.size();
        vector<vector<int>> adj(sz);
        for(int i = 0;i<sz;++i){
            if(edges[i] != -1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> dist1(sz);
        vector<int> dist2(sz);
        queue<int> q;
        
        for(int i = 0;i<sz;++i){
            dist1[i] = -1;
        }
        q.push(node1);
        dist1[node1] = 0;
        while(!q.empty()){
            int cur_node = q.front();
            int cur_distance = dist1[cur_node];
            for(int i = 0;i<adj[cur_node].size();++i){
                if(dist1[adj[cur_node][i]] == -1){
                    dist1[adj[cur_node][i]] = cur_distance + 1;
                    q.push(adj[cur_node][i]);
                }
            }
            q.pop();
        }

        for(int i = 0;i<sz;++i){
            dist2[i] = -1;
        }
        q.push(node2);
        dist2[node2] = 0;
        while(!q.empty()){
            int cur_node = q.front();
            int cur_distance = dist2[cur_node];
            for(int i = 0;i<adj[cur_node].size();++i){
                if(dist2[adj[cur_node][i]] == -1){
                    dist2[adj[cur_node][i]] = cur_distance + 1;
                    q.push(adj[cur_node][i]);
                }
            }
            q.pop();
        }
        int mindist = 2*sz;
        int ans = -1;
        for(int i = 0;i<sz;++i){
            if(mindist>max(dist1[i], dist2[i]) && dist1[i]!=-1 && dist2[i]!=-1){
                ans = i;
                mindist = max(dist1[i], dist2[i]);
            }
        }
        return ans;
    }
};
