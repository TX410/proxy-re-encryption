#ifndef PROXY_RE_ENCRYPTION_CIPHERTEXT_HPP
#define PROXY_RE_ENCRYPTION_CIPHERTEXT_HPP

#include "cryptopp/integer.h"

namespace pre {

class Ciphertext {

 public:
  Ciphertext(const std::string &str);
  Ciphertext(const CryptoPP::Integer &t1, const CryptoPP::Integer &t2);

  CryptoPP::Integer getT1();
  void setT1(const CryptoPP::Integer &t1);

  CryptoPP::Integer getT2();
  void setT2(const CryptoPP::Integer &t2);

  std::string getStringCiphertext();
  void setStringCiphertext(const std::string &cipher);

 private:
  CryptoPP::Integer t1;
  CryptoPP::Integer t2;
  std::string ciphertext;
};

} // namespace pre

#endif //PROXY_RE_ENCRYPTION_CIPHERTEXT_HPP
