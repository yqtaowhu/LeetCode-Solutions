/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 //����ϸ�ڣ��Ƿ�Ϊ�յ����Ҫ���ǵ�  p->next->next�������
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
       RandomListNode* cur = head;
       RandomListNode* newNode = nullptr;
       if(!cur) return newNode;
       while(cur){
            newNode = new  RandomListNode(0);
            newNode->label = cur->label;
            RandomListNode *nxt = cur->next;
            cur->next = newNode;
            newNode->next  =nxt;
            cur = nxt;
       }
       cur = head;
       while(cur&&cur->next) { 
           cur->next->random = cur->random ? cur->random->next:nullptr;  //ע��randomΪ��
           cur = cur->next->next;
       }
       cur = head;
       newNode = cur->next;
       while (cur&&cur->next) {
		     RandomListNode* nxt = cur->next;
		     cur->next = nxt->next;
		     nxt->next = nxt->next ? nxt->next->next : nullptr;
		cur = cur->next;
	   }
    	return newNode;
    }
};