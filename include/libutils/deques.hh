#ifndef LIBUTILS_DEQUES_HH
#define LIBUTILS_DEQUES_HH

#include <deque>
#include <ostream>
#include <algorithm>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::deque<T>& objects) {
    for (auto it = objects.begin(); it != objects.end(); ++it) {
        if (it != objects.begin())
            out << " ";
        out << *it;
    }
    return out;
}

template<typename T>
unsigned int deque_index(std::deque<T>& objects, T object) {
    auto it = std::find(objects.begin(), objects.end(), object);
    return std::distance(objects.begin(), it);
}

#endif
