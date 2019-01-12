#include <iostream>
using namespace std;
class Node
{
    public:
    int data;//stores the data
    Node* next;//pointer to the next node
    public:
    Node()//default constructor
    {
        data=0;//data inilialized to 0
        next=NULL;//pointer initialized to null
    }
};
class LinkedList
{
    //start and nodes inside linked with each other
    public:
    Node* start;//start is a node type pointer
    public:
    LinkedList()//default constructor
    {
        start=NULL;//initializes start to null
    }
    void insertVal(int value)
    {
    Node* ptr=new Node;//new node created of Node type
        ptr->data=value;//data stores the value to be stored in the node
        if(start==NULL)//if the list is empty
        start=ptr;//the first element is added
        else
        {
            Node* temp=start;//new pointer to traverse the list
            while(temp->next!=NULL)//while the end of the list is reached            
        temp=temp->next;//temp traverses the list
        temp->next=ptr;//the pointer of the current node points to the new node to be inserted
        }
        cout<<value<<" has been inserted in the Linked List.\n";
    }//end of function to insert a value into the linked list
    void insertAt(int position,int value)//insertion function
    {
        Node* ptr=new Node;//new node created of Node type
        ptr->data=value;//data stores the value to be stored in the node
        if(start==NULL||position==1)//if the list is empty
        start=ptr;//the first element is added
        else
        {
            Node* temp=start;//new pointer to traverse the list
            int i=1;//variable to denote the position of the pointer temp
            while(temp->next!=NULL&&i<position-1)//while the end of the list is reached or the required position is reached
            {
        temp=temp->next;//temp traverses the list
        i++;
        }
            ptr->next=temp->next;//the pointer of the node ptr points to the next node in the list
            temp->next=ptr;//the pointer of the current node points to the new node to be inserted
        }
        cout<<value<<" has been inserted in the Linked List.\n";
    }//end of function to insert a value into the linked list
    int deleteVal()
    {
    Node* temp=start;//pointer temp to traverse the list
        int delVal=0;//variable to store the dleted value
        if(temp==NULL)//if the first node is to be deleted
        return -9999;
    else if(temp->next==NULL)//if there is one element in the list
    {
        delVal=temp->data;//its value is stored
        delete temp;//it is deleted
    }
        else
        {
            while(temp->next->next!=NULL)//while the end of the list is reached
            temp=temp->next;//the pointer temp traverses through the list
            Node* temp1=temp->next;//new pointer to point to the last node in the list
            temp->next=NULL;//pointer of second last node becomes null, that is end of the list
            delVal=temp1->data;//the data removed is stored
            delete temp1;//the last node is deleted
        }
        return delVal;//the value deleted is returned
    }
    int deleteAt(int position)//deletion function
    {
        Node* temp=start;//pointer temp to traverse the list
        int delVal=0;//variable to store the dleted value
        if(position==1)//if the first node is to be deleted
        {
            start=temp->next;//start points to the second element in the list
            temp->next=NULL;//the first element is disconnected from the list
            delVal=temp->data;//its data is stored
            delete temp;//the node is deleted
        }
        else
        {
            int i=1;//variable to denote the position of the pointer temp
            while(temp->next!=NULL&&i<position-1)//while the end of the list is reached or the required position is reached
            {
        temp=temp->next;//the pointer temp traverses through the list
        i++;
        }
            Node* temp1=temp->next;//new pointer to point to the next node in the list
            temp->next=temp->next->next;//pointer of current node points to the second following node in the list
            temp1->next=NULL;//the next node is disconnected from the list
            delVal=temp1->data;//the data removed is stored
            delete temp1;//the node is deleted
        }
        return delVal;//the value deleted is returned
    }
    int countItems()//function to count the number of elements in the list
    {
    int counter=0;//variable to store the number of elements in the list
    Node* temp=start;//pointer to traverse the list
    while(temp!=NULL)//till the endof the list is reached
    {
        temp=temp->next;//pointer moves forward
        counter++;//number of elements incremented
    }
    return counter;//number of elements returned
    }
    void display()//display function
    {
        Node* temp=start;//pointer to traverse through the list
        while(temp!=NULL)//while the end of the list is reached
        {
            cout<<temp->data<<", ";//the data is printed
            temp=temp->next;//the pointer is moved forward
        }
        cout<<".\n";
    }
};//end of class Linked List
int main()//main function
{
    cout<<"Linked List Object.";
    LinkedList list;//object of Linked List class created
    int choice=0;
    int val=0;
    int pos=0;
    cout<<"Enter 1 to add an element to the end of the linked list\n";
    cout<<"Enter 2 to add an element at a specified position in the linked list.\n";
    cout<<"Enter 3 to delete an element from the end of the linked list.\n";
    cout<<"Enter 4 to delete an element from a specified position in the linked list.\n";
    cout<<"Enter 5 to count the number of elements in th linked list.\n";
    cout<<"Enter 6 to display the elements of the linked list.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
        case 1 :cout<<"Enter the value to be added to the end of the linked list\n";
                    cin>>val;
                    list.insertVal(val);
                    break;
            case 2 :cout<<"Enter the value to be added to the linked list\n";
                    cin>>val;
                    cout<<"Enter the position where the value has to be inserted\n";
                    cin>>pos;
                    list.insertAt(pos,val);
                    break;
        case 3 :val=list.deleteVal();
            cout<<val<<" has been deleted from the linked list.\n";
               break;
            case 4 :cout<<"Enter the position to be deleted from the linked list\n";
                    cin>>pos;
                    val=list.deleteAt(pos);
                    cout<<val<<" has been deleted from the linked list.\n";
                    break;
        case 5 :val=list.countItems();
            cout<<"The number of elements in the list is "<<val<<endl;
            break;
            case 6 :list.display();
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}