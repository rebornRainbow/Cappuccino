### 总结

子类构造的时候会调用父类的构造方法，是在构造列表里，不写的话调用默认构造

子类析构的时候也会调用父类的析构方法。
  注意，如果指针的话
    如果用的是父类的指针，销毁父类指针的时候，如果父类的方法不是虚函数，那么不会调用子类的方法，
      只有当父类的析构方法时虚函数的时候才会调用子类的析构函数



### 难点
复制构造
Class(Class &cla) 这个方法是用来构造的，使用的时候，之前没有调用过构造方法

operator=(Class &cla) 这个方法是复制构造，使用的时候一般已经够早过了。

这一段特别有意思
可以把
```c++
void Cappuccino::operator=(const Cappuccino& cap){
  name = cap.name;
  //////////////////////////////////////
  this->side_items.clear();//这一行注释看看会发生什么
  //////////////////////////////////////
  for(auto &item :cap.side_items){
    this->side_items.push_back(
      IngredientFactory::getItem(item));
  }

}
```


```c++
TEST(HW5Test, TEST8) {
    Cappuccino cappuccino;
    cappuccino.add_side_item(new Water{1});
    Cappuccino equal = cappuccino;
    equal.add_side_item(new Sugar{1});
    equal = cappuccino;
    EXPECT_EQ(equal.price(), 56);
}
```


上面的代码依然有问题

如果是让自己等于自己，因为额外的料已经删除了，所以不可以在加，这样就会有问题。

解决办法，是先拿到=之前的一份副本，之后再存起来。
```c++
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

```
