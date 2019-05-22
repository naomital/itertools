#include "iostream"

namespace itertools {

template <typename Template1, typename Template2>
class chain {

private:
Template1 it1;
Template2 it2;

public:
chain(Template1 start, Template2 end) :  it1(start), it2(end) {
}

auto begin() const{
        return iterator<decltype(it1.begin()),decltype(it2.begin())>(it1.begin(), it2.begin());
}

auto end() const{
        return iterator<decltype(it1.end()),decltype(it2.end())>(it1.end(), it2.end());
}
template <typename C1, typename C2>
class iterator {

private:
C1 it1;
C2 it2;
bool some;

public:
iterator(C1 itA, C2 itB) : it1(itA), it2(itB), some(true)  {
}

iterator<C1,C2>& operator++() {
        if(some==true)
                ++it1;
        else
                ++it2;
        return *this;
}
decltype(*it1) operator*() const {

        if(some)
                return *it1;
        else
                return *it2;
}
bool operator!=(iterator<C1,C2>  it){
        if(some && !(it1 != it.it1)) {
                some = false;
        }
        if(some) {
                return it1 != it.it1;
        }else{
                return it2 != it.it2;
        }
}
};

};
}
