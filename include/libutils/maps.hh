#ifndef LIBUTILS_MAPS_HH
#define LIBUTILS_MAPS_HH
#include <map>
#include <algorithm>

template<typename K, typename V>
bool map_in(std::map<K, V>& a, K obj) {
    auto it = a.find(obj);
    return (it != a.end());
}
#endif
