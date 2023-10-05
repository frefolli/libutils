#ifndef LIBUTILS_SETS_HH
#define LIBUTILS_SETS_HH
#include <set>
#include <algorithm>

template<typename T>
bool set_in(std::set<T>& a, T obj) {
    auto it = std::find(a.begin(), a.end(), obj);
    return (it != a.end());
}

template<typename T>
bool set_union(std::set<T>& a, std::set<T> b) {
    bool changed = false;
    for (T obj : b) {
        if (! set_in(a, obj)) {
            changed = true;
            a.insert(obj);
        }
    }
    return changed;
}

template<typename T>
std::set<T> set_diff(std::set<T>& a, std::set<T> b) {
    std::set<T> result = {};
    for (T obj : a) {
        if (! set_in(b, obj)) {
            result.insert(obj);
        }
    }
    return result;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, std::set<T>& objects) {
    for (auto it = objects.begin(); it != objects.end(); ++it) {
        if (it != objects.begin())
            out << " ";
        out << *it;
    }
    return out;
}
#endif
