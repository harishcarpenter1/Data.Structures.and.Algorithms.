//{ Driver Code Starts
#include <bits/stdc++.h> 
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
/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
class Solution{
  public:
    int listSize(Node* head) {
        int count = 0;
        Node* curr = head;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    Node* deleteMid(Node* head) {
        if ( head->next == NULL) {
            return NULL;
        }
        int middle = (listSize(head) / 2) + 1;
        Node* prev = NULL;
        Node* curr = head;
        // Bringing curr to the node to be deleted
        for (int i = 1; i < middle; i++) {
            prev = curr;
            curr = curr->next;
        }
        // Deleting the current node
        prev->next = curr->next;
        delete curr;
        return head;
    }
};



//{ Driver Code Starts.



void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		Solution obj;
		head = obj.deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends