//����õģ�ÿ��Ԫ�س���һ��
//1->1->2 => 1->2 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if(!head||!head->next) return head;
       ListNode* cur=head;
       while(cur){
           ListNode* nxt= cur->next;
           while(nxt&&nxt->val==cur->val) {
               nxt = nxt->next;
           }
            cur->next=nxt;
            cur = cur->next;
       }
       return head;
    }
};
//ɾ�����е��ظ�����
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head||!head->next) return head;
        ListNode preHead(0),*pre=&preHead,*cur=head;
        preHead.next=head;
        while (cur&&cur->next) {
            ListNode *nxt=cur->next;
            if (cur->val==nxt->val) {
                while(nxt&&cur->val==nxt->val) nxt=nxt->next;
                pre->next=nxt;
                cur=nxt;
            }
            else {
                pre=pre->next;
                cur=cur->next;
            }
        }
        return preHead.next;
    }
};