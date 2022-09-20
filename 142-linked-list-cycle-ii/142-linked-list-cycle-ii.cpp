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
    ListNode *detectCycle(ListNode *head) {
      //   if(head==NULL || head->next==NULL)
      //   {
      //       return NULL;
      //   }
      // ListNode*fast=head;
      //   ListNode*slow=head;
      //   bool cycle=false;
      //   while(fast!=NULL && fast->next!=NULL)
      //   {
      //       fast=fast->next->next;
      //       slow=slow->next;
      //       if(fast==slow)
      //       {
      //           cycle=true;
      //           break;
      //       }
      //   }
      //   if(cycle==false)
      //   {
      //       return NULL;
      //   }
      //   slow=head;
      //   while(slow!=fast)
      //   {
      //       slow=slow->next;
      //       fast=fast->next;
      //   }
      //   return slow;
        unordered_map<ListNode*,int> s;
        ListNode*temp=head;
        int i=0;
        while(temp!=NULL)
        {
            if(s.find(temp)!=s.end())
            {
                return temp;
                break;
            }
            else
            {
                s[temp]=i;
            }
            temp=temp->next;
            i++;
        }
        return NULL;
    }
};