//Basic Program for Creation of linkes list

#include<iostream>
using namespace std;

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
  temp=NULL;
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
  print(root);
  return 0;
}
