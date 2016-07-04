#include "lazy_string.cpp"

int main(int argc, char const *argv[]) {
	using namespace std;
	string str = "abacaba";
	lazy_string s(str);
	lazy_string t = s;
	printf("%c %c\n", s[1], t[2]);
	// printf("%d\n", t.size());
	// t[3] = 'd';
	return 0;
}