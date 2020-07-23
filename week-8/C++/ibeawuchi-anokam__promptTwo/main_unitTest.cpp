///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Week 8 - Search Prompt 2                             //
// Filename:            main.cpp                                             //
//---                                                                        //
// Date of Creation:    07/15/20                                             //
// Last Revised By:     N/A                                                  //
// Last Revision Date:  N/A                                                  //
//---                                                                        //
// Copyright:           Copyright © 2020 Ibeawuchi Anokam.                   //
//                      All rights reserved.                                 //
//---------------------------------------------------------------------------//
//                                                                           //
//- Program Description:                                                     //
//                                                                           //
//      You are given a List of N number ( a1,a2,a3........an ).             //
//      You have to find smallest number from the List that is               //
//      repeated in the List exactly K number of times.                      //
//                                                                           //
//  Note: There Will Be At least One Variable Which Is Repeated K Times      //
//        [ ELSE return -1 ]                                                 //
//                                                                           //
//---------------------------------------------------------------------------//
//                                                                           //
//- Problem Constraints:                                                     //
//                                                                           //
//      0 <  N  < 100001                                                     //
//      0 <= K  < 100001                                                     //
//      0 <= ai < 100001                                                     //
//                                                                           //
//- Program Constraints:                                                     //
//                                                                           //
//      * Time Limit:      1.0  sec(s) for each input file                   //
//      * Memory Limit:    256  MB                                           //
//      * Source Limit:    1024 KB                                           //
//                                                                           //
//---------------------------------------------------------------------------//
//                                                                           //
//- Example:                                                                 //
//                                                                           //
//      Input:                                                               //
//                      5               // N number of inputs                //
//                      2 2 1 3 1       // N spaced values                   //
//                      2               // K frequency to search for         //
//                                                                           //
//      Output:                                                              //
//                      1                                                    //
//                                                                           //
//      Explanation:                                                         //
//                      The Smallest Integer Value That is Repeated          //
//                      Exactly K Number of Times is returned                //
//                                                                           //
//---------------------------------------------------------------------------//
//- Source:                                                                  //
//                                                                           //
//  https://www.hackerearth.com/practice/algorithms/searching/               //
//  linear-search/practice-problems/algorithm/repeated-k-times/              //
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
#include <map>
using namespace std;


//===========================================================================//
//        F U N C T I O N    M O D U L E (S)    T O    T E S T               //
//===========================================================================//
int repeated_k_times (  vector< int > List,  int k  )
{
    
    //---------------------------------------
    // Variable Declarations                :
    //---------------------------------------
    map< int, int > freq_graph;   // Note: Maps are already SORTED !
    int lowest_val;
    

    if( List.size() > 0 ){
        //---------------------------------------
        // Populate The Frequency Graph         :
        //---------------------------------------
        for( auto list_val : List ){

            // add the count
            freq_graph[ list_val ]++;
        }
        //---------------------------------------
        // SEARCH The Frequency Graph for       :
        // the lowest value with 'k' frequency  :
        //---------------------------------------
        // Note: Since The Frequency Graph is an
        // instantation of <map>, it is already SORTED!
        lowest_val = -1;
        for( auto freq_val : freq_graph ){

            // Searching the map...
            // If nothing is found for 'k' then
            // return -1 ELSE return the found value:
            if( freq_val.second == k ){
                lowest_val = freq_val.first;
                break;
            }
        }
    }
    else{
        // if your array has no values then return -1:
        lowest_val = -1;
    }

    return ( lowest_val );
}


//===========================================================================//
//                    U N I T    T E S T     C A S E S                       //
//===========================================================================//
TEST_CASE(       "GivenAnEmptyList"        ,
              "[weekEightPromptTwo_test]"       )
{
// Test Description -
//
//  This test validates that the function, "repeated_k_times",
//  returns -1 when given an empty List.
//--------------------------------------------------------------------
    
    
    //---------------------------------------------------
    // TEST 1                                           :
    //---------------------------------------------------
    vector< int > input = { };
    int k_val = 1;
    
    // Output Value:
    REQUIRE(  repeated_k_times( input, k_val ) == -1   );
}
TEST_CASE(       "GivenANonEmptyList"        ,
              "[weekEightPromptTwo_test]"       )
{
// Test Description -
//
//  This test validates that the function, "repeated_k_times",
//  returns the correct values.
//--
//  NOTE:
//  Since the independent parameter, List, is not empty
//  The focus is put on the DEPENDENT parameter, 'k'.
//--------------------------------------------------------------------
    
    //---------------------------------------------------
    // Variable Declarations                            :
    //---------------------------------------------------
    vector< int > input;
    int k_val;
    
    SECTION( "NoFrequencyValueIsFound" ){
    // A search for numbers with the K frequency are not found
    //----------------------------------------------------------
        
        //---------------------------------------------------
        // TEST 2                                           :
        //---------------------------------------------------
        input = { 2, 2, 1, 3, 1 };
        k_val = 3;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == -1   );
        //---------------------------------------------------
        // TEST 3                                           :
        //---------------------------------------------------
        input = { 2, 2, 2, 2, 1, 3, 1 };
        k_val = 3;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == -1   );
    }
    SECTION( "OneFrequencyValueExists" ){
    // A search for numbers with the K frequency is found once
    //----------------------------------------------------------
        
        
        //---------------------------------------------------
        // TEST 4                                           :
        //---------------------------------------------------
        // The Value is in the middle:
        input = { 1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6 };
        k_val = 1;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 3   );
        //---------------------------------------------------
        // TEST 5                                           :
        //---------------------------------------------------
        // The Value is at the back:
        input = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6 };
        k_val = 1;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 6   );
        //---------------------------------------------------
        // TEST 6                                           :
        //---------------------------------------------------
        // The Value is in the front:
        input = { 0, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6 };
        k_val = 1;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 0   );
    }
    SECTION( "MultipleFrequencyValuesExists" ){
    // A search for numbers with the K frequency are found
    // multiple times
    //----------------------------------------------------------
        
        //---------------------------------------------------
        // TEST 7                                           :
        //---------------------------------------------------
        // ordered - The Value is scattered:
        input = { 2, 2, 1, 3, 1 };
        k_val = 2;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 1   );
        //---------------------------------------------------
        // TEST 8                                           :
        //---------------------------------------------------
        // ordered - The Value is in the middle:
        input = { 1, 1, 2, 2, 3, 4, 4, 5, 6, 6, 6 };
        k_val = 1;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 3   );
        //---------------------------------------------------
        // TEST 9                                           :
        //---------------------------------------------------
        // ordered - The Value is at the back:
        input = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7 };
        k_val = 1;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 7   );
        //---------------------------------------------------
        // TEST 10                                          :
        //---------------------------------------------------
        // ordered - The Value is in the front:
        input = { 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 6 };
        k_val = 1;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 0   );
        //---------------------------------------------------
        // TEST 11                                          :
        //---------------------------------------------------
        // Unordered - The Value is in the middle:
        input = { 9, 1, 1, 2, 2, 3, 4, 4, 5, 6, 6, 6 };
        k_val = 1;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 3   );
        //---------------------------------------------------
        // TEST 12                                          :
        //---------------------------------------------------
        // Unordered - The Value is at the back:
        input = { 9, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7 };
        k_val = 1;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 7   );
        //---------------------------------------------------
        // TEST 13                                          :
        //---------------------------------------------------
        // Unordered - The Value is in the front:
        input = { 9, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7 };
        k_val = 1;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 1   );
        //---------------------------------------------------
        // TEST 14                                          :
        //---------------------------------------------------
        // Unordered - The Value is scattered:
        input = { 9, 1, 2, 2, 1, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7 };
        k_val = 2;
        
        // Output Value:
        REQUIRE(   repeated_k_times( input, k_val ) == 1   );
    }
}
