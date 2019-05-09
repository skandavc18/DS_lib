#include <stdlib.h> 
#include <stdio.h> 
typedef char* string;

// A linked list (LL) node to store a queue entry
#define QUEUE_DECLARE(type)                                             \
typedef struct type##_QNode_s                                             \
{                                                                       \
	type key;                                                           \
	struct type##_QNode_s *next;                                          \
}type##_QNode;                                                          \
                                                                        \
typedef struct type##_Queue_s                                                   \
{                                                                       \
	type##_QNode *front, *rear;                                         \
}type##_Queue;                                                          \
                                                                        \
type##_QNode* type##_newNode(type k);                                   \
type##_Queue* type##_createQueue();                                     \
void type##_enQueue(type##_Queue *q, type k);                            \
type##_QNode* type##_deQueue(type##_Queue *q);                          

#define QUEUE_DEFINE(type)                                              \
type##_QNode* type##_newNode(type k)                                    \
{                                                                       \
	type##_QNode *temp = (type##_QNode*)malloc(sizeof(type##_QNode));   \
	temp->key = k;                                                      \
	temp->next = NULL;                                                  \
	return temp;                                                        \
}                                                                       \
                                                                        \
type##_Queue* type##_createQueue()                                      \
{                                                                       \
	type##_Queue *q = (type##_Queue*)malloc(sizeof(type##_Queue));      \
	q->front = q->rear = NULL;                                          \
	return q;                                                           \
}                                                                       \
                                                                        \
void type##_enQueue(type##_Queue *q, type k)                            \
{                                                                       \
	type##_QNode *temp = type##_newNode(k);                                    \
                                                                        \
	if (q->rear == NULL)                                                \
	{                                                                   \
	q->front = q->rear = temp;                                          \
	return;                                                             \
	}                                                                   \
                                                                        \
	q->rear->next = temp;                                               \
	q->rear = temp;                                                     \
}                                                                       \
                                                                        \
type##_QNode* type##_deQueue(type##_Queue *q)                           \
{                                                                       \
	if (q->front == NULL)                                               \
	return NULL;                                                        \
                                                                        \
	type##_QNode *temp = q->front;                                      \
	q->front = q->front->next;                                          \
                                                                        \
	if (q->front == NULL)                                               \
	q->rear = NULL;                                                     \
	return temp;                                                        \
}                                                                       


#define QUEUE_TYPE(type)\
type##_Queue

#define QUEUE_NODE_TYPE(type)\
type##_QNode

#define QUEUE_NEW_NODE(type, data)\
type##_newNode(data)

#define QUEUE_CREATE(type)\
type##_createQueue()

#define QUEUE_ENQUEUE(type,q,data)\
type##_enQueue(q,data)

#define QUEUE_DEQUEUE(type, q)\
type##_deQueue(q)
 
QUEUE_DECLARE(string)
QUEUE_DEFINE(string)
QUEUE_DECLARE(int)
QUEUE_DEFINE(int)
QUEUE_DECLARE(double)
QUEUE_DEFINE(double)