//https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1


/*This is a function problem.You only need to complete the function given below*/
/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// Your are required to complete this function
// function should return root of the modified BST
void inorder(Node *root, vector<int>& vec){
    if(root==NULL)
        return ;
    inorder(root->left,vec);
    vec.push_back(root->data);
    inorder(root->right,vec);
}

Node* formBST(vector<int>& vec,int begin, int end){
    if(begin>end)
        return NULL;
        
    int mid=(begin+end)/2;
    Node* root=new Node();
    root->data=vec[mid];
    root->left=formBST(vec,begin,mid-1);
    root->right=formBST(vec,mid+1,end);
    
    return root;
}


Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> vec;
	inorder(root,vec);
	int n=vec.size();
	return formBST(vec,0,n-1);
}
