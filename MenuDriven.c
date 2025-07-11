#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node *start = NULL;

void insertAtB(int);
void insertAtE(int);
void insertAtSP(int,int);
void deleteAtB();
void deleteAtE();
void deleteAtSP(int p);
void showAll();
void showAll2(struct Node *);
int countNode();
int SearchNode();

void main()
{
int c;
int p,x;
M:
printf("\n---------------MENU---------------\n\n");
printf("1.Insert At Beginning\n");
printf("2.Insert At End\n");
printf("3.Insert At Specific Position\n");
printf("4.Delete At Beginning\n");
printf("5.Delete At End\n");
printf("6.Delete At Specific Position\n");
printf("7.Show Data\n");
printf("8.Show Data in reverse order\n");
printf("9.Search Node\n");

printf("\nENTER YOUR CHOICE : ");
scanf("%d",&c);

       if(c>=1 && c<=9)
  	    {
  	      switch(c)
  	    	{
  	    		case 1: printf("ENTER DATA :");
						scanf("%d",&x);
					    insertAtB(x);
						showAll();
						goto M;
				
  	    		case 2: printf("ENTER DATA :");
						scanf("%d",&x);
				        insertAtE(x);
						showAll();
						goto M;
				
  	    		case 3: printf("ENTER DATA AND POSITION :");
						scanf("%d %d",&x,&p); 
						insertAtSP(p,x);
						showAll();
						goto M;
				
  	    		case 4:
						deleteAtB();
						showAll();
						goto M;
				
				case 5:
						deleteAtE();
						showAll();
						goto M;
				
				case 6: printf("ENTER POSITION :");
						scanf("%d",&p);
						deleteAtSP(p);
						showAll();
						goto M;
				
				case 7:
						showAll();
						goto M;
				
				case 8:
						showAll2(start);
						goto M;
				
				case 9: printf("ENTER DATA :");
						scanf("%d",&x);
						printf("%d",SearchNode(x));
						goto M;
			}
		  }
		  else
		  {
		  	printf("INVALID CHOICE!");
		  }
}

void insertAtB(int x)
{
	struct Node *temp = malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("\n.....no space....\n");
	}
	temp->data=x;
	temp->next=start;
	start=temp;
}
void showAll()
{
	struct Node *temp1=start;
	while(temp1!=NULL)
	{
		printf("%d\n",temp1->data);
		temp1=temp1->next;
	}
}

void insertAtE(int x)
{
	if(start == NULL)
	{
		insertAtB(x);
		return;
	}
	struct Node *temp=malloc(sizeof(struct Node));
	
	struct Node *temp1=start;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp->data=x;
	temp1->next=temp;
	temp->next =NULL;
}

void deleteAtB()
{
	if(start==NULL)
	{
		printf("\nList is Empty!\n");
		return;
	}
	struct Node *temp1=start;
	start=start->next;
	free(temp1);
	
}

void deleteAtE()
{
	if(start==NULL || start->next==NULL)
	{
		deleteAtB();
		return;
	}
	struct Node *temp1=start;
	while(temp1->next->next != NULL)//3000
	{
		temp1=temp1->next;//4000
	}
	free(temp1->next);
	temp1->next=NULL;
}

void insertAtSP(int p, int x)
{
	if(p<=1)
	{
		insertAtB(x);
		return;
	}
	if(p>countNode())
	{
		insertAtE(x);
		return;
	}
	struct Node *temp=malloc(sizeof(struct Node));
	temp->data=x;
	
	struct Node *temp1=start;
	
	for(int i=1; i<p-1; i++)
	{
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}
int countNode()
{
	struct Node *temp1=start;
	int c=0;
	while(temp1!=NULL)
	{
		c++;
		temp1=temp1->next;
	}
	return c;
}

void deleteAtSP(int p)
{
	if(p<=1)
	{
		deleteAtB();
		return;
	}
	if(p>countNode())
	{
		deleteAtE();
		return;
	}
	struct Node *temp1=start;
	struct Node *temp2=start;
	for(int i=1; i<p-1; i++)
		temp1=temp1->next;
	
	temp2=temp1->next->next;
	free(temp1->next);
	temp1->next=temp2;
	
}

void showAll2(struct Node *temp1)
{
	if(start==NULL)
	{
		printf("\nLinked list has no Node\n");
	}
	if(temp1==NULL)
	return;
    
	showAll2(temp1->next);
	printf("%d\n",temp1->data);
}

int SearchNode(int se)
{
	int index=-1;
	if(start==NULL)
		return index;
	
	struct Node *temp1=start;
	while(temp1!=NULL)
	{
		index++;
		if(temp1->data==se)
		{
			return index;
		}
		temp1=temp1->next;
	}
	return -1;
}