///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Week 6 - Trees Prompt 2                              //
// Filename:            main.cpp                                             //
//---                                                                        //
// Date of Creation:    07/04/20                                             //
// Last Revised By:     N/A                                                  //
// Last Revision Date:  N/A                                                  //
//---                                                                        //
// Copyright:           Copyright © 2020 Ibeawuchi Anokam.                   //
//                      All rights reserved.                                 //
//---------------------------------------------------------------------------//
//                                                                           //
//- Program Description:                                                     //
//                                                                           //
//      You are given a Binary Tree.                                         //
//      Write an algorithm to print the leaf to root path for every          //
//      leaf node of the binary tree.                                        //
//                                                                           //
//---------------------------------------------------------------------------//
//                                                                           //
//- Example:                                                                 //
//                                                                           //
//      Input:                                                               //
//                           6                                               //
//                        /     \                                            //
//                       3       8                                           //
//                              /  \                                         //
//                            2     4                                        //
//                          /  \                                             //
//                         1    7                                            //
//                                                                           //
//        Output:                                                            //
//                  6 > 3                                                    //
//                  6 > 8 > 2 > 1                                            //
//                  6 > 8 > 2 > 7                                            //
//                  6 > 8 > 4                                                //
//                                                                           //
//        Explanation:                                                       //
//                  Output all path instances from the root                  //
//                  all the way to a leaf node                               //
//                                                                           //
//---------------------------------------------------------------------------//


//===========================================================================//
//                    F U N C T I O N    M O D U L E   -                     //
//                      G L O B A L    S E C T I O N                         //
//===========================================================================//
//---------------------------------------
// Testing Library                      :
//---------------------------------------
#define CATCH_CONFIG_MAIN   // Allows the Catch2 Library to instantiate a
                            // Main() module of it's own

#include "catch.hpp"        // Catch2 Unit Test FrameWork (Library)
//---------------------------------------
// System Libraries                     :
//---------------------------------------
#include <iostream>
using namespace std;

//---------------------------------------
// Binary Tree Node Creation            :
//---------------------------------------
// Node Template:
struct nodeType{
    // DATA FIELD(S):
    int data;
    // POINTER FIELDS:
    nodeType* left;
    nodeType* right;
};
// Head Pointer:
nodeType* head = nullptr;


//===========================================================================//
//                    U T I L I T Y    F U N C T I O N (S)                   //
//===========================================================================//
//---------------------------------------
// Binary Tree Creation                 :
//---------------------------------------
// Insertion of Nodes:
void binaryTree_creator ( nodeType* &strt_ptr ){

        // Parent Node:
        nodeType* firstNode = new nodeType;
        firstNode -> data   = 6;
        
        // Point the head to the firstNode:
        strt_ptr = firstNode;
    //-------------------------------------------
        // Left Child Node - Tier 1:
        (firstNode -> left) = new nodeType;
        (firstNode -> left) -> data = 3;
        
        (firstNode -> left) -> left  = nullptr;
        (firstNode -> left) -> right = nullptr;
        
        
        // Right Child Node - Tier 1:
        (firstNode -> right) = new nodeType;
        (firstNode -> right) -> data = 8;
        
    //-------------------------------------------
        // Right Child Node - Tier 2:
        (firstNode -> right) -> left  = new nodeType;
        (firstNode -> right) -> right = new nodeType;
        
        ((firstNode -> right) -> left )  -> data  = 2;
        ((firstNode -> right) -> right ) -> data  = 4;
    
   //-------------------------------------------
        // Right Child Node - Tier 3:
        ((firstNode -> right) -> left )  -> left  = new nodeType;
        ((firstNode -> right) -> left )  -> right = new nodeType;
        
        (((firstNode -> right) -> left )  -> left  ) -> data = 1;
        (((firstNode -> right) -> left )  -> right ) -> data = 7;
        
        ((firstNode -> right) -> right ) -> right = nullptr;
        ((firstNode -> right) -> right ) -> left  = nullptr;
    
    //-------------------------------------------
        // Right Child Node - Tier 4:
        (((firstNode -> right) -> left )  -> left  ) -> left  = nullptr;
        (((firstNode -> right) -> left )  -> left  ) -> right = nullptr;
        
        (((firstNode -> right) -> left )  -> right ) -> left  = nullptr;
        (((firstNode -> right) -> left )  -> right ) -> right = nullptr;

}


//===========================================================================//
//        F U N C T I O N    M O D U L E (S)    T O    T E S T               //
//===========================================================================//
//---------------------------------------
// Binary Tree Traversal                :
//---------------------------------------
void binaryTree_leafPaths(  nodeType*   strt_ptr,
                            vector<int> &path_container   )
{
// Function Definition -
// Traverse and find the leaf paths
// in the tree.
//---------------------------------------
    
    //----------------------------------
    // Base Case ( stack i.0 )         :
    //----------------------------------
    if( strt_ptr == nullptr ){
        return;
    }
    //----------------------------------
    // Recursive Step (preOrder)       :
    //----------------------------------
    // PreOrder pushback of a found Node:
    path_container.push_back( strt_ptr->data ); // push_front
    
    // If you Have reached a Leaf node print the Found Path:
    if(  strt_ptr->left  == nullptr &&
         strt_ptr->right == nullptr     )
    {
        // Begin Printing the Path:
        for ( long i = path_container.size() - 1; i >= 0; i--)
        {
            // Print The Node in the path:
            cout << path_container.at( i );
            
            // Print the path arrow:
            if( i !=  0 ){
               cout << "   <-   ";
            }
        }
        
        // Begin a new line for the next Path to be printed, if any:
        cout << endl;
    }
    else{ // ... Keep Traversing the tree in preOrder as you look for Paths to print:
        binaryTree_leafPaths( strt_ptr->left,  path_container );
        binaryTree_leafPaths( strt_ptr->right, path_container );
    }
    // Erase the Leaf Node (as you double-back):
    path_container.pop_back();
}


//===========================================================================//
//                    U N I T    T E S T     C A S E S                       //
//===========================================================================//
TEST_CASE(       "CanGetNonEmptyTree"   ,
              "[weekSixPromptOne_test]"       )
{
// Test Description -
//
//  This test validates that the function, "binaryTree_creator",
//  is not empty.
//--------------------------------------------------------------------
    
    
    //---------------------------------------------------
    // TEST 1                                           :
    //---------------------------------------------------
    // Initialize Binary Tree:
    binaryTree_creator( head );
    
    REQUIRE(   head != nullptr   );
    
}
TEST_CASE(       "CanGetTreeConnections" ,
              "[weekSixPromptOne_test]"       )
{
// Test Description -
//
//  This test validates that, after using the function "binaryTree_creator",
//  the tree was created correctly by outputting the preOrder paths
//  using the function "binaryTree_leafPaths".
//--------------------------------------------------------------------
    
    
    //---------------------------------------------------
    // TEST 2                                           :
    //---------------------------------------------------
    // Initialize Binary Tree:
    binaryTree_creator( head );
    
    // print Binary Tree:
    vector<int> path;
    binaryTree_leafPaths( head, path );
    
    // Give a space after the output:
    cout << endl;
}
