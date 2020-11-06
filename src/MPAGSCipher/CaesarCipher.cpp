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


std::string CaesarCipher::applyCipher( const std::string& inputText, const bool encrypt )
{
  // Create the output string
  std::string outputText {};

  const size_t alphabetSize = alphabet_.size();

  // Make sure that the key is in the range 0 - 25
  const size_t truncatedKey { key_ % alphabetSize };

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {

    // For each character in the input text, find the corresponding position in
    // the alphabet by using an indexed loop over the alphabet container
    for ( size_t i{0}; i < alphabetSize; ++i ) {

      if ( origChar == alphabet_[i] ) {

	// Apply the appropriate shift (depending on whether we're encrypting
	// or decrypting) and determine the new character
	// Can then break out of the loop over the alphabet
	if ( encrypt ) {
	  processedChar = alphabet_[ (i + truncatedKey) % alphabetSize ];
	} else {
	  processedChar = alphabet_[ (i + alphabetSize - truncatedKey) % alphabetSize ];
	}
	break;
      }
    }

    // Add the new character to the output text
    outputText += processedChar;
  }

  return outputText;
}