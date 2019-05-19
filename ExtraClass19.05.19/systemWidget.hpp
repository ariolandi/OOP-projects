#ifndef SYSTEM_H_
#define SYSTEM_H_
#include"item.hpp"


class SystemWidget: public Item{
    public:
    SystemWidget();
};

SystemWidget::SystemWidget():Item("SystemWidget", false){}

#endif // SYSTEM_H_
