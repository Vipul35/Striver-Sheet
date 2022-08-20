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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,int> m;
        for(int i=0;i<lists.size();i++)
        {
            while(lists[i])
            {
                m[lists[i]->val]++;
                lists[i]=lists[i]->next;
            }
        }
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        for(auto it:m)
        {
            while(it.second)
            {
                temp->next=new ListNode(it.first);
                temp=temp->next;
                it.second--;
            }
        }
        return dummy->next;
    }
};