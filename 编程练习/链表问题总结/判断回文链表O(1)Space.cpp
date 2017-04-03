class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode preHead(0),*pre=&preHead,*cur=head;
        pre->next=head;
        while(cur->next) {
            ListNode* nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return preHead.next;
    }
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode* mid = findMid(head);              //�ҵ��е�
        ListNode* cur = reverse(mid);				//��ת�����
        while(cur) {								//�Ƚ�
            if(cur->val!=head->val)
                return false;
            cur=cur->next;
            head=head->next;
        }
        return true;
    }
};