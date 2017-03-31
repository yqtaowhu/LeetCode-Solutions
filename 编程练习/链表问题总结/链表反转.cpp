#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {

	}
};
// һ��Ҫ��ס����������������������������������������������
ListNode* reverseList(ListNode* head) {
	if (!head) return nullptr;
	ListNode preHead(0), *pre = &preHead;
	pre->next = head;
	ListNode* cur = head;
	while (cur->next) {
		ListNode* nxt = cur->next;
		cur->next = nxt->next;
		nxt->next = pre->next;
		pre->next = nxt;         //һ����Ҫ�����
	}
	return preHead.next;
}
int main() {
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(4);
	ListNode* p5 = new ListNode(5);
	p1->next = p2; p2->next = p3; p3->next = p4; p4->next = p5;
	ListNode* tmp = p1;
	while (tmp) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
	ListNode* n = reverseList(p1);
	while (n) {
		cout << n->val << " ";
		n = n->next;
	}
	cout << endl;
	return 0;
}
//��תm-n������ͬ����ǳ�������
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n) return head;
        ListNode preHead(0),*pre=&preHead;
        preHead.next=head;
        for (int i=0;i<m-1;i++)
            pre=pre->next;
        ListNode *cur=pre->next;
        for (int i=0;i<n-m;i++) {
            ListNode *nxt=cur->next;
            cur->next=nxt->next;
            nxt->next=pre->next;
            pre->next=nxt;
        }
        return preHead.next;
   
    }
};