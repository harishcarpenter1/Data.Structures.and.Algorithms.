//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    
struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int>s;
    
    Node * c1 = head1;
    Node * c2 = head2;
    
    Node * head = NULL;
    Node * c3 = NULL;
    
    while(c1!= NULL){
        s.insert(c1->data);
        c1 = c1->next;
    }
    
    while(c2!= NULL){
        s.insert(c2->data);
        c2 = c2->next;
    }
    
    for(auto it = s.begin(); it!= s.end(); it++){
        if(head == NULL){
            Node * temp = new Node(*it);
            head = temp;
            c3 = head;
        }else{
            Node * temp = new Node(*it);
            c3->next = temp;
            c3 = temp;
        }
    }
    
    return head;
}
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends