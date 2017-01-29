//This Program illustrates how we can reverse linked list using only
//"2 Pointers", Remember we are going to reverse linked list sing only 2 pointers

#include<iostream>
#include<cstdint>
using namespace std;

typedef uintptr_t ui;
struct Node
{
  int info;
  struct Node * next;
};

struct Node* CreateNode()
{
  struct Node *p = new Node;
  p->info=0;
  p->next=NULL;
  return p;
}

//Function to reverse Linked List
void ReverseLinkedList(struct Node* & root)
{
  struct Node* current = root;
  struct Node* prev    = NULL;

  while(current != NULL)
  {
    current = (struct Node*)((ui)prev ^ (ui)current ^ (ui)current->next ^ (ui)(current->next=prev) ^ (ui)(prev=current));
  }
  root = prev;
}
//Function to insert node
void InsertNode(struct Node* & root, int info)
{
  if (NULL == root)
  {
    root = CreateNode();
    root->info= info;
  }
  else
  {
    struct Node *temp= root;
    while(NULL!=temp->next)
       temp=temp->next;
    struct Node * p =CreateNode();
    p->info=info;
    temp->next= p;
  }
}

void print(struct Node* root)
{
  struct Node* temp = root;
  while(NULL!=temp->next)
  {
    cout<<temp->info<<"->";
    temp=temp->next;
  }
  cout<<temp->info;
  cout<<"\n";
}

//Driver code
int main()
{
  struct Node* root = NULL;
  int arr[]={1,2,3,4};
  int arr_size = sizeof(arr)/sizeof(arr[0]);

  for(int i=0; i< arr_size; i++)
  {
    InsertNode(root, arr[i]);
  }
  cout<<"\n Linked List Before Reversing:\n";
  print(root);
  ReverseLinkedList(root);
  cout<<"\n Linked List After Reversing:\n";
  print(root);
  return 0;
}
