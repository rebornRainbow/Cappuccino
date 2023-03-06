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
    
    double get_price_unit();
    size_t get_units();
    virtual std::string get_name() = 0;//纯虚函数
    
    double price();
    

protected:
    Ingredient(double price_unit, size_t units):price_unit(price_unit),units(units)
    {
      
    }

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

    ~Ingredient()
    {}
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