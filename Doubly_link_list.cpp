#include <iostream>
#include <fstream>
using namespace std;
class Node
{
private:
  int data;
  Node *Next;
  Node *Previous;
public:
  Node(int);
  void set_Next(Node*);
  Node* get_Next();
  void set_Previous(Node*);
  Node* get_Previous();
  void set_data(int);
  int get_data();
};
Node::Node(int data)
{
  this->data=data;
  Next=NULL;
  Previous=NULL;
}
void Node::set_Next(Node* temp)
{
  Next=temp;
}
Node* Node::get_Next()
{
  return Next;
}
void Node::set_Previous(Node* temp)
{
  Previous=temp;
}
Node* Node::get_Previous()
{
  return Previous;
}
void Node::set_data(int data)
{
  this->data=data;
}
int Node::get_data()
{
  return data;
}
class Doubly_link_list
{
private:
  Node *first;
public:
  Doubly_link_list();
  void add_node_end_list(int);
  void add_node_start_list(int);
  void remove_node_from_start();
  void remove_node_end_list();
  void remove_node_for_value(int);
  void remove_node_for_index(int);
  void add_node_at_index(int,int);
  int get_value_at_given_index(int);
  int find_value_return_index(int);
  void find_length_of_list();
  void perform_actions_from_file_for_list();
  void display_list();
};
Doubly_link_list::Doubly_link_list()
{
  first=NULL;
}
void Doubly_link_list::add_node_end_list(int input)
{
  Node *temp=new Node(input);
  Node *temp2=first;
  Node *temp3;
  if(temp2==NULL)
  {
    first=temp;
  }
  else
  {
    while(temp2->get_Next()!=NULL)
    {
      temp2=temp2->get_Next();
    }
    temp2->set_Next(temp);
    temp3=temp2->get_Next();
    temp3->set_Previous(temp2);
  }
}
void Doubly_link_list::add_node_start_list(int input)
{
  Node *temp=new Node(input);
  Node *temp2=first;
  if(temp2==NULL)
  {
    first=temp;
  }
  else
  {
    temp->set_Next(temp2);
    temp2->set_Previous(temp);
    first=temp;
  }
}
void Doubly_link_list::remove_node_from_start()
{
  if(first==NULL)
  {
    cout << "List is empty\n";
  }
  else
  {
    if(first->get_Next()==NULL)
    {
      first=NULL;
    }
    else
    {
    first=first->get_Next();
    first->set_Previous(NULL);
    }
  }
}
void Doubly_link_list::remove_node_end_list()
{
  Node *temp;
  temp=first;
  if(first==NULL)
  {
    cout << "List is empty\n";
  }
  else if(first->get_Next()==NULL)
  {
    first=NULL;
  }
  else if(first!=NULL)
  {
  while(temp->get_Next()->get_Next()!=NULL)
  {
    temp=temp->get_Next();
  }
  temp->set_Next(NULL);
  }
}
void Doubly_link_list::remove_node_for_value(int input)
{
  Node *temp;
  temp=first;
  if(first==NULL)
  {
    cout << "List is empty\n";
  }
  else if(temp->get_data()==input)//for to remove first node
  {
    temp=temp->get_Next();
    first=temp;
    first->set_Previous(NULL);
  }
  else if(first!=NULL)
  {
    while(temp!=NULL)
    {
    if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()==input)//For to remove last node
    {
      temp->set_Next(NULL);
    }
    else if(temp->get_Next()->get_data()==input&&temp->get_Next()->get_Next()!=NULL)//for to remove middle node
    {
     Node *temp2;
     temp2=temp;
     temp2=temp2->get_Next()->get_Next();
     temp->set_Next(temp2);
     temp2->set_Previous(temp);
     break;
    }
    temp=temp->get_Next();
    }
  }
}
void Doubly_link_list::remove_node_for_index(int input)
{
  if(first==NULL)
  {
    cout << "List is empty\n";
  }
  else
  {
   Node *temp;
   int counter=0,a;
   temp=first;
   while(temp!=NULL)
   {
     temp=temp->get_Next();
     counter++;
   }
   Node *temp3;
   temp3=first;
   for(a=0;a<=counter;a++)
   {

     if(input==0)
     {
       remove_node_from_start();
       break;
     }
     else if(input==counter-1)
     {
       remove_node_end_list();
       break;
     }
     else if(a==input-1)
     {
       Node *temp2;
       temp2=temp3;
       temp2=temp2->get_Next()->get_Next();
       temp3->set_Next(temp2);
       temp2->set_Previous(temp3);
       break;
     }
     temp3=temp3->get_Next();
   }
 }
}
void Doubly_link_list::add_node_at_index(int input,int data)
{
  Node *temp;
  int counter=0,a;
  temp=first;
  while(temp!=NULL)
  {
    temp=temp->get_Next();
    counter++;
  }
  Node *temp3;
  temp3=first;
  for(a=0;a<=counter;a++)
  {

    if(input<=0)
    {
      add_node_start_list(data);
      break;
    }
    else if(input>=counter-1)
    {
      add_node_end_list(data);
      break;
    }
    else if(a==input-1)
    {
      Node *temp=new Node(data);
      Node *temp2=temp3;//store first chain
      Node *temp4=temp3->get_Next();//store end chain after adding
      temp2->set_Next(temp);
      temp->set_Previous(temp2);
      temp2->get_Next()->set_Next(temp4);
      temp4->set_Previous(temp2->get_Next());
      break;
    }
    temp3=temp3->get_Next();
  }

}
int Doubly_link_list::get_value_at_given_index(int input)
{
  Node *temp;
  int counter=0,a;
  temp=first;
  while(temp!=NULL)
  {
    temp=temp->get_Next();
    counter++;
  }
  Node *temp3;
  temp3=first;
  for(a=0;a<=input;a++)
  {

    if(input==0)
    {
      return temp3->get_data();
      break;
    }
    else if(a==input)
    {
      cout << "Value at index " << temp3->get_data() << endl;
      break;
    }
    temp3=temp3->get_Next();
  }
}
int Doubly_link_list::find_value_return_index(int input)
{
  int check=0,counter=1;
  Node *temp;
  temp=first;
  if(temp->get_data()==input)//for first node
  {
    return 0;
  }
  else
  {
    while(temp!=NULL)
    {
    if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()==input)//For to find last node
    {
      return counter;
      break;
    }
    else if(temp->get_Next()->get_data()==input&&temp->get_Next()->get_Next()!=NULL)//for find middle node
    {
     return counter;
     break;
    }
    else if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()!=input)
    {
      return -1;
      break;
    }
    temp=temp->get_Next();
    counter++;
    }
  }
}
void Doubly_link_list::find_length_of_list()
{
  Node *temp=first;
  int counter=0;
  while(temp!=NULL)
  {
    counter++;
    temp=temp->get_Next();
  }
  cout << "Total length of your list " << counter << endl;
}
void Doubly_link_list::perform_actions_from_file_for_list()
{
  string input_for_function;
  int input_for_value;
  ifstream read;
  read.open("Data.txt");
  while(!read.eof())
  {
    read >> input_for_function;
    if(input_for_function=="A")
    {
      read >> input_for_value;
      add_node_end_list(input_for_value);
    }
    else if(input_for_function=="AAS")
    {
      read >> input_for_value;
      add_node_start_list(input_for_value);
    }
    else if(input_for_function=="RFS")
    {
      remove_node_from_start();
    }
    else if(input_for_function=="RFE")
    {
      remove_node_end_list();
    }
    else if(input_for_function=="R")
    {
      read >> input_for_value;
      remove_node_for_value(input_for_value);
    }
    else if(input_for_function=="RA")
    {
      read >> input_for_value;
      remove_node_for_index(input_for_value);
    }
    else if(input_for_function=="AT")
    {
      read >> input_for_value;
      int input;
      read >> input;
      add_node_at_index(input_for_value,input);
    }
    else if(input_for_function=="D")
    {
      display_list();
      input_for_function="None";
    }
  }
  read.close();
}
void Doubly_link_list::display_list()
{
  Node *temp=first;
  while(temp!=NULL)
  {
     cout << temp->get_data() << endl;
     temp=temp->get_Next();
  }
/*  while(temp!=NULL)
  {
  cout << temp->get_data() << endl;
  temp=temp->get_Previous();
  }
  */
}
int main()
{
  Doubly_link_list list;
  int a,input,choice;
  while(true)
  {
  cout << "*********************************************************\n";
  cout << "Here is menue for list to perform functions\n";
  cout << "Enter 1 to add node end of list\n";
  cout << "Enter 2 to add node start of list\n";
  cout << "Enter 3 remove node start of your list\n";
  cout << "Enter 4 remove node end of your list\n";
  cout << "Enter 5 remove node with your input value\n";
  cout << "Enter 6 remove node with index position\n";
  cout << "Enter 7 add value in your list at provided index\n";
  cout << "Enter 8 Return value from provided index position\n";
  cout << "Enter 9 Find value in your list with index position\n";
  cout << "Enter 10 Calculate size of your list\n";
  cout << "Enter 11 Display all values in your list\n";
  cout << "Enter 12 to perform actions from file\n";
  cout << "**********************************************************\n";
  cin >> input;
  if(input==1)
  {
    int data;
    cout << "Enter value for to add end of your list\n";
    cin >> data;
    list.add_node_end_list(data);
  }
  else if(input==2)
  {
    int data;
    cout << "Enter value to add start of your list\n";
    cin >> data;
    list.add_node_start_list(data);
  }
  else if(input==3)
  {
    list.remove_node_from_start();
  }
  else if(input==4)
  {
    list.remove_node_end_list();
  }
  else if(input==5)
  {
    cout << "Enter value you want to remove from list\n";
    int data;
    cin >> data;
    list.remove_node_for_value(data);
  }
  else if(input==6)
  {
    int data;
    cout << "Enter index from 0 to end of list to remove value of node\n";
    cin >> data;
    list.remove_node_for_index(data);
  }
  else if(input==7)
  {
    int data;
    int input;
    cout << "Enter index to add value in your list\n";
    cin >> data;
    cout << "Enter value to add at that index position\n";
    cin >> input;
    list.add_node_at_index(data,input);
  }
  else if(input==8)
  {
    int data,check;
    cout << "Enter index to find value in that index\n";
    cin >> data;
    check=list.get_value_at_given_index(data);
    cout << "Value at index " << data << " is " << check << endl;
  }
  else if(input==9)
  {
    cout << "Enter value to find its index position\n";
    int check,data;
    cin >> data;
    check=list.find_value_return_index(data);
    if(check!=-1)
    {
      cout << "Value " << data << " is stored at index " << check << endl;
    }
    else if(check==-1)
    {
      cout << "No match is found for your input value\n";
    }
  }
  else if(input==10)
  {
    list.find_length_of_list();
  }
  else if(input==11)
  {
    list.display_list();
  }
  else if(input==12)
  {
    list.perform_actions_from_file_for_list();
  }

  cout << "Enter 1 for to continue use functions for list or 0 to stop\n";
  cin >> choice;
  if(choice!=1)
  {
    break;
  }
 }
}
