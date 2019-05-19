#ifndef ITEM_H_
#define ITEM_H_
#include<string>
using std::string, std::ostream;

class Item{
    protected:
    string name;
    bool movable;
    public:
    Item(const string&, const bool);
    const string& getTitle()const;
    bool canMove()const;
    bool operator==(const Item&)const;
};

Item::Item(const string& _name="", const bool _movable=true){
    name=_name;
    movable=_movable;
}

const string& Item::getTitle() const{
    return name;
}

bool Item::canMove() const{
    return movable;
}

bool Item::operator==(const Item& other) const{
    return name==other.name;
}




#endif // ITEM_H_
