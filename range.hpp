#include "iostream"

//NameSpace for a Tasks
namespace itertools {

template <typename Template>
class range {

public:

Template start;
Template finish;

range(Template start, Template finish) {
        this->start = start;
        this->finish = finish;
}
range(range const &other) {
        this->start = other.start;
        this->finish = other.finish;
}
class iterator {

private:
Template* it;

public:


iterator(Template* it = nullptr) : it(it) {
}

iterator& operator++() {
        (*it)++;
        return *this;
}


Template& operator*() const {
        return *it;
}


const iterator operator++(int) {
        iterator temp = *this;
        it++;
        return temp;
}

bool operator!=(iterator itr) const {
        return *it != *itr.it;
}

bool operator==(iterator itr) const {
        return *it == *itr.it;
}
};

iterator begin()
{
        return iterator{&start};
}

iterator end()
{
        return iterator{&finish};
}

};
}
