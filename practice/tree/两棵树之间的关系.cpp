
����1: �������������ж��ǲ���һ������

	// �ݹ�
	bool isSameTree(TreeNode* p, TreeNode* q) {
       if (p == NULL || q == NULL) return (p == q);   //��ֹ����
	   // ��ǰֵ������������������������ͬʱ�����Ƿ�����
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
	
	

����2�� һ�����Ƿ�Ϊ��һ�ŵ��ӽṹ���涨������������������ӽṹ
	bool HasSubtree(TreeNode* p1, TreeNode* p2) {
        if(p1==NULL||p2==NULL) return false;
        return Hbtree(p1,p2);
    }
	//�ȱ���P1,֪��ֵ��ͬһ�����
    bool Hbtree(TreeNode* p1, TreeNode* p2){
        if(p2==NULL) return true;
        if(p1==NULL) return false;
        if(p1->val==p2->val){
             if(Hbtree(p1->left,p2->left)&&Hbtree(p1->right,p2->right)) return true;
        }
        return Hbtree(p1->left,p2)||Hbtree(p1->right,p2);    
    }
