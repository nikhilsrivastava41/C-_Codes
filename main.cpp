#include<iostream>
using namespace std;

//########### PRINT BOUNDARY TRAVERSAL OF BINARY TREE ############
class TreeNode{
	public:
	TreeNode *left;
	TreeNode* right;
	int data;
};
void printleft(TreeNode *root) {
	if (!root)
		return;
	if (root->left) {
		cout << root->data << endl;
		printleft(root->left);
	}
	else if (root->right) {
		cout << root->data << endl;
		printleft(root->right);
	}
	return;
}
void printleave(TreeNode *root) {
	if (!root) {
		return;
	}
	printleave(root->left);
	if (!root->left && !root->right) {
		cout << root->data << endl;
	}
	printleave(root->right);
}
void printright(TreeNode *root) {
	if (!root) {
		return;
	}
	if (root->right) {
		printright(root->right);
		cout << root->data << endl;
	}
	else if (root->left) {
		printright(root->left);
		cout << root->data << endl;
	}
	return;
}
void print(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << endl;
	printleft(root->left);
	printleave(root->left);
	printleave(root->right);
	printright(root->right);
}
char* reverse(char* s,int size){
	if(size==1)
		return s;
	char *ans;
	
}
int main() {
	//print(root);
	char* s ="Nikhil";
	cout<<s<<endl;
	cout<<reverse(s,6)<<endl;
	return 0;
}