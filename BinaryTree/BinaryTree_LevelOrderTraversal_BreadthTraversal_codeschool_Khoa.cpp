/* Binary tree - Level Order Traversal */
#include<iostream>
#include<queue>
using namespace std;

struct Node {
	char data;
	Node *left;
	Node *right;
};

// Function to print Nodes in a binary tree in Level order
void LevelOrder(Node* temp){
    queue<Node*> Q;                                                 // cần phải tạo thêm queue để thực hiện thuật toán này
    if (temp == NULL)
        return;
    else{
        Q.push(temp);
        while (!Q.empty()){
            Node* bien;
            bien = Q.front();
            cout << " " << bien->data;
            if (bien->left != NULL) Q.push(bien->left);            //  ý nghĩa của thuật toán này là trước khi lấy parent ra khỏi queue thì phải đẩy children của nó vào queue trước
            if (bien->right != NULL) Q.push(bien->right);
            Q.pop();
        }
    }
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');
	//Print Nodes in Level Order. 
	LevelOrder(root);
}