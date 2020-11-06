#include "CaesarCipher.hpp"

#include <iostream>

CaesarCipher::CaesarCipher(const size_t key)
 : key_{key} 
{
}

CaesarCipher::CaesarCipher(const std::string key)
 : key_{0}
{
    if ( !key.empty() ) {
    // Before doing the conversion we should check that the string contains a
    // valid positive integer by checking each character is a digit.
    // What is rather hard to check is whether the number is too large 
    // to be represented by an unsigned long, so we've omitted that for now.
        for ( const auto& elem : key ) {
            if ( ! std::isdigit(elem) ) {
                std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
	                      << "        the supplied key (" << key << ") could not be successfully converted" << std::endl;
	            exit(1);
            }
        }
        key_ = std::stoul(key);
    }
}