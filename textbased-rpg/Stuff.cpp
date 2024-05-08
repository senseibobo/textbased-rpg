#include "Stuff.h"

void replace_character(std::string& s, char c1, char c2) {
    for (std::size_t i = 0; i < s.size(); ++i) {
        if (s[i] == c1) {
            s[i] = c2;
        }
    }
}