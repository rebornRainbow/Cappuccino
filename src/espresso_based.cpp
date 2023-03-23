#include "espresso_based.h"


EspressoBased::EspressoBased()//因为这是基类不能构造
{}

EspressoBased::EspressoBased(const EspressoBased& esp)
{
  this->name = esp.name;
  //复制狗仔
  for(size_t i = 0;i < esp.ingredients.size();++i)
  {
    this->ingredients.push_back(new Ingredient(*esp.ingredients[i]));
  }
}

void EspressoBased::operator=(const EspressoBased& esp)
{
  this->name = esp.name;
  for(size_t i = 0;i < esp.ingredients.size();++i)
  {
    this->ingredients.push_back(new Ingredient(*esp.ingredients[i]));
  }
}


EspressoBased::~EspressoBased()
{
    for(const auto& i : ingredients)
        delete i;
    this->ingredients.clear();
}