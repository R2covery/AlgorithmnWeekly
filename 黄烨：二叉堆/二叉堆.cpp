void swap(int &x,int &y){int t=x;x=y;y=t;}//�������� 
int heap[N];//����һ�����������
int siz;//�ѵĴ�С 
void push(int x){//Ҫ������� 
    heap[++siz]=x;
    now=siz;
    //���뵽�ѵ� 
    while(now){//��û�����ڵ㣬���ܽ��� 
        ll nxt=now>>1;//�ҵ����ĸ��� 
        if(heap[nxt]>heap[now])swap(heap[nxt],heap[now]);//���ױ������Ǿͽ��� 
        else break;//�����������С���Ǿʹ����Ų�������� 
        now=nxt;//���� 
    }
    return; 
}
void pop(){
    swap(heap[siz],heap[1]);siz--;//�����Ѷ��Ͷѵף�Ȼ��ֱ�ӵ����ѵ� 
    int now=1;
    while((now<<1)<=siz){//�Ըýڵ�������½����Ĳ��� 
        int nxt=now<<1;//�ҳ���ǰ�ڵ������� 
        if(nxt+1<=siz&&heap[nxt+1]<heap[nxt])nxt++;//������Ҫ����ӻ����Ҷ��Ӹ����� 
        if(heap[nxt]<heap[now])swap(heap[now],heap[nxt]);//��������϶����ʾͻ� 
        else break;//���������� 
        now=nxt;//����һ��������½��� 
    }
}
