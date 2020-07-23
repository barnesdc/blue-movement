///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Week 6 - Trees Prompt 1                              //
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
//      Find the maximum difference between a node and its                   //
//      descendants from the Binary Tree.                                    //
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
//      Output:                                                              //
//                   7                                                       //
//                                                                           //
//      Explanation:                                                         //
//                  ( max_value  - min_value ) =  ( 8 - 1 )  =  7            //
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
//---------------------------------------
// Binary Tree Printer                  :
//---------------------------------------
void binaryTree_printer ( nodeType* strt_ptr,
                          int image_justify = 0,       // DEFAULT justification of the binary tree image
                          int tier_padding  = 15     ) // DEFAULT padding between the tiers
{
// Function Definition -
// Print the Binary Tree with the top of
// the tree on the left and the bottom of the
// tree to the right of it.
//---------------------------------------
    
    //---------------------------------------
    // Base case                            :
    //---------------------------------------
    if (strt_ptr == nullptr){
        return;
    }
    
    //---------------------------------------
    // Recursive case                       :
    //---------------------------------------
    // Add image spacing:
    image_justify += tier_padding;
    cout << "  ";
    
        //-----------------------------------
        // Begin Printing                   :
        //-----------------------------------
        // Right child first :
        binaryTree_printer(strt_ptr->right, image_justify);
        cout << endl;

        // print current node after tier_padding it
        // with spaces :
        for ( int i = tier_padding; i < image_justify; i++ )
            cout << ' ';
        cout << "    " << ( strt_ptr->data );
        if ( strt_ptr->right != NULL ){
            cout << " ⬈" ;
        }
        if ( strt_ptr->left != NULL ){
            cout << " ⬊" ;
        }

        // Left child Second :
        cout << endl;
        binaryTree_printer(strt_ptr->left, image_justify);
}


//===========================================================================//
//        F U N C T I O N    M O D U L E (S)    T O    T E S T               //
//===========================================================================//
//---------------------------------------
// Binary Tree Traversal                :
//---------------------------------------
int binaryTree_max( nodeType* strt_ptr ){
// Function Definition -
// Traverse and find the max value
// in the tree.
//---------------------------------------
    
    //----------------------------------
    // Base Case ( stack i.0 )         :
    //----------------------------------
    if( strt_ptr == nullptr ){
        return INT_MIN;
    }
    //----------------------------------
    // Recursive Step                  :
    //----------------------------------
    int max_val   = ( strt_ptr-> data );                 // Find the current Value
    int leftval   = binaryTree_max( strt_ptr-> left  );  // Recursive Left
    int rightval  = binaryTree_max( strt_ptr-> right );  // Recursive Right
    
    // Max:
    if(  (leftval)   >  (max_val)  ){
        max_val   =  (leftval);
    }
    if(  (rightval)  >  (max_val)  ){
        max_val   =  (rightval);
    }
    
    // Return the Max:
    return max_val;
}


int binaryTree_min( nodeType* strt_ptr ){
// Function Definition -
// Traverse and find the min value
// in the tree.
//---------------------------------------
    
    //----------------------------------
    // Base Case ( stack i.0 )         :
    //----------------------------------
    if( strt_ptr == nullptr ){
        return INT_MAX;
    }
    //----------------------------------
    // Recursive Step                  :
    //----------------------------------
    int min_val   = ( strt_ptr-> data );                 // Find the current Value
    int leftval   = binaryTree_min( strt_ptr-> left  );  // Recursive Left
    int rightval  = binaryTree_min( strt_ptr-> right );  // Recursive Right

    // Max:
    if(  (leftval)   <  (min_val)  ){
        min_val   =  (leftval);
    }
    if(  (rightval)  <  (min_val)  ){
        min_val   =  (rightval);
    }

    // Return the Max:
    return min_val;
}


//===========================================================================//
//                    U N I T    T E S T     C A S E S                       //
//===========================================================================//
TEST_CASE(       "CanGetNonEmptyTree"        ,
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
TEST_CASE(       "CanGetTreeConnections"        ,
              "[weekSixPromptOne_test]"       )
{
// Test Description -
//
//  This test validates that the function, "binaryTree_creator",
//  has the correct connections by using the function,
//  "binaryTree_printer", to check it.
//--------------------------------------------------------------------
    
    
    //---------------------------------------------------
    // TEST 2                                           :
    //---------------------------------------------------
    // Initialize Binary Tree:
    binaryTree_creator( head );
    // print Binary Tree:
    binaryTree_printer( head );
    // Give space between outputs:
    cout << endl;
    
}
TEST_CASE(       "CanGetMax"        ,
              "[weekSixPromptOne_test]"       )
{
// Test Description -
//
//  This test validates that the function, "binaryTree_max",
//  gives you the correct maximum value found in the tree.
//--------------------------------------------------------------------
    
    
    //---------------------------------------------------
    // TEST 3                                           :
    //---------------------------------------------------
    // Initialize Binary Tree:
    binaryTree_creator( head );
    
    // Check Assertion:
    REQUIRE(   binaryTree_max(   head   ) == 8    );
    
}
TEST_CASE(       "CanGetMin"        ,
              "[weekSixPromptOne_test]"       )
{
// Test Description -
//
//  This test validates that the function, "binaryTree_min",
//  gives you the correct minimum value found in the tree.
//--------------------------------------------------------------------
    
    
    //---------------------------------------------------
    // TEST 4                                           :
    //---------------------------------------------------
    // Initialize Binary Tree:
    binaryTree_creator( head );
    
    // Check Assertion:
    REQUIRE(   binaryTree_min(   head   ) == 1    );
    
}
TEST_CASE(     "CanGetMaxMinDifference"  ,
              "[weekSixPromptOne_test]"       )
{
// Test Description -
//
//  This test validates that the subtraction of the function
//  "binaryTree_min" from the function "binaryTree_max"
//  gives you the correct max difference value from the tree.
//--------------------------------------------------------------------
    
    
    //---------------------------------------------------
    // TEST 5                                           :
    //---------------------------------------------------
    // Initialize Binary Tree:
    binaryTree_creator( head );
    
    // Check Assertion:
    REQUIRE(   ( binaryTree_max( head )  -  binaryTree_min( head ) )  ==  7    );
    
}
