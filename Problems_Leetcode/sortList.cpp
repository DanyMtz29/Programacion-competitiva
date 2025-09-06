#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void showList(ListNode* head){
    cout<<"\nLISTA"<<endl;
    ListNode* aux = head;
    while(aux){
        cout<<aux->val<<"|";
        aux = aux->next;
    }
    cout<<endl;
}

ListNode* sort(ListNode* left, ListNode* right){
    ListNode* prev = new ListNode(-1);
    ListNode* aux = prev;
    while(left && right){
        if(left->val < right->val){
            aux->next = left;
            left = left->next;
        }else{
            aux->next = right;
            right = right->next;
        }
        aux=aux->next;
    }
    aux->next= (left)?left:right;
    return prev->next;
}

ListNode* solve(ListNode* head){
    if(!head->next) return head;

    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next=NULL;
    ListNode* left = solve(head);
    ListNode* right = solve(mid);
    return sort(left,right);
}

int main(){
    ListNode* head = new ListNode(7);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(9);
    head->next->next->next->next = new ListNode(1);
    showList(head);
    ListNode* head2 = solve(head);
    showList(head2);
    return 0;
}