#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <vector>

class CaesarCipher {
  public:
    explicit CaesarCipher(const size_t key);
    explicit CaesarCipher(const std::string key);

    std::string applyCipher(const std::string& inputText, const bool encrypt);

  private:
    size_t key_{0}; // the cipher key
    const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
};

#endif // MPAGSCIPHER_CAESARCIPHER_HPP