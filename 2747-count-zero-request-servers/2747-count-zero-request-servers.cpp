class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
      
        int numQueries = queries.size();
      
        vector<pair<int, int>> queryPairs(numQueries);
        for (int i = 0; i < numQueries; ++i) {
            queryPairs[i] = {queries[i], i};
        }
      
        sort(queryPairs.begin(), queryPairs.end());
      
        unordered_map<int, int> serverRequestCount;
      
        vector<int> result(numQueries);
      
        int leftPointer = 0;   
        int rightPointer = 0;  
      
        for (auto& [queryTime, originalIndex] : queryPairs) {
            int windowStart = queryTime - x;
          
            while (rightPointer < logs.size() && logs[rightPointer][1] <= queryTime) {
                int serverId = logs[rightPointer][0];
                ++serverRequestCount[serverId];
                ++rightPointer;
            }
          
            while (leftPointer < logs.size() && logs[leftPointer][1] < windowStart) {
                int serverId = logs[leftPointer][0];
                --serverRequestCount[serverId];
              
                if (serverRequestCount[serverId] == 0) {
                    serverRequestCount.erase(serverId);
                }
                ++leftPointer;
            }
          
            result[originalIndex] = n - serverRequestCount.size();
        }
      
        return result;
    }
};
