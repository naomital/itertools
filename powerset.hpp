#include "iostream"
#include <vector>
#include <cmath>
#include <iostream>

namespace itertools {
template <typename Obj>
std::ostream &operator<<(std::ostream &os, const std::vector<Obj> &S)
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



template <typename Template>
class powerset {
//Test
private:
Template it;

public:
powerset(Template start) : it(start) {
}



template <typename obj>
class iterator {
private:
//All combination in vector
vector<vector<obj> >  combination(const vector<obj> & s){
        vector<vector<obj> > AllCombin;
        vector<obj> Temp;
        AllCombin.push_back(Temp);
        for (int i = 0; i < s.size(); i++) {
                vector<vector<obj> > AllCombinTemp = AllCombin;
                for (int j = 0; j < AllCombinTemp.size(); j++) {
                        AllCombinTemp[j].push_back(s[i]);
                }
                for (int j = 0; j < AllCombinTemp.size(); j++) {
                        AllCombin.push_back( AllCombinTemp[j] );
                }
        }
        return AllCombin;
}

vector<obj> change(const obj i,const obj j){
        vector<obj> ans;
        obj runner = i;
        while(runner != j) {
                ans.push_back(runner);
                ++runner;
        }
        return ans;
}

size_t length(const obj start,const obj end){
        obj runner = start;
        size_t ans = 0;
        while(runner != end) {
                ans++;
                ++runner;
        }
        return pow(2,ans);
}
public:

obj it_s;
obj it_b;
uint ind;
size_t size;
vector<vector<obj> > list;

iterator(obj itA, obj itB) : it_s(itA), it_b(itB), size(length(itA,itB)),ind(0){
}

auto operator*(){
        vector<obj> S = change(it_s,it_b);
        list = combination(S);
        vector<typename remove_const<typename remove_reference<decltype(*it_s)>::type>::type> se; // every call to this operator function the vector is absoulutly new
        for(auto i : list[ind]) {
                se.push_back(*i);
        }
        return se;
}

auto operator++() {      // advaced value
        ++ind;
        return *this;
}

bool operator!= (const iterator & temp){
        return (ind != size);
}
};

auto begin() const {
        return iterator<decltype(it.begin())> (it.begin(), it.end());
}
auto end() const {
        return iterator<decltype(it.begin())>(it.end(), it.end());
}

};
};
