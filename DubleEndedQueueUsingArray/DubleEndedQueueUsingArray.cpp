// DubleEndedQueueUsingArray.cpp 
//Double ended queue will enable insert and delete at both ends done using array



#include <iostream>

using namespace std;

struct Node
{
	int size;
	int front;
	int rear;
	int* arr;
};


void enqueueFront(struct Node* ,int);
void enqueueRear(struct Node* ,int );
void dequeueFront(struct Node*);
void dequeueRear(struct Node*);
bool IsEmpty(struct Node*);
bool IsFull(struct Node*);
void display(struct Node*);



void dequeueRear(struct Node* q)
{
	if (IsEmpty(q))
	{
		cout << "Queue is empty ." << endl;
		return;
	}
	cout << "Deleted -> " << q->arr[q->rear--] << " from the queue's rear . " << endl;
	

}


void dequeueFront(struct Node* q)
{

	if (IsEmpty(q))
	{
		cout << "Queue is empty . " << endl;
		return;
	}
	cout << "Deleted -> " << q->arr[++q->front] << " from the queue's front side." << endl;
	


}


void enqueueRear(struct Node* q, int x)
{
	if (IsFull(q))
	{
		cout << "Queue is full . Insertion of " << x << " from rear end is not possible ." << endl;
		return;
	}
	cout << "Inserted -> " << x << " rear of the queue ." << endl;
	q->arr[++q->rear] = x;
}


void enqueueFront(struct Node* q,int x)
{
	if (q->front == -1 && q->rear!=-1)
	{
		cout << "Queue has no space in front to insert .Insertion of -> " << x << " in front not possible" << endl;
		return;
	}
	//special case ...front ,rear both at -1
	if (q->front == -1 && q->rear == -1)
	{
		cout << "Queue is empty .so inserted -> " << x << " using the rear pointer . " << endl;
		q->arr[++q->rear] = x;
		return;
	}

	cout << "Inserted -> " << x << " in front of queue." << endl;
	q->arr[q->front--] = x;

}


void display(struct Node* q)
{
	int i = q->front;
	while (i < q->rear)
		cout << q->arr[++i]<<" ";
	cout << endl;
}


bool IsEmpty(struct Node* q)
{
	return (q->front == q->rear) ? 1 : 0;
}


bool IsFull(struct Node* q)
{
	return (q->rear == q->size - 1 )? 1 : 0;
}


int main()
{
	struct Node q;
	q.size = 8;
	q.arr = new int[q.size];
	q.front = q.rear = -1;

	enqueueFront(&q, 10);
	enqueueRear(&q, 20);
	enqueueRear(&q, 30);
	enqueueRear(&q, 40);
	enqueueRear(&q, 50);
	enqueueRear(&q, 60);
	enqueueRear(&q, 70);
	enqueueRear(&q, 80);
	display(&q);
	dequeueFront(&q);
	dequeueFront(&q);
	dequeueRear(&q);
	dequeueRear(&q);
	display(&q);
	enqueueFront(&q, 100);
	enqueueFront(&q, 105);
	enqueueFront(&q, 110);
	display(&q);
	enqueueRear(&q, 200);
	enqueueRear(&q, 300);
	enqueueRear(&q, 400);
	enqueueRear(&q, 500);
	display(&q);
}
