template<typename T, typename Cmp = less<T>>
using iset = tree<T, null_type, Cmp, rb_tree_tag,
          tree_order_statistics_node_update, allocator<T>>;