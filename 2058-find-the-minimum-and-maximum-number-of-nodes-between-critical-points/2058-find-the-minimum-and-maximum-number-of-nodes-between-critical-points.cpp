/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {INT_MAX, 0};
      
        int firstCriticalIndex = -1;
        int lastCriticalIndex = -1;
      
        for (int currentIndex = 0; head->next->next != nullptr; head = head->next, ++currentIndex) {
            int previousValue = head->val;
            int currentValue = head->next->val;
            int nextValue = head->next->next->val;
          
            bool isLocalMinimum = (currentValue < previousValue && currentValue < nextValue);
            bool isLocalMaximum = (currentValue > previousValue && currentValue > nextValue);
          
            if (isLocalMinimum || isLocalMaximum) {
                if (lastCriticalIndex == -1) {
                    firstCriticalIndex = currentIndex;
                    lastCriticalIndex = currentIndex;
                } else {
                    result[0] = min(result[0], currentIndex - lastCriticalIndex);
                  
                    lastCriticalIndex = currentIndex;
                  
                    result[1] = max(result[1], lastCriticalIndex - firstCriticalIndex);
                }
            }
        }
      
       
        if (firstCriticalIndex == lastCriticalIndex) {
            return vector<int>{-1, -1};
        }
      
        return result;
    }
};
