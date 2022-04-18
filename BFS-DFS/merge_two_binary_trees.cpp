#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1 == nullptr) {
        return root2;
    } else if(root2 == nullptr) {
        return root1;
    } else {
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
}

void constructTree(string treeString, TreeNode* &root) {
    int start;
    int end = 0;
 
    vector<string> nodesVals;
    while ((start = treeString.find_first_not_of(" ", end)) != std::string::npos)
    {
        end = treeString.find(" ", start);
        nodesVals.push_back(treeString.substr(start, end - start));
    }

    int n = nodesVals.size();
    
    if(n == 0)
        return;
    
    root = new TreeNode(stoi(nodesVals[0]));
    
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 0;

    while (!q.empty()) {
        if(nodesVals[i] == "null") {
            i++;
            continue;
        }

        TreeNode* currentNode = q.front();
        q.pop();

        int leftIdx = 2*i + 1;
        int rightIdx = 2*i+ 2;

        if(leftIdx < n && nodesVals[leftIdx] != "null") {
            currentNode->left = new TreeNode(stoi(nodesVals[leftIdx]));
            q.push(currentNode->left);
        }
        
        if(rightIdx < n && nodesVals[rightIdx] != "null") {
            currentNode->right = new TreeNode(stoi(nodesVals[rightIdx]));
            q.push(currentNode->right);
        }

        i++;
    }
    
}

void printTree(TreeNode* root) {

    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* currentNode = q.front();
        q.pop();
        
        if(currentNode->val == -10e5) {
            cout<<"null ";
            continue;
        }

        cout<<currentNode->val<<" ";
        if(currentNode->left != nullptr) 
            q.push(currentNode->left);
        else if(currentNode->left == nullptr && currentNode->right != nullptr)
            q.push(new TreeNode(-10e5));
        
        if(currentNode->right != nullptr) q.push(currentNode->right);
    }
}

int main() {
    string tree1String, tree2String;
    
    getline(cin, tree1String);
    getline(cin, tree2String);

    TreeNode* root1, *root2;

    constructTree(tree1String, root1);
    constructTree(tree2String, root2);

    TreeNode* mergedTree = mergeTrees(root1, root2);

    printTree(mergedTree);

    return 0;
}