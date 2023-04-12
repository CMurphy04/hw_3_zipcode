/*
 * Unit testing for the integer homework
 */
//#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_MAIN  // Catch supplies a main program
#include "NO_MAIN.cc"

#include "catch.hpp"

const int MAX_SCORE = 20;
const int NUM_TESTS = 2;
static int score = 0;
static int testsPassed = 0;

TEST_CASE("Testing getDigitCode function") {
    SECTION("getDigitCode") {
        REQUIRE(":::||" == getDigitCode('1'));
        REQUIRE("::|:|" == getDigitCode('2'));
        REQUIRE("::||:" == getDigitCode('3'));
        REQUIRE(":|::|" == getDigitCode('4'));
        REQUIRE(":|:|:" == getDigitCode('5'));
        REQUIRE(":||::" == getDigitCode('6'));
        REQUIRE("|:::|" == getDigitCode('7'));
        REQUIRE("|::|:" == getDigitCode('8'));
        REQUIRE("|:|::" == getDigitCode('9'));
        REQUIRE("||:::" == getDigitCode('0'));
        score += 10;
        testsPassed++;
    }
    SECTION("getCheckDigitValue") {
        REQUIRE(0 == getCheckDigitValue(40));
        REQUIRE(5 == getCheckDigitValue(35));
        REQUIRE(6 == getCheckDigitValue(34));
        REQUIRE(9 == getCheckDigitValue(31));
        REQUIRE(2 == getCheckDigitValue(38));
       
        testsPassed++;
        score += 10;
    }
    

    SECTION("Score"){
        cout << "\n==========================================" << endl;
        cout << "\033[1;33m" <<  " Score: " << score << "/" << MAX_SCORE << "\033[1;35m"
        << " (passed " << testsPassed <<  " out of " << NUM_TESTS << " tests)" << "\033[0m" << endl;
        cout << "==========================================\n" << endl;
    }
}

