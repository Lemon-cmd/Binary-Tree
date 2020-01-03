#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree 
{
    public: 
        Node* create(int data)
        {
            Node* root = new Node();
            root->data = data;
            root->left = root->right = NULL;

            return root;
        }

        Node* insert(Node* root, int data)
        {
            if (root == NULL)
            {
                root = create(data);
            }
            
            else if (data <= root->data)
            {
                root->left = insert(root->left, data);
            }

            else if (data >= root->data)
            {
                root->right = insert(root->right, data);
            }

            return root;
        }

        bool search(Node* root, int target)
        {
            if (root == NULL)
            {
                return false;
            }
            
            else if (root->data == target)
            {
                return true;
            }

            else if (target <= root->data)
            {
                return search(root->left, target);
            }

            else if (target >= root->data)
            {
                return search(root->right, target);
            }
           
        }
};

int main()
{
    BinaryTree tree = BinaryTree();
    Node* root;
    root = NULL;
    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);
    root = tree.insert(root, 90);
    root = tree.insert(root, 11);
    root = tree.insert(root, 22);
    root = tree.insert(root, 33);
    root = tree.insert(root, 40);

    cout << tree.search(root, 10) << endl;
     
}