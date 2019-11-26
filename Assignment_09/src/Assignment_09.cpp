//============================================================================
// Name        : Assignment_09.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	int nodeValue;
	int bf;
	node * left;
	node * right;
};

class BST
{
private:
	node * root;

	void traverseInOrderInternal(node *);		// internal functions - all by subtree
	void traversePreOrderInternal(node *);
	void traversePostOrderInternal(node *);
	bool traverseLevelOrderInternal(node *, int);
	void print2DInternal(node *, int);

	void deleteInternal (node * &);				// internal delete function

	int heightInternal(node *);					// internal BF functions
	void setallBFInternal(node *);
	int getLargestBFInternal(node *);

public:
	BST();
	void insert (int &);				// user functions - all whole tree
	bool search (int &);
	void udelete (int &);

	void setallBF();					// sets BF for whole tree
	int height();						// height of whole tree
	int getLargestBF();					// largest BF in whole tree

	void traverseLevelOrder();			// traversal functions
	void print2D();
	void traverseInOrder();
	void traversePreOrder();
	void traversePostOrder();
};

BST::BST()
{
	root = nullptr;
}





//********************************************************
// user search - search, given a value
//********************************************************
bool BST::search(int & value)
{
	node *current;
	bool found = false;
	if (root == nullptr)
	{
		cout << "search: tree is empty" << endl;
		exit (1);
	}
	else
	{
		current = root;
		while (current != nullptr && !found)
		{
			if (current->nodeValue == value)
			{
				found = true;
			}
			else if (current->nodeValue > value)
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
		}
	}
	return found;
}




//********************************************************
// user insert - insert, given a value
//********************************************************
//  ----- insert goes here -----
void BST::insert (int & toInsert)
{
	node * newNode = new node;
	newNode -> right = nullptr;
	newNode -> left = nullptr;
	newNode -> nodeValue = toInsert;
	node * tail = new node;

	if(!root) root = newNode;
	else
	{
		node * trav = root;
		while(trav) // while the currently traversed node is not null, do the following
		{
			tail = trav;
			if(trav -> nodeValue < toInsert) trav = trav -> right;
			else if (trav -> nodeValue > toInsert) trav = trav -> left;
			else throw "Duplicated Value, Not Cool"; //check for equality, meaning duplicate value
		}
		if(tail -> nodeValue > toInsert) tail -> left = newNode;
		else tail -> right = newNode;
	}
	return;
}




//********************************************************
// user delete - delete, given a value
//********************************************************
void BST::udelete(int & value)
{
	node * current; 		// pointer to node we're looking at
	node * trailing; 		// trailing pointer to parent

	bool found = false;
	if (root == NULL)
	{
		cout << "udelete:  empty tree" << endl;
		exit (1);
	}
	else
	{
		current = root;
		trailing = root;
		while (current != nullptr && !found)
		{
			if (current->nodeValue == value)
			{
				found = true;
			}
			else
			{
				trailing = current;
				if (current->nodeValue > value)
				{
					current = current->left;
				}
				else
				{
					current = current->right;
				}
			}
		}
		if (current == nullptr)
		{
			cout << "udelete:  not found" << endl;
		}
		else if (found)
		{
			if (current == root)
			{
				deleteInternal(root);
			}
			else if (trailing->nodeValue > value)
			{
				deleteInternal(trailing->left);
			}
			else
			{
				deleteInternal(trailing->right);
			}
		}
	}
}




//********************************************************
// internal delete - delete, given the pointer to node to delete that is physically
// located in the node's parent as left or right
//********************************************************
void BST::deleteInternal (node * &p)
{
	node * current;			// pointer to node we're looking at
	node * trailing;		// trailing pointer to parent
	node * temp;			// temp pointer for delete

	if (p == nullptr)
	{
		cout << "delete: null node" << endl;
		exit(1);
	}
	else if(p->left == nullptr && p->right == nullptr)
	{
		temp = p;
		p = nullptr;
		delete temp;
	}
	else if(p->left == nullptr)
	{
		temp = p;
		p = temp->right;
		delete temp;
	}
	else if(p->right == nullptr)
	{
		temp = p;
		p = temp->left;
		delete temp;
	}
	else
	{
		current = p->left;
		trailing = nullptr;
		while (current->right != nullptr)
		{
			trailing = current;
			current = current->right;
		}
		p->nodeValue = current->nodeValue;
		if (trailing == NULL)
		{
			p->left = current->left;
		}
		else
		{
			trailing->right = current->left;
		}
		delete current;

	}
}




//********************************************************
// user traversal functions
//********************************************************
void BST::traverseInOrder()
{
	traverseInOrderInternal(root);
}
void BST::traversePreOrder()
{
	traversePreOrderInternal(root);
}
void BST::traversePostOrder()
{
	traversePostOrderInternal(root);
}
void BST::print2D()
{
    print2DInternal(root, 0);
}
void BST::traverseLevelOrder()
{
    int level = 1;
    while (traverseLevelOrderInternal(root,level))
    {
    	cout << endl;
        level++;
    }
}



//********************************************************
// internal traversal functions
//********************************************************
void BST::traverseInOrderInternal(node * p)
{
	if (p == nullptr)
	{
//		cout << "enter inorder with null" << endl;
	}
	else
	{
//		cout << "enter inorder " << p ->nodeValue << endl;
	}
	if (p != nullptr)
	{
		traverseInOrderInternal(p->left);
		cout << p->nodeValue << endl;
		traverseInOrderInternal(p->right);
	}
}

void BST::traversePreOrderInternal(node * p)
{
	if (p != nullptr)
	{
		cout << p->nodeValue << endl;
		traversePreOrderInternal(p->left);
		traversePreOrderInternal(p->right);
	}
}

void BST::traversePostOrderInternal(node * p)
{
	if (p != nullptr)
	{
		traversePostOrderInternal(p->left);
		traversePostOrderInternal(p->right);
		cout << p->nodeValue << endl;
	}
}

bool BST::traverseLevelOrderInternal(node * p, int level)
{
    if (p == nullptr)
        return false;
    if (level == 1)
    {
    	cout << p->nodeValue << "   ";
    	return true;
    }
    bool l = traverseLevelOrderInternal(p->left, level-1);
    bool r = traverseLevelOrderInternal(p->right, level-1);
    return l || r;
}
// internal recursive function, called by print2D
// does a reverse inorder traversal to display top to bottom
void BST::print2DInternal(node *root, int space)
{
	int count=8;
    if (root == NULL)
        return;
    space += count;
    print2DInternal(root->right, space);	// process right (top of page)
    cout<<endl;								// display node after spacing
    for (int i = count; i < space; i++)
        cout<<" ";
    cout<<root->nodeValue/*<<"("<<root->bf<<")"*/<<"\n"; //get rid of mid comment
    print2DInternal(root->left, space);	// process left (bottom of page)
}





//********************************************************
// user BF functions
//********************************************************
// user height - sets the BF for each node

int BST::height()
{
	return heightInternal(root);
}




//*****************************************************
// user setallBF - sets the BF for all nodes in the tree
//*****************************************************
//  ----- setallBF goes here -----
void BST::setallBF()
{
	setallBFInternal(root);
	return;
}


//*****************************************************
// user setallBFInernal - sets the BF for all nodes in the tree
//*****************************************************
//  ----- setallBF goes here -----
void BST::setallBFInternal(node * givenNode)
{
	int lh, rh = 0; //left height and right height
	if(givenNode) //if the passed node is not nullptr, then
	{
		lh = heightInternal (givenNode -> left);
		rh = heightInternal (givenNode -> right);
		givenNode -> bf =rh - lh;
		setallBFInternal (givenNode -> left);
		setallBFInternal (givenNode -> right);
	}
	return;
}



//*************************************************************
// user BF - returns the largest balance factor in the tree
//*************************************************************
//  ----- getLargestBF goes here -----

int BST::getLargestBF()
{
	getLargestBFInternal (root);
	return 0;
}



//********************************************************
// internal BF functions
//********************************************************
// heightInternal - recursive function,
// returns height of a subtree given its root
int BST::getLargestBFInternal(node * givenNode)
{
	int ll, lr = 0; //largestLeft and LargestRight
	if(givenNode)
	{
		ll = getLargestBFInternal(givenNode -> left);
		lr = getLargestBFInternal(givenNode -> right);
		if(abs(givenNode -> bf) > abs(ll)) ll = givenNode -> bf;
		else if (abs(givenNode -> bf) > abs(lr)) lr = givenNode -> bf;
		// end if

		//--------- RETURN STAGE ----------//
		if(abs(ll) > abs (lr)) return ll;
		else return lr; //return finals answer of bf
	}

	return 0;
}





int BST::heightInternal(node* p)
{
	if (p != nullptr)
	{
		int lh, rh;
		lh = heightInternal(p->left);
		rh = heightInternal(p->right);
		if (lh > rh)
		{
			lh++;
			return lh;
		}
		else
		{
			rh++;
			return rh;
		}
	}
	else
	{
		return -1;
	}
}

// setallBFinternal - recursive function,
// calculates the bf of a node and its subtrees
//  ----- setallBFinternal goes here -----
// getlargestBFInternal - resursive function,
// returns largest BF in the given subtree
//  ----- getLargestBFInternal goes here -----



/* =========================================================
 ****************** TO BE USED IN PART I ******************
 ======================================================== */
/*
int main() {
	BST mytree;
	int i;
	bool b;

// start with this small tree and test code
// will be easier to debug

	i=5;
	mytree.insert(i);
	i=8;

	mytree.insert(i);
	i=3;
	mytree.insert(i);
	i=12;
	mytree.insert(i);
	i=9;
	mytree.insert(i);

	mytree.print2D();
	cout << "-------------------------------------------" << endl;
	mytree.print2D();
	i = 9;
	b = mytree.search(i);
	if (b)
		cout << "search for 9 successful" << endl;
	else
		cout << "search for 9 not successful" << endl;
	return 0;


}*/




/* =========================================================
 ****************** TO BE USED IN PART II ******************
 ======================================================== */
int main() {
	BST mytree;
	int i;
	bool b;


	// use this code and tree when the small tree is working
	int array[14] = {60,50,70,30,53,80,35,57,75,32,40,77,48,45};
	for (int i=0;i<14;i++)
	{
		mytree.insert(array[i]);
	}


	cout << "traverse inorder" << endl;
	mytree.traverseInOrder();
	cout << "traverse preorder" << endl;
	mytree.traversePreOrder();
	cout << "traverse postorder" << endl;
	mytree.traversePostOrder();

	mytree.print2D();
	cout << "-------------------------------------------" << endl;
	mytree.setallBF();
	mytree.print2D();
	cout <<" largest BF " << mytree.getLargestBF() << endl;
	cout << "-------------------------------------------" << endl;
	i = 46;
	mytree.insert(i);
	i = 47;
	mytree.insert(i);
	mytree.setallBF();
	mytree.print2D();
	cout <<" largest BF " << mytree.getLargestBF() << endl;
	cout << "-------------------------------------------" << endl;
	i=45;
	mytree.udelete(i);
	mytree.setallBF();
	mytree.print2D();
	i = 53;
	b = mytree.search(i);
	if (b)
		cout << "search for 53 successful" << endl;
	else
		cout << "search for 53 not successful" << endl;
	return 0;
}
