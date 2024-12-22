#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"
using namespace std;

class BinaryTree
{
    Node* root;
    Node* getNodeByData(int data){
        if(root == NULL){
            throw "Empty Binary Tree";
            return NULL;
        }
        Node* current = root;
        while(current != NULL){
            if(current->data == data){
                return current;
            }
            else if(data > current->data){
                current=current->right;
            }else{
                current=current->left;
            }
        }
        throw "Node Not found!";
        return NULL;
    }

    Node* getParent(Node* node){
        if(root == NULL){
            throw "Empty Binary Tree";
            return NULL;
        }
        if(node == root){
            throw "Root Node doesn't has a parent Node!";
            return NULL;
        }
        Node* parent = root;
        while(parent != NULL){
            if(parent->right ==node || parent->left==node){
                return parent;
            }else if(node->data > parent->data){
                parent=parent->right;
            }else{
                parent=parent->left;
            }
        }
        //throw "Node Not found!";
        return NULL;
    }

    Node* getMaxRight(Node* node){
        Node* current = node;
        while(current->right != NULL){
            current=current->right;
        }
        return current;

    }

    Node* getMinLeft(Node* node){
        Node* current = node;
        while(current->left != NULL){
            current=current->left;
        }
        return current;
    }

    void display(Node* node){
        if(node == NULL){
            return;
        }
        display(node->left);
        cout <<node->data<<" ";
        display(node->right);
    }

    public:
        BinaryTree() {
            root=NULL;
        }

        void add(int data){
            Node* newNode = new Node(data);

            if(root==NULL){
                root=newNode;
                return;
            }
            Node* current = root;
            Node* parent = NULL;

            while(current != NULL){
                parent=current;
                if(newNode->data > current->data){
                    current=current->right;
                }
                else{
                    current = current->left;
                }
            }
            if(newNode->data > parent->data){
                parent->right= newNode;
            }else{
                parent->left=newNode;
            }
        }

        int findDataInTree(int data){
            if(getNodeByData(data)==NULL){
                return 0;
            }else{
                return 1;
            }
        }

        int findParent(int data){
            Node* findNode = getNodeByData(data);
            Node* parentNode = getParent(findNode);
            if(parentNode==NULL){
                return 0;
            }
            return parentNode->data;
        }

        int getMaxRightByData(int data){
            Node* node = getNodeByData(data);
            Node* maxR = getMaxRight(node);
            return maxR->data;

        }

        int getMaxInTree(){
            Node* maxRight = getMaxRight(root);
            return maxRight->data;
        }

        int getMinInTree(){
            Node* minLeft = getMinLeft(root);
            return minLeft->data;
        }

        void displayAll(){
            display(root);
        }

        void removeNode(int data){
            Node* target = getNodeByData(data);
            if(target == NULL){
                throw "Targeted Node not found!";
            }
            if(target == root){
                if(target->right==NULL && target->left==NULL){
                    root=NULL;
                }else if(target->right==NULL){
                    root=target->left;
                }else if(target->left==NULL){
                    root=target->right;
                }else{
                    Node* newRoot = root->left;             // newRoot = First Left Child
                    Node* maxRight = getMaxRight(newRoot);      // get Max Right of the newRood
                    maxRight->right=root->right;                // maxRight ->right = First Right Child
                    root=newRoot;                           // Make Root points to the newRoot Node
                }
                //delete root;
            }else{
                Node* parent = getParent(target);
                //Node* child = NULL;

                if(target->right==NULL && target->left==NULL){
                    if(parent->right==target){
                        parent->right=NULL;
                    }else{
                        parent->left=NULL;
                    }
                }else if(target->right==NULL){
                    if(parent->right==target){
                        parent->right=target->left;
                    }else{
                        parent->left=target->left;
                    }

                }else if(target->left==NULL){
                    if(parent->right==target){
                        parent->right=target->right;
                    }else{
                        parent->left=target->right;
                    }
                }else{
                    Node* newParent = target->left;             // newRoot = First Left Child
                    Node* maxRight = getMaxRight(newParent);      // get Max Right of the newRood
                    maxRight->right=target->right;                // maxRight ->right = First Right Child
                    if(parent->right == target){
                        parent->right=newParent;
                    }else{
                        parent->left=newParent;
                    }
                }

            delete target;
            }

        }


        ~BinaryTree() {}

    protected:

    private:
};

#endif // BINARYTREE_H
