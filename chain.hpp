// #include "iostream"
// #include "range.hpp"
// namespace itertools {
//
//     template <class range>
//     template <class Template>
//     class chain {
//
//     public:
//            range r;
//          Template start;
//          Template finish;
//          chain(range start, Template finish) {
//                this->start = start;
//              this->finish = finish;
//          }
//         class iterator {
//
//         private:
//             Template* it;
//
//         public:
//
//
//             iterator(Template* it = nullptr): it(it) {}
//
//            iterator& operator++() {
//                 (*it)++;
//                 return *this;
//             }
//
//
//             Template& operator*() const {
//                 return *it;
//             }
//
//
//             const iterator operator++(int) {
//                 iterator temp = *this;
//                 it++;
//                 return temp;
//             }
//
//             bool operator!=(iterator  itr) const {
//                 return *it != *itr.it;
//             }
//
//             bool operator==(iterator itr) const {
//                 return *it == *itr.it;
//             }
//
//
//
//         };
//
//         iterator begin()
//         {
//             return iterator{&start};
//         }
//
//         iterator end()
//         {
//             return iterator{&finish};
//         }
//
//     };
// }
