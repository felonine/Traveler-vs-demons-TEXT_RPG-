#ifndef CHARACTERS_H
#define CHARACTERS_H 
#include <string>


class valueError : public std::exception {
    std::string msg;
    public:
   explicit valueError(const std::string& str = "") noexcept;
   const char* what() const noexcept override;
};
  enum {max_hp = 300};
class Character {
    protected:
    std::string name;
    int hp, attack, defense;
    int potions_hp;
    public:
    Character(std::string str = "", int hp = 100, int atk = 0, int def = 0);
    virtual void Attack(Character& target);
   virtual void TakeDmg(int damage);
    const std::string& get_name() const;
    int get_hp() const;
    bool isAlive() const ;
   virtual ~Character() {}
    int get_defense() const;
     int get_attack() const;  
     void AddPotions();
     bool usePotion_HP(int health);     
}; 
 class Warrior final : public Character {
     public:
     Warrior(std::string str = "", int hp = 230, int atk = 0, int def = 0);
     void Attack(Character& target) override;
     void TakeDmg(int damage) override; 
      bool Block();
      void CriticalDamage(Character& other);
 };
  class Boss : public Character {
    public:
    explicit Boss(std::string str, int hp, int atk, int def);
    bool Dodge();
  };

#endif