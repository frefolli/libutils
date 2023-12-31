#ifndef LIBUTILS_VECTORS_HH
#define LIBUTILS_VECTORS_HH

#include <vector>
#include <ostream>
#include <algorithm>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& objects) {
    for (auto it = objects.begin(); it != objects.end(); ++it) {
        if (it != objects.begin())
            out << " ";
        out << *it;
    }
    return out;
}

template<typename T>
unsigned int vector_index(std::vector<T>& objects, T object) {
    auto it = std::find(objects.begin(), objects.end(), object);
    return std::distance(objects.begin(), it);
}

#endif
