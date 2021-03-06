#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 15;
const int mazeMax = 150;
int n,m;
bool visite[maxn][maxn];
string maze[maxn];
struct Node
{
    int x,y;
    int step;
    Node():step(0){}
    void insert(int a,int b) {x=a;y=b;step=0;}
};
int NumberSize[2];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int totol,Min;
Node save[2][mazeMax]; 

bool jude(Node A)
{
    return (A.x>=0&&A.x<n&&A.y>=0&&A.y<m&&maze[A.x][A.y]=='#'&&(!visite[A.x][A.y]));
}

void bfs(Node a,Node b,int statu,int index)
{
    int cnt = 0,Step = 0;
    Node now,next;
    if(statu) NumberSize[index] = 0;
    queue<Node> List;
    List.push(a);
    if(statu==0) List.push(b);
    while(!List.empty())
    {
        now = List.front();
        List.pop();
        if(!jude(now)) continue;
        if(statu) save[index][cnt] = now,NumberSize[index]++;
        cnt++;
        visite[now.x][now.y] = 1;
        for(int i=0; i<4; i++)
        {
            next.y = now.y + dir[i][0];
            next.x = now.x + dir[i][1];
            if(statu==0) next.step = now.step + 1;
            List.push(next);
        }
        Step = now.step;
    }
    if(statu) totol+=cnt;
    else if(totol==cnt) Min = min(Min,Step);
}




int FindWay()
{
    int cnt=0;
    Node a,b;
    memset(visite,0,sizeof(visite));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(maze[i][j]=='#'&&!visite[i][j])
            {
                if(cnt==2) return -1;
                a.insert(i,j);
                bfs(a,b,1,cnt);
                cnt++;
            }

        }
    return cnt;
}

int main()
{
    int T,cnt=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(NumberSize,0,sizeof(NumberSize));
        totol = 0;
        Min = INT_MAX;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++) cin >> maze[i]; 
        int flag = FindWay();
        printf("Case %d: ",++cnt);
        if(flag == -1) printf("-1\n");
        else
        { 
            if(totol <= 2) Min = 0;
            else if(flag == 2)
            {
                int end1 = NumberSize[0],end2=NumberSize[1];
                for(int i=0; i<end1; i++)
                    for(int j=0; j<end2;j++)
                    {
                        memset(visite,0,sizeof(visite));
                        bfs(save[0][i],save[1][j],0,0);
                    }
            }
            else 
            {
                int end1 = NumberSize[0];
                for(int i=0; i<end1; i++)
                    for(int j=i+1; j<end1; j++)
                    {
                        memset(visite,0,sizeof(visite));
                        bfs(save[0][i],save[0][j],0,0);
                    }
            }
            printf("%d\n",Min); 
        }
    }
    return 0;
}
