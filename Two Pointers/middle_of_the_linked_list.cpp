#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    int n = 0;
    ListNode* iter = head;
    while (iter != nullptr) {
        n++;
        iter = iter->next;
    }

    iter = head;
    for (int i = 0; i < n/2; i++) {
        iter = iter->next;
    }

    return iter;
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
    int n;
    cin>>n;

    ListNode* head = nullptr;

    int val;
    for (int i = 0; i < n; i++) {
        cin>>val;
        ListNode* newNode = new ListNode(val);
        insert(head, newNode);
    }

    // printLinkedList(head);

    ListNode* middle = middleNode(head);

    printLinkedList(middle);

    return 0;
}