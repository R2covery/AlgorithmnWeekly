//num:��Ʒ���� container:�����ռ�
void Resolve_KnapSack()
{
    for (int i=1;i<=num;++i) //������Ʒ���滮����ѡ��
    {
        for (int j=1;j<=container;j++)
        {
            if (j>=w[i])
            {
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+p[i]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
}

