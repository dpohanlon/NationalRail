#ifndef MAPUTILS_H
#define MAPUTILS_H

#include <map>

namespace mapUtils
{

template <class V, class T>
    using catFun  = void (*)(V & v, T & t);

// Make a recursive call to insertWith after calling the default type
// constructor to insert into the container. Avoids extra container
// construction overhead/template specialization required if performing
// a direct emplace.

template <class K, class V, class T, class F>
void insertWith(std::map<K, V> & m, K key, T val, F cat)
{
    typename std::map<K, V>::iterator l = m.find(key);
    if(l != m.end()){
        cat(l->second, val);
    }
    else{
        m.insert(std::make_pair(key, V()));
        insertWith(m, key, val, cat);
    }
}

} // namespace utils

#endif
