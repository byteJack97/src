#include<stdio.h>
#include<stdlib.h>
#include<surses.h>

struct Link
{
    int data;
    struct Link *next;
};

void printLink(struct Link *head)
{
        struct Link *p;
        p=head;
        while(p!= NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        putchar('\n');
}
struct Link* insertBehind(struct Link *head, struct Link *new)
{
        struct Link *p;
		p=head;
        if(head==NULL)
        {
            head=new;
            head->next=NULL;
			return head;
        }
		else
		{
			while(p->next != NULL)
			{
				p=p->next;
			}
			p->next=new;
		}
        return head;
}
struct Link *createLink(struct Link *head)
{
        struct Link *new;
        while(1)
        {
            new=(struct Link*)malloc(sizeof(struct Link));
			new->next=NULL;
            puts("please input your data:");
            scanf("%d",&(new->data));
            if(new->data==0)
            {
                puts("0 node over");
                free(new);
                return head;
            }
            head=insertBehind(head,new);
        }
}
int main()
{
        struct Link *head=NULL;
        head=createLink(head);
        printLink(head);

        struct Link test={1000,NULL};
        head=insertBehind(head,&test);
        printLink(head);
        return 0;
}
