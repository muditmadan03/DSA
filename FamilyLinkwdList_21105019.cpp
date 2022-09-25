#include <bits/stdc++.h>                   
using namespace std;                  

//Creating node class
class Node{
    public:
    
    //Creating class elements
    string name;
    int age;
    Node*next; 
    Node*prev; 
    
    //Constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; 
        prev=NULL; 
    }
};

//Function to insert elements at back of the linked list
void push_back(Node* &head,string name,int age){

    Node*temp=head;
    Node*new_node=new Node(name,age);

    //Inserting Node in empty list
    if(temp==NULL){
        head=new_node;
    }

    //Inserting node in non empty list
    else{
        while(temp->next!=NULL){
            temp=temp->next;    
        }
        temp->next=new_node;
        new_node->prev=temp;
    }
}

//Function to push(add) elements from front of the linked list 
void push_front(Node*&head,string name,int age){

    Node*new_node=new Node(name,age);

    //Inserting new node at head
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

//Print data from start to end of the linked list
void print_start(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<->";
        temp=temp->next;
    }
	
    //Printing last element 
    if(temp->next==NULL)
    {
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]";
    }
    cout<<endl;
}

//Print linked list beginning from last uptill the first element of linked list 
void print_end(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp->prev!=NULL)
    {
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<->";
        temp=temp->prev;
    }
	
    //Printing first element 
    if(temp->prev==NULL)
    {
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]";
    }
    cout<<endl;
}

//Function to delete the ith element in the linked list except the last element{
	
    //If its the first element 
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    
    //For any other value of i  
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){
            temp=temp->next; //Traversing to reach the correct index
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//Function to delete last element of the linked list
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){
	    temp=temp->next;    //Traversing to reach the last element of the list
    }
    temp->prev->next=NULL;
    delete temp;
}

int main(){

    Node*head=NULL;
	
	//Taking the number of family members as input
	int no_of_family_mem;
	cout<<"Enter Number Of Family Members:";
    	cin>>no_of_family_mem;

    	//Inserting family member's details and info into the list funtion
	for(int i=1;i<=no_of_family_mem;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";
		
		//To prevent getlien from taking white space caused by previous cin to take as input we ignore one cin 
        	cin.ignore();
		getline(cin,name);   
		
		cout<<"Enter Family Member "<<i<<" Age:";
        	cin>>age;
        	
		
		push_back(head,name,age);
	}
    cout<<endl;

    //Displaying Family details in doubly linked list
    cout<<"Following is the doubly linked list :"<<endl<<endl;
	
    //Printing linked list from beginnning to end using print_start funtion
    print_start(head);
}