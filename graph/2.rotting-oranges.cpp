#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int orangesRotting(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    queue<pair<int,int>> que;
    int cnt=0;   //新鲜橘子的数量
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(grid[i][j]==1) cnt++;
            else if(grid[i][j]==2) que.push(pair<int,int>{i,j});
        }
    }

    int round=0;  //round表示橘子腐烂的轮数，或者分钟数
    while(cnt>0&&(!que.empty())){
        round++;
        int sz=que.size();
        for(int i=0;i<sz;++i){
            pair<int,int> cur=que.front(); que.pop();
            
            for(int j=0;j<4;++j){
                int r=cur.first+dir[j][0];
                int c=cur.second+dir[j][1];
                if(r>=0&&r<m&&c>=0&&c<n){
                    if(grid[r][c]==1){
                        cnt--;
                        grid[r][c]=2;
                        que.push(pair<int,int>{r,c});
                    }
                }
            }
        }
    }
    if(cnt>0) return -1;
    return round;
}

int main(){
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,1}};
    int ans=orangesRotting(grid);
    cout<<ans<<endl;
    return 0;
}