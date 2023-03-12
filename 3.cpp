#include <iostream>
#include <set>

int main() {
    char x;
    std::cin >> x;
    std::set<std::string> kont;
    for (int i = 0; x != '#'; i++) {
        std::string line;
        std::cin >> line;
        if (x == '+') {
            kont.insert(line);
        }
        else if (x == '-') {
            kont.erase(line);
        }
        else if (x == '?') {
            std::_Rb_tree_const_iterator<std::basic_string<char>> k = kont.find(line);
            if (k != kont.end()) {
                std::cout << "YES" << std::endl;
            }
            else {
                std::cout << "NO" << std::endl;
            }
        }
        std::cin >> x;
    }

    return 0;
}
