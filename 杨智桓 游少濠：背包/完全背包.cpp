//num:��Ʒ���� container:�����ռ�
void Resolve_KnapSack()
{
    for(int j=1;j<=container;++j)
	{
		dp[j]=dp[j-1];
        for(int i=1;i<=num;++i) //������Ʒ���滮����ѡ��
        {
            if(j>=w[i])
            {
                dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
            }
        }
    }
}
