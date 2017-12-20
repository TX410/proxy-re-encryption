#include "ciphertext.hpp"

#include <sstream>

namespace pre {

Ciphertext::Ciphertext(const std::string &str) {

  setStringCiphertext(str);
}

Ciphertext::Ciphertext(const CryptoPP::Integer &t1, const CryptoPP::Integer &t2) {

  this->t1 = t1;
  this->t2 = t2;

  std::string hext1, hext2;

  std::ostringstream oss1, oss2;

  oss1 << std::hex << t1;
  hext1.append(oss1.str());
  hext1.erase(hext1.length() - 1);

  oss2 << std::hex << t2;
  hext2.append(oss2.str());
  hext2.erase(hext2.length() - 1);

  ciphertext.clear();
  ciphertext.append("t1:").append(hext1).append("t2:").append(hext2);
}

CryptoPP::Integer Ciphertext::getT1() {

  return t1;
}

void Ciphertext::setT1(const CryptoPP::Integer &t1) {

  this->t1 = t1;

  std::ostringstream oss;
  oss << std::hex << t1;

  std::string temp = "t1:";
  temp.append(std::string(oss.str()));
  temp.erase(temp.length() - 1);

  int t2index = ciphertext.find("t2:");

  temp.append(ciphertext.substr(t2index));

  ciphertext.clear();
  ciphertext.append(temp);
}

CryptoPP::Integer Ciphertext::getT2() {

  return t2;
}

void Ciphertext::setT2(const CryptoPP::Integer &t2) {

  this->t2 = t2;

  int t2index = ciphertext.find("t2:");

  std::string temp = ciphertext.substr(0, t2index);
  temp.append("t2:");

  std::ostringstream oss;
  oss << std::hex << t2;

  temp.append(std::string(oss.str()));

  // remove last h
  temp.erase(temp.length() - 1);

  ciphertext.clear();
  ciphertext.append(temp);
}

std::string Ciphertext::getStringCiphertext() {

  return ciphertext;
}

void Ciphertext::setStringCiphertext(const std::string &cipher) {

  ciphertext.clear();
  ciphertext.append(cipher);

  int t1index = cipher.find("t1:");
  int t2index = cipher.find("t2:");

  std::string hext1 = cipher.substr(t1index + 3, t2index - 3);
  std::string hext2 = cipher.substr(t2index + 3);

  hext1.append("h");
  hext2.append("h");

  t1 = CryptoPP::Integer(hext1.c_str());
  t2 = CryptoPP::Integer(hext2.c_str());
}

} // namespace pre