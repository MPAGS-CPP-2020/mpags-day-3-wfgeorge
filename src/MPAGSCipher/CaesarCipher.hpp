#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

class CaesarCipher {
  public:
    CaesarCipher(const size_t key);
    
    size_t key_; // the cipher key
};

#endif // MPAGSCIPHER_CAESARCIPHER_HPP