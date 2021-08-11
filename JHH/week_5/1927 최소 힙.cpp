#include <iostream>

using namespace std;

int *heap;
int heap_size;
void push(int input) {
	int currentNode = ++heap_size;
	while (currentNode !=1 && heap[currentNode/2]>input)
	{
		heap[currentNode] = heap[currentNode / 2];
		currentNode /= 2;
	}
	heap[currentNode] = input;
}

int pop() {

	if (heap_size == 0) {
		return 0;
	}

	int minVal = heap[1];
	int lastNodeVal = heap[heap_size--];
	int currentNode = 1;
	int child = 2;

	
	while (child<=heap_size)
	{
		if (child < heap_size && heap[child] > heap[child + 1]) 
			child++;

		if (heap[child] > lastNodeVal)
			break;

		heap[currentNode] = heap[child];
		currentNode = child; 
		child *= 2;
	}
	heap[currentNode] = lastNodeVal;

	return minVal;
}
int main() {

	int N;
	scanf("%d", &N);
	heap = new int[N];
	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input == 0)
			printf("%d \n", pop());
		else {
			push(input);
		}
	}


	delete[] heap;
	return 0;
}
