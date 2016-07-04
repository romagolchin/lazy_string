#include <string>

class lazy_string {
	char* s;
	size_t len;
	bool has_reference;
	lazy_string* origin;
public:
	lazy_string(std::string);
	size_t size();
	size_t length();
	class lazy_char at();
	lazy_char operator[](size_t);
	lazy_string substr(size_t pos, size_t len);
	operator std::string();
	lazy_string& operator=(lazy_string &source);
	// ~lazy_string();
	friend class lazy_char;
};

struct lazy_char {
	lazy_string* host_str;
	size_t pos;
	lazy_char(lazy_string*, size_t);
	operator char();
	lazy_char& operator=(char c);
	~lazy_char();
	
};

