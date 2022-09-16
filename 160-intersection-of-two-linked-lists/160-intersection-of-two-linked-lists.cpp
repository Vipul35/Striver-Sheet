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
        ListNode*temp=head1;
        ListNode*temp2=head2;
        int len1=0;
        int len2=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            len1++;
        }
        while(temp2!=NULL)
        {
            temp2=temp2->next;
            len2++;
        }
        ListNode*list1=head1;
        ListNode*list2=head2;
        if(len2>len1)
        {
            int n=len2-len1;
            while(n--)
            {
                list2=list2->next;
            }
        }
        else
        {
            int n=len1-len2;
            while(n--)
            {
                list1=list1->next;
            }
        }
        while(list1!=NULL && list2!=NULL)
        {
            if(list1==list2)
            {
                return list1;
                break;
            }
            list1=list1->next;
            list2=list2->next;
        }
        return NULL;
    }
};