#include "iostream"


namespace itertools {

template <typename Template>
class range {

private:

Template start;
Template finish;

class iterator
{

public:
Template it;

//constructor
iterator(Template v) : it(v){
}

// operators
bool operator!=(iterator const &other) const
{
        return it != other.it;
}
bool operator== (range::iterator const &other) const
{
        return it == other.it;

}
Template operator*() const
{
        return it;
}
iterator &operator++()
{

        ++it;
        return *this;
}
};

public:
range(Template from, Template to) : start(from), finish(to) {
}
iterator begin() const {
        return iterator(start);
}
iterator end() const {
        return iterator(finish);
}
};
}
