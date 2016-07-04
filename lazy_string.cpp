#include "lazy_string.h"

lazy_char::lazy_char(lazy_string* hs, size_t pos) :
host_str(hs), pos(pos)
{}

lazy_char& lazy_char::operator=(char c) {
	if(host_str->has_reference) {
		host_str->s = new char[host_str->len];
		for(size_t i = 0; i < host_str->len; ++i)
			host_str->s[i] = host_str->origin->s[i];	
	}
	*(host_str->s) = c;
	return *this;
}

lazy_string::lazy_string(std::string str) {
	len = str.length();
	s = new char[len + 1];
	for(size_t i = 0; i < len; ++i)
		s[i] = str[i];
	s[len] = '\0';
	has_reference = 0;
}

lazy_string& lazy_string::operator=(lazy_string& source) {
	if(this == &source)
		return *this;
	delete s;
	s = source.s;
	len = source.len;
	has_reference = 1;
}

size_t lazy_string::length() {return len; }
size_t lazy_string::size() {return len; }


lazy_char lazy_string::operator[](size_t pos) {
	return lazy_char(this, pos);
}

lazy_char::operator char() {
	return *(host_str->s + pos);
}
