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
            C it1;
            C it2;
            int   index;
            int   counter;


        public:
            iterator(C itA , C itB): it1(itA), it2(itB) , index(0),counter(0)  {

            C _element_iterator = it1;
            while (_element_iterator != it2)
            {
                ++counter;
                ++_element_iterator;
            }

            counter = std::pow(2, counter);
            }

           iterator<C>& operator++() {
               ++index;
               return *this;
            }

            set<decltype(*it1)> operator*() const         {
            C _element_iterator = it1;
            std::set<decltype(*it1)> S;
            unsigned int i = index;
            while (i != 0 && _element_iterator != it2)
            {
                unsigned int r = i % 2;
                i = i >> 1;

                if (r == 1)
                    S.insert(*_element_iterator);

                ++_element_iterator;
            }

            return S;
        }

        bool operator!=(iterator<C> const &it) const {
            return ((counter - index) != (it.counter - it.index - 1));

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
