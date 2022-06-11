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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if(head1==NULL || head2==NULL)
        {
            return NULL;
        }
        if(head1==head2)
        {
            return head1;
        }
        int len1=0;
        int len2=0;
        ListNode*pointer1=head1;
        ListNode*pointer2=head2;
        while(pointer1!=NULL)
        {
            len1++;
            pointer1=pointer1->next;
        }
        while(pointer2!=NULL)
        {
            len2++;
            pointer2=pointer2->next;
        }
        int diff=abs(len1-len2);
        if(len1>len2)
        {
            while(diff)
            {
                diff--;
                head1=head1->next;
            }
        }
        else
        {
            while(diff)
            {
                diff--;
                head2=head2->next;
            }
        }
        while(head1!=NULL && head2!=NULL)
        {
            if(head1==head2)
            {
                return head1;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return NULL;
    }
};