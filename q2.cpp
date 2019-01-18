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
    void print()//function to print the elements of the linked list
    {
        Node* temp=start;//pointer to traverse through the list
        while(temp!=NULL)//while the end of the list is reached
        {
            cout<<temp->data<<", ";//the data is printed
            temp=temp->next;//the pointer is moved forward
        }
        cout<<".\n";
    }
    void insertValAtEnd(int value)//function to insert a node at the tail of the linked list
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
    void insertValAtStart(int value)//function to insert a node at the head of the linked list
    {
        Node* ptr=new Node;//new node created of Node type
        ptr->data=value;//data stores the value to be stored in the node
        if(start==NULL)//if the list is empty
        start=ptr;//the first element is added
        else
        {
            ptr->next=start;//the current node points to the first node in the list
            start=ptr;//strat points to the current node
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
    int deleteValAtEnd()//function to delete a node from the tail of the linked list
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
    }//end of method to delete a node from the tail of the linked list
    int deleteValAtStart()//function to delete a node from the head of the linked list
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
            start=start->next;//new start points to the second node in the list
            temp->next=NULL;//pointer of first node becomes null, that is removed from the list
            delVal=temp->data;//the data removed is stored
            delete temp;//the last node is deleted
        }
        return delVal;//the value deleted is returned
    }//end of function to delete a node from the head of the linked list
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
    void printReverse()//function to print the elements in the reverse order
    {
	int noOfNodes=countItems();
	Node* temp=NULL;
	for(int i=noOfNodes;i>0;i--)
	{
	    temp=start;
	    int j=1;
	    while(j++<i)
	    temp=temp->next;
	    cout<<temp->data<<", ";
	}
	cout<<"."<<endl;	
    }//end of function to print the elements of the linked list in the reversed order
    void printRev(Node* temp)
    {
        if(temp->next==NULL)
        cout<<temp->data<<", ";
        else
        {
            printRev(temp->next);
            cout<<temp->data<<", ";
        }
    }
    void reverse()//function to reverse the elements of the linked list
    {
	if(start==NULL)//if the list is empty then there is no list to reverse
        cout<<"The list is empty\n";
	else
	{
	    int noOfNodes=this->countItems();//number of nodes in the list is counted
	    Node* first=start;//pointer to the first node to be swapped
	    Node* last=NULL;//pointer to the last node to be swapped
	    Node* temp=NULL;//pointer to traverse the list and determine the last node to be swapped
	    for(int i=0;i<noOfNodes/2;i++)//number of times swapping takes place is half the number of elements in the list
	    {
		temp=start;//temp starts from the beginning of the list
		while(temp->next!=last)//till the last element of the unreversed list is obtained
		temp=temp->next;//it traverses the list
		last=temp;//last updated to the last unreversed element in the list
		last->data=last->data+first->data;//data swapped
		first->data=last->data-first->data;
		last->data=last->data-first->data;
		first=first->next;//first updated to the first unreversed element in the list
	    }
	}
    }//end of method to reverse the elements of the linked list     
};
int main()//main function
{
    cout<<"Linked List Object.\n";
    LinkedList list;//object of Linked List class created
    int choice=0;
    int val=0;
    int pos=0;
    cout<<"Enter 1 to add an element to the end of the linked list\n";
    cout<<"Enter 2 to add an element to the beginnning of the linked list\n";
    cout<<"Enter 3 to add an element at a specified position in the linked list.\n";
    cout<<"Enter 4 to delete an element from the end of the linked list.\n";
    cout<<"Enter 5 to delete an element from the beginning of the linked list/\n";
    cout<<"Enter 6 to delete an element from a specified position in the linked list.\n";
    cout<<"Enter 7 to count the number of elements in th linked list.\n";
    cout<<"Enter 8 to display the elements of the linked list.\n";
    cout<<"Enter 9 to display the elements of the linked list in the reverse order.\n";
    cout<<"Enter 10 to reverse the elements of the linked list.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be added to the end of the linked list\n";
                    cin>>val;
                    list.insertValAtEnd(val);
                    break;
	        case 2 :cout<<"Enter the value to be added to the beginning of the linked list\n";
                    cin>>val;
                    list.insertValAtStart(val);
                    break;
            case 3 :cout<<"Enter the value to be added to the linked list\n";
                    cin>>val;
                    cout<<"Enter the position where the value has to be inserted\n";
                    cin>>pos;
                    list.insertAt(pos,val);
                    break;
            case 4 :val=list.deleteValAtEnd();
            	    cout<<val<<" has been deleted from the linked list.\n";
               	    break;
	        case 5 :val=list.deleteValAtStart();
            	    cout<<val<<" has been deleted from the linked list.\n";
               	    break;
            case 6 :cout<<"Enter the position to be deleted from the linked list\n";
                    cin>>pos;
                    val=list.deleteAt(pos);
                    cout<<val<<" has been deleted from the linked list.\n";
                    break;
            case 7 :val=list.countItems();
            	    cout<<"The number of elements in the list is "<<val<<endl;
            	    break;
            case 8 :list.print();
                    break;
	        case 9 :list.printRev(list.start);
	                cout<<".\n";
		            break;
	        case 10:list.reverse();
		            cout<<"The list after reverseing is:\n";
                    list.print();
		    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}



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
    void print()//function to print the elements of the linked list
    {
        Node* temp=start;//pointer to traverse through the list
        while(temp!=NULL)//while the end of the list is reached
        {
            cout<<temp->data<<", ";//the data is printed
            temp=temp->next;//the pointer is moved forward
        }
        cout<<".\n";
    }
    void insertValAtEnd(int value)//function to insert a node at the tail of the linked list
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
    void insertValAtStart(int value)//function to insert a node at the head of the linked list
    {
        Node* ptr=new Node;//new node created of Node type
        ptr->data=value;//data stores the value to be stored in the node
        if(start==NULL)//if the list is empty
        start=ptr;//the first element is added
        else
        {
            ptr->next=start;//the current node points to the first node in the list
            start=ptr;//strat points to the current node
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
    int deleteValAtEnd()//function to delete a node from the tail of the linked list
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
    }//end of method to delete a node from the tail of the linked list
    int deleteValAtStart()//function to delete a node from the head of the linked list
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
            start=start->next;//new start points to the second node in the list
            temp->next=NULL;//pointer of first node becomes null, that is removed from the list
            delVal=temp->data;//the data removed is stored
            delete temp;//the last node is deleted
        }
        return delVal;//the value deleted is returned
    }//end of function to delete a node from the head of the linked list
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
    void printReverse()//function to print the elements in the reverse order
    {
	int noOfNodes=countItems();
	Node* temp=NULL;
	for(int i=noOfNodes;i>0;i--)
	{
	    temp=start;
	    int j=1;
	    while(j++<i)
	    temp=temp->next;
	    cout<<temp->data<<", ";
	}
	cout<<"."<<endl;	
    }//end of function to print the elements of the linked list in the reversed order
    void printRev(Node* temp)
    {
        if(temp->next==NULL)
        cout<<temp->data<<", ";
        else
        {
            printRev(temp->next);
            cout<<temp->data<<", ";
        }
    }
    void reverse()//function to reverse the elements of the linked list
    {
	if(start==NULL)//if the list is empty then there is no list to reverse
        cout<<"The list is empty\n";
	else
	{
	    int noOfNodes=this->countItems();//number of nodes in the list is counted
	    Node* first=start;//pointer to the first node to be swapped
	    Node* last=NULL;//pointer to the last node to be swapped
	    Node* temp=NULL;//pointer to traverse the list and determine the last node to be swapped
	    for(int i=0;i<noOfNodes/2;i++)//number of times swapping takes place is half the number of elements in the list
	    {
		temp=start;//temp starts from the beginning of the list
		while(temp->next!=last)//till the last element of the unreversed list is obtained
		temp=temp->next;//it traverses the list
		last=temp;//last updated to the last unreversed element in the list
		last->data=last->data+first->data;//data swapped
		first->data=last->data-first->data;
		last->data=last->data-first->data;
		first=first->next;//first updated to the first unreversed element in the list
	    }
	}
    }//end of method to reverse the elements of the linked list     
};
int main()//main function
{
    cout<<"Linked List Object.\n";
    LinkedList list;//object of Linked List class created
    int choice=0;
    int val=0;
    int pos=0;
    cout<<"Enter 1 to add an element to the end of the linked list\n";
    cout<<"Enter 2 to add an element to the beginnning of the linked list\n";
    cout<<"Enter 3 to add an element at a specified position in the linked list.\n";
    cout<<"Enter 4 to delete an element from the end of the linked list.\n";
    cout<<"Enter 5 to delete an element from the beginning of the linked list/\n";
    cout<<"Enter 6 to delete an element from a specified position in the linked list.\n";
    cout<<"Enter 7 to count the number of elements in th linked list.\n";
    cout<<"Enter 8 to display the elements of the linked list.\n";
    cout<<"Enter 9 to display the elements of the linked list in the reverse order.\n";
    cout<<"Enter 10 to reverse the elements of the linked list.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be added to the end of the linked list\n";
                    cin>>val;
                    list.insertValAtEnd(val);
                    break;
	        case 2 :cout<<"Enter the value to be added to the beginning of the linked list\n";
                    cin>>val;
                    list.insertValAtStart(val);
                    break;
            case 3 :cout<<"Enter the value to be added to the linked list\n";
                    cin>>val;
                    cout<<"Enter the position where the value has to be inserted\n";
                    cin>>pos;
                    list.insertAt(pos,val);
                    break;
            case 4 :val=list.deleteValAtEnd();
            	    cout<<val<<" has been deleted from the linked list.\n";
               	    break;
	        case 5 :val=list.deleteValAtStart();
            	    cout<<val<<" has been deleted from the linked list.\n";
               	    break;
            case 6 :cout<<"Enter the position to be deleted from the linked list\n";
                    cin>>pos;
                    val=list.deleteAt(pos);
                    cout<<val<<" has been deleted from the linked list.\n";
                    break;
            case 7 :val=list.countItems();
            	    cout<<"The number of elements in the list is "<<val<<endl;
            	    break;
            case 8 :list.print();
                    break;
	        case 9 :list.printRev(list.start);
	                cout<<".\n";
		            break;
	        case 10:list.reverse();
		            cout<<"The list after reverseing is:\n";
                    list.print();
		    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}

