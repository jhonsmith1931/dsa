#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *next;
};
node *head = NULL;
class Linked
{
public:void create ()
  {
    node *head = NULL;
    node *nn = new node;
  }

  void insertbeg ()
  {
    cout << "Enter the Data:" << "\n";
    node *nn = new node;
    if (head == NULL)
      {
	cin >> nn->data;
	nn->next = NULL;
	head = nn;
      }
    else
      {
	cin >> nn->data;
	nn->next = head;
	head = nn;
      }
  }

  void display ()
  {
    node *temp = head;
    while (temp != NULL)
      {
	cout << temp->data << "->";
	temp = temp->next;
      }
    cout << "NULL" << endl;
  }

  void insertend ()
  {
    node *temp = head;
    cout << "Enter the Data:" << "\n";
    node *nn = new node;

    nn->next = NULL;
    if (head == NULL)
      {
	cin >> nn->data;
	nn->next = NULL;
	head = nn;
      }
    else
      {
	while (temp->next != NULL)
	  {
	    temp = temp->next;
	  }
	cin >> nn->data;
	temp->next = nn;
      }
  }

  void insertran ()
  {
    int loc;
    node *nn = new node;
    nn->next = NULL;
    cout << "Enter the Location :" << endl;
    cin >> loc;
    cout << "Enter the data:" << endl;
    if (loc < 1)
      {
	cout << "Invalid Input" << "\n";
      }
    else if (loc == 1)
      {
	cin >> nn->data;
	nn->next = head;
	head = nn;
      }
    else
      {
	node *temp = head;
	for (int i = 1; i < loc - 1; i++)
	  {
	    if (temp != NULL)
	      {
		temp = temp->next;
	      }
	  }
	if (temp != NULL)
	  {
	    cin >> nn->data;
	    nn->next = temp->next;
	    temp->next = nn;
	  }

	else
	  {
	    cout << "the previous node is null" << "\n";
	  }
      }
  }

  void deletebin ()
  {
    node *temp;
    if (head == NULL)
      {
	cout << "Underflow Plz First insert a node first\n" << endl;
      }
    else
      {
	temp = head;
	head = head->next;
	delete temp;

      }
  }

  void deleteend ()
  {
    node *temp;
    node *current;
    if (head == NULL)
      {
	cout << "Underflow Plz First insert a node first\n" << endl;
      }
    else
      {
	temp = head;
	while (temp->next != NULL)
	  {
	    current = temp;
	    temp = temp->next;

	  }
	current->next = NULL;
	delete temp;
      }
  }

  void deleteran ()
  {
    if (head == NULL)
      {
	cout << "List is Empty please Insert a Node First\n" << endl;
      }
    else

      {
	int pos, i = 1;
	node *temp, *nextnode;
	cout << "Plz enter Position : ";
	cin >> pos;
	temp = head;
	while (i < pos - 1)
	  {
	    temp = temp->next;
	    i++;
	  }
	nextnode = temp->next;
	temp->next = nextnode->next;
	delete nextnode;

      }
  }

};

int main ()
{
  Linked L1;
  int ch;
  while (1)
    {
      cout << "---Menu---" << "\n";
      cout << "1.Create a Node\n";
      cout << "2.Insert" << endl;
      cout << "3.Delete" << endl;
      cout << "4.Exit" << "\n";
      cout << "Enter Your Choice : ";
      cin >> ch;
      switch (ch)
	{
	case 1:
	  L1.create ();
	  L1.display ();
	  break;
	case 2:int b;
	      cout << "******Sub-Menu******" << endl;
	      cout << "1.Insert at Begin" << "\n";
	      cout << "2.Insert at End" << "\n";
	      cout << "3.Insert at random " << "\n";

	  cout << "Enter Your Choice : ";
	  cin >> b;
	  switch (b)

	    {

	    case 1:
	      cout << "1.Insert at Begin" << "\n";
	      L1.insertbeg ();
	      L1.display ();
	      break;

	    case 2:
	      cout << "2.Insert at End" << "\n";
	      L1.insertend ();
	      L1.display ();
	      break;
	      
	    case 3:
	      cout << "3.Insert at random " << "\n";
	      L1.insertran ();
	      L1.display ();
	      break;

	    }
	    break;

	case 3:int c;
	      cout << "1.Delete at Begin" << "\n";
	      cout << "2.Delete at End" << "\n";
	      cout << "3.Delete at Random Position\n";
	  cout << "Enter Your Choice : ";
	  cin >> c;
	  switch (c)
	    {
	    case 1:
	      cout << "Delete at Begin" << endl;
	      L1.deletebin ();
	      L1.display ();
	      break;

	    case 2:
	      cout << "Delete at End\n";
	      L1.deleteend ();
	      L1.display ();
	      break;

	    case 3:
	      cout << "Delete at Random Position\n";
	      L1.deleteran ();
	      L1.display ();
	      break;

	    }
	    break;

	case 4:
	  exit (0);
	}

    }
}

