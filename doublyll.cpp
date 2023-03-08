#include <iostream>
using namespace std;
  
// A doubly linked list node Insertion
struct node 
{
    int data;
    node* next;
    node* prev;
};
node *head=NULL;
class DLL_new
{
    public:
    void insertbeg()
    {
        cout<<"Enter the data :"<<endl;
        node *nn=new node;
        nn->next=head;
        nn->prev=NULL;
        if(head==NULL)
        {
            cin>>nn->data;
            head=nn;
        }
        else
        {
            cin>>nn->data;  
            head->prev=nn;
            head=nn;
        }
    }
    void display()
    {
        node *temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void insertend()
    {
        cout<<"Enter the data :"<<endl;
        node *nn=new node;
            nn->next=NULL;
            nn->prev=NULL;
        if(head==NULL)
        {
            cin>>nn->data;
            head=nn;
        }
        else
        {
            cin>>nn->data;
            node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn;
            nn->prev=temp;
        }
    }
    void insertloc()
    {
        int loc;
        node *nn=new node;
        nn->next=NULL;
        nn->prev=NULL;
        cout<<"Enter the Location :"<<endl;
        cin>>loc;
        cout<<"Enter the data :"<<endl;
        if(loc<1)
        {
            cout<<"Location should be greater than 1.\n";
        }
        else if(loc==1)
        {
            cin>>nn->data;
            nn->next=head;
            head->prev=nn;
            head=nn;
        }
        else
        {
            node *temp=head;
            for(int i=1; i<loc-1; i++)
            {
                if(temp!=NULL)
                {
                    temp=temp->next;
                }
            }
            if(temp!=NULL)
            {
                cin>>nn->data;
                nn->next=temp->next;
                nn->prev=temp;
                temp->next=nn;
            }
            if(nn->next!=NULL)
            {
                nn->next->prev=nn;
            }
            else
            {
                cout<<"The previous node is null.\n";
            }
        }  
    } 
    void deletebig()
    {
      node *temp;
      if(head==NULL)
      {
       cout<<"Please Insert a Node First\n";
      }
      else if(head->next==NULL)   
      {
      head=NULL;
      delete head;
      cout<<"Node Gayi\n"<<endl;
      }
      else
      {
      temp=head;
      head=head->next;
      head->prev=NULL;
      delete temp;
      }
  }
    void deleteend()
    {
    node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->prev->next=NULL;
    delete temp;
    }
  void deleteRM()
  {
   int pos;
   cout<<"Enter Position : ";
   cin>>pos;
   if(pos<1)
   { 
    cout<<"Please Insert a node First\n";
   }
   else if(pos==1 && head!=NULL)
   {
    node *del_node = head;
    head=head->next;
    delete del_node;
    if(head!=NULL)
    {
      head->prev=NULL;
    }
    }
    else
    {
     node *temp=head;
     for(int i=1;i<pos-1;i++)
     {
      if(temp!=NULL)  
       {
        
         temp=temp->next;
        }
      }
     if(temp!=NULL && temp->next!=NULL)
     { 
     node *del_node=temp->next;
     temp->next=temp->next->next;
     if(temp->next->next!=NULL)
       {
        temp->next->next->prev=temp->next;
       }
       delete del_node;
      }
    else
    {
    cout<<"Node is Already Deleted\n";
}
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

                        case 2: bb.insertloc();
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



