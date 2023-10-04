#ifndef LIBUTILS_VECTORS_HH
#define LIBUTILS_VECTORS_HH

#include <vector>
#include <ostream>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& objects) {
    for (auto it = objects.begin(); it != objects.end(); ++it) {
        if (it != objects.begin())
            out << " ";
        out << *it;
    }
    return out;
}

#endif
