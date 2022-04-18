#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


Node* connect(Node* root) {
    if(root == nullptr)
        return nullptr;
    
    queue<Node*> q;
    q.push(root);

    int l = 1, i = 0;
    
    Node* previousNode = nullptr;
    while (!q.empty()) {
        Node* currentNode = q.front();
        q.pop();
        
        if(i == 0) {
            currentNode->next = nullptr;
        } else {
            currentNode->next = previousNode;
        }

        i++;
        if(i == l) {
            l *= 2;
            i = 0;
        }

        if(currentNode->right != nullptr) q.push(currentNode->right);
        if(currentNode->left != nullptr) q.push(currentNode->left);

        previousNode = currentNode;
    }
    
    return root;
}


void constructTree(string treeString, Node* &root) {
    if(treeString.empty())
        return;
    
    int start;
    int end = 0;
 
    vector<int> nodesVals;
    while ((start = treeString.find_first_not_of(" ", end)) != std::string::npos)
    {
        end = treeString.find(" ", start);
        nodesVals.push_back(stoi(treeString.substr(start, end - start)));
    }

    int n = nodesVals.size();
    
    if(n == 0)
        return;
    
    root = new Node(nodesVals[0]);
    
    queue<Node*> q;
    q.push(root);
    
    int i = 0;

    while (!q.empty()) {

        Node* currentNode = q.front();
        q.pop();

        int leftIdx = 2*i + 1;
        int rightIdx = 2*i+ 2;

        if(leftIdx < n) {
            currentNode->left = new Node(nodesVals[leftIdx]);
            q.push(currentNode->left);
        }
        
        if(rightIdx < n) {
            currentNode->right = new Node(nodesVals[rightIdx]);
            q.push(currentNode->right);
        }

        i++;
    }
    
}

void printTree(Node* root) {
    if(root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* currentNode = q.front();
        q.pop();
        
        
        cout<<currentNode->val<<" ";
        if(currentNode->left != nullptr) 
            q.push(currentNode->left);
        
        if(currentNode->right != nullptr) 
            q.push(currentNode->right);
    }
}

void printLevels(Node* root) {
    if(root == nullptr)
        return;
    
    Node* iter = root;
    while (iter != nullptr){
        cout<<iter->val<<" ";
        iter = iter->next;
    }
    
    cout<<"# ";
    printLevels(root->left);
}

int main() {
    
    string treeString;
    
    getline(cin, treeString);

    Node* root = nullptr;

    constructTree(treeString, root);
    
    root = connect(root);

    printLevels(root);
    
    return 0;
}