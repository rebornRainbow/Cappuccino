#ifndef Ingredient_FACTORY_H
#define Ingredient_FACTORY_H

class IngredientFactory
{

public:
  static Cinnamon *copyCinnamon(Ingredient *ing){
    return new Cinnamon(ing->get_units());
  }

  static Chocolate *copyChocolate(Ingredient *ing){
    return new Chocolate(ing->get_units());
  }

  static Sugar *copySugar(Ingredient *ing){
    return new Sugar(ing->get_units());
  }

  static Cookie *copyCookie(Ingredient *ing){
    return new Cookie(ing->get_units());
  }

  static Espresso *copyEspresso(Ingredient *ing){
    return new Espresso(ing->get_units());
  }

  static Milk *copyMilk(Ingredient *ing){
    return new Milk(ing->get_units());
  }

  static MilkFoam *copyMilkFoam(Ingredient *ing){
    return new MilkFoam(ing->get_units());
  }

  static Water *copyWater(Ingredient *ing){
    return new Water(ing->get_units());
  }

  static Ingredient* getItem(Ingredient* ing){

    std::string name = ing->get_name();
    if(name == "Cinnamon")
      return copyCinnamon(ing);
    else if(name == "Chocolate")
      return copyChocolate(ing);
    else if(name == "Sugar")
      return copySugar(ing);
    else if(name == "Cookie")
      return copyCookie(ing);
    else if(name == "Espresso")
      return copyEspresso(ing);
    else if(name == "Milk")
      return copyMilk(ing);
    else if(name == "MilkFoam")
      return copyMilkFoam(ing);
    else if(name == "Water")
      return copyWater(ing);
  }

};

#endif