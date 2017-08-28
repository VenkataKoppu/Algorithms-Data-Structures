//Author: Venkat
//Cormen: Data Structures: Single Linked List Operations
//A better design would be to send a refrence to insert and delete: &head : Use double pointer: No need to return head each time

#include <stdio.h>
#include <stdlib.h>

struct Node {

	int info;
	struct Node* link;
};

struct Node* allocate_block(struct Node* temp, int item) {
	temp = (struct Node*)malloc(sizeof(struct Node));
	if(temp == NULL) {
		printf("Insufficient Memory!");
		exit(1);
	}
	else {
		temp->info = item;
		return temp;
	}
}

struct Node* insert_node(struct Node* head, int item, int idx, int *size) {

	//Empty List
	struct Node* temp;
	if(head == NULL) {
		//Check input index validity
		if(idx == 0) {
			head = allocate_block(temp, item);
			head->link = NULL;
			++*size;
			return head;
		}
		else {
			printf("Invalid Input Position!\n");
			printf("Current Size of List is : %d\n", *size);
			return head;
		}
	}
	//Non-Empty List
	else {
		//Insert at front
		if(idx == 0) {
			temp = allocate_block(temp, item);
			temp->link = head;
			++*size;
			return temp;
		}
		//Insert an rear
		else if(idx == *size) {
			temp = allocate_block(temp, item);
			struct Node* cur = head;
			//Traverse till the end
			while(cur->link != NULL) {
				cur = cur->link;
			}
			cur->link = temp;
			temp->link = NULL;
			++*size;
			return head;
		}
		//Insert in middle
		else {
			struct Node* cur = head;
			struct Node* prev;
			//Traverse till the index position
			while(idx-- > 0) {
				if(cur->link != NULL) {
					prev = cur;
					cur = cur->link;
				}
				//Check input index validity: reached end
				else {
					printf("Invalid Input Position!\n");
					printf("Current Size of List is : %d\n", *size);
					return head;
				}
			}
			temp = allocate_block(temp, item);
			temp->link = cur;
			prev->link = temp;
			++*size;
			return head;
		}
	}
}

struct Node* delete_node(struct Node* head, int idx, int *size) {

	struct Node* temp;
	//Check empty list Condition
	if(head == NULL) {
		printf("List is Empty\n");
		return;
	}
	//Non-Empty List
	else {
		//Delete from front
		if(idx == 0) {
			temp = head->link;
			--*size;
			free(head);
			return temp;
		}
		//Delete from rear
		else if(idx == *size-1) {
			struct Node* cur = head;
			struct Node* prev;
			//Traverse till the end
			while(cur->link != NULL) {
				
				prev = cur;
				cur = cur->link;
			}
			prev->link = NULL;
			free(cur);
			--*size;
			return head;
		}
		//Delete from middle
		else {
			struct Node* cur = head;
			struct Node* prev = NULL;
			struct Node* next = NULL;
			//Traverse till the index position
			while(idx-- > 0) {
				if(cur->link != NULL) {
					prev = cur;
					cur = cur->link;
				}
				//Check input index validity
				else {
					printf("Invalid Input Position!\n");
					printf("Current Size of List is : %d\n", *size);
					return head;
				}
			}
			prev->link = cur->link;
			--*size;
			free(cur);
			return head;

		}
	}
}

void search(struct Node* temp, int key) {
		if(temp == NULL) {
		printf("List is Empty\n");
		return;
	}
	else {
		int i = 0;
		while(temp != NULL) {
			if(temp->info == key) {
				printf("Item found at index: %d\n", i);
				return;
			}
			else {
				temp = temp->link;
				++i;
			}
		}
		printf("Key not Found!\n");
	}
}

void display(struct Node* temp) {
	if(temp == NULL) {
		printf("List is Empty\n");
		return;
	}
	else {
		printf("Elements are: ");
		while(temp != NULL) {
			printf(" %d ", temp->info);
			temp = temp->link;
		}
	}
	printf("\n");
}

int main(void) {

	int choice;
	int idx;
	int item;
	int size = 0;
	struct Node* head = NULL;
	while(1) {
		printf("\nMenu:\n1.)Insert at Index 'X' 2.)Delete at Index 'X' 3.)Search 'X' 4.)Reverse List 5.)Display 6.)Exit \n");
		printf("Enter Choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: printf("Enter Item: ");
					scanf("%d", &item);
					printf("Enter Index: ");
					scanf("%d", &idx);
					head = insert_node(head, item, idx, &size);
					break;
			case 2: printf("Enter Index: ");
					scanf("%d", &idx);
					head = delete_node(head, idx, &size);
					break;
			case 3: printf("Enter Key: ");
					scanf("%d", &item);
					search(head, item);
					break;
			case 4:
			case 5: display(head);
					break;
			case 6: exit(1);
			default: printf("Invalid Choice\n");
		}
	}
}
