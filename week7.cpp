

#include<iostream>
#include<queue>
using namespace std;
class node{
public:
int data;
node*left;
node*right;
node*parent;
node(int value){
data=value;
left=NULL;
right=NULL;
parent=NULL;
}
};
class BST{
public:
node*root;
//constructor
BST(){
root=NULL;
}
void insert1(node*current,int value){
if(current==NULL){current=new node(value);
root=current;
root->parent=NULL;
//return root;
}
else if(value>current->data){
    if(current->right==NULL){current->right=new node(value);
       current->right->parent=current;
    }
    else insert1(current->right,value);
}
else{
    if(current->left==NULL){current->left=new node(value);
    current->left->parent=current;
    }
    else insert1(current->left,value);
}
}
void insert(int value){
insert1(root,value);
}
void display1(node*current){
if(current==NULL) return;
display1(current->left);
cout<<current->data<<"  ";
 display1(current->right);
}
void display(){
display1(root);
cout<<endl;
}
bool search3(node*current,int value){
if(current==NULL){return false;}
else if(current->data==value)
{return true;}
else if(value>current->data) return search3(current->right,value);
else if(value<current->data) return search3(current->left,value);
}
void search(int value){
    if(search3(root,value)==1)
    cout<<endl<<"the element "<<value<<" is  found in the binary search tree  ";
    else
        cout<<" The element  "<<value<<" is not found  ";
}
//function to find minimum of all values
 node*findmin1(node*current){
//take current as argument
if(current->left==NULL)
    {return current;}
else return findmin1(current->left);
}
//function to return address of min node
node* findmin(){
return findmin1(root);
}
//return min element of BST
void replace1(node*current,node*temp){

int x=temp->data;
temp->data=current->data;
current->data=x;
}
void replace(node*current,int value){
node*temp=new node(value);
replace1(current,temp);
}
int min(){
return findmin1(root)->data;}
node* delete1(node*current,int value){
if(root==NULL) return root;
else if(value<current->data) current->left=delete1(current->left,value);
else if(value>current->data) current->right=delete1(current->right,value);
else{
    //desired element
    //CASE-------1
    if(current->left==NULL && current->right==NULL){
        delete current;
        current=NULL;
        return current;
    }
    //CASE--------2
    else if(current->left==NULL){
        node*temp=current;
        current=current->right;
        delete temp;
    }

    else if(current->right==NULL){
        node*temp=current;
        current=current->left;
        delete temp;
    }
   //CASE---------3
   else{
    node*temp=findmin1(current->right);
    node*as=current;
    current->data=temp->data;
     current->right=delete1(current->right,temp->data);
   }
}
  return current;
}
void Delete(int value){
if(search3(root,value)==1)
delete1(root,value);
else
    cout<<" entered no "<<value<<" is invalid"<<endl;
}
};
int main(){
BST b;
b.insert(6);
b.insert(5);
b.insert(3);
b.insert(8);
b.insert(4);
b.insert(10);
b.insert(9);
b.insert(13);
b.insert(14);
b.insert(18);
b.insert(17);
b.insert(16);
b.insert(15);
b.display();
b.search(5);
cout<<"the minimum element is :"<<b.findmin()->data<<b.min()<<endl;

cout<<endl<<"the root of tree is  "<<b.root->data<<endl;
cout<<endl;
b.display();
b.Delete(5);
cout<<endl<<"After delete "<<endl;
b.display();
b.Delete(4);
cout<<endl<<"After delete element  "<<endl;
b.display();
cout<<"the data of leaf nodes are  :";
return 0;
}
