#include <iostream>
#include "Characters.h"
#include <ctime>
#include <process.h>
#include <vector>
#include <limits>

int main() { 
srand(time(nullptr));
int value;
std::cout << "Hello dear friend choice a class \n";
std::cout << "1 - Warrior \n";
std::cout << " 2 - Default man (neerdy_coder) \n";
std::cout << "  3 - Mag (beta test)  \n";
std::cout << "   4 - Robot$@&!I (secret test SOON:)\n";
std::cout << "Enter your choice: ";
std::cin >> value;

Character* ptr = nullptr;

   switch(value) { 
    case 1:
    ptr = new Warrior("Conan", 230, 54, 40);
      std::cout << " ---------------------------------------------------------------------------------- \n";
    std::cout << "You choice: " << ptr->get_name() 
    << "(HP: " << ptr->get_hp() << ") " 
    << " <<<<<<< " 
    << " your Damage: " <<  ptr->get_attack() 
    << " <<<<<<< " <<
      "Defense " << ptr->get_defense() 
      << " <<<<<<< \n";
      std::cout << " ---------------------------------------------------------------------------------- \n";
    break;
    case 2:
    ptr = new Character("peasant", 50, 10, 3);
    std::cout << " ---------------------------------------------------------------------------------- \n";
   std::cout << "You choice: " << ptr->get_name() 
   << "(HP " << ptr->get_hp() << ") " 
   << " <<<<<<< " 
   << " your Damage: " <<  ptr->get_attack() 
   << " <<<<<<< "
    << "Defense " << ptr->get_defense() 
    << " <<<<<<< \n";
    std::cout << " ---------------------------------------------------------------------------------- \n";
   break;
   case 3:
   std::cout << "Mag in the beta test!\n";
   exit(0);
   case 4:
   std::cout << "Robot in the beta test!\n";
   exit(0);
    default:
    std::cout << "The choice or command is incorrect, please select again" << std::endl;
   }

   if(!ptr) {std::cout << "Game is ended..! \n";
   return 0;}

 std::cout << " ---------------------------------------------------------------------------------- \n";
  std::cout << " ---------------------------------------------------------------------------------- \n";
   std::cout << " ---------------------------------------------------------------------------------- \n";
   std::string choice;
   while(true){
   std::cout << "U ready went go to travel? \n";
   std::cout << "yes or no \n";
   std::cin >> choice; 
   if(choice == "yes" || choice == "YES" || choice == "Yes") {
   std::cout << "Okay, good luck dear friend \n";
   break;
   }
   else if(choice == "no" || choice == "NO" || choice == "nO" || choice == "No") {
    delete ptr;
    return 0;
   } 
   else {
    std::cout << " ---------------------------------------------------------------------------------- \n";
   std::cout << "plz write - (yes) or (no)\n";
   std::cout << " ---------------------------------------------------------------------------------- \n";
   }
    }
       std::cout << " * 1 level * \n";

   std::cout << " ---------------------------------------------------------------------------------- \n";
   std::cout << " ---------------------------------------------------------------------------------- \n";
   
     std::cout << "Be careful you met the enemy\n";
        std::vector<Character*> enemies = {
          new Character("Goblin", 130, 33, 10),
          new Character("Dark Knight", 350, 61, 32),
          new Boss("BELPHEGOR", 400, 58, 1)
        };
        // думал сделать через переменные но гпт предупредил о баге что будет баг при крит ударе возникнет UB'ишка
          // int counterPotions = 0;
          // const int health_potion = 35;
         for(size_t i = 0; i < enemies.size(); ++i) {
   std::cout << " ---------------------------------------------------------------------------------- \n";
          std::cout << "Welcome to the " << i + 1 << " LEVEL \n";
            if(dynamic_cast<Boss*>(enemies[i])) std::cout << "WARNING IS BOSS, BE CARE!\n";   
        std::cout << "your enemy is - " << enemies[i]->get_name() << " "  
        << "HP: " << enemies[i]->get_hp() <<  " " 
        << "DMG: " << enemies[i]->get_attack() << " " 
        << "DEFENSE: " << enemies[i]->get_defense() << std::endl;
         std::cout << " ---------------------------------------------------------------------------------- \n";
         std::cout << " ---------------------------------------------------------------------------------- \n";
             while(ptr->isAlive() && enemies[i]->isAlive()) { 
                int choice_2;
                std::cout << "Enter your action: \n";
              std::cout << "1 Attack \n";
                 std::cout << " 2 Defense \n";
                 std::cout << "  3 use health potion \n";
                 std::cout << "(you will receive +35 health regardless of the damage)\n";
                 std::cout << "   4 Run (chance 50 %)\n";
                 if(std::cin.fail()){
                  std::cin.clear();
                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорируем остаток ввода
         std::cout << " ---------------------------------------------------------------------------------- \n";
            std::cout << "Invalid input! Please enter a number from 1 to 4.\n";
         std::cout << " ---------------------------------------------------------------------------------- \n";
         continue; 
                 }
         std::cout << " ---------------------------------------------------------------------------------- \n";
         std::cout << " ---------------------------------------------------------------------------------- \n";
                   std::cin >> choice_2; 
                   bool defens = false;
                    
                   if(choice_2 == 1) { 
         std::cout << " ---------------------------------------------------------------------------------- \n";
         std::cout << " ---------------------------------------------------------------------------------- \n";
          if(Boss* b = dynamic_cast<Boss*>(enemies[i])){
             if(b->Dodge()) {
         std::cout << " ---------------------------------------------------------------------------------- \n";
              std::cout << "BELPHEGOR successfully dodged \n";
                int damageTo_player = std::max(0, enemies[i]->get_attack() - ptr->get_defense());
                      if(defens) damageTo_player /= 2;
                      ptr->TakeDmg(damageTo_player);
                      std::cout << enemies[i]->get_name() << " " << "you were attacked for \n" << " DMG: " << damageTo_player << 
                       "\n" << "current HP: (" << ptr->get_hp() << ")" << std::endl;
         std::cout << " ---------------------------------------------------------------------------------- \n";
             continue;
          } 
        }
         if(Warrior* w = dynamic_cast<Warrior*>(ptr)) {
    if(rand() % 100 < 18) { 
        w->CriticalDamage(*enemies[i]);
    } else {
        int dmgTo_enemy = std::max(0, ptr->get_attack() - enemies[i]->get_defense());
        enemies[i]->TakeDmg(dmgTo_enemy);
        std::cout << ptr->get_name() << " hits " << enemies[i]->get_name() << " for " << dmgTo_enemy << "\n";
    }
      } else {
    int dmgTo_enemy = std::max(0, ptr->get_attack() - enemies[i]->get_defense());
    enemies[i]->TakeDmg(dmgTo_enemy);
    std::cout << ptr->get_name() << " hits " << enemies[i]->get_name() << " for " << dmgTo_enemy << "\n";
      } 

               if(Boss* p = dynamic_cast<Boss*>(enemies[i])) {
                           if(!p->isAlive()) {
          std::cout << " ---------------------------------------------------------------------------------- \n";
                            std::cout << "*******YOU HAVE DEFEATED THE BOSS CONGRATULATIONS!!!*******\n";
          std::cout << " ---------------------------------------------------------------------------------- \n";
            std::cout << " ---------------------------------------------------------------------------------- \n";                    
                           std::cout << "you have successfully completed the game, \n" << "thank you for your gameplay.\n" << 
                            "As you can see in the README, future developments and updates are planned. FELONINE <3 <3 0_o\n";
                            goto END;
                          }
                        }
                   }
                    else if(choice_2 == 2) {
                      std::cout << "You " << ptr->get_name() << " " <<  "have successfully defended yourself \n";
                      defens = true;
                    } 
                     else if(choice_2 == 3) {
                      ptr->usePotion_HP(35);
                     }  
                    else if(choice_2 == 4) {
                    if(rand() % 2 == 0) {       
                      std::cout << "Succesfully escaped!\n";
                      break;
                    } else {
                      std::cout << "Escape failed! The enemy blocks your path! \n";
                     }
                    } 
                    else {
                      std::cout << "Invalid action! You lose your turn!\n";
                    }
                     if(!enemies[i]->isAlive()) {
                      std::cout << "Congrulations! you win " << enemies[i]->get_name() <<"\n";
         std::cout << " ---------------------------------------------------------------------------------- \n";         
         std::cout << "After killing the enemy, you received a potion health \n";
                      ptr->AddPotions();
                      break;
                     }
  std::cout << " ---------------------------------------------------------------------------------- \n";
       int damageTo_player = std::max(0, enemies[i]->get_attack() - ptr->get_defense());
                      if(defens) damageTo_player /= 2;
                      ptr->TakeDmg(damageTo_player);
                      std::cout << enemies[i]->get_name() << " " << "you were attacked for \n" << " DMG: " << damageTo_player << 
                       "\n" << "current HP: (" << ptr->get_hp() << ")" << std::endl;
         std::cout << " ---------------------------------------------------------------------------------- \n";
                       if(!ptr->isAlive()) {
                          std::cout << "You are dead, Game over.... " << ptr->get_name() <<"\n";
                        goto END;
                       }
                 } 
                 char choice_3;
                       std::cout << "Continue to next level? \n";
                       std::cout << "CLICK TO NEXT - T \n";
                       std::cout << "OR click to exit - Q \n";
                   std::cin >> choice_3;
          if(choice_3 == 'Q' || choice_3 == 'q') {
               std::cout << "Game ended, thanks for playing!\n";
                goto END;
                   }
                   else if(choice_3 == 'T' || choice_3 == 't') {} 
                    else {
                      std::cout << "INVALID COMMAND! \n";
                      break;
                    }
            }
            

          
             
  END:
      for(const auto& enemy_ptr : enemies) { 
        delete enemy_ptr;
      }
    delete ptr;
    return 0;
   } 
   


