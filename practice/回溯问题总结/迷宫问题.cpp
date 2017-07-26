����һ����ά����N*M������2<=N<=10;2<=M<=10������5 �� 5��������ʾ�� 

int maze[5][5] = {

        0, 1, 0, 0, 0,

        0, 1, 0, 1, 0,

        0, 0, 0, 0, 0,

        0, 1, 1, 1, 0,

        0, 0, 0, 1, 0,

};

����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ���ڵ�Ϊ[0,0],�ȵ�һ�ո��ǿ����ߵ�·��
Input
һ��N �� M�Ķ�ά���飬��ʾһ���Թ������ݱ�֤��Ψһ��,�������ж�����������Թ�ֻ��һ��ͨ����

#include<iostream>
#include<vector>
using namespace std;
//dfs+backtracing
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<pair<int,int>> res;
void dfs(int x, int y, vector<vector<int>>&map, vector<pair<int, int>>& path) {
	int row = map.size()-1, col = map[0].size()-1;
	map[x][y] = -1; //�����,��ʾ�Ѿ�������
	path.push_back({ x,y });
	//4���������,dfs
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (tx<1 || tx>row || ty<1 || ty>col) continue;
		//��������
		if (tx == row&&ty == col) {
			if (res.size()<path.size())
				res = path;
			return;
		}
		if (map[tx][ty] == 0)
			dfs(tx, ty, map, path);
	}
	path.pop_back();
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		vector<vector<int>> map(m + 1, vector<int>(n + 1, 1));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		}
		vector<pair<int,int>>path;
		dfs(1,1,map, path);
		for (auto i : res)
			cout << "(" << i.first - 1 << "," << i.second - 1 << ")" << endl;
		cout << "(" << m - 1 << "," << n - 1 << ")"<<endl ;
        res.clear();
	}
}