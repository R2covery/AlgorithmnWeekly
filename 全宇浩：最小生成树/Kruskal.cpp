#include <cstdio>
#include <algorithm>
using namespace std;
const int N=5e3+10;
const int M=2e5+10;
const int Inf=2147483647;
struct Graph {
	int u,v,w,nx;
	friend bool operator < (Graph a,Graph b) {return a.w<b.w;}//����Ȩ���� 
}g[2*M];
int cnt,list[N],f[N];
int n,m,wans;

int Get_F(int x) {return f[x]==x?x:f[x]=Get_F(f[x]);}

bool Kruskal() {
	for (int i=1;i<=n;i++) f[i]=i;//���鼯��ʼ�� 
	sort(g+1,g+m+1);//��С�������� 
	for (int i=1,fu,fv;i<=m;i++)
		if ((fu=Get_F(g[i].u))!=(fv=Get_F(g[i].v))) {//���ö�ٵıߵĶ˵㲻����ͬһ����ͨ�� 
			f[fu]=fv;//��ϲ�������ͨ�� 
			wans+=g[i].w;
		}
	int anc=Get_F(1);
	for (int i=2;i<=n;i++) if (Get_F(i)!=anc) return 0;//������ڲ�ͬ����ͨ��˵��ͼ����ͨ 
	return 1;
}

void Add(int u,int v,int w) {g[++cnt]=(Graph){u,v,w,list[u]};list[u]=cnt;}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,w;i<=m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		Add(u,v,w);
	}
	if (Kruskal()) printf("%d",wans);
	else printf("disconnected");
}
