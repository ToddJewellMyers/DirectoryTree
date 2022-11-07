#include "Tree.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Tree constructor
Tree::Tree()
{
	TreeNode* newnode = new TreeNode;
	newnode->name.assign("root");
	root = newnode;
    root->parent = NULL;
	pointer = root;
}

Tree::~Tree() 
{

}

//Exists function for exists command
bool Tree::exists(string name) 
{
    if (root == NULL) 
    {
        return false;
    }

    //using items in queue, loop until queue is empty
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        while (n > 0)
        {
            TreeNode* p = q.front();
            q.pop();
            if (p->name.compare(name) == 0) 
            {
                return true;
            }

            for (int i = 0; i < p->children.size(); i++)
                q.push(p->children[i]);
            n--;
        }
    }
    return false;
}

//insert function for mkdir command
void Tree::insert(string name) 
{
	TreeNode* newnode = new TreeNode;
	newnode->name.assign(name);

	newnode->parent = pointer;
	pointer->children.push_back(newnode);
}

//remove function for rmdir command
void Tree::remove(TreeNode* root)
{
    if (root == NULL) 
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++) 
    {
        remove(root->children[i]);
    }

    delete root;
}

//printchildren function for ls command
void Tree::printchildren(TreeNode* root) 
{
    for (int i = 0; i < root->children.size(); i++) 
    {
        cout << root->children[i]->name << " ";
    }
    cout << endl;
}

//count function for countdir command
int Tree::count(TreeNode* root)
{
    int count = 0;

    if (root == NULL) 
    {
        return count;
    }
    
    //using items in queue, loop until queue is empty
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        while (n > 0)
        {
            TreeNode* p = q.front();
            q.pop();
            count++;

            for (int i = 0; i < p->children.size(); i++)
                q.push(p->children[i]);
            n--;
        }
    }

    return count;
}

//showtree function for showtree command
void Tree::showtree(TreeNode* root) 
{
    string tab = "";
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    //using items in queue, loop until queue is empty
    while (!q.empty())
    {
        int n = q.size();

        while (n > 0)
        {
            TreeNode* p = q.front();
            q.pop();
            cout << p->name << " ";

            for (int i = 0; i < p->children.size(); i++)
                q.push(p->children[i]);
            n--;
        }
        cout << endl;
        if (!q.empty()) 
        {
            tab.append("    ");
            cout << tab;
        }
    }
}