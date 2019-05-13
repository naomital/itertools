#include "iostream"
#include <set>
#include <cmath>
#include <iostream>

namespace itertools {

    template <class Template>
    class powerset {

    private:
        Template it;

    public:
    powerset(Template start) : it(start) {}

    auto begin() {
    return iterator<decltype(it.begin())> (it.begin(), it.end());
    }
    auto end()  {
    return iterator<decltype(it.begin())>(it.end(), it.end());
    }

    template <class C>
        class iterator {

        private:
            C it_s;
            C it_b;
            unsigned   i;
            unsigned   count;


        public:
            iterator(C itA , C itB): it_s(itA), it_b(itB) , i(0),count(0)  {

            C iterator = it_s;
            while (iterator != it_b)
            {
                ++count;
                ++iterator;
            }

            count = std::pow(2, count);
            }

           iterator<C>& operator++() {
               ++i;
               return *this;
            }

            set<decltype(*it_s)> operator*() const         {
            C iterator = it_s;
            std::set<decltype(*it_s)> S;
            unsigned int index = i;
            while (index != 0 && iterator != it_b)
            {
                unsigned int r = index % 2;
                index = index >> 1;

                if (r == 1)
                    S.insert(*iterator);

                ++iterator;
            }

            return S;
        }

        bool operator!=(iterator<C> const &it) const {
            return ((count - i) != (it.count - it.i - 1));

            }


        };


    };

template <typename D>
std::ostream &operator<<(std::ostream &os, const std::set<D> &S)
{
    os << "{";

    auto it = S.begin();
    if(it != S.end())
    {
        os << *it;
        ++it;
    }

    while (it != S.end())
    {
        os << ',' << *it;
        ++it;
    }

    os << "}";

    return os;
}
}
