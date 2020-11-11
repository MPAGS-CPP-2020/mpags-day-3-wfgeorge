#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <vector>

#include "CipherMode.hpp"

class CaesarCipher {
  public:
    explicit CaesarCipher(const size_t key);
    explicit CaesarCipher(const std::string key);

    void setKey(const size_t key);
    void setKey(const std::string key);

    std::string applyCipher(const std::string& inputText, const CipherMode encrypt);

  private:
    size_t key_{0}; // the cipher key
    const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
};

#endif // MPAGSCIPHER_CAESARCIPHER_HPP