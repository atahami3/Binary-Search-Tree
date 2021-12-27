//Program Specification:
//
//Build a binary search tree, using links (not an array) for 15 records. The data in these records will hold names and their associated weights. Read the data from the screen.
//
//Required functionality (Each # should be separate methods):
//
//Build the tree from the unique set of names (names are the key value) and their associated weights.
//Execute a preorder traversal
//Execute an inorder traversal
//Execute a postorder traversal
//Find and print the height of the tree using recursion, do not add a height variable to the tree structure, the algorithm stack should hold this.
//Determine the number of leaves and print the result (remember a leaf has no children).
//Implement search functionality that will search for a name and indicate the weight for that individual if they exist in the structure, otherwise stating no match exists.
//Determine the lowest weight contained in the tree.
//Find the first name in alphabetical order (this should not go through every node, unless the tree happens to be a linked list).
//=======================================================================================================================================================================================//
#include <iostream>
#include<string>
using namespace std;
struct Node
{
    string name;
    float weight;
    Node* left;
    Node* right;
};

//new node
Node* node(string name, float weight)
{
    Node* newNode = new Node();
    newNode->name = name;
    newNode->weight = weight;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

//put in alphabetical
Node* Insert(Node *root, string name, float weight)
{
    //if empty place inside root
    if(root == NULL)
    {
        root = node(name, weight);
    }
    //else procede to new nodes
    else if(name <= root->name)
    {
        root->left = Insert(root->left, name, weight);
    }
    else if(name > root->name)
    {
        root->right = Insert(root->right, name, weight);
    }
    
    return root;
}

//print the tree
void print (Node *temp, int levels)
{
    int i;
    if(temp != NULL)
    {
        print(temp->right,levels + 1);
        cout<<endl;
        for(i = 0; i<levels;i++)
        cout<<" ";
        cout<<temp->name<<"("<<temp->weight<<")";
        print(temp->left, levels + 1);
    }
}

//inorder trav
void Inorder(Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout<<root->name<<"("<<root->weight<<")"<<endl;
        Inorder(root->right);
    }
}

//preOrder trav
void PreOrder(Node *root)
{
    if(root != NULL)
    {
    cout<<root->name<<"("<<root->weight<<")"<<endl;
    PreOrder(root->left);
    PreOrder(root->right);
    }
}

//PostOrder trav
void PostOrder(Node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->name<<"("<<root->weight<<")"<<endl;
    }
}

//compare height(recursion)
int max(int leftT, int rightT)
{
    if(leftT >= rightT)
        return leftT;
    else
        return rightT;
}

//find height
int Fheight(Node* root)
{
    if(root == NULL)
    {
        return -1;//-1 meand there is one root null
    }
    else
        return max(Fheight(root->left), Fheight(root->right)) + 1;
}

//count leaves
int leafCounter(Node *root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
    {
        int left = leafCounter(root->left);
        int right = leafCounter(root->right);
        return left + right;
    }
}

//searching for name then outputting weight
float Search(Node* root, string name)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->name == name)
    {
        return root->weight;
    }
    else if(name < root->name)
    {
        return Search(root->left, name);
    }
    else if(name >= root->name)
    {
        return Search(root->right, name);
    }
    else
        return 0;
}

//find min(use for function below)
float minimum(float X, float Y)
{
    if(X < Y)
    {
        return X;
    }
    else
        return Y;
}

//find minimum weight
float minimumWeight(Node* root)
{
    float minLeft;
    float minRight;
    if(root == NULL)
    {
        return 9999;
    }
    else
    {
        minLeft = minimum(minimumWeight(root->left), root->weight);
        minRight = minimum(minimumWeight(root->right), root->weight);
    }
    if(minLeft < minRight)
    {
        return minLeft;
    }
    else
    return minRight;
}
//Find the first name in alphabetical order
void FirstName(Node* root)
{
    if(root == NULL)
    {
        cout<<"The tree is empty"<<endl;
        return;
    }
    else if(root->left != NULL)
    {
        FirstName(root->left);
    }
    else
        cout<<"First Name in Alpabetical order is: "<<root->name<<endl;
}


int main()
{
    string name;
    string searchName;
    float weight = 0;
    float searchValue = 0;
    Node* root = NULL;
    int leaves = 0;
    int user = 0;
    
    
    while (user != 11)
    {
        cout<<endl;
        
        cout << "Press 1 to Insert 15 Elements to BST" << endl;
        cout << "Press 2 to Display the Tree" << endl;
        cout << "Press 3 to Execute a preorder traversal" << endl;
        cout << "Press 4 to Execute a inorder traversal"<<endl;
        cout << "Press 5 to Execute a postorder traversal"<<endl;
        cout << "Press 6 to print the height of the tree"<<endl;
        cout << "Press 7 to Determine the number of leaves "<<endl;
        cout << "Press 8 to search for a name and weight "<<endl;
        cout << "Press 9 to Determine the lowest weight in the tree."<<endl;
        cout << "Press 10 to Find the first name in alphabetical order"<<endl;
        cout << "Or 11 to Quit"<<endl;
        cout<<endl;
        cin >> user;
        
        //add into tree
        if(user == 1)
        {
            for(int i = 0;i<15;i++)
            {
                cout<<"Enter Name and the Weight"<<endl;
                fflush(stdin);
                getline(cin,name);
                cin>>weight;
                root = Insert(root, name, weight);
            }
        }
        
        //print tree
        if(user == 2)
        {
            cout<<"BST: "<<endl;
            cout<<"The tree starts from the left: "<<endl;
            print(root, 1);
            cout<<endl;
        }
        
        //preorder
        if(user == 3)
        {
            cout<<"\npreorder treversal\n";
            PreOrder(root);
            cout<<endl;
        }
        
        //inorder
        if(user == 4)
        {
            cout<<"\nInorder treversal\n";
            Inorder(root);
            cout<<endl;
        }
        
        //postorder
        if(user == 5)
        {
            cout<<"\nPostOrder treversal\n";
            PostOrder(root);
            cout<<endl;

        }
        
        //height of tree
        if(user == 6)
        {
            if(Fheight(root) == -1)
            {
                cout<<"Tree is empty\n";
            }
            else
            {
                cout<<"The height of the tree is "<<Fheight(root)<<endl;
            }
        }
        
        //num of leaves
        if(user == 7)
        {
            leaves = leafCounter(root);
            cout<<"Number of leaves is "<<leaves<<endl;
        }
        
        //search for weight using name
        if(user == 8)
        {
            cout<<"\nEnter name your searching for "<<endl;
            cin>>searchName;
            searchValue = Search(root, searchName);
            if(searchValue == 0)
            {
                cout<<"Name not in Tree"<<endl;
            }
            else
            {
                cout<<searchName<<" weighs "<<searchValue<<"LBS "<<endl;
            }
        }
        
        //lightest weight
        if(user == 9)
        {
            if(minimumWeight(root) != 9999)
            {
                cout<<"The lightest weight recorded is "<<minimumWeight(root)<<endl;
            }
        }
        
        
        
        //alphabetical order
        if(user == 10)
        {
            FirstName(root);
        }
    }
}
/**
 
 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 1
 Enter Name and the Weight
 Mark
 150
 Enter Name and the Weight
 Tina
 115
 Enter Name and the Weight
 Zach
 55
 Enter Name and the Weight
 Amy
 140
 Enter Name and the Weight
 Steve
 220
 Enter Name and the Weight
 Brian
 250
 Enter Name and the Weight
 Liz
 125
 Enter Name and the Weight
 Brian
 220
 Enter Name and the Weight
 Laura
 115
 Enter Name and the Weight
 Alex
 175
 Enter Name and the Weight
 Jason
 210
 Enter Name and the Weight
 Eric
 175
 Enter Name and the Weight
 Aaron
 195
 Enter Name and the Weight
 Kim
 135
 Enter Name and the Weight
 Brandon
 78

 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 2
 
 BST:
 The tree starts from the left:

    Zach(55)
   Tina(115)
    Steve(220)
  Mark(150)
     Liz(125)
      Laura(115)
        Kim(135)
       Jason(210)
        Eric(175)
    Brian(250)
     Brian(220)
      Brandon(78)
   Amy(140)
    Alex(175)
     Aaron(195)

 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 3

 preorder treversal
 Mark(150)
 Amy(140)
 Alex(175)
 Aaron(195)
 Brian(250)
 Brian(220)
 Brandon(78)
 Liz(125)
 Laura(115)
 Jason(210)
 Eric(175)
 Kim(135)
 Tina(115)
 Steve(220)
 Zach(55)


 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 4

 Inorder treversal
 Aaron(195)
 Alex(175)
 Amy(140)
 Brandon(78)
 Brian(220)
 Brian(250)
 Eric(175)
 Jason(210)
 Kim(135)
 Laura(115)
 Liz(125)
 Mark(150)
 Steve(220)
 Tina(115)
 Zach(55)


 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 5

 PostOrder treversal
 Aaron(195)
 Alex(175)
 Brandon(78)
 Brian(220)
 Eric(175)
 Kim(135)
 Jason(210)
 Laura(115)
 Liz(125)
 Brian(250)
 Amy(140)
 Steve(220)
 Zach(55)
 Tina(115)
 Mark(150)


 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 6
 The height of the tree is 6

 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 7
 Number of leaves is 6

 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 8

 Enter name your searching for
 Amy
 Amy weighs 140LBS

 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 9
 The lightest weight recorded is 55

 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 10
 First Name in Alpabetical order is: Aaron

 Press 1 to Insert 15 Elements to BST
 Press 2 to Display the Tree
 Press 3 to Execute a preorder traversal
 Press 4 to Execute a inorder traversal
 Press 5 to Execute a postorder traversal
 Press 6 to print the height of the tree
 Press 7 to Determine the number of leaves
 Press 8 to search for a name and weight
 Press 9 to Determine the lowest weight in the tree.
 Press 10 to Find the first name in alphabetical order
 Or 11 to Quit

 11
 Program ended with exit code: 0
 */
