#include <bits/stdc++.h>
using namespace std;

string trim(string);

int get_ans(int N, int M, int L) {
    const int MOD = 1000000007;
    
    // Edge cases
    if (M > N) return 0;
    if (M == 0) return (L == 1) ? 1 : 0;
    
    // Generate all possible edges
    vector<pair<int, int>> edges;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            edges.push_back({i, j});
        }
    }
    
    int totalEdges = edges.size();
    int validCount = 0;
    
    // Function to check if a set of edges forms a valid graph
    auto isValid = [&](const vector<int>& selectedEdges) -> bool {
        vector<int> degree(N, 0);
        vector<vector<int>> adj(N);
        
        // Build graph and check degree constraint
        for (int idx : selectedEdges) {
            int u = edges[idx].first;
            int v = edges[idx].second;
            degree[u]++;
            degree[v]++;
            if (degree[u] > 2 || degree[v] > 2) return false;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Check connected component sizes
        vector<bool> visited(N, false);
        int maxCompSize = 0;
        
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                int compSize = 0;
                function<void(int)> dfs = [&](int node) {
                    visited[node] = true;
                    compSize++;
                    for (int next : adj[node]) {
                        if (!visited[next]) dfs(next);
                    }
                };
                dfs(i);
                maxCompSize = max(maxCompSize, compSize);
            }
        }
        
        // The maximum component size must be EXACTLY L
        return maxCompSize == L;
    };
    
    // Generate all combinations of M edges
    function<void(int, int, vector<int>&)> generate = 
        [&](int pos, int chosen, vector<int>& current) {
            if (chosen == M) {
                if (isValid(current)) {
                    validCount = (validCount + 1) % MOD;
                }
                return;
            }
            if (pos >= totalEdges || pos + (M - chosen) > totalEdges) return;
            
            // Include current edge
            current.push_back(pos);
            generate(pos + 1, chosen + 1, current);
            current.pop_back();
            
            // Exclude current edge
            generate(pos + 1, chosen, current);
        };
    
    vector<int> current;
    generate(0, 0, current);
    
    return validCount;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string inputline;
    
    getline(cin, inputline);
    int N = stoi(trim(inputline));
    
    getline(cin, inputline);
    int M = stoi(trim(inputline));
    
    getline(cin, inputline);
    int L = stoi(trim(inputline));
    
    int result = get_ans(N, M, L);
    
    cout << result << "\n";
    
    return 0;
}

string trim(string str) {
    if(str.empty())
        return str;
    
    size_t firstScan = str.find_first_not_of(' ');
    size_t first = firstScan == string::npos ? str.length() : firstScan;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last-first+1);
}
