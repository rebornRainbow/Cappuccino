#ifndef INGREDIENT_H
#define INGREDIENT_H

/**
 * @brief 
 * 配料类：
 * 是所有配料的基本类型。
 */
class Ingredient
{
public:
    //单价
    double get_price_unit()
    {
      return price_unit;
    }
    //个数
    size_t get_units()
    {
      return units;
    }
    //名称
    virtual std::string get_name() = 0;//纯虚函数
    //价格
    double price()
    {
      return price_unit*units;
    }
    
    ~Ingredient()
    {}
protected:
    //构造
    Ingredient(double price_unit, size_t units):price_unit(price_unit),units(units){}

    Ingredient(const Ingredient & isp)
    {
      name = isp.name;
      units = isp.units;
      price_unit = isp.price_unit;
    }

    void operator=(const Ingredient & isp)
    {
      name = isp.name;
      units = isp.units;
      price_unit = isp.price_unit;
    }

   
    /**
     * @brief 
     * 单价
     */
    double price_unit;
    /**
     * @brief 
     * 数量
     */
    size_t units;
    /**
     * @brief 
     * 名称
     */
    std::string name;
};
#endif // INGREDIENT_H