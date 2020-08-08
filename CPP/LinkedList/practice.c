#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}node_t;

/*
111      1000     2000     3000     4000      NULL
1,1000   2,2000   3,8000   4,4000   5,NULL

                       6,3000
                       8000
*/
int insert(node_t** head_ref)
{
	static int size = 0;
	node_t* new_node = (node_t*)malloc(sizeof(node_t*));
	printf("Enter the data:");
	if(new_node != NULL)
	{
		int pos = -1;
		scanf("%d",&new_node->data);

		printf("Enter pos:");
		scanf("%d",&pos);
		if(pos<1 || pos>size+1)
		{
			printf("Invalid position");
			return -1;
		}
		else if(pos == 1)
		{
			new_node->next = *head_ref;
			*head_ref = new_node;
			size++;
		}
		else if(pos<=size+1)
		{
			node_t* tmp = *head_ref;
			for(int i = 1;i<pos-1;i++)
			{
				tmp = tmp->next;
			}
			new_node->next =tmp->next;
			tmp->next = new_node;
			size++;
		}
	}
}
/*
111      1000     2000     3000     4000      NULL
1,1000   2,2000   3,3000   4,4000   5,NULL

tmp2 = 3000
*/
void delete(node_t** head_ref)
{
	node_t* tmp = *head_ref;
	int pos=-1;
	printf("Enter position");
	scanf("%d",&pos);

	if(pos<1)
	{
		printf("Invalid position");
	}
	if(pos ==1 )
	{
		*head_ref = tmp->next;
		free(tmp);
	}
	else
	{
		for(int i=1; i<pos-1; i++)
		{
			tmp = tmp->next;
		}
		node_t* tmp2 = tmp->next;
		tmp->next = tmp2->next;
		free(tmp2);
	}
}

void sort(node_t** head_ref)
{
	node_t *pptr, *cptr;
	int tmp;
	pptr = *head_ref;
	while(pptr->next!=NULL)
	{
		cptr = pptr->next;
		while(cptr!=NULL)
		{
			if(pptr->data > cptr->data)
			{
				tmp = pptr->data;
				pptr->data = cptr->data;
				cptr->data = tmp;
			}
			cptr=cptr->next;
		}
		pptr = pptr->next;
	}
}

void reverse(node_t** head_ref)
{
	node_t* prev = NULL;
	node_t* curr = *head_ref;
	node_t* next;
	if(curr == NULL)
	{
		printf("Empty List");
		return;
	}
	if(curr->next == NULL)
	{
		printf("List is already reversed");
		return;
	}
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head_ref = prev;
}

int detectLoop(node_t* head)
{
	node_t* slow_p = head;
	node_t* fast_p = head;
	while(slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		if(slow_p == fast_p)
			return 1;
	}
	return 0;
}

void display(node_t* head)
{
	node_t* tmp = head;
	while(tmp!=NULL)
	{
		printf("%d  ",tmp->data);
		tmp = tmp->next;
	}
	printf("-->  NULL\n");
}

void insertElem(node_t** headref_final, int data)
{
	node_t* new_node = (node_t*)malloc(sizeof(node_t*));
        new_node->data = data;
	new_node->next = NULL;

	node_t* last = *headref_final;
	while(last->next!=NULL)
	{
		last = last->next;
	}

	last->next = new_node;
}

node_t* merge(node_t* list1_head, node_t* list2_head)
{
	node_t* flist = NULL;
	node_t* p = list1_head;
	node_t* q = list2_head;

	while(p && q)
	{
		if(p->data<q->data)
		{
			insertElem(&flist,p->data);
			p = p->next;
		}
		else
		{
		 	insertElem(&flist,q->data);
                        q = q->next;
		}
	}

	while(p)
	{
		insertElem(&flist,p->data);
		p = p->next;
	}

	while(q)
	{
		insertElem(&flist,q->data);
		q = q->next;
	}
	return flist;
}

node_t* checkLinkedListCrossing(node_t* l1, node_t* l2)
{
	node_t* p = l1;
	node_t* q = l2;

	if((p==NULL)||(q==NULL))
		return 0;

	//Method - 1  - Brute force
	/*
	while(p)
	{
		while(q)
		{
			if(p==q)
			{
				return true;
			}
			q = q->next;
		}
		p = p->next;
	}
	return false;
	*/
	// Method - 1 - end
	
	//Method - 2
	int sizeOfp = 0;
	while(p->next!=NULL)
	{
		++sizeOfp;
		p = p->next;

	}
	int sizeOfq = 0;
	while(q->next!=NULL)
	{
		++sizeOfq;
		q = q->next;
	}
	p = l1;
	q = l2;
	if(sizeOfp>sizeOfq)
	{
		int diff = sizeOfp - sizeOfq;
		for(int i = 0;i < diff;i++ )
		{
			p = p->next;
		}
	}
	else
	{
		int diff = sizeOfq - sizeOfp;
		for(int i = 0;i< diff; i++)
		{
			q = q->next;
		}
	}
	while(p!=q)
	{
		p = p->next;
		q = q->next;
	}
	return p;

}
int main(void)
{
	node_t* list1 = NULL;
	insert(&list1);
	insert(&list1);
	insert(&list1);
	insert(&list1);
	insert(&list1);
	display(list1);
	sort(&list1);
	display(list1);
	//reverse(&list1);
	//display(list1);

	node_t* list2 = NULL;
        insert(&list2);
        insert(&list2);
        insert(&list2);
        insert(&list2);
        insert(&list2);
        display(list2);
	sort(&list2);
	display(list2);

	printf("\n******** Final List *******\n");
	node_t* finalList = merge(list1,list2);
	display(finalList);
	return 0;
}
