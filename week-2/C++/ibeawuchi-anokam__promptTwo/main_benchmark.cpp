///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Week 2 - Arrays Prompt 2                             //
// Filename:            main_benchmark.cpp                                   //
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
//                           B E N C H M A R K (S)                           //
//===========================================================================//
TEST_CASE(       "CanGetEmptySet"        ,
               "[weekTwoPromptOne_test]"       )
{
// Test Description -
//
//  This test benchmarks the function, "str_permutations",
//  which gives an empty Set and returns its performance.
//--------------------------------------------------------------------

    
    //---------------------------------------------------
    // TEST 1                                           :
    //---------------------------------------------------
    BENCHMARK("EmptySet__SIZE_0"){
        // Input Value:
        string word = "";   // EMPTY String
        
        // Answers to compare:
        vector< string >   ans     =  {  };
        vector< string >   output;
        
        return( str_permutations(  word,
                                   0, static_cast<int>( word.size() ) - 1,
                                   output                                      ) );
    };
}
TEST_CASE(       "CanGetNonEmptySet"        ,
               "[weekTwoPromptOne_test]"       )
{
// Test Description -
//
//  This test benchmarks the function, "str_permutations",
//  which gives a non-empty Set and returns its performance.
//--------------------------------------------------------------------

    
    //---------------------------------------------------
    // Variable Declarations                            :
    //---------------------------------------------------
    string word;
    vector< string >   ans;
    vector< string >   output;
    
    
    //---------------------------------------------------
    // TEST 2.0                                         :
    //---------------------------------------------------
    BENCHMARK("NonEmptySet_ProperOutputs__SIZE_720"){
          //--------------------------------------------------
          // TEST 2.1                                        :
          //--------------------------------------------------
          // Input Value:
          word = "aabbcc";

          // Answers to compare: ( 6! == 720 values )
          output  =  { };                                             // Empty set to store
                                                                      // your output Set
          
          // Get the output Set:
          return(  str_permutations(  word,
                                      0, static_cast<int>( word.size() ) - 1,
                                      output                                     ) );
    };
    BENCHMARK("NonEmptySet_ProperOutputs__SIZE_5040"){
          //--------------------------------------------------
          // TEST 2.2                                        :
          //--------------------------------------------------
          // Input Value:
          word = "aabbccd";

          // Answers to compare: ( 7! == 5040 values )
          output  =  { };                                             // Empty set to store
                                                                      // your output Set
          
          // Get the output Set:
          return(  str_permutations(  word,
                                      0, static_cast<int>( word.size() ) - 1,
                                      output                                     ) );
    };
    BENCHMARK("NonEmptySet_ProperOutputs__SIZE_40320"){
          //--------------------------------------------------
          // TEST 2.3                                        :
          //--------------------------------------------------
          // Input Value:
          word = "aabbccdd";

          // Answers to compare: ( 8! == 40320 values )
          output  =  { };                                             // Empty set to store
                                                                      // your output Set
          
          // Get the output Set:
          return(  str_permutations(  word,
                                      0, static_cast<int>( word.size() ) - 1,
                                      output                                     ) );
    };
}
