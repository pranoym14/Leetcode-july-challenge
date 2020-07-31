/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        Node* p=head,*prev=nullptr;
        stack <Node*> s;
        while(p)
        {
            if(p->child)
            {
                while(p->child)
                {
                    if(p->next)
                    s.push(p->next);
                    p->next=p->child;
                    p->child->prev=p;
                    p->child=nullptr;
                    prev=p;
                    p=p->next;
                }
            }
            else
               { prev=p;
            p=p->next;}
        }
        p=prev;
        while(!s.empty())
        {
            if(!p->next)
           { p->next=s.top();
            s.top()->prev=p;
            s.pop();}
            p=p->next;
        }
        p=head;
        // while(p->next)
        //    { cout<<p->val;p=p->next;}
            // p->next=head;
        return head;
    }
};