#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include "ingredient.h"

#define DEFCLASS(ClassName,price,str)                 \
class ClassName:public Ingredient                   \
{                                                   \
public:                                             \
    ClassName(size_t units): Ingredient{price, units} \
    {                                               \
        this->name = str;                           \
    }                                               \ 
                                                    \
    virtual std::string get_name() {                \
      return this->name;                            \
    }                                               \
};                                                  \



DEFCLASS(Cinnamon, 5,"Cinnamon");

DEFCLASS(Chocolate, 5,"Chocolate");

DEFCLASS(Sugar, 1,"Sugar");

DEFCLASS(Cookie, 10,"Cookie");

DEFCLASS(Espresso, 15,"Espresso");

DEFCLASS(Milk, 10,"Milk");

DEFCLASS(MilkFoam, 5,"MilkFoam");

DEFCLASS(Water, 1,"Water");



#endif // SUB_INGREDIENTS_H

