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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
        {
            return head;
        }
        ListNode*temp=head;
        ListNode*curr=head;
        int cnt=0;
        ListNode*prev=NULL;
        while(curr!=NULL)
        {
            curr=curr->next;
            cnt++;
        }
        k=(k%cnt);
        while(k--)
        {   
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
            temp->next=head;
            head=prev->next;
            prev->next=NULL;
            
        }
        return temp;
    }
};