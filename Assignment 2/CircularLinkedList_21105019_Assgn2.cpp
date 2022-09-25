/* [Question.1] While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element? */

//[Ans.1]
//Lets take an example and understand by traversing the circular linked list 
#include <iostream>
using namespace std;
//Creating Node class
class Node{
    //Creating class objects
    public:
    int data;
    Node*next;
    //Calling Node constructor
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
//Function to insert a node at end on linked list
void InsertAtEnd(Node*&head,int data){
    Node*curr=head;
    Node*new_node=new Node(data);
    if(curr==NULL){head=new_node;new_node->next=head;return;}
    while(curr->next!=head){curr=curr->next;}   //This condition establishes that the traversing element(temp) has reached the first element
    curr->next=new_node;
    new_node->next=head;
}
//Function to print elements of linked list from head to the last node.
void printlist(Node*&head){
    Node*curr=head;
    do{cout<<curr->data<<"->";curr=curr->next;}
    while(curr!=head);
}

int main(){
    Node*head=NULL;
    InsertAtEnd(head,9);
    InsertAtEnd(head,7);
    printlist(head);
}
/*
With reference to above example of circular linked list.
Line 24 i.e. while(curr->next!=head){curr=curr->next;} establishes that the pointer has again reached the first element.
This code indicates that we keep traversing throughout the linked list until we reach the head of the linked list again
*/



/*[Question.2]  What are the practical applications of a circular linked list? (Try to find applications in your respective fields).
Practical applications of circular linked list are :
1)Multiplayer Games: All the Players are kept in a Circular Linked List and the pointer keeps on moving forward as a player's chance ends.
2)Circular lists are used in applications where the entire list is accessed one-by-one in a loop.
3)Computing Resources: Circular Linked Lists is used to manage the computing resources of the computer.
4)It is also used by the Operating system to share time for different users, generally uses a Round-Robin time-sharing mechanism.3)Fionacci Heap: Circular Linked List is also used in the implementation of advanced data structures such as a Fibonacci Heap.
5)Computer Networking:Circular linked list is also used in computer networking for token scheduling.
6)Implementation of Advanced data structures like Fibonacci Heap
7)Implementation of Data Structure: Data structures such as stacks and queues are implemented with the help of the circular linked lists.
8)Audio/Video Streaming: Circular linked list is also used in audio and video streaming,for ex. when one copmlete audio list finishes playing in music player then it again starts playing from start.
9)The browser cache which allows you to hit the BACK button
10)Undo functionality in Photoshop or Word
11)Circular linked lists are used in Round Robin Scheduling
12)Circular linked list used Most recent list (MRU LIST)
*/
