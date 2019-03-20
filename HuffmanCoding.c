#include<stdio.h>
#include<stdlib.h>
struct Tree
{
    int freq;
    char key;
    struct Tree *left,*right,*next;
};
struct Tree* CreatNode(int,char);
struct Tree *head=NULL;
void pushList(struct Tree*,int);
void popList();
void HuffenTree();
void HuffmanCoding(struct Tree* ,int,char []);
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int val;
        char key;
        scanf("%d %c",&val,&key);
        pushList(CreatNode(val,key),val);  
    }
    HuffenTree();
    char str[n];
    HuffmanCoding(head,0,str);
    return 0;
}
struct Tree* CreatNode(int data,char key)
{
    struct Tree* temp=(struct Tree*)malloc(sizeof(struct Tree));
    temp->freq=data;
    temp->key=key;
    temp->left=temp->right=temp->next=NULL;
    return temp;
}
void HuffenTree()
{
    if(head->next==NULL)
      return ;
    int a1=head->freq;
    int a2=head->next->freq;
    int a3=a1+a2;
    
    struct Tree* templeft,*tempright,*temp;
    tempright=templeft=temp=(struct Tree*)malloc(sizeof(struct Tree));
    temp->freq=a3;
    temp->left=head;
    temp->right=head->next;
    temp->next=NULL;
    popList();
    popList();
    pushList(temp,a3);

    HuffenTree();
}
void pushList(struct Tree* run,int data)
{
    if(head==NULL)
    {
        head=run;
        return ;
    }
    struct Tree* temp=head;
    while((temp->next!=NULL)&&(temp->next->freq<data))
        temp=temp->next;
    run->next=temp->next;
    temp->next=run;
    return ;
}

void popList()
{
    head=head->next;
    return ;
}
void HuffmanCoding(struct Tree* run,int i,char str[])
{
    if(run->left==NULL)
    {
        str[i]='\0';
        printf("%c %s\n",run->key,str);
        return ;
    }
    str[i]='0';
    HuffmanCoding(run->left,i+1,str);
    str[i]='1';
    HuffmanCoding(run->right,i+1,str);
    return ;
}
