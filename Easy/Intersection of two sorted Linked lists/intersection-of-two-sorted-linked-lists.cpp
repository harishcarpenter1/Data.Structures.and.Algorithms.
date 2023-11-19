//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    
    /* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node * head = NULL;
    Node * curr = NULL;
    
    Node * t1 = head1;
    Node * t2 = head2;
    
    while(t1!=NULL && t2!=NULL){
        if(t1->data == t2->data){
            if(head == NULL){
                Node * NodeToBe = new Node(t1->data);
                head = NodeToBe;
                curr = head;
            }
            else{
                Node * NodeToBe = new Node(t1->data);
                curr->next = NodeToBe;
                curr = NodeToBe;
            }
            t1 = t1->next;
            t2 = t2->next;
        }else{
            if(t1->data < t2->data){
                t1 = t1->next;
            }else{
                t2 = t2->next;
            }
        }
    }
    
    return head;
    
}
    
    
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends