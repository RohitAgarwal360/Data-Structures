#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
struct node *next;
int data;
};

typedef struct node *PNODE;
typedef struct node **PPNODE;
typedef struct node NODE; 
																			//ADDNODE
int addatbeg(PPNODE first)
{
if(first==NULL)
printf("NULL address recieved addatbeg()");
PNODE newnode=(PNODE)malloc(sizeof(NODE));

printf("Enter the data of the node");
scanf("%d",&newnode->data);
newnode->next=*first;
*first=newnode;
}

void display(PNODE first)
{
	printf("                                      LL->");
	while(first!=NULL)
	{
		printf("%d->",first->data);
		first=first->next;
	}
	printf("\n");
}

int addatend(PPNODE first)
{
	PNODE head=*first;
	while(head->next!=NULL)
	{
		head=head->next;
	}
	PNODE newn=(PNODE)malloc(sizeof(NODE));
	printf("Data in node");
	scanf("%d",&newn->data);
	head->next=newn;
	newn->next=NULL;
}

int addatpos(PPNODE first,int pos)
{
	PNODE head=*first;
	if(*first==NULL)
	{
		//printf("First is NULL");
		PNODE newn=(PNODE)malloc(sizeof(NODE));
		printf("Enter Data ");
		scanf("%d",&newn->data);
		newn->next=NULL;
		*first=newn;
		return 1;
	}
	if(pos<=0)
	return -1;
	if(pos==1)
	{
		addatbeg(first);
		return -1;
	}
	int cond=1;
	while(cond!=pos-1)
	{
		if(head->next==NULL)
		break;					//When pos is greater than elements size
		head=head->next;
		cond++;
	}

	PNODE newn=(PNODE)malloc(sizeof(NODE));
	printf("Enter Data ");
	scanf("%d",&newn->data);
	newn->next=head->next;
	head->next=newn;
	
}
int deleteatbeg(PPNODE first)
{
	if(*first==NULL)
	return -1;
	PNODE head=*first;
	head=head->next;
	free(*first);
	*first=head;	
}
int deleteatend(PPNODE first)
{
	
	PNODE head=*first;
	if(head==NULL)
		return -1;
	if(head->next==NULL)
	{
		free(*first);
		*first=NULL;
		return -1;
	}	
	while(head->next->next!=NULL)
	{
			head=head->next;
	}
	free(head->next);
	head->next=NULL;
}

int deleteatpos(PPNODE first,int pos)
{
	if (*first==NULL) {
		printf("empty ll");
		return -1;
	}
	if(pos<=0)
	{
		printf("Wrong Pos");
		return -1;
	}
	if (pos==1) {
		deleteatbeg(first);
		return 1;
	}
	PNODE head=*first;
	int cond=1;
	while(cond!=pos-1)		//THINK...here
	{
		if(head->next==NULL)
		{
			printf("head-<next is null pos too big.");
			return -1;
		}
    	head=head->next;
		cond++;
	}
	PNODE temp=head->next->next;
	free(head->next);
	head->next=temp;
	return 1;
	
}
int main()
{	
	PNODE head=NULL;
	char loop='y';
	int choice;
	int check;
	int pos;
	while(1)
	{
			printf("============================================================\n");
			printf("                           LinkList\n");
			printf("============================================================\n");
		printf("1.Add  At Beginning\n2.Add at END\n3.add at pos\n4.delete at beg\n5.delete at end\n6.delatpos\n7.Show Linklist\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: check=addatbeg(&head);
					break;
			
			case 2: check=addatend(&head);	
					break;	

			case 3: printf("Enter Position?");
					scanf("%d",&pos);
					check=addatpos(&head, pos);
					break;

			case 4: check=deleteatbeg(&head);
					break;

			case 5: check=deleteatend(&head);
					break;	

			case 6: printf("Enter Position?");
					scanf("%d",&pos);
					check=deleteatpos(&head,pos);
					break;							
			
			case 7: display(head);
					break;
		}
		
		
		
		
		
		//printf("Continue?");
		//scanf("%s",&loop);	
	}
	
	
}

