
/*************************************************************
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
***************************************************************/
//�����������·
TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree || (!pRootOfTree->left && !pRootOfTree->right))  return pRootOfTree;
        stack<TreeNode*> st;
        TreeNode* p=pRootOfTree,*last=NULL;
        bool isFirst=true;
        while (p||!st.empty()) {
            if(p) {
				st.push(p);p=p->left;
            }
            else {
            	p=st.top();
            	st.pop();
            	if (isFirst) {
                	pRootOfTree=p;
                	last=pRootOfTree;
                	isFirst=false;
            	}
            	else {
					last->right=p;
                	p->left=last;
                	last=p;
           		 }
           	    p=p->right;
        	}
        }
        return pRootOfTree;
    }