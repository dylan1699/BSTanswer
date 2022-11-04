#include<iostream>
#include<limits.h>

using namespace std;

struct node{
    int val;
    struct node* left;
    struct node* right;
    node(int v){val=v;left=right=NULL;} //this is the constructor to initialise the left right pointer and the value.
};



void findClosestElementForGivenValue(struct node* root,int key,int &minDiff,int &finalAnswer){

    if(!root) return; //if anypoint of time we reach to null simply return

    if( abs(root->val-key) < minDiff ){
        finalAnswer = root->val; // if the difference between the root and key is less then minDiff then simply update the finalAnswer

        minDiff = abs(root->val - key); //and we update the minDiff value with diff between rootvalue and key

    }

    // for selecting the decision wheater we move to left child or right child we use this condition
    if(root->val > key){
        findClosestElementForGivenValue(root->left,key,minDiff,finalAnswer);
    } else {
        findClosestElementForGivenValue(root->right,key,minDiff,finalAnswer);
    }
}



int main(){
    struct node* root = new node(10);//Here I directly insert the value , without creating any insert fun for BST.
    root->left = new node(5);
    root->right = new node(20);
    root->left->left = new node(2);
    root->left->right = new node(8);
    root->right->left = new node(15);
    root->right->right =new node(22);
    int key = 7;
    int minDiff= INT_MAX; // I take minDiff as INT_MAX becasue I don't know currently what is minimum diff.
    int finalAnswer;
    findClosestElementForGivenValue(root,key,minDiff,finalAnswer);
    if(key==finalAnswer)
       cout<<-1<<endl;
    else
       cout<<finalAnswer;
}
