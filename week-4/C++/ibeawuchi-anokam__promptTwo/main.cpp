///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Week 4 - Linked List Prompt 2                        //
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
//      You are given a linked list, 'S', which represents a sentence        //
//      where each node represents a letter.                                 //
//      Write a function that returns the list, a reversed sentence,         //
//      without reversing the individual words.                              //
//                                                                           //
//- Example:                                                                 //
//  Input:                                                                   //
//  I-> ->l->o->v->e-> ->G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s->NULL   //
//                                                                           //
//  Output:                                                                  //
//  G->e->e->k->s-> ->f->o->r-> ->G->e->e->k->s-> ->l->o->v->e-> ->I->NULL   //
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
list<char> weekFourPromptTwo(   list<char> S   )
{
// Fuunction Description -
//
//  This function reverses the order of each word in a sentence
//  and stores each of the characters of that sentence into individual
//  nodes and returns the reversed list
//--------------------------------------------------------------------
    
    //-----------------------------------------------------------
    // Iterator Variable Declarations                           :
    //-----------------------------------------------------------
    list<char>::iterator i;
    //-----------------------------------------------------------
    // Variable Declarations                                    :
    //-----------------------------------------------------------
    string     buffer;               // Buffer
    string     buffer_concatenate;   // String to hold a concatenated buffer
    list<char> reverse_sentence;     // Initialize Summation List
    
    bool is_ok_to_print = true;      // boolean checks if the List, S ,
                                     // has a valid sentence
    
    bool is_space_on = false;        // boolean checks if the function should
                                     // store a space character or not
    
    //-----------------------------------------------------------
    // Check That ONLY ascii[a-zA-z] and                        :
    // ascii[space] characters exists in the List, S            :
    //-----------------------------------------------------------
    i  =  S.begin();
    while( i !=  S.end()  && is_ok_to_print == true  )
    {
        // If a letter or space is NOT reached ... :
        if(  !( ( *i >= 'a'  &&  *i <= 'z' ) ||
                ( *i >= 'A'  &&  *i <= 'Z' ) ||
                ( *i == ' '                )     )   )
        {
            is_ok_to_print = false;
        }
        else{ // ... increment through sentence
            i++;
        }
    }
    
    //-----------------------------------------------------------
    // Sentence Reversal                                        :
    //-----------------------------------------------------------
    if( !S.empty() &&  is_ok_to_print == true ){
        //-------------------------------------------------------
        // Count the number of Spaces In The List               :
        //-------------------------------------------------------
        int  number_of_spaces = 0;
        for( i = S.begin();  i != S.end();  i++ ){
            if( (static_cast<int>(*i) == 32)  ){
                number_of_spaces++;
            }
        }

        //-------------------------------------------------------
        // Reverse The List                                     :
        //-------------------------------------------------------
        for( i = S.begin();  i != S.end();  i++ )
        {
            // If a letter or space is reached:
            if(  ( *i >= 'a'  &&  *i <= 'z' ) ||
                 ( *i >= 'A'  &&  *i <= 'Z' )    )
            {
                buffer.push_back( *i );
            }
            // If a space is reached:
            else {  // ... if( (static_cast<int>(*i) == 32)  ){
                if( is_space_on == false ){
                    is_space_on = true;
                }
                else{
                    // Account for the first words space:
                    buffer += " ";                       // Put the space behind a word
                }
                buffer_concatenate.insert( 0, buffer);   // concatenate the Reverse List
                buffer.clear();                          // RESET/Clear the buffer
            }
        }
        // Account for a Space not being at the end of the sentence:
        if( number_of_spaces > 0 ){
            // If more than one word (i.e. a space) was accounted for ... :
            buffer += " ";                       // put the space at the end
        }
        buffer_concatenate.insert( 0, buffer);   // concatenate the Reverse List
        buffer.clear();                          // Reset/Clear the buffer


        //-------------------------------------------------------
        // Insert reversed sentence into A List                 :
        // where each character is inserted into it the List    :
        // node by node                                         :
        //-------------------------------------------------------
        for( int j = 0;  j < static_cast<int>(buffer_concatenate.size());  j++ )
        {
            reverse_sentence.push_back(  buffer_concatenate.at( j )  );
        }

        //-------------------------------------------------------
        // RETURN A Non-Empty List                              :
        //-------------------------------------------------------
        return ( reverse_sentence );
    }
    else{
        //-------------------------------------------------------
        // RETURN An Empty List                                 :
        //-------------------------------------------------------
        return ( reverse_sentence );
    }
}


//===========================================================================//
//                         U N I T    T E S T (S) -                          //
//                      G L O B A L    S E C T I O N                         //
//===========================================================================//
// Original Sentence List Container:
list<char>  L1_container;
// Reversed Sentence List head ptr:
list<char>  *L2_ptr;
// Reversed Sentence String Container:
string      reversed_sentence;
// Iterator Variable:
list<char>::iterator i;

//===========================================================================//
//                    U N I T    T E S T     C A S E S                       //
//===========================================================================//
TEST_CASE(       "CanGetEmptyList"        ,
              "[weekFourPromptTwo_test]"       )
{
// Test Description -
//
//  CASE 1  :
//  ---------
//  This test validates that the function, "weekFourPromptTwo",
//  cannot take an empty List input and returns an empty list.
//--------------------------------------------------------------------
    
    //---------------------------------------------------
    // TEST 1.1                                         :
    //---------------------------------------------------
    // Initialize L1 as an empty List:
    L1_container.clear();
    // Check Assertion:
    REQUIRE(   weekFourPromptTwo(   L1_container   ).empty( )     );
    
}
TEST_CASE(       "CanGetNonEmptyList"     ,
               "[weekFourPromptTwo_test]"       )
{
// Test Description -
//
//  CASE 2  :
//  ---------
//  The test validates that the function, "weekFourPromptTwo", can
//  take a non-empty List parameter and returns a non-empty list
//
//-
//  Constraint: List only accepts ascii[a-zA-z] and a ascii[space]
//--------------------------------------------------------------------

    // Initialize L1 as an empty List:
    L1_container.clear();
    
    //---------------------------------------------------
    // TEST 2.1                                         :
    //---------------------------------------------------
    SECTION( "FirstLowercaseLetter" ){
        // L1 - Original Sentence:
        L1_container.push_back(  'a'  );
        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );
        // Check Assertion:
        REQUIRE(   !( L2_ptr -> empty( ) )    );
    }
    //---------------------------------------------------
    // TEST 2.2                                         :
    //---------------------------------------------------
    SECTION( "AnyMiddleLowercaseLetter" ){
        // L1 - Original Sentence:
        L1_container.push_back(  'm'  );
        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );
        // Check Assertion:
        REQUIRE(   !( L2_ptr -> empty( ) )    );
    }
    //---------------------------------------------------
    // TEST 2.3                                         :
    //---------------------------------------------------
    SECTION( "LastLowercaseLetter" ){
        // L1 - Original Sentence:
        L1_container.push_back(  'z'  );
        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );
        // Check Assertion:
        REQUIRE(   !( L2_ptr -> empty( ) )    );
    }
    //---------------------------------------------------
    // TEST 2.4                                         :
    //---------------------------------------------------
    SECTION( "FirstUppercaseLetter" ){
        // L1 - Original Sentence:
        L1_container.push_back(  'A'  );
        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );
        // Check Assertion:
        REQUIRE(   !( L2_ptr -> empty( ) )    );
    }
    //---------------------------------------------------
    // TEST 2.5                                         :
    //---------------------------------------------------
    SECTION( "AnyMiddleUppercaseLetter" ){
        // L1 - Original Sentence:
        L1_container.push_back(  'M'  );
        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );
        // Check Assertion:
        REQUIRE(   !( L2_ptr -> empty( ) )    );
    }
    //---------------------------------------------------
    // TEST 2.6                                         :
    //---------------------------------------------------
    SECTION( "LastUppercaseLetter" ){
        // L1 - Original Sentence:
        L1_container.push_back(  'Z'  );
        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );
        // Check Assertion:
        REQUIRE(   !( L2_ptr -> empty( ) )    );
    }

}
TEST_CASE(  "CanGetEmptyListWithInvalidCharacters"  ,
                "[weekFourPromptTwo_test]"               )
{
// Test Description -
//
//  CASE 3  :
//  ---------
//  This test validates that the function, "weekFourPromptTwo",
//  cannot take a List with invalid characters -- It returns
//  an empty list
//-
//  ( i.e. Constraint: List only accepts ascii[a-zA-z] and a ascii[space] )
//--------------------------------------------------------------------
    
    // Initialize L1 as an empty List:
    L1_container.clear();

    //---------------------------------------------------
    // TEST 3.1                                         :
    //---------------------------------------------------
    SECTION( "InvalidCharacters_Numbers" ){
        // L1 - Original Sentence:
        L1_container.push_back(  '5'  );
        // Check Assertion:
        REQUIRE(   weekFourPromptTwo(   L1_container   ).empty( )     );
    }
    //---------------------------------------------------
    // TEST 3.2                                         :
    //---------------------------------------------------
    SECTION( "InvalidCharacters_Symbols" ){
        // L1 - Original Sentence:
        L1_container.clear();
        L1_container.push_back(  '@'  );
        // Check Assertion:
        REQUIRE(   weekFourPromptTwo(   L1_container   ).empty( )     );
    }
    //---------------------------------------------------
    // TEST 3.3                                         :
    //---------------------------------------------------
    SECTION( "InvalidCharacters_Numbers_Symbols" ){
        // L1 - Original Sentence:
        L1_container.clear();
        L1_container.push_back(  '5'  );
        L1_container.push_back(  '@'  );
        // Check Assertion:
        REQUIRE(   weekFourPromptTwo(   L1_container   ).empty( )     );
    }
    //---------------------------------------------------
    // TEST 3.4                                         :
    //---------------------------------------------------
    SECTION( "InvalidCharacters_Numbers_letters" ){
        // L1 - Original Sentence:
        L1_container.push_back(  '1'  );
        L1_container.push_back(  'a'  );
        L1_container.push_back(  'A'  );
        L1_container.push_back(  '2'  );
        L1_container.push_back(  'z'  );
        L1_container.push_back(  'Z'  );
        L1_container.push_back(  '3'  );
        // Check Assertion:
        REQUIRE(   weekFourPromptTwo(   L1_container   ).empty( )     );
    }
    //---------------------------------------------------
    // TEST 3.5                                         :
    //---------------------------------------------------
    SECTION( "InvalidCharacters_Symbols_letters" ){
        // L1 - Original Sentence:
        L1_container.push_back(  '&'  );
        L1_container.push_back(  'a'  );
        L1_container.push_back(  'A'  );
        L1_container.push_back(  '.'  );
        L1_container.push_back(  'z'  );
        L1_container.push_back(  'Z'  );
        L1_container.push_back(  '*'  );
        // Check Assertion:
        REQUIRE(   weekFourPromptTwo(   L1_container   ).empty( )     );
    }
    //---------------------------------------------------
    // TEST 3.6                                         :
    //---------------------------------------------------
    SECTION( "InvalidCharacters_Numbers_Symbols_letters" ){
        // L1 - Original Sentence:
        L1_container.push_back(  'A'  );
        L1_container.push_back(  '1'  );
        L1_container.push_back(  'a'  );
        L1_container.push_back(  ')'  );
        L1_container.push_back(  '2'  );
        L1_container.push_back(  '3'  );
        L1_container.push_back(  'z'  );
        L1_container.push_back(  'Z'  );
        L1_container.push_back(  '*'  );
        // Check Assertion:
        REQUIRE(   weekFourPromptTwo(   L1_container   ).empty( )     );
    }

}
 TEST_CASE(    "CanGetAReversedSentence"  ,
               "[weekFourPromptTwo_test]"      )
{
// Test Description -
//
//  CASE 4   :
//  ---------
//  These tests validate that the function, "weekFourPromptTwo",
//  outputs the correct reversed sentence value
//
//-
//  Constraint: List only accepts ascii[a-zA-z] and a ascii[space]
//--------------------------------------------------------------------
 
    // Initialize L1 as an empty List:
    L1_container.clear();
    
    //---------------------------------------------------
    //  TEST 4.1                                        :
    //---------------------------------------------------
    SECTION( "OneWord_NoSpaces_one" ){
        // L1 := IBM :
        L1_container.push_back(  'I'  );
        L1_container.push_back(  'B'  );
        L1_container.push_back(  'M'  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
           i !=  L2_ptr -> end();
           i++                )
        {
             // Append char value(s):
             reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  "IBM"   );
    }

    //---------------------------------------------------
    //  TEST 4.2                                        :
    //---------------------------------------------------
    SECTION( "OneWord_NoSpaces_two" ){
        // L1 := FAM :
        L1_container.push_back(  'F'  );
        L1_container.push_back(  'a'  );
        L1_container.push_back(  'M'  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
           i !=  L2_ptr -> end();
           i++                )
        {
             // Append char value(s):
             reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  "FaM"   );
    }

    //---------------------------------------------------
    //  TEST 4.3                                        :
    //---------------------------------------------------
    SECTION( "OneWord_NoSpaces_three" ){
        // L1 := space :
        L1_container.push_back(  's'  );
        L1_container.push_back(  'p'  );
        L1_container.push_back(  'a'  );
        L1_container.push_back(  'c'  );
        L1_container.push_back(  'e'  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
           i !=  L2_ptr -> end();
           i++                )
        {
             // Append char value(s):
             reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  "space"   );
    }

    //---------------------------------------------------
    //  TEST 4.4                                        :
    //---------------------------------------------------
    SECTION( "OneWord_SpaceInFront" ){
        // L1 :=     sPaCe :
        L1_container.push_back(  ' '  );
        L1_container.push_back(  's'  );
        L1_container.push_back(  'P'  );
        L1_container.push_back(  'a'  );
        L1_container.push_back(  'C'  );
        L1_container.push_back(  'e'  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
         i !=  L2_ptr -> end();
         i++                )
        {
            // Append char value(s):
            reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  "sPaCe "   );
    }

    //---------------------------------------------------
    //  TEST 4.5                                        :
    //---------------------------------------------------
    SECTION( "OneWord_SpaceInBack" ){
        // L1 := sPaCe     :
        L1_container.push_back(  's'  );
        L1_container.push_back(  'P'  );
        L1_container.push_back(  'a'  );
        L1_container.push_back(  'C'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  ' '  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
         i !=  L2_ptr -> end();
         i++                )
        {
            // Append char value(s):
            reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  " sPaCe"   );
    }

    //---------------------------------------------------
    //  TEST 4.6                                        :
    //---------------------------------------------------
    SECTION( "OneWord_SpacesInFrontAndBack" ){
        // L1 :=   sPaCe   :
        L1_container.push_back(  ' '  );
        L1_container.push_back(  's'  );
        L1_container.push_back(  'P'  );
        L1_container.push_back(  'a'  );
        L1_container.push_back(  'C'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  ' '  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
         i !=  L2_ptr -> end();
         i++                )
        {
            // Append char value(s):
            reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  " sPaCe "   );
    }

    //---------------------------------------------------
    //  TEST 4.7                                        :
    //---------------------------------------------------
    SECTION( "Sentence_NoSpacesInFrontAndBack_one" ){
        // L1 := I Love Geeks For Geeks :
        L1_container.push_back(  'I'  );
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'L'  );
        L1_container.push_back(  'o'  );
        L1_container.push_back(  'v'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'G'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  'k'  );
        L1_container.push_back(  's'  );
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'F'  );
        L1_container.push_back(  'o'  );
        L1_container.push_back(  'r'  );
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'G'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  'k'  );
        L1_container.push_back(  's'  );
        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
           i !=  L2_ptr -> end();
           i++                )
        {
             // Append char value(s):
             reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  "Geeks For Geeks Love I"   );
    }

    //---------------------------------------------------
    //  TEST 4.8                                        :
    //---------------------------------------------------
    SECTION( "Sentence_NoSpacesInFrontAndBack_two" ){
        // L1 :=  Week four prompt :
        L1_container.push_back(  'W'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  'k'  );
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'f'  );
        L1_container.push_back(  'o'  );
        L1_container.push_back(  'u'  );
        L1_container.push_back(  'r'  );
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'p'  );
        L1_container.push_back(  'r'  );
        L1_container.push_back(  'o'  );
        L1_container.push_back(  'm'  );
        L1_container.push_back(  'p'  );
        L1_container.push_back(  't'  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
         i !=  L2_ptr -> end();
         i++                )
        {
            // Append char value(s):
            reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  "prompt four Week"   );
    }

    //---------------------------------------------------
    //  TEST 4.9                                        :
    //---------------------------------------------------
    SECTION( "Sentence_NoSpacesInFrontAndBack_three" ){
        // L1 :=   GitHub Code   :
        L1_container.push_back(  'G'  );
        L1_container.push_back(  'i'  );
        L1_container.push_back(  't'  );
        L1_container.push_back(  'H'  );
        L1_container.push_back(  'u'  );
        L1_container.push_back(  'b'  );
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'c'  );
        L1_container.push_back(  'o'  );
        L1_container.push_back(  'd'  );
        L1_container.push_back(  'e'  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
         i !=  L2_ptr -> end();
         i++                )
        {
            // Append char value(s):
            reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  "code GitHub"   );
    }

    //---------------------------------------------------
    //  TEST 4.10                                       :
    //---------------------------------------------------
    SECTION( "Sentence_SpaceInFront" ){
        // L1 :=     GitHub Code :
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'G'  );
        L1_container.push_back(  'i'  );
        L1_container.push_back(  't'  );
        L1_container.push_back(  'H'  );
        L1_container.push_back(  'u'  );
        L1_container.push_back(  'b'  );
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'c'  );
        L1_container.push_back(  'o'  );
        L1_container.push_back(  'd'  );
        L1_container.push_back(  'e'  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
         i !=  L2_ptr -> end();
         i++                )
        {
            // Append char value(s):
            reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  "code GitHub "   );
    }

    //---------------------------------------------------
    //  TEST 4.11                                       :
    //---------------------------------------------------
    SECTION( "Sentence_SpaceInBack" ){
        // L1 := GitHub Code     :
        L1_container.push_back(  'G'  );
        L1_container.push_back(  'i'  );
        L1_container.push_back(  't'  );
        L1_container.push_back(  'H'  );
        L1_container.push_back(  'u'  );
        L1_container.push_back(  'b'  );
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'c'  );
        L1_container.push_back(  'o'  );
        L1_container.push_back(  'd'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  ' '  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
         i !=  L2_ptr -> end();
         i++                )
        {
            // Append char value(s):
            reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  " code GitHub"   );
    }

    //---------------------------------------------------
    //  TEST 4.12                                       :
    //---------------------------------------------------
    SECTION( "Sentence_SpacesInFrontAndBack" ){
        // L1 :=   GitHub Code   :
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'G'  );
        L1_container.push_back(  'i'  );
        L1_container.push_back(  't'  );
        L1_container.push_back(  'H'  );
        L1_container.push_back(  'u'  );
        L1_container.push_back(  'b'  );
        L1_container.push_back(  ' '  );
        L1_container.push_back(  'c'  );
        L1_container.push_back(  'o'  );
        L1_container.push_back(  'd'  );
        L1_container.push_back(  'e'  );
        L1_container.push_back(  ' '  );

        // L2 - Reversed Sentence:
        L2_ptr = new list<char>(  weekFourPromptTwo(   L1_container   ) );

        // Iterate and grab each individual ascii[a-zA-z] and ascii[space]
        // character in L2 and insert them into a string:
        reversed_sentence.clear();
        for(  i  =  L2_ptr -> begin();
         i !=  L2_ptr -> end();
         i++                )
        {
            // Append char value(s):
            reversed_sentence += *i;
        }
        // Check Assertion:
        REQUIRE(   reversed_sentence  ==  " code GitHub "   );
    }
}
