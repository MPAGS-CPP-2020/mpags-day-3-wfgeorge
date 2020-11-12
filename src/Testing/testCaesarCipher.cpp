// Test CaesarCipher interface with Catch
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Cipher encryption works","[encryption]"){

    //Cipher operates on character-by-character basis so test encryption of one letter at a time

    const std::string upperChars{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    CaesarCipher cipher{"0"};

    SECTION("Key of 0 does not encrypt (returns input)"){
        
        //For each letter of alphabet, encryption with key=0 should return input letter
        for (size_t i = 0; i < upperChars.size(); i++){
            REQUIRE( cipher.applyCipher(upperChars.substr(i,1),CipherMode::Encrypt) == upperChars.substr(i,1) );
        }
    }
    
    SECTION("Key greater than alphabet size wraps round"){
        
        cipher.setKey("26");

        //For each letter of alphabet, encryption with key=26 should return input letter
        // as key=26 should wrap around to key=0
        for (size_t i = 0; i < upperChars.size(); i++){
            REQUIRE( cipher.applyCipher(upperChars.substr(i,1),CipherMode::Encrypt) == upperChars.substr(i,1) );
        }
    }

    SECTION("Encryption uses Caesar Cipher"){

        std::string key = "1";

        // For each possible key (1-25) test that cipher returns expected encrypted letter 
        // for each letter of the alphabet
        for (int j = 1; j < 26; j++){
            key = std::to_string(j);
            cipher.setKey(key);

            for (size_t i = 0; i < upperChars.size(); i++){

                REQUIRE( cipher.applyCipher(upperChars.substr(i,1),CipherMode::Encrypt) == upperChars.substr((i+j)%26,1) );
            }
        }

    }
}

TEST_CASE("Cipher decryption works","[decryption]"){

    //Tests as above but decrypting this time
    const std::string upperChars{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    CaesarCipher cipher{"0"};

    SECTION("Key of 0 does not decrypt (returns input)"){

        for (size_t i = 0; i < upperChars.size(); i++){
            REQUIRE( cipher.applyCipher(upperChars.substr(i,1),CipherMode::Decrypt) == upperChars.substr(i,1) );
        }
    }
    
    SECTION("Key greater than alphabet size wraps round"){
        
        cipher.setKey("26");

        for (size_t i = 0; i < upperChars.size(); i++){
            REQUIRE( cipher.applyCipher(upperChars.substr(i,1),CipherMode::Decrypt) == upperChars.substr(i,1) );
        }
    }

    SECTION("Decryption uses Caesar Cipher"){

        std::string key = "1";

        for (int j = 1; j < 26; j++){
            key = std::to_string(j);
            cipher.setKey(key);

            for (size_t i = 0; i < upperChars.size(); i++){

                REQUIRE( cipher.applyCipher(upperChars.substr(i,1),CipherMode::Decrypt) == upperChars.substr((i-j+26)%26,1) );
            }
        }

    }
}