#include "cappuccino.h"
#include "ingredientFactory.h"

Cappuccino::Cappuccino():EspressoBased(){
  name = "Cappuccino";
  this->ingredients.push_back(new Espresso(2));
  this->ingredients.push_back(new Milk(2));
  this->ingredients.push_back(new MilkFoam(1));
}



Cappuccino::Cappuccino(const Cappuccino& cap){
  name = cap.name;
  for(auto &item :cap.side_items){
    this->side_items.push_back(
      IngredientFactory::getItem(item));
  }
  for(auto &item :cap.ingredients){
    this->ingredients.push_back(
      IngredientFactory::getItem(item));
  }

}

void Cappuccino::operator=(const Cappuccino& cap){
  name = cap.name;

  std::vector<Ingredient*> tem_g;
  
  for(auto &item :cap.side_items){
    tem_g.push_back(
      IngredientFactory::getItem(item));
  }

  this->side_items.clear();

  for(auto &item :tem_g){
    this->side_items.push_back(
      IngredientFactory::getItem(item));
  }

}

Cappuccino::~Cappuccino(){
  for(const auto& i : side_items)
    delete i;
  this->side_items.clear();
}


std::string Cappuccino::get_name(){
  return name;
}

double Cappuccino::price(){
  double sum = 0;
  for(const auto& item : side_items)
    sum += item->price();
  for(const auto& item : ingredients)
    sum += item->price();
  return sum;
}

void Cappuccino::add_side_item(Ingredient* side){
  this->side_items.push_back(side);
}

std::vector<Ingredient*>& Cappuccino::get_side_items(){
  return side_items;
}