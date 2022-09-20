/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    //     ListNode*fast=head;
    //     ListNode*slow=head;
    //     while(fast!=NULL && fast->next!=NULL)
    //     {
    //         fast=fast->next->next;
    //         slow=slow->next;
    //         if(fast==slow)
    //         {
    //             return fast;
    //         }
    //     }
    //     return false;
        unordered_map<ListNode*,int> m;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(m.find(temp)!=m.end())
            {
                return true;
                break;
            }
            else
            {
                m[temp]=temp->val;
            }
            temp=temp->next;
        }
        return false;
     }
        
};