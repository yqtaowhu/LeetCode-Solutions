
//������תkλ
/*
	��ĩβ��ͷ����
	�����µ�ͷ���
	����ĩβ����
*/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
       if (!head||k<=0) return head;
       ListNode *p=head;int len=1;
       while (p->next) {     //count the length
           len++;            
           p=p->next;        //notice:p is the last node ,but not NULL
       }
       p->next=head;
       k=len-k%len; //find the new head
       for (int i=0;i<k;i++) 
           p=p->next;
        head=p->next;
        p->next=NULL;
        return head;
    }
};