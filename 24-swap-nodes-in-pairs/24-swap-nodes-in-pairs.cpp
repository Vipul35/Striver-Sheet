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
    ListNode* swapPairs(ListNode* head) {
         ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*nextptr=NULL;
        ListNode*nexthead=head;
        int k=2;
        for(int i=0;i<k;i++)
        {
            if(nexthead==NULL)
            {
                return head;
            }
            nexthead=nexthead->next;
        }
        int cnt=0;
        while(curr!=NULL && cnt<k)
        {
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
            cnt++;
        }
        if(nextptr!=NULL)
        {
            head->next=swapPairs(nextptr);
        }
        return prev;
    }
};