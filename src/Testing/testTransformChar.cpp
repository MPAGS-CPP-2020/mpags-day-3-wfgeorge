// Test transformChar interface with Catch
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "TransformChar.hpp"

TEST_CASE("Characters are uppercased","[alphanumeric]"){
    const std::string upperChars{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const std::string lowerChars{"abcdefghijklmnopqrstuvwxyz"};
    
    for (size_t i = 0; i < upperChars.size(); i++){
        REQUIRE( transformChar(lowerChars[i]) == std::string{upperChars[i]} );
    }
}

TEST_CASE("Digits are transliterated","[alphanumeric]"){
    REQUIRE( transformChar('0') == "ZERO" );
    REQUIRE( transformChar('1') == "ONE" );
    REQUIRE( transformChar('2') == "TWO" );
    REQUIRE( transformChar('3') == "THREE" );
    REQUIRE( transformChar('4') == "FOUR" );
    REQUIRE( transformChar('5') == "FIVE" );
    REQUIRE( transformChar('6') == "SIX" );
    REQUIRE( transformChar('7') == "SEVEN" );
    REQUIRE( transformChar('8') == "EIGHT" );
    REQUIRE( transformChar('9') == "NINE" );
}

TEST_CASE("Special characters are removed","[punctuation]"){
    const std::string specialChars{"\"!£$%^&*()-_+={}[]~#:;'@?/><>,.\\|"};
    
    for (size_t i = 0; i < specialChars.size(); i++){
        REQUIRE( transformChar(specialChars[i]) == "" );
    }
}