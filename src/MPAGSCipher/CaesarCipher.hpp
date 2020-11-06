#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

class CaesarCipher {
  public:
    explicit CaesarCipher(const size_t key);
    explicit CaesarCipher(const std::string key);
    
    size_t key_{0}; // the cipher key
};

#endif // MPAGSCIPHER_CAESARCIPHER_HPP