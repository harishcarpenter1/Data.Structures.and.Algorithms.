//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    
struct Node * mergeResult(Node *node1,Node *node2)
{
    
    Node * RES = NULL;
    
    Node * c1 = node1;
    Node * c2 = node2;
    
    while(c1 && c2)
    {
        if(c1->data <= c2->data)
        {
           
           Node * temp = c1->next;
           c1->next = RES;
           RES = c1;
           c1 = temp;
        }
        else
        {
            Node * temp = c2->next;
            c2->next = RES;
            RES = c2;
            c2 = temp;
        }
    }
    
    while(c1){
        Node * temp = c1->next;
        c1->next = RES;
        RES = c1;
        c1 = temp;
    }
    
    while(c2)
    {
        Node * temp = c2->next;
        c2->next = RES;
        RES = c2;
        c2 = temp;
    }
    
    return RES;
    } 
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends