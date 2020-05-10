#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
	char letr;
	struct node *nextPtr;
	struct node *prevPtr;
};

class dlist
{
public:
	node * root;
public:
	dlist()
	{
		root = NULL;
	}

	//insert a new value
	void insert(char data)
	{
		node *t, *ptr, *p;
		int d, flag = 0;
		t = (node *)malloc(sizeof(node));
		t->letr = data;
		t->nextPtr = t->prevPtr = NULL;
		if (root == NULL)
			root = t;
		else if (root->nextPtr == NULL)
		{
			ptr = root;
			if (t->letr < ptr->letr)
			{
				t->nextPtr = ptr;
				ptr->prevPtr = t;
				root = t;
			}
			else
			{
				ptr->nextPtr = t;
				t->prevPtr = ptr;
				root = ptr;
			}
		}
		else
		{
			ptr = root;
			if (data < ptr->letr)
			{
				t->nextPtr = ptr;
				ptr->prevPtr = t;
				root = t;
			}
			else
			{
				while ((ptr->nextPtr) != NULL)
				{
					p = ptr->nextPtr;
					if (data > ptr->letr&&data <= p->letr)
					{
						ptr->nextPtr = t;
						t->prevPtr = ptr;
						t->nextPtr = p;
						p->prevPtr = t;
						flag = 1;
						break;
					}
					ptr = ptr->nextPtr;
				}
				if (flag == 0)
				{
					ptr->nextPtr = t;
					t->prevPtr = ptr;
					t->nextPtr = NULL;
				}
			}
		}
	}

	//function to display the values forward
	void displayf()
	{
		node *ptr = root;
		try
		{
			if (root == NULL)
				throw 0;
		}
		catch (int x)
		{
			cout << "\nList is empty\n";
			return;
		}
		cout << "List in forward order: ";
		while (ptr != NULL)
		{
			cout << ptr->letr << " ";
			ptr = ptr->nextPtr;
		}
		cout << "\n";
	}

	//display inputted values backwards
	void displayb()
	{
		try
		{
			if (root == NULL)
				throw 0;
		}
		catch (int x)
		{
			cout << "\nList is empty\n";
			return;
		}
		node *ptr = root, *p;
		cout << "List in backward order: ";
		while (ptr->nextPtr != NULL)
		{
			ptr = ptr->nextPtr;
		}
		p = ptr;
		while (p != NULL)
		{
			cout << p->letr << " ";
			p = p->prevPtr;
		}
		cout << "\n";
	}

	node* middle(node* start, node* last)
	{
		if (start == NULL)
			return NULL;
		node* slow = start;
		node* fast = start->nextPtr;
		while (fast != last)
		{
			fast = fast->nextPtr;
			if (fast != last)
			{
				slow = slow->nextPtr;
				fast = fast->nextPtr;
			}
		}
		return slow;
	}

	//search for value/node
	node* search(int value, node* start, node* last)
	{
		if (last == NULL || last != start)
		{
			node* mid = middle(start, last);
			if (mid == NULL)
				return NULL;
			if (mid->letr == value)
				return mid;
			if (mid->letr < value)
			{
				start = mid->nextPtr;
				search(value, start, last);
			}
			else
			{
				last = mid;
				search(value, start, last);
			}
		}
		else
			return NULL;
	}

	//function to delete a value/node
	void delete1(char h)
	{
		try
		{
			if (root == NULL)
				throw 0;
		}
		catch (int x)
		{
			cout << "\nList is empty\n";
			return;
		}

		node *p, *w, *x;
		p = search(h, root, NULL);
		if (p->nextPtr == NULL)
		{
			w = p->prevPtr;
			w->nextPtr = NULL;
			free(p);
		}
		else
		{
			w = p->prevPtr;
			x = p->nextPtr;
			w->nextPtr = x;
			x->prevPtr = w;
			free(p);
		}
	}
}ob;

int main()
{
	int ch;
	node *p;
	char h;
	while (1)
	{
		cout << "Doubly linked list operation options:" << endl;
		cout << "1 - Insert new node" << endl;
		cout << "2 - Search for a node value" << endl;
		cout << "3 - Display the list forwards" << endl;
		cout << "4 - Display the list backwards" << endl;
		cout << "5 - Delete a node value" << endl;
		cout << "6 - Exit" << endl;
		cout << "Pleaase enter your operation choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter the letter: ";
			cin >> h;
			ob.insert(h);
			break;

		case 2:
			cout << "Enter the letter: ";
			cin >> h;
			p = ob.search(h, ob.root, NULL);
			if (p == NULL)
				cout << "\nletter not present in list.\n";
			else
				cout << "\nletter found in list\n";
			break;

		case 3:
			ob.displayf();
			break;

		case 4:
			ob.displayb();
			break;

		case 5:
			cout << "Enter data to delete: ";
			cin >> h;
			p = ob.search(h, ob.root, NULL);
			try
			{
				if (p == NULL)
					throw 0;
				ob.delete1(h);
			}
			catch (int x)
			{
				cout << "\nData not in list.\n";
			}
			break;

		case 6:
			cout << "\nProgram ends\n";
			exit(0);

		default:
			cout << "\nInvalid choice";
		}
	}
	system("pause");
	return 0;
}