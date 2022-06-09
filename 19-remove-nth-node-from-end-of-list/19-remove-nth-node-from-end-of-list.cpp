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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        if(cnt==n)
        {
            return head->next;
        }
        int x=cnt-n;
        int cnt2=0;
        ListNode*temp2=head;
        ListNode*prev=NULL;
        while(x-- && temp2!=NULL)
        {
            prev=temp2;
            temp2=temp2->next;
            cnt2++;
        }
        prev->next=temp2->next;
        delete(temp2);
        return head;
    }
};