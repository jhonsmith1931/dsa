#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
node *head=NULL;
class CSLL
{
	public :
		int pos;
		
		void insetbeg()
		{
			node *nn=new node;
			if(head==NULL)
			{
				cout<<"Enter the Data :";
				cin>>nn->data;
				head=nn;
				head->next=head;
			}
			else
			{
				cout<<"Enter the Data :";
				cin>>nn->data;
				nn->next=head->next;
				head->next=nn;
				head=nn;
			}
			
		}
		void disp()
		{
			node *temp=head;
			do
			{
		        cout<<temp->data<<"->";
			temp=temp->next;
			}while(temp!=head);
			cout<<head->data;
		
		}
		void insertend()
		{
			node *nn=new node;
			if(head==NULL)
			{
				cout<<"Enter the Data :";
				cin>>nn->data;
				head=nn;
				head->next=head;
			}
			else
			{
				node *temp=head;
				do
				{
				   temp=temp->next;	
				}while(temp->next!=head);
				cout<<"Enter the data : ";
				cin>>nn->data;
				nn->next=temp->next;
				temp->next=nn;
			}
			cout<<head->data;
		}
		void insertRM()
		{
                 node *nn, *current;
                 int i,pos;
                 if(head == NULL)
                 {
                   cout<<"List is empty";
                 }
                 else
                 {
        
                 node *nn=new node;
                 cout<<"Enter the data : ";
                 cin>>nn->data;
                 cout<<"Enter the Position : ";
	         cin>>pos;
                 current = head;
                 for(i=0; i<pos-1; i++) 
                 { 
                 current = current->next;
                 }
                 nn->next = current->next;
                 current->next = nn;
                 }

		
		}
                void deletebig ()
                {
                 node *temp;
                 if (head == NULL)
                 {
	         cout << "Underflow Plz First insert a node first\n" << endl;
                 }
                 else
                  {
	           temp = head;
	           while (temp->next != head)
	            {
	   
	             temp = temp->next;

	           }
                   temp->next=head->next;
                   delete head;
	           head=temp->next;
	          }
}
             void deleteend()
             {
             node *temp,*current;
             if (head == NULL)
             {
	     cout << "Underflow Plz First insert a node first\n" << endl;
             }
             else
             {
	     temp = head;
	     while (temp->next != head)
             {
	     current = temp;
	     temp = temp->next;

	     }
	     current->next = head;
	     delete temp;
      }
             }
};
int main()
{
    DLL_new bb;
    int ch;
    while(1)
    {
        cout<<"----Menu---"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter the choice : ";
        cin>>ch;
        switch (ch)
        {
        case 1: int b;
                cout<<"1.Insert at Beginning"<<endl;
                cout<<"2.Insert at Specific Location"<<endl;
                cout<<"3.Insert at End "<<endl;
                cout<<"Enter the choice : ";
                cin>>b;
                    switch(b)
                    {
                        case 1: bb.insertbeg();
                                bb.display();
                                break;

                        case 2: bb.insertRM();
                                bb.display();
                                break;

                        case 3: bb.insertend();
                                bb.display();
                                break;
                      
                        default: cout<<"Invalid Choice :-(\n";
                                break;
                    }
                    break;
                   
        case 2:int c;
                cout<<"1.Delete at Beginning"<<endl;
                cout<<"2.Delete at End "<<endl;
                cout<<"3.Delete at Specific Location"<<endl;
                cout<<"Enter the choice : ";
                cin>>c;
                switch(c)
                {
                  case 1: bb.deletebig();
                          bb.display();
                          break;
                          
                  case 2:bb.deleteend();
                         bb.display();
                         break;
                  
                  case 3:bb.deleteRM();
                         bb.display();
                         break;
                }
                break;
        case 3: exit(0);

        default: cout<<"Invalid Choice :-(\n";
                break;
        }
     }
   return 0;
}


