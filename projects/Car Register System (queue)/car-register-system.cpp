#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_CARS = 100;

struct Node {
	string name, brand, model;
	Node* next;
};

struct Queue {
	Node *front, *rear;
	int size;
};

void initQueue(Queue *q);
void enqueue(Queue *q, string name, string brand, string model);
Node* dequeue(Queue *q);
void printQueue(Queue *q);

int main()
{
	Queue q;
	Node *removed_node = NULL;
	int answer;
	string name, brand, model;
	string delete_confirm;
	
	initQueue(&q);
	
	while(1)
	{
		cout << "Choose an option:" << endl;
		cout << "[1] Enqueue new car\n[2] Dequeue car\n[3] Print queue\n[4] Exit\nR: ";
		cin >> answer;
		
		switch(answer)
		{
			case 1:
			{
				if(q.size < MAX_CARS)
				{
					cout << "\nInsert the car name: ";
					cin >> name;
					cout << "Insert the car brand: ";
					cin >> brand;
					cout << "Insert the car model: ";
					cin >> model;
					
					enqueue(&q, name, brand, model);
					cout << "\nCar added with success!\n" << endl;
				}
				else
					cout << "\nFail adding the register. The car queue is full, remove a car to add a new one.\n" << endl;
				
				break;
			}
			case 2:
			{
				if(q.front)
				{
					while(1)
					{
						cout << "\nThe followed register will be removed:" << endl;
						cout << "Name: " << q.front->name << endl;
						cout << "Brand: " << q.front->brand << endl;
						cout << "Model: " << q.front->model << endl;
	
						cout << "\nAre you sure?\nR: ";
						cin >> delete_confirm;
						
						if(delete_confirm == "S" || delete_confirm == "s" || delete_confirm == "Sim" || delete_confirm == "sim")
						{
							removed_node = dequeue(&q);
							delete removed_node;
							
							cout << "\nRegister deleted with success!\nThere are " << q.size << " registers left in the queue.\n" << endl;
							break;
						}
						else if(delete_confirm == "N" || delete_confirm == "n" || delete_confirm == "N�o" || delete_confirm == "n�o" || delete_confirm == "Nao" || delete_confirm == "nao")
						{
							cout << "\nRight! The removing operation was canceled. The queue is intact.\n" << endl;
							break;
						}	
						else
							cout << "\nThe option is invalid. Choose 'Sim' or 'Nao' or its variants." << endl;
					}
				}
				else
					cout << "\nThere's nothing in the queue to remove.\n" << endl;
				
				break;
			}
			case 3:
			{
				if(q.size > 0)
					printQueue(&q);
				else
					cout << "\nThere's nothing in the queue to print.\n" << endl;
				break;
			}
			case 4:
			{
				cout << "\nSee you!" << endl;
				break;
			}
			default:
			{
				cout << "\nInsert a valid option\n" << endl;
				break;
			}
		}
		
		if(answer == 4)
			break; 
	}
	
	return 0;
}

void initQueue(Queue *q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

void enqueue(Queue *q, string name, string brand, string model)
{
	Node *new_node = new Node;
	
	if(new_node)
	{
		new_node->name = name;
		new_node->brand = brand;
		new_node->model = model;
		new_node->next = NULL;
		
		if(q->size == 0)
		{
			q->front = new_node;
			q->rear = new_node;
		}
		else
		{
			q->rear->next = new_node;
			q->rear = new_node;
		}
		
		q->size++;
	}
	else
		cout << "\nOps! Something went wrong.\n" << endl;
}

Node* dequeue(Queue *q)
{
	Node *remove = NULL;
	
	if(q->size > 0)
	{
		remove = q->front;
		q->front = q->front->next;
		q->size--;
	}
	
	return remove;
}

void printQueue(Queue *q)
{
	Node *aux = q->front;
	int counter = 1;
	
	cout << "\n===== First register (queue's front) | Total of cars: " << setw(2) << setfill('0') << q->size << " =====" << endl;
	
	while(aux)
	{
		cout << "\n               ----- Car " << setw(2) << setfill('0') << counter << " -----" << endl;
		cout << "                   Name: " << aux->name << endl;
		cout << "                   Brand: " << aux->brand << endl;
		cout << "                   Model: " << aux->model << endl;
		cout << "               ------------------\n" << endl;
		
		counter++;
		aux = aux->next;
	}
	
	cout << "================ Last register (queue's rear) ================\n" << endl;
}
