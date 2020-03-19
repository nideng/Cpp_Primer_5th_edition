#ifndef TREENODE_H
#define TREENODE_H
#include<string>
using namespace std;
class TreeNode {
private:
	string value;
	int *count;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode():value(string()),count(new int(1)),left(nullptr),right(nullptr){}
	TreeNode(const TreeNode&t)
		:value(t.value),count(t.count), left(t.left), right(t.right) {
		++*count;
	}
	TreeNode& operator=(const TreeNode& t)
	{
		++* t.count;
		if (-- * count == 0)
		{
			delete left;
			delete right;
			delete count;
		}
		value = t.value;
		count = t.count;
		left = t.left;
		right = t.right;
		return *this;
	}
	~TreeNode()
	{
		if (--* count == 0)
		{
			delete count;
			delete left;
			delete right;
		}
	}
};
class BinStrTree
{
private:
	TreeNode* root;
public:
	BinStrTree() :root(new TreeNode()){}
	BinStrTree(const BinStrTree&s):root(new TreeNode(*s.root)){}
	BinStrTree& operator=(const BinStrTree& s)
	{
		auto newp = new TreeNode(*s.root);
		delete root;
		root = newp;
		return *this;
	}
};
#endif  