#include "../template.cpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

/**
 * @brief Set data structure with rank - know which element is the kth 
 * smallest. O(logn) operations.
 * 
 * find_by_order(n) => (n - 1)th smallest key
 * order_of_key(k) => rank of key k
 * 
 * algorithm - nth_element for O(n) on any vector
 * 
 * @tparam TKey Type of set key
 */
template <class TKey>
using indexed_set = tree<TKey, null_type, less<Tkey>, rb_tree_tag,
                         tree_order_statistics_node_update>;
