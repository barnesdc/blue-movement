///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Week 2 - Arrays Prompt 2                             //
// Filename:            main_unitTest.cpp                                    //
//---                                                                        //
// Date of Creation:    06/09/20                                             //
// Last Revised By:     N/A                                                  //
// Last Revision Date:  N/A                                                  //
//---                                                                        //
// Copyright:           Copyright © 2020 Ibeawuchi Anokam.                   //
//                      All rights reserved.                                 //
//---------------------------------------------------------------------------//
//                                                                           //
//- Program Description:                                                     //
//                                                                           //
//      You are given a string, str.                                         //
//      The task is to print all the permutations of str.                    //
//                                                                           //
//      NOTE:  A permutation is an arrangement of all or part                //
//      ----   of a set of objects, with regard to the order of              //
//             the arrangement.                                              //
//                                                                           //
//---------------------------------------------------------------------------//
//                                                                           //
//- Example:                                                                 //
//                                                                           //
//      Input:                                                               //
//                  { "abb" }                                                //
//                                                                           //
//        Output:                                                            //
//                  { "abb", "abb", "bab", "bba", "bba", "bab" }             //
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
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include "catch.h"          // Catch2 Unit Test FrameWork (Library)
//---------------------------------------
// System Libraries                     :
//---------------------------------------
#include <iostream>         // Used for Debugging
#include <algorithm>        // swap( x, y )  |  sort(  x.begin(), x.end()  )
#include <string>           // container for the INPUT  value
#include <vector>           // container for the RETURN Value
using namespace std;

//===========================================================================//
//        F U N C T I O N    M O D U L E (S)    T O    T E S T               //
//===========================================================================//
void str_permutations(   string str,
                         int left_side, int right_side,
                         vector< string >& permutations     )
{
// Function Definition -
// This function finds all the
// permutations of a given string
//---------------------------------------
    
    
    //--------------------------------------
    // Check the Characters                :
    //--------------------------------------
    bool is_properformat = true;
    for(  long i = 0;  i < str.size();  i++  ){
        
        // Make sure that only the ascii[ a-z ] characters are
        // in the string ELSE stop the check:
        if(  !( (str.at(i) >= 'a'  && str.at(i)  <= 'z') )  )
        {
            is_properformat = false;
            break;
        }
    }
    //--------------------------------------
    // BEGIN finding the  Permutations     :
    //--------------------------------------
    if( is_properformat == true ){
            
        //----------------------------------
        // Base Case                       :
        //----------------------------------
        if(  left_side == right_side  ){
            
            // Return Set -
            // Give an Empty / Non-Empty Set:
            permutations.push_back( str );
        }
        //----------------------------------
        // Recursive Case                  :
        //----------------------------------
        else{
            for( int i = left_side;  i <= right_side;  i++ ){
                
                // Swap:
                swap(  str.at( left_side ), str.at( i )  );
                
                // Account for the change. Add it to the stack:
                str_permutations(  str,
                                   left_side + 1, right_side,
                                   permutations                );
                
                // ReSwap:
                swap(  str.at( left_side ), str.at( i )  );
            }
        }
    }
    else{
        // Return an Empty Set:
        permutations = { };
    }
}


//===========================================================================//
//                    U N I T    T E S T     C A S E S                       //
//===========================================================================//
//----------------------------------
// Test Suite #1                   :
//----------------------------------
TEST_CASE(       "CanGetEmptySet"        ,
               "[weekTwoPromptTwo_test]"       )
{
// Test Description -
//
//  This test validates that the function, "str_permutations",
//  is empty.
//--------------------------------------------------------------------
    
    //---------------------------------------------------
    // TEST 1                                           :
    //---------------------------------------------------
    // Input Value:
    string word = "";   // EMPTY String
    
    // Answers to compare:
    vector< string >   ans     =  {  };
    vector< string >   output;
    str_permutations(  word,
                       0, static_cast<int>( word.size() ) - 1,
                       output                                      );

    // SORT (needed to be done for proper checking to be done):
    sort(  ans.begin(),    ans.end()  );
    sort(  output.begin(), output.end()  );
    
    // CHECK Assertions:
    REQUIRE(  (  ans.size( ) == output.size( ) &&
                (ans.size( ) == 0 && output.size( ) == 0)  )   );
    
    
    SECTION( "CanGetProperOutputs" ){
        //---------------------------------------------------
        // TEST 2                                           :
        //---------------------------------------------------
        // Input Value:
        word = "AAbc";                                              // Note: only ascii[ a-z ]
                                                                    // characters are allowed

        // Answers to compare: (0 values)
        ans     =  { };                                             // Expected answer Set

        output  =  { };                                             // Empty set to store
                                                                    // your output Set

        // Get the output Set:
        str_permutations(  word,
                        0, static_cast<int>( word.size() ) - 1,
                        output                                      );

        // SORT (needed to be done for proper checking to be done):
        sort(  ans.begin(),    ans.end()  );
        sort(  output.begin(), output.end()  );

        // CHECK Assertions:
        if(  ans.size( ) == output.size( )  ){

         int chekVal_2 = 0;
         for( auto chekVal_1 : ans ){

             REQUIRE( chekVal_1 == output[ chekVal_2 ] );
             chekVal_2++;
         }
        }
        else{
         REQUIRE( true == false );
        }
        //---------------------------------------------------
        // TEST 3                                           :
        //---------------------------------------------------
        // Input Value:
        word = ".!?#";                                            // Note: only ascii[ a-z ]
                                                                  // characters are allowed

        // Answers to compare: (0 values)
        ans     =  { };                                           // Expected answer Set

        output  =  { };                                           // Empty set to store
                                                                  // your output Set

        // Get the output Set:
        str_permutations(  word,
                        0, static_cast<int>( word.size() ) - 1,
                        output                                      );

        // SORT (needed to be done for proper checking to be done):
        sort(  ans.begin(),    ans.end()  );
        sort(  output.begin(), output.end()  );

        // CHECK Assertions:
        if(  ans.size( ) == output.size( )  ){

         int chekVal_2 = 0;
         for( auto chekVal_1 : ans ){

             REQUIRE( chekVal_1 == output[ chekVal_2 ] );
             chekVal_2++;
         }
        }
        else{
         REQUIRE( true == false );
        }
    }
}
TEST_CASE(       "CanGetNonEmptySet"        ,
               "[weekTwoPromptTwo_test]"       )
{
// Test Description -
//
//  This test validates that the function, "str_permutations",
//  is not empty and returns the correct values.
//--------------------------------------------------------------------

    
    //---------------------------------------------------
    // Variable Declarations                            :
    //---------------------------------------------------
    string word ;
    vector< string >   ans;
    vector< string >   output;
    
    
    SECTION( "CanGetProperOutputs" ){
        //---------------------------------------------------
        // TEST 4                                           :
        //---------------------------------------------------
        // Input Value:
        word = "abb";

        // Answers to compare: (6 values)
        ans     =  { "abb", "abb", "bab", "bba", "bab", "bba" };    // Expected answer Set
        
        output  =  { };                                             // Empty set to store
                                                                    // your output Set
        
        // Get the output Set:
        str_permutations(  word,
                           0, static_cast<int>( word.size() ) - 1,
                           output                                      );

        // SORT (needed to be done for proper checking to be done):
        sort(  ans.begin(),    ans.end()  );
        sort(  output.begin(), output.end()  );

        // CHECK Assertions:
        if(  ans.size( ) == output.size( )  ){

            int chekVal_2 = 0;
            for( auto chekVal_1 : ans ){

                REQUIRE( chekVal_1 == output[ chekVal_2 ] );
                chekVal_2++;
            }
        }
        else{
            REQUIRE( true == false );
        }
        //---------------------------------------------------
        // TEST 5                                           :
        //---------------------------------------------------
        // Input Value:
        word = "aabc";

        // Answers to compare: (24 values)
        ans     =  { "aabc", "aacb", "abac", "abca",                // Expected answer Set
                     "acab", "acba", "aabc", "aacb",
                     "abac", "abca", "acab", "acba",
                     "baac", "baca", "baac", "baca",
                     "bcaa", "bcaa", "caab", "caba",
                     "caab", "caba", "cbaa", "cbaa" };
        
        output  =  { };                                             // Empty set to store
                                                                    // your output Set
        
        // Get the output Set:
        str_permutations(  word,
                           0, static_cast<int>( word.size() ) - 1,
                           output                                      );

        // SORT (needed to be done for proper checking to be done):
        sort(  ans.begin(),    ans.end()  );
        sort(  output.begin(), output.end()  );

        // CHECK Assertions:
        if(  ans.size( ) == output.size( )  ){

            int chekVal_2 = 0;
            for( auto chekVal_1 : ans ){

                REQUIRE( chekVal_1 == output[ chekVal_2 ] );
                chekVal_2++;
            }
        }
        else{
            REQUIRE( true == false );
        }
    }
}
