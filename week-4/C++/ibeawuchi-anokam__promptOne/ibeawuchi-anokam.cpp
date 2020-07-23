///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Week 4 - Linked List Prompt 1                        //
// Filename:            main.cpp                                             //
//---                                                                        //
// Date of Creation:    06/20/20                                             //
// Last Revised By:     N/A                                                  //
// Last Revision Date:  N/A                                                  //
//---                                                                        //
// Copyright:           Copyright © 2020 Ibeawuchi Anokam.                   //
//                      All rights reserved.                                 //
//---------------------------------------------------------------------------//
//                                                                           //
// Program Description:                                                      //
//                                                                           //
//      You are given two linked lists storing positive integers.            //
//      Write a function that adds the numbers and returns the sum           //
//      as a linked list.                                                    //
//                                                                           //
//     - Example:                                                            //
//          Input:                                                           //
//          L1 = 5 -> 6 -> 3 -> NULL                                         //
//          L2 = 8 -> 4 -> 2 -> NULL                                         //
//                                                                           //
//          Output: 1 -> 4 -> 0 -> 5 -> NULL                                 //
//                                                                           //
//---------------------------------------------------------------------------//


//===========================================================================//
//                   F U N C T I O N    M O D U L E (S) -                    //
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
#include <list>
#include <string>
using namespace std;

//===========================================================================//
//            F U N C T I O N    M O D U L E    T O    T E S T               //
//===========================================================================//
list<int> weekFourPromptOne(   list<int> L1,
                               list<int> L2    )
{
// Fuunction Description -
//
//  This function takes two positive integer values
//  stored individually in two Lists, L1 and L2. Each individual digit
//  of the integers are stored node by node within their respective
//  lists.
//
//  The stored integer values are added together and the
//  summation value is returned as a list where each individual digit
//  of the integers are stored node by node within it.
//--------------------------------------------------------------------
    
    //-----------------------------------------------------------
    // Iterator Variable Declarations                           :
    //-----------------------------------------------------------
    list<int>::iterator i;
    //-----------------------------------------------------------
    // Variable Declarations                                    :
    //-----------------------------------------------------------
    string    L1_str, L2_str;       // List Buffers
    
    string    L3_sum;               // Stores the Summation Value
    
    list<int> L3_sumList;           // Initializes Summation List
    
    bool is_positive_digit = true;  // boolean checks if all
                                    // digits in a list are
                                    // positive
    
    //-----------------------------------------------------------
    // Iterate and grab each individual digit in L1             :
    //-----------------------------------------------------------
    i  =  L1.begin();
    while( i !=  L1.end()  && is_positive_digit == true  )
    {
        if( *i >= 0   &&   *i <= 9 ){
            // Append digits into a string
            // while making sure to change the
            // 'int' to a 'char' :
            L1_str += to_string( *i );
        }
        else{
            is_positive_digit = false;
        }
        i++;
    }
    //-----------------------------------------------------------
    // Iterate and grab each individual digit in L2             :
    //-----------------------------------------------------------
    i  =  L2.begin();
    while( i !=  L2.end()  && is_positive_digit == true  )
    {
        if( *i >= 0   &&   *i <= 9 ){
            // Append digits into a string
            // while making sure to change the
            // 'int' to a 'char' :
            L2_str += to_string( *i );
        }
        else{
            is_positive_digit = false;
        }
        i++;
    }

    //-----------------------------------------------------------
    // Output The summation List IF there exists ONLY           :
    // positive integers in each node of L1 and L2              :
    // ELSE output an empty List                                :
    //-----------------------------------------------------------
    if(  is_positive_digit == true  &&
         !L1.empty()                &&
         !L2.empty()                     )
    {
        //-------------------------------------------------------
        // Add the L1_str and L2_str integers and store         :
        // the summation value                                  :
        //-------------------------------------------------------
        L3_sum  = to_string(  stoi( L1_str ) + stoi( L2_str )   );

        //-------------------------------------------------------
        // Insert each individual digit found in the sum        :
        // into individual nodes in the list                    :
        //-------------------------------------------------------
        for(  int j = 0;
              j < static_cast<int>(L3_sum.size());
              j++                                    )
        {
            // * NOTE: CONVERT 'char' TO 'int' BEFORE PUSHING IT INTO  L3:
            L3_sumList.push_back(  static_cast<int>(L3_sum.at( j ))-48  );
        }

        // RETURN A Non-empty List With The Summation Digits:
        return ( L3_sumList );
    }
    else{
        // RETURN An Empty List:
        return ( L3_sumList );
    }
}


//===========================================================================//
//                         U N I T    T E S T (S) -                          //
//                      G L O B A L    S E C T I O N                         //
//===========================================================================//
// Digit List Containers:
list<int>   L1_container;    // L1 digits
list<int>   L2_container;    // L2 digits
list<int>  *L3_ptr;          // L3 digits - head pointer
// Summation Value Container:
string      summation_value; // L1 + L2 Summation
// Iterator Variable:
list<int>::iterator i;

//===========================================================================//
//                    U N I T    T E S T     C A S E S                       //
//===========================================================================//
TEST_CASE(  "CanGetEmptySummationList"    ,   "[weekFourPromptOne_test]"    ){
// Test Description -
//
//  CASE 1  :
//  ---------
//  This test validates that the function, "weekFourPromptOne",
//  cannot take 2 empty List parameters or 2 List parameters with
//  any or both lists having negative integers in it's nodes.
//  It returns an empty summation list
//--------------------------------------------------------------------

    // Initialize L1 as an empty List:
    L1_container.clear();
    // Initialize L2 as an empty List:
    L2_container.clear();
    
    //---------------------------------------------------
    // TEST 1.1                                         :
    //---------------------------------------------------
    SECTION( "EmptyLists" ){
        // Check Assertion:
        REQUIRE(   weekFourPromptOne( L1_container, L2_container ).empty( )     );
    }
    //---------------------------------------------------
    // TEST 1.2                                         :
    //---------------------------------------------------
    SECTION( "FirstNumberIsNegative" ){
        // L1 := -1 :
        L1_container.push_back(  -1  );
        // L2 := 0  :
        L2_container.push_back(  0  );
        // Check Assertion:
        REQUIRE( weekFourPromptOne( L1_container, L2_container ).empty( )   );
    }
    //---------------------------------------------------
    // TEST 1.3                                         :
    //---------------------------------------------------
    SECTION( "SecondNumberIsNegative" ){
        // L1 := -1 :
        L1_container.push_back(  0  );
        // L2 := 0  :
        L2_container.push_back(  -1  );
        // Check Assertion:
        REQUIRE( weekFourPromptOne( L1_container, L2_container ).empty( )   );
    }
    //---------------------------------------------------
    // TEST 1.4                                         :
    //---------------------------------------------------
    SECTION( "BothNumbersAreNegative" ){
        // L1 := -1 :
        L1_container.push_back(  -1  );
        // L2 := -1 :
        L2_container.push_back(  -1  );
        // Check Assertion:
        REQUIRE( weekFourPromptOne( L1_container, L2_container ).empty( )   );
    }
    
}
TEST_CASE(  "CanGetNonEmptySummationList" ,   "[weekFourPromptOne_test]"    ){
// Test Description -
//
//  CASE 2  :
//  ---------
//  These tests validate that the function, "weekFourPromptOne", can
//  take 2 List parameters with either positive integers or zero in
//  each of their nodes and returns a non-empty summation list
//--------------------------------------------------------------------

    // Initialize L1 as an empty List:
    L1_container.clear();
    // Initialize L2 as an empty List:
    L2_container.clear();
    
    //---------------------------------------------------
    // TEST 2.1                                         :
    //---------------------------------------------------
    SECTION( "BothNumbersAreZero" ){
        // L1 := 0 :
        L1_container.push_back(  0  );
        // L2 := 0 :
        L2_container.push_back(  0  );
        // Check Assertion:
        REQUIRE(   !weekFourPromptOne( L1_container, L2_container ).empty( )    );
    }
    //---------------------------------------------------
    // TEST 2.2                                         :
    //---------------------------------------------------
    SECTION( "APositiveAndAZero" ){
        // L1 := 1 :
        L1_container.push_back(  1  );
        // L2 := 0 :
        L2_container.push_back(  0  );
        // Check Assertion:
        REQUIRE(   !weekFourPromptOne( L1_container, L2_container ).empty( )    );
    }
    //---------------------------------------------------
    // TEST 2.3                                         :
    //---------------------------------------------------
    SECTION( "AZeroAndAPositive" ){
        // L1 := 0 :
        L1_container.push_back(  0  );
        // L2 := 1 :
        L2_container.push_back(  1  );
        // Check Assertion:
        REQUIRE(   !weekFourPromptOne( L1_container, L2_container ).empty( )    );
    }
    //---------------------------------------------------
    // TEST 2.4                                         :
    //---------------------------------------------------
    SECTION( "APositiveAndAPositive" ){
        // L1 := 1 :
        L1_container.push_back(  1  );
        // L2 := 1 :
        L2_container.push_back(  1  );
        // Check Assertion:
        REQUIRE(   !weekFourPromptOne( L1_container, L2_container ).empty( )    );
    }
    
}
TEST_CASE(  "CanOnlyTakeDigitsPerEachNode"   ,   "[weekFourPromptOne_test]" ){
// Test Description -
//
//  CASE 3  :
//  ---------
//  These tests validate that the function, "weekFourPromptOne", cannot
//  take 2 List parameters where one or both of the lists has one or
//  more nodes that hold an integer value that's not
//  between 0 and 9 ( i.e. a digit ).
//  It returns an empty summation list.
//--------------------------------------------------------------------
    
    // Initialize L1 as an empty List:
    L1_container.clear();
    // Initialize L2 as an empty List:
    L2_container.clear();
    
    //---------------------------------------------------
    //  TEST 3.1                                        :
    //---------------------------------------------------
    SECTION( "FirstNumberIsNotADigit" ){
        // L1 := 0 :
        L1_container.push_back(  123  );
        // L2 := 1 :
        L2_container.push_back(   0   );
        // Check Assertion:
        REQUIRE(   weekFourPromptOne( L1_container, L2_container ).empty( )    );
    }
    //---------------------------------------------------
    //  TEST 3.2                                        :
    //---------------------------------------------------
    SECTION( "SecondNumberIsNotADigit" ){
        // L1 := 0 :
        L1_container.push_back(   0   );
        // L2 := 1 :
        L2_container.push_back(  123  );
        // Check Assertion:
        REQUIRE(   weekFourPromptOne( L1_container, L2_container ).empty( )    );
    }
    //---------------------------------------------------
    //  TEST 3.3                                        :
    //---------------------------------------------------
    SECTION( "BothNumbersAreNotDigits_one" ){
        // L1 := 0 :
        L1_container.push_back(  123  );
        // L2 := 1 :
        L2_container.push_back(  123  );
        // Check Assertion:
        REQUIRE(   weekFourPromptOne( L1_container, L2_container ).empty( )    );
    }
    //---------------------------------------------------
    //  TEST 3.4                                        :
    //---------------------------------------------------
    SECTION( "BothNumbersAreNotDigits_two" ){
        // L1 := 0 :
        L1_container.push_back(  99999  );
        // L2 := 1 :
        L2_container.push_back(  111  );
        // Check Assertion:
        REQUIRE(   weekFourPromptOne( L1_container, L2_container ).empty( )    );
    }
    //---------------------------------------------------
    //  TEST 3.5                                        :
    //---------------------------------------------------
    SECTION( "BothNumbersAreNotDigits_three" ){
        // L1 := 0 :
        L1_container.push_back(  1243  );
        // L2 := 1 :
        L2_container.push_back(  123423  );
        // Check Assertion:
        REQUIRE(   weekFourPromptOne( L1_container, L2_container ).empty( )    );
    }
}
TEST_CASE(  "CanGetProperSummationSolutions" ,   "[weekFourPromptOne_test]" ){
// Test Description -
//
//  CASE 4  :
//  ---------
//  These tests validate that the function, "weekFourPromptOne",
//  outputs the correct summation value
//--------------------------------------------------------------------
 
    // Initialize L1 as an empty List:
    L1_container.clear();
    // Initialize L2 as an empty List:
    L2_container.clear();
    
    //---------------------------------------------------
    //  TEST 4.1                                        :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestOne" ){
        // L1 := 0 :
        L1_container.push_back(  0  );
        // L2 := 0 :
        L2_container.push_back(  0  );
        // L3 := L1 + L2 == (0) + (0) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  0   );
    }
    //---------------------------------------------------
    //  TEST 4.2                                        :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestTwo" ){
        // L1 := 1 :
        L1_container.push_back(  1  );
        // L2 := 0 :
        L2_container.push_back(  0  );
        // L3 := L1 + L2 == (1) + (0) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  1   );
    }
    //---------------------------------------------------
    //  TEST 4.3                                        :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestThree" ){
        // L1 := 0 :
        L1_container.push_back(  0  );
        // L2 := 1 :
        L2_container.push_back(  1  );
        // L3 := L1 + L2 == (0) + (1) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  1   );
    }
    //---------------------------------------------------
    //  TEST 4.4                                        :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestFour" ){
        // L1 := 1 :
        L1_container.push_back(  1  );
        // L2 := 1 :
        L2_container.push_back(  1  );
        // L3 := L1 + L2 == (1) + (1) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  2   );
    }
    //---------------------------------------------------
    //  TEST 4.5                                        :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestFive" ){
        // L1 := 111 :
        L1_container.push_back(  1  );
        L1_container.push_back(  1  );
        L1_container.push_back(  1  );
        // L2 := 111 :
        L2_container.push_back(  1  );
        L2_container.push_back(  1  );
        L2_container.push_back(  1  );
        // L3 := L1 + L2 == (111) + (111) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  222   );
    }
    //---------------------------------------------------
    //  TEST 4.6                                        :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestSix" ){
        // L1 := 000 :
        L1_container.push_back(  0  );
        L1_container.push_back(  0  );
        L1_container.push_back(  0  );
        // L2 := 111 :
        L2_container.push_back(  1  );
        L2_container.push_back(  1  );
        L2_container.push_back(  1  );
        // L3 := L1 + L2 == (000) + (111) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  111   );
    }
    //---------------------------------------------------
    //  TEST 4.7                                        :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestSeven" ){
        // L1 := 111 :
        L1_container.push_back(  1  );
        L1_container.push_back(  1  );
        L1_container.push_back(  1  );
        // L2 := 000 :
        L2_container.push_back(  0  );
        L2_container.push_back(  0  );
        L2_container.push_back(  0  );
        // L3 := L1 + L2 == (111) + (000) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  111   );
    }
    //---------------------------------------------------
    //  TEST 4.8                                        :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestEight" ){
        // L1 := 563 :
        L1_container.push_back(  5  );
        L1_container.push_back(  6  );
        L1_container.push_back(  3  );
        // L2 := 842 :
        L2_container.push_back(  8  );
        L2_container.push_back(  4  );
        L2_container.push_back(  2  );
        // L3 := L1 + L2 == (563) + (842) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  1405   );
    }
    //---------------------------------------------------
    //  TEST 4.9                                        :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestNine" ){
        // L1 := 6712 :
        L1_container.push_back(  6  );
        L1_container.push_back(  7  );
        L1_container.push_back(  1  );
        L1_container.push_back(  2  );
        // L2 := 132 :
        L2_container.push_back(  1  );
        L2_container.push_back(  3  );
        L2_container.push_back(  2  );
        // L3 := L1 + L2 == (6712) + (132) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  6844   );
    }
    //---------------------------------------------------
    //  TEST 4.10                                       :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestTen" ){
        // L1 := 0 :
        L1_container.push_back(  0  );
        // L2 := 119,0000 :
        L2_container.push_back(  1  );
        L2_container.push_back(  1  );
        L2_container.push_back(  9  );
        L2_container.push_back(  0  );
        L2_container.push_back(  0  );
        L2_container.push_back(  0  );
        // L3 := L1 + L2 == (0) + (119,0000) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                      )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  119000   );
    }
    //---------------------------------------------------
    //  TEST 4.11                                       :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestEleven" ){
        // L1 := 123456789 :
        L1_container.push_back(  1  );
        L1_container.push_back(  2  );
        L1_container.push_back(  3  );
        L1_container.push_back(  4  );
        L1_container.push_back(  5  );
        L1_container.push_back(  6  );
        L1_container.push_back(  7  );
        L1_container.push_back(  8  );
        L1_container.push_back(  9  );
        // L2 := 1 :
        L2_container.push_back(  1  );
        // L3 := L1 + L2 == (123456789) + (1) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                      )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  123456790   );
    }
    //---------------------------------------------------
    //  TEST 4.12                                       :
    //---------------------------------------------------
    SECTION( "ProperSummation_TestTwelve" ){
        // L1 := 92 :
        L1_container.push_back(  9  );
        L1_container.push_back(  2  );
        // L2 := 8 :
        L2_container.push_back(  8  );
        // L3 := L1 + L2 == (92) + (8) :
        L3_ptr = new list<int>( weekFourPromptOne( L1_container, L2_container ) );

        // Iterate and grab each individual integer in L3:
        summation_value.clear();
        for(  i  =  L3_ptr -> begin();
           i !=  L3_ptr -> end();
           i++                      )
        {
         // Append each integer into a string:
         summation_value += to_string(*i);
        }
        // Check Assertion:
        REQUIRE(   stoi( summation_value ) ==  100   );
    }
}
