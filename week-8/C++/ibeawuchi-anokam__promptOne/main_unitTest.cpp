///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Week 8 - Search Prompt 1                             //
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
//      You are given the number of stones Senorita collects                 //
//      each day for N numbers of days, starting from the                    //
//      very first day. Now you are given Q queries, in each                 //
//      query her friend Shambhavi asks you the number of days               //
//      she has taken to collect M number of stones.                         //
//                                                                           //
//      Please note that each query contains the different                   //
//      number of M.                                                         //
//                                                                           //
//---------------------------------------------------------------------------//
//                                                                           //
//- Problem Constraints:                                                     //
//                                                                           //
//      1 <= N, Q <= 5*10^5                                                  //
//      1 <= A[i] <= 10^5                                                    //
//      1 <= M <= sum of all the elements in the array.                      //
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
//                 5, 4             // N number of days | Q queries          //
//               { 1, 2, 3, 4, 5 }  // N spaced M integers(stoned per day)   //
//               { 3, 8, 10, 14  }  // Q spaced query values                 //
//                                                                           //
//      Output:                                                              //
//                   2                                                       //
//                   4                                                       //
//                   4                                                       //
//                   5                                                       //
//                                                                           //
//      Explanation:                                                         //
//                   For each of the Q queries, you have to output           //
//                   the number of days she has taken to collect M           //
//                   number of stones in a new line.                         //
//                                                                           //
//---------------------------------------------------------------------------//
//- Source:                                                                  //
//                                                                           //
//  https://www.hackerearth.com/practice/algorithms/searching/               //
//  binary-search/practice-problems/algorithm/stones-love/description/       //
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
vector<int> stones_love (  vector< int > N,
                           vector< int > Q     )
{
    
    //---------------------------------------
    // Variable Declarations                :
    //---------------------------------------
    int day           =  1;             // The current day
    int running_total =  0;             // The Running total of rocks that are found each day
    map< int, int >  rocks_per_day;     // The Frequency graph of  (  x day,  y number of rocks  )
    vector<int>      return_val = { };  // The Set that will be returned to the main function
    

    if(  ( N.size() >= 1 && N.size() <= (5*(10*10*10*10*10))  )  &&
         ( Q.size() >= 1 && Q.size() <= (5*(10*10*10*10*10))  )      )
    {
        //---------------------------------------
        // Populate The Rocks per Day Graph     :
        //---------------------------------------
        for( auto rock_val : N ){
            
            // If The constraints of the function are not met
            // Then Return an empty Set:
            if(  !( rock_val >= 1  &&  rock_val <= (10*10*10*10*10) )  ){
                return_val = { };
                return (return_val);
            }
            
            // Keep the running total:
            running_total += rock_val;
            
            // Insert number of rocks found
            // ( i.e. the running total ):
            rocks_per_day[ day ] += running_total;
            
            // Continue to the next day:
            day++;
        }
        //---------------------------------------
        // QUERY The Frequency Graph for        :
        // the Q value it is searching for      :
        //---------------------------------------
        // Note: Since The Frequency Graph is an
        // instantation of <map>, it is already SORTED!
        for(  auto query : Q ){
            
            // If The constraints of the function are not met
            // Then Return an empty Set:
            if(  !( query >= 1  &&  query <= (10*10*10*10*10) )  ){
                return_val = { };
                return (return_val);
            }
            
            for( auto rock_count : rocks_per_day ){
                
                // Searching the map...
                // If the value is found push it into the array:
                if(  rock_count.second >= query  ){
                    return_val.push_back( rock_count.first  );
                    break;
                }
            }
        }
    }
    else{
        // if your N and Q array sizes are out of range
        // Then Return an empty array:
        return_val = { };
    }
    
    return ( return_val );
}


//===========================================================================//
//                    U N I T    T E S T     C A S E S                       //
//===========================================================================//
TEST_CASE(       "GivenAnEmptySet"        ,
              "[weekEightPromptOne_test]"       )
{
// Test Description -
//
//  This test validates that the function, "stones_love",
//  returns an empty Set when given empty Sets.
//--------------------------------------------------------------------
    
    
    //------------------------
    // Variable Declarations :
    //------------------------
    vector< int > N_container;
    vector< int > Q_container;
    
    vector< int > expected_output;
    
    
    //----------------------------------------------------------
    // 1.0                                                     :
    //----------------------------------------------------------
    SECTION( "BothParameterSetsAreEmpty" ){
        // Variable Declarations:
        N_container     = { };    // input parameter 1
        Q_container     = { };    // input parameter 2
        
        expected_output = { };    // output

        // Assertion:
        REQUIRE(  stones_love( N_container, Q_container ) ==  expected_output  );
    }
    //----------------------------------------------------------
    // 2.0                                                     :
    //----------------------------------------------------------
    SECTION( "OneParameterSetIsEmpty" ){
        //------------------------------------------------------
        // 2.1                                                 :
        //------------------------------------------------------
        // Variable Declarations:
        N_container     = { 1, 2 }; // input parameter 1
        Q_container     = { };      // input parameter 2
        
        expected_output = { };      // output

        // Assertion:
        REQUIRE(  stones_love( N_container, Q_container ) ==  expected_output  );
        //------------------------------------------------------
        // 2.2                                                 :
        //------------------------------------------------------
        // Variable Declarations:
        N_container     = { };        // input parameter 1
        Q_container     = { 1, 2 };   // input parameter 2
        
        expected_output = { };        // output

        // Assertion:
        REQUIRE(  stones_love( N_container, Q_container ) ==  expected_output  );
    }
    //----------------------------------------------------------
    // 3.0                                                     :
    //----------------------------------------------------------
    SECTION( "ParameterElementIsOutOfRange" ){
        //------------------------------------------------------
        // 3.1                                                 :
        //------------------------------------------------------
        // Variable Declarations:
        N_container     = { -1, 2, 3, 4, 5 };    // input parameter 1
        Q_container     = { 3, 8, 10, 14 };      // input parameter 1
        
        expected_output = { };                   // output

        // Assertion:
        REQUIRE(  stones_love( N_container, Q_container ) ==  expected_output  );
        //------------------------------------------------------
        // 3.2                                                 :
        //------------------------------------------------------
        // Variable Declarations:
        N_container     = { 1, 2, 3, 4, 5 };     // input parameter 1
        Q_container     = { 3, -8, 10, 14 };     // input parameter 1
        
        expected_output = { };                   // output

        // Assertion:
        REQUIRE(  stones_love( N_container, Q_container ) ==  expected_output  );
        //------------------------------------------------------
        // 3.3                                                 :
        //------------------------------------------------------
        // Variable Declarations:
        N_container     = { -1, 2, 3, 4, 5 };    // input parameter 1
        Q_container     = { 3, -8, 10, 14 };     // input parameter 1
        
        expected_output = { };                   // output

        // Assertion:
        REQUIRE(  stones_love( N_container, Q_container ) ==  expected_output  );
        //------------------------------------------------------
        // 3.4                                                 :
        //------------------------------------------------------
        // Variable Declarations:
        N_container     = { 100001, 2, 3, 4, 5 };   // input parameter 1
        Q_container     = { 3, 8, 10, 14 };         // input parameter 1
        
        expected_output = { };                      // output

        // Assertion:
        REQUIRE(  stones_love( N_container, Q_container ) ==  expected_output  );
        //------------------------------------------------------
        // 3.5                                                 :
        //------------------------------------------------------
        // Variable Declarations:
        N_container     = { 1, 2, 3, 4, 5 };        // input parameter 1
        Q_container     = { 3, 8, 100001, 14 };     // input parameter 1
        
        expected_output = { };                      // output

        // Assertion:
        REQUIRE(  stones_love( N_container, Q_container ) ==  expected_output  );
        //------------------------------------------------------
        // 3.6                                                 :
        //------------------------------------------------------
        // Variable Declarations:
        N_container     = { 100001, 2, 3, 4, 5 };   // input parameter 1
        Q_container     = { 3, 8, 100001, 14 };     // input parameter 1
        
        expected_output = { };                      // output

        // Assertion:
        REQUIRE(  stones_love( N_container, Q_container ) ==  expected_output  );
    }
}
TEST_CASE(       "GivenANonEmptySet"        ,
              "[weekEightPromptOne_test]"       )
{
// Test Description -
//
//  This test validates that the function, "stones_love",
//  returns the correct Set.
//--------------------------------------------------------------------

    
    //------------------------
    // Variable Declarations :
    //------------------------
    vector< int > N_container;
    vector< int > Q_container;
    
    vector< int > expected_output;

    //----------------------------------------------------------
    // 4.0                                                     :
    //----------------------------------------------------------
    SECTION( "ExpectedOutputValuesFound" ){
        //------------------------------------------------------
        // 4.1                                                 :
        //------------------------------------------------------
        // Variable Declarations:
        N_container     = { 1, 2, 3, 4, 5 };    // input parameter 1
        Q_container     = { 3, 8, 10, 14 };     // input parameter 1
        
        expected_output = { 2, 4, 4, 5 };       // output

        // Assertion:
        REQUIRE(  stones_love( N_container, Q_container ) ==  expected_output  );
    }
}
