#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode 
{
	string name;
	TreeNode* parent;
	vector<TreeNode*> children;
};

class Tree 
{
private:
	TreeNode* root;
public:
	TreeNode* pointer;
	Tree();
	~Tree();
	bool exists(string name);
	void insert(string name);
	void remove(TreeNode* root);
	void printchildren(TreeNode* root);
	int count(TreeNode* root);
	void showtree(TreeNode* root);
};