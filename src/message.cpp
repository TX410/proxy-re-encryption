#include "message.hpp"

#include <sstream>
#include <cryptopp/hex.h>

namespace pre {

Message::Message(const std::string &str) {

  setStringMessage(str);
}

Message::Message(const CryptoPP::Integer &integer) {

  setIntegerMessage(integer);
}

CryptoPP::Integer Message::getIntegerMessage() {

  return m;
}

void Message::setIntegerMessage(const CryptoPP::Integer &integer) {

  m = integer;

  std::ostringstream oss;
  oss << std::hex << integer;

  std::string temp;

  temp = std::string(oss.str());

  // remove last h
  temp.erase(temp.length() - 1);

  message.clear();

  CryptoPP::StringSource ss(temp, true,
                            new CryptoPP::HexDecoder(
                                new CryptoPP::StringSink(message)
                            )
  );
}

std::string Message::getStringMessage() {

  return message;
}

void Message::setStringMessage(const std::string &str) {
  message = str;

  std::string hexmessage;

  CryptoPP::StringSource ss(str, true,
                            new CryptoPP::HexEncoder(
                                new CryptoPP::StringSink(hexmessage)
                            )
  );

  // add h for 16 base
  hexmessage.append("h");

  m = CryptoPP::Integer(hexmessage.c_str());
}

} // namespace pre

