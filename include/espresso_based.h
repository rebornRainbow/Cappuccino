#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H

#include<string>
#include <vector>


#include "sub_ingredients.h"


/**
 * @brief 
 * 浓缩咖啡的基本类型
 */
class EspressoBased
{
public:
    /**
     * @brief Get the name object
     * 抽象方法
     * 返回这是什么咖啡
     * @return std::string 
     */
    virtual std::string get_name() = 0;
    /**
     * @brief 
     * 抽象方法
     * 返回这个的价格
     * @return double 
     */
    virtual double price() = 0;

    void brew();
    std::vector<Ingredient*>& get_ingredients();

    ~EspressoBased();

protected:
    EspressoBased();//因为这是基类不能构造
    EspressoBased(const EspressoBased& esp);
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;

};

#endif // ESPRESSO_BASED_H