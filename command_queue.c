#include "shell.h"

/**
 * create_queue - Creates the queue of nodes
 *
 * Return: Address of node
 */

queue_t *create_queue()
{
	queue_t *q = malloc(sizeof(queue_t));

	if (!q)
		return (NULL);

	q->front = q->rear = NULL;
	return (q);
}

/**
 * enqueue - Adds new node to the front
 *
 * @q: Pointer to queue
 *
 * @separator: Used for character that
 * that separates each command
 *
 * @command: Points to the first char
 * in the stream
 *
 * Return: (0) failure (1) success
 */

int enqueue(queue_t *q, char separator, char **command)
{
	command_t *new_node = create_command(separator, command);

	if (!command_t)
		return (0);

	if (!q->rear)
	{
		q->front = new_node;
		q->rear = new_node;
		return (1);
	}

	q->rear->next = new_node;
	q->rear = new_node;
	return (1);
}


/**
 * dequeue - Removes the node after executed
 *
 * @q: Pointer to the queue
 *
 * Return: Node that was executed
 */

command_t *dequeue(queue_t *q)
{
	command_t *old_node = NULL;

	if (!q->front)
		return (NULL);

	old_node = q->front;
	q->front = q->front->next;

	if (!q->front)
		q->rear = NULL;

	return (old_node);
}


/**
 * print_queue - Prints the entire contents of the node
 *
 * @q: Pointer to the queue
 *
 * Return: Node that was executed
 */

void print_queue(queue_t *q)
{
	int i = 0;

	command_t *temp = NULL;

	if (!q)
		printf("NULL QUEUE\0");

	temp = q->front;

	while (temp)
	{
		printf("%d\n", temp->prev_valid);
		printf("%c\n", temp->separator);

		while (temp->command[i])
			printf("%s ,", temp->command[i++]);
		printf("\n");
		temp = temp->next;
		printf("\n\n");
	}
}
