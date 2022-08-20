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
    ListNode*merge(ListNode*lists1,ListNode*lists2)
    {
        ListNode*head1=lists1;
        ListNode*head2=lists2;
        ListNode*temp2=new ListNode(-1);
        ListNode*temp=temp2;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val>=head2->val)
            {
                temp->next=head2;
                temp=temp->next;
                head2=head2->next;
            }
            else
            {
                temp->next=head1;
                temp=temp->next;
                head1=head1->next;
            }
        }
        while(head1!=NULL)
        {
            temp->next=head1;
            temp=temp->next;
            head1=head1->next;
        }
        while(head2!=NULL)
        {
            temp->next=head2;
            temp=temp->next;
            head2=head2->next;
        }
        return temp2->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        {
            return NULL;
        }
        if(lists.size()==1)
        {
            return lists[0];
        }
        for(int i=1;i<lists.size();i++)
        {
            lists[0]=merge(lists[0],lists[i]);
        }
        return lists[0];
    }
};