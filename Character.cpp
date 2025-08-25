#include "Characters.h"
#include <iostream>
#include <ctime>


 valueError::valueError(const std::string& str) noexcept : msg(str) {}
const char* valueError::what() const noexcept  { return msg.c_str();}

Character::Character(std::string str, int hp, int atk, int def) : name(str),
attack(atk), defense(def) { if(hp < 0) throw valueError("Hp now is 0, not be zero!:("); Character::hp = hp; }

void Character::Attack(Character& target) {
 int dmg = attack - target.defense; 
   if(!target.isAlive()) {
     std::cout << "ENEMY IS DEAD!!!" << std::endl;
     return;
   }
   
 if(dmg < 1) dmg = 1;
    std::cout << "The " << name << " dealt damage to the enemy " << target.get_name() << 
     "damage: "  << dmg << std::endl;
     target.TakeDmg(dmg);
}
 void Character::TakeDmg(int damage) { 
    hp -= damage;
    if(hp < 0 ) hp = 0;
     std::cout << "The " << name << " takes damage: " << damage << std::endl;
     std::cout << "Current HP: " << hp << std::endl;
 }
   const std::string& Character::get_name() const { return name; }
      int Character::get_hp() const { 
        if(hp < 0) return 0;
        return hp;
     }
    bool Character::isAlive() const  { 
            return (hp > 0);
    } 
      bool Character::usePotion_HP(int health) {
        if(potions_hp <= 0) {
            std::cout << "You HAVENT (potion health) :(\n";
            return false;
         } 
         hp += health;
         if(hp > max_hp) hp = max_hp;
         --potions_hp;
         std::cout << "Used potion +" << health << "\n";
         std::cout << "Your current (HP: " << hp << " )\n";
         return true;
      }
       void Character::AddPotions() { 
        potions_hp++; 
            }
     
    int Character::get_defense() const { return defense; }
    int Character::get_attack() const {return attack; }

// ===== Warrior =====
        Warrior::Warrior(std::string str, int hp, int atk, int def) : Character(str, hp, atk, def) {if(hp < 0) throw valueError("Hp now is 0, not be zero!:("); }
        void Warrior::Attack(Character& target)  { 
          if(!isAlive()) {std::cout << "GAME OVER GG!!!"; return; }
            int dmg = attack - target.get_defense();
            if(dmg < 1) dmg = 1;
            std::cout << "The " << name << " dealt damage to the enemy " << target.get_name() << 
         "damage: "  << dmg << std::endl;
        target.TakeDmg(dmg);
        }
        void Warrior::TakeDmg(int damage) {
             if(Block()) {
             std::cout << "You " << name <<  " blocked the attack. " << std::endl;
                return;
            }
             hp -= damage;
             if(hp < 0) hp = 0;
              std::cout << "The " << name << " takes damage: " << damage << std::endl;
             std::cout << "Current HP: " << hp << std::endl;
        }
        bool Warrior::Block() {
            return (rand() % 100) < 25;
        }
          void Warrior::CriticalDamage(Character& other) { 
             int dmg = (attack * 2) - other.get_defense();
               if(dmg < 1) dmg = 1;
            std::cout << name  << " A critical hit was made on: " << other.get_name() << " for " << dmg << " CRIIT!!" << std::endl;
              other.TakeDmg(dmg);
          } 
        // BO$$ 
        Boss::Boss(std::string str, int hp, int atk, int def) : Character(str, hp, atk, def) {}
          bool Boss::Dodge() { return (rand() % 100 < 18);};