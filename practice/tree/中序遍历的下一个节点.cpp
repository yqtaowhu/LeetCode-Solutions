/****************************************************************************
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
********************************************************************************/

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
         TreeLinkNode *p=pNode;
        if (pNode->right) {               //��ǰ�ڵ���������
            p=pNode->right;
            while (p->left) p=p->left;
            return p;
        }
        else {                            //û�������������ϲ���
			p=pNode->next;
            while (p) {
             	if (p->left==pNode) return p;  
                else {
                    pNode=p;
                    p=p->next;
                }
            }
            return nullptr;
        }
    }