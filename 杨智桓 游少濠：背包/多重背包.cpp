//v[i]:i����Ʒ�ļ�ֵ w[i]:i����Ʒռ�õĿռ� dn:��ֺ���Ʒ���� num:��Ʒ����
int dn;
void divide(int k,int val,int weight)
{
    int x=1;
	while(k-x>=0)
	{
        p[++dn]=x*val;
        w[dn]=x*weight;
        k-=x;x=x*2;
    }
}
int pre()
{
    int k,val,weight;
	for(int i=1;i<=num;++i)
	{
        scanf("%d%d%d",&k,&val,&weight);
        divide(k,val,weight);
    }
}
//����������ͨ��01����

