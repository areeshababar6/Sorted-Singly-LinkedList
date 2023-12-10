#include<iostream>
using namespace std;

/*     Qusetion 1
The following C function takes a singly linked list as a input argument. It modifies the list by moving the last elements
to the front of the list and returns the modifies list ?*/

/*     Qusetion 2
The following C function takes a singly linked list of integer as a parameters and rearrange the elements of the list. 
The function is called with the list containing the integers 1,2,3,4,5,6,7,8,9 in the order. What will be content of 
the ist after the function completes the executions?*/

struct node
{
	int data;
	node *link;
};

//Question 1 
node *move_to_front(node *head)
{
	node *p, *q;
	if (head == NULL || head->link == NULL);
	{
		return head;
	}
	q = NULL;
	p = head;

	while (p->link != NULL)
	{
		q = p;
		p = p->link;
	}

	q->link = NULL;
	p->link = head;
	head = p;
	return head;
}   

//Question 2
void re_arrange(node *list)
{
	node *p, *q;
	int temp;

	if (!list || !list->link)
		return;
	p = list;
	q = list->link;

	while (q)
	{
		temp = p->data;
		p->data = q->data;
		q->data = temp;
		p = q->link;
		//q = p ? p->link : 0;   //is equvilant to q = p!= NULL ? p->link : 0;

		//or
		if (p != NULL)
		{
			q = p->link;
		}
		else
			q = 0;
	}
}
int main()
{
	node *head, *list;

	move_to_front(head);
	re_arrange(list);
}
