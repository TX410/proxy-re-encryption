#ifndef PROXY_RE_ENCRYPTION_MESSAGE_HPP
#define PROXY_RE_ENCRYPTION_MESSAGE_HPP

#include <cryptopp/integer.h>

namespace pre {

class Message {

 public:
  Message(const std::string &str);
  Message(const CryptoPP::Integer &integer);

  CryptoPP::Integer getIntegerMessage();
  void setIntegerMessage(const CryptoPP::Integer &integer);

  std::string getStringMessage();
  void setStringMessage(const std::string &str);

 private:
  CryptoPP::Integer m;
  std::string message;

}; // class Message

} // namespace pre

#endif //PROXY_RE_ENCRYPTION_MESSAGE_HPP
