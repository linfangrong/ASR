#ifndef TYPES_HPP
#define TYPES_HPP

#include <google/dense_hash_map>

namespace ASR {

template <typename KEY,  typename VALUE>
class HashMap : public google::dense_hash_map
                       <KEY, VALUE, std::hash<KEY>, std::equal_to<KEY> > {};

} // end namespace ASR

#endif // END TYPES
