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
    ListNode*reverse(ListNode*head)
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*nextptr=NULL;
        while(curr!=NULL)
        {
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        ListNode*temp=head;
        while(slow!=NULL)
        {
            if(slow->val!=temp->val)
            {
                return false;
            }
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
};