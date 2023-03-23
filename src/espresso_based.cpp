#include "espresso_based.h"
#include "ingredientFactory.h"
#include <iostream>

EspressoBased::EspressoBased()//因为这是基类不能构造
{}

EspressoBased::EspressoBased(const EspressoBased& esp)
{
  this->name = esp.name;
  //复制构造
  for(auto &item:esp.ingredients){
    this->ingredients.push_back(
      IngredientFactory::getItem(item));
  }
}

void EspressoBased::operator=(const EspressoBased& esp)
{
  this->name = esp.name;
  for(auto &item:esp.ingredients){
    this->ingredients.push_back(
      IngredientFactory::getItem(item));
  }
}


std::vector<Ingredient*>& EspressoBased::get_ingredients(){
  return this->ingredients;
} 

EspressoBased::~EspressoBased()
{
    for(const auto& i : ingredients)
        delete i;
    this->ingredients.clear();
}



void EspressoBased::brew()
{
  std::cout << name << " making..." << std::endl;
}