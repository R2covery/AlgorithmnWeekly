#include <cstdio>
#include <cstring>
using namespace std;
const int N=5e3+10;
const int M=2e5+10;
struct Graph {
	int u,v,w,nx;
}g[M];
int cnt,list[N],f[N],link[N];//link[i]��ʾ���ڵ�Ϊ i �Ĳ��鼯����ͨ�飩����������̱� 
bool used[M];
int n,m,wans;

int Get_F(int x) {return f[x]==x?x:f[x]=Get_F(f[x]);}

bool Boruvka() {
	bool flag;
	int coa=0;//ͳ����ͨ��ϲ����� 
	for (int i=1;i<=n;i++) f[i]=i;//���鼯��ʼ�� 
	do {
		flag=0;
		for (int i=1;i<=n;i++) link[i]=0;//ÿ����Ҫ���¼�¼��ͨ������������̵ı� 
		for (int i=1,fu,fv;i<=m;i++)
			if (!used[i]&&(fu=Get_F(g[i].u))!=(fv=Get_F(g[i].v))) {//�Ѿ��� MST �еıߺ���ͨ���ڲ��еı��ǲ���ȡ�� 
				if (!link[fu]||g[link[fu]].w>g[i].w||g[link[fu]].w==g[i].w&&link[fu]>i)//˫�ؼ���ȷ����̱� 
					link[fu]=i;
				if (!link[fv]||g[link[fv]].w>g[i].w||g[link[fv]].w==g[i].w&&link[fv]>i)
					link[fv]=i;
			}
		for (int i=1;i<=n;i++)
			if (link[i]&&!used[link[i]]) {//�ϲ���ͨ�飬ͬʱ��Ǳ� 
				flag=1;
				used[link[i]]=1;
				wans+=g[link[i]].w;
				coa++;
				f[Get_F(g[link[i]].u)]=Get_F(g[link[i]].v);
			}
	}
	while (flag);//���û���ٽ��кϲ�������˵������ͼ����ͨ�鶼�Ѿ�ǿ��ͨ 
	return coa==n-1;//�����ͨ��ϲ�����ǡ��Ϊ n-1��˵��ͼ��ͨ 
}

void Add(int u,int v,int w) {g[++cnt]=(Graph){u,v,w,list[u]};list[u]=cnt;}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,w;i<=m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		Add(u,v,w);
	}
	Boruvka();
	printf("%d",wans);
}
