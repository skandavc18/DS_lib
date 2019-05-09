 #include "queue.h"

// Driver Program to test anove functions 
int main() 
{ 
	QUEUE_TYPE(int)* q = QUEUE_CREATE(int); 
	QUEUE_ENQUEUE(int,q, 10); 
	QUEUE_ENQUEUE(int,q, 20); 
	QUEUE_DEQUEUE(int,q); 
	QUEUE_DEQUEUE(int,q); 
	QUEUE_ENQUEUE(int,q, 30); 
	QUEUE_ENQUEUE(int,q, 40); 
	QUEUE_ENQUEUE(int,q, 50); 
	QUEUE_NODE_TYPE(int) *n = QUEUE_DEQUEUE(int,q); 
	if (n != NULL) 
	printf("Dequeued item is %d\n", n->key); 

	QUEUE_TYPE(double)* qDouble = QUEUE_CREATE(double); 
	QUEUE_ENQUEUE(double,qDouble, 10); 
	QUEUE_ENQUEUE(double,qDouble, 20); 
	QUEUE_DEQUEUE(double,qDouble); 
	QUEUE_DEQUEUE(double,qDouble); 
	QUEUE_ENQUEUE(double,qDouble, 30); 
	QUEUE_ENQUEUE(double,qDouble, 40); 
	QUEUE_ENQUEUE(double,qDouble, 50); 
	QUEUE_NODE_TYPE(double) *nDouble = QUEUE_DEQUEUE(double,qDouble); 
	if (nDouble != NULL) 
	printf("Dequeued item is %lf\n", nDouble->key);

	QUEUE_TYPE(string)* qString = QUEUE_CREATE(string); 
	QUEUE_ENQUEUE(string,qString, "Hello"); 
	QUEUE_ENQUEUE(string,qString, "How"); 
	QUEUE_DEQUEUE(string,qString); 
	QUEUE_DEQUEUE(string,qString); 
	QUEUE_ENQUEUE(string,qString, "r"); 
	QUEUE_ENQUEUE(string,qString, "u"); 
	QUEUE_ENQUEUE(string,qString, "?"); 
	QUEUE_NODE_TYPE(string) *nString = QUEUE_DEQUEUE(string,qString); 
	if (nString != NULL) 
	printf("Dequeued item is %s\n", nString->key);

	return 0; 
} 
