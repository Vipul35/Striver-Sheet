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
    ListNode*reverse(ListNode*head,int left,int right)
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*nextptr;
        while(curr!=NULL && left<=right)
        {
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
            left++;
        }
        head->next=curr;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
        {
            return head;
        }
        if(head==NULL)
        {
            return head;
        }
        int cnt=1;
        ListNode*temp=head;
        ListNode*prev=head;
        ListNode*temp2=new ListNode(-1);
        if(cnt==left)
        {
            temp2->next=reverse(prev,left,right);
            return temp2->next;
        }
        while(cnt<left)
        {
            cnt++;
            prev=temp;
            temp=temp->next;
        }
        prev->next=reverse(prev->next,left,right);
        return head;
    }
};