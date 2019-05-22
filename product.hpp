
#include "iostream"


namespace itertools {
bool Help=false;
    template <typename Template1, typename Template2>

    class product {

    private:
        Template1 it1;
        Template2 it2;

    public:
        product(Template1 start, Template2 end) :  it1(start), it2(end) {
          Help=false;
          if(!(end.begin()!=end.end())){
            Help=true;
          }
        }

    auto begin() const{
        return  iterator<decltype(it1.begin()),decltype(it2.begin())>(it1.begin(), it2.begin()); }  // iteratable object

    auto end() const{
        return iterator<decltype(it1.end()),decltype(it2.end())>(it1.end(), it2.end()); }  // iteratable object

    template <typename C1, typename C2>
        class iterator {

        private:
            C1 it1;
            C2 it2;
            C2 pos;
            bool save;

        public:
            iterator(C1 itA , C2 itB): it1(itA) , it2(itB) , pos(it2),save(false) {}

           iterator<C1,C2>& operator++() {
            if(!save)
               ++it2;
               return *this;

            }

            auto operator*() const {

             return  std::pair<decltype(*it1),decltype(*it2)> (*it1 , *it2);
            }

            bool operator!=(iterator const  it){
                if((it1 != it.it1) && !(it2 != it.it2)){
                  save=true;
                }
                if(save){

                save=false;
                    it2 = pos;
                    ++it1;
                }
                return (it1 != it.it1&& !Help);

            }



        };


    };

}
