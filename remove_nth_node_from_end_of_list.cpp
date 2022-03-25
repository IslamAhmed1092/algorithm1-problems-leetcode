#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* firstItr = head, *secondItr = nullptr;

    int i = 0;
    while (firstItr->next != nullptr) {
        firstItr = firstItr->next;
        if (i == n-1) secondItr = head;
        else if(i >= n) secondItr = secondItr->next;
        i++;
    }
    
    if(secondItr == nullptr) {
        // remove the head
        head = head->next;
    } else {
        // remove the node in the next of secondItr
        secondItr->next = secondItr->next->next;
    }

    return head;
}


// utility functions

void insert(ListNode* &head, ListNode* newNode) {
    ListNode* iter = head;

    if(iter == nullptr) {
        head = newNode;
        return;
    }

    while (iter->next != nullptr) {
        iter = iter->next;
    }

    iter->next = newNode;

}

void printLinkedList(ListNode* head) {
    ListNode* iter = head;
    while (iter != nullptr) {
        cout<<iter->val<<" ";
        iter = iter->next;
    }

    cout<<endl;
}

int main() {
    int n, nth;
    cin>>n>>nth;

    ListNode* head = nullptr;

    int val;
    for (int i = 0; i < n; i++) {
        cin>>val;
        ListNode* newNode = new ListNode(val);
        insert(head, newNode);
    }
    
    ListNode* newHead = removeNthFromEnd(head, nth);

    printLinkedList(newHead);

    return 0;
}