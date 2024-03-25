#include <iostream>
using namespace std;
//ІДЕЯ ПРОДАЖУ ДАЙМОНДІВ КОЇНІВ І НАГЕТІВ ДЛЯ ОТРИМАННЯ ГРОШЕЙ ЗА ЯКІ ВСЕ КУПУЄТЬСЯ
class Resources {
protected:
	int count;
	int cost;
public:
	Resources() :count{ 0 } {}
	int getCost() const {
		return cost;
	}
	int getCount() const {
		return count;
	}
	void Add(int count) {
		this->count += count;
	}
	void Sub(int count) {
		this->count -= count;
	}
	void Print()const {
		cout << " Cost: " << cost << endl;
		cout<<" Count: " << count << endl;
	}
};
class Hero;
class Diamonds :public Resources {
public:
	Diamonds(){cost = 15;}
	/*int CountOfMoney()const {
		return (count * cost);
	}*/
	void Falling(int count, Hero& hero)const;
	void Print()const {
		cout << " -= Diamonds =-" << endl;
		Resources::Print();
	}
};
class Coins:public Resources {
public:
	Coins()  {cost = 3;}
	void Falling(int count, Hero& hero)const;
	void Print()const {
		cout << " -= Coins =-" << endl;
		Resources::Print();
	}
};
class Nuggets :public Resources {
public:
	Nuggets() {cost = 1;}
	void Falling(int count, Hero& hero)const;
	void Print()const {
		cout << " -= Nuggets =-" << endl;
		Resources::Print();
	}
};
class Wood :public Resources {
public:
	Wood(){cost = 1;}
	void CuttingDown(int count, Hero& hero)const;
	void Print()const {
		cout << " -= Wood =-" << endl;
		Resources::Print();
	}
};
class Potion :public Resources {
public:
	Potion(){cost = 30;}
	virtual void PrintPotion() const = 0;
};
class HealthPotion : public Potion {
public:
	void NewPotion(int count, Hero& hero)const ;
	void PrintPotion() const override{
		cout << " -= Health potion =-" << endl;
		cout << " Potion effect: +4 HP" << endl;
		Print();
	}
};
class StrengthPotion : public Potion {
public:
	void NewPotion(int count, Hero& hero)const ;
	void PrintPotion() const override {
		cout << " -= Strength potion =-" << endl;
		cout << "Potion effect: +3 strength" << endl;
		Print();
	}
};
class Inventory {
	int money=0;
	Coins coins;
	Nuggets nuggets;
	Diamonds diamonds;
	Wood wood;
	HealthPotion healthPotion;
	StrengthPotion strengthPotion;
public:
	int getMoney()const {
		return money;
	}
	int getWoodCount()const {
		return wood.getCount();
	}
	int getDaimondsCount()const {
		return diamonds.getCount();
	}
	int getCoinsCount()const {
		return coins.getCount();
	}
	int getNuggetsCount()const {
		return nuggets.getCount();
	}
	int GetHealthPotionCount()const {
		return healthPotion.getCount();
	}
	int GetStrengthPotionCount()const {
		return strengthPotion.getCount();
	}
	int getWoodCost()const {
		return wood.getCost();
	}
	int getDaimondsCost()const {
		return diamonds.getCost();
	}
	int getCoinsCost()const {
		return coins.getCost();
	}
	int getNuggetsCost()const {
		return nuggets.getCost();
	}
	void AddMoney(int money) {
		this->money += money;
		cout << " +" << money << " money" << endl;
	}
	void AddCoins(int count) {
		coins.Add(count);
		cout << " +" << count << " coins" << endl;
	}
	void AddNuggets(int count) {
		nuggets.Add(count);
		cout << " +" << count << " nuggets" << endl;
	}
	void AddDiamonds(int count) {
		diamonds.Add(count);
		cout << " +" << count << " diamonds" << endl;
	}
	void AddWood(int count) {
		wood.Add(count);
		cout << " +" << count << " wood" << endl;
	}
	void AddHealthPotion(int count) {
		healthPotion.Add(count);
	}
	void AddStrengthPotion(int count) {
		strengthPotion.Add(count);
	}
	void RemoveMoney(int money) {
		if (money == 0 || this->money - money < 0) {
			cout << "Not enough money" << endl;
		}
		else {
			this->money -= money;
			cout << " -" << money << " money" << endl;
		}
	}
	void RemoveCoins(int count) {
		if (coins.getCount() == 0 || coins.getCount() - count < 0) {
			cout << "Not enough coins" << endl;
		}
		else {
			coins.Sub(count);
			cout << " -" << count << " coins" << endl;

		}
	}
	void RemoveNuggets(int count) {
		if (nuggets.getCount() == 0 || nuggets.getCount() - count < 0) {
			cout << "Not enough nuggets" << endl;
		}
		else {
			nuggets.Sub(count);
			cout << " -" << count << " nuggets" << endl;
		}
	}
	void RemoveDiamonds(int count) {
		if (diamonds.getCount() == 0 || diamonds.getCount() - count < 0) {
			cout << "Not enough diamonds" << endl;
		}
		else {
			diamonds.Sub(count);
			cout << " -" << count << " daimonds" << endl;

		}
	}
	void RemoveWood(int count) {
		if(wood.getCount()==0||wood.getCount()-count<0){
			cout << "Not enough wood" << endl;
		}
		else {
			wood.Sub(count);
		}
	}
	void RemoveHealthPotion(int count) {
		if (healthPotion.getCount() == 0 || healthPotion.getCount() - count < 0) {
			cout << "Not enough health potion" << endl;
		}
		else {
			healthPotion.Sub(count);
			cout << " -" << count << " health potion" << endl;
		}
	}
	void RemoveStrengthPotion(int count) {
		if (strengthPotion.getCount() == 0 || strengthPotion.getCount() - count < 0) {
			cout << "Not enough strength potion" << endl;
		}
		else {
			strengthPotion.Sub(count);
			cout << " -" << count << " strength potion" << endl;
		}
	}
	void Print()const {
		cout << " -===== Inventory =====-" << endl;
		cout << " Money:" << money << endl;
		if(diamonds.getCount()>0){ diamonds.Print(); }
		if (coins.getCount() > 0) { coins.Print(); }
		if (nuggets.getCount() > 0) { nuggets.Print(); }
		if (wood.getCount() > 0) { wood.Print(); }
		if (healthPotion.getCount() > 0){ healthPotion.PrintPotion(); }
		if (strengthPotion.getCount() > 0) { strengthPotion.PrintPotion(); }
	}
};
class Units {
protected:
	int HP;
	int strength;
	int lvl;
public:
	Units() :HP{ 20 }, lvl{ 0 } {}
	void LossHP(int hp) {
		HP -= hp;
		cout << "-" << hp << " HP" << endl;
	}
	int GetHP()const {
		return HP;
	}
	int GetStrength()const {
		return strength;
	}
	void Print()const {
		cout << "Level: " << lvl << endl;
		cout << "Strength: " << strength << endl;
		cout << "HP: " << HP << endl;
}
	virtual void LevelUp() {
		HP += 2;
		strength += 2;
		lvl++;
	}
	virtual void Speak(bool isWin)const = 0;
};
class Enemy :public Units {
protected:
	string type;
public:
	void Attack(Hero& hero)const; 
	virtual void Dead(Hero& hero)=0;
	void Print()const {
		cout << "Type: " << type << endl;
		Units::Print();
	}
};
class Hero :public Units {
private:
	int Exp;
	int maxHP;
	Inventory inventory;
public:
	Hero() :Exp{ 0 }, maxHP{ 20+(2*lvl)}, Units() {
		strength = 3;
	}
	void LevelUp() override{
		maxHP += 2;
		strength += 2;
		lvl++;
	}
	Inventory& GetInventory() {
		return inventory;
	}
	int GetMaxHP()const {
		return maxHP;
	}
	void Print()const {
		cout << " -===== HERO =====-" << endl;
		Units::Print();
		cout << "Max HP: " << maxHP << endl;
		cout << "Experience: " << Exp << "\tExperience until the next level:" << 25 - Exp << endl;
		inventory.Print();
	}
	void Speak(bool isWin)const override {
		if (isWin) {
			cout << "YEES! I win!" << endl;
		}
		else {
			cout << "No..." << endl;
		}
	}
	void Attack(Enemy& enemy)const {
		cout << "Enemy has ";
		enemy.LossHP(strength);
		
	}
	void AddHP(int hp) {
		if (GetHP() + hp <= GetMaxHP()) {
			HP += hp;
			cout << "+" << hp << " HP" << endl;
		}
		else {
			cout << "You have full HP or new HP exceeds the health limit" << endl;
		}
	}
	void AddStrength(int str) {
		strength += str;
		cout << "+" << strength << " strength" << endl;
	}
	void AddExp(int exp) {
		Exp = exp;
	}
	void GetNewHP() {
		if (GetHP() + 4 <= GetMaxHP()) {
			if(inventory.GetHealthPotionCount()>0){
				inventory.RemoveHealthPotion(1);
				AddHP(4);
			}
			else {
				cout << "No health potion" << endl;
			}
		}
		else {
			cout << "You have full HP or too much HP to use potion" << endl;
		}
	}
	void GetNewStrength() {
		if(inventory.GetStrengthPotionCount()>0){
			inventory.RemoveStrengthPotion(1);
			AddStrength(3);
		}
		else { cout << "No strength potion" << endl; }
	}
	void Dead() {
		cout << "You dead" << endl;
		Hero();
		//Menu();
	}
};
class Dragon :public Enemy {
private:
	string name;
	Diamonds diamonds;
	Coins coins;
	HealthPotion healthPotion;
	int exp;
	bool IsAlive;
public:
	Dragon(string name):exp{20}, name{ name }{
		IsAlive = true;
		type = "DRAGON";
		strength = 6;
		diamonds.Add(1);
		coins.Add(2);
		if ((rand() % 2 + 1) == 2) {
			healthPotion.Add(1);
		}
	}
	string GetName()const {
		return name;
	}
	void SetIsAlive(bool value) {
		IsAlive = value;
	}
	bool GetIsAlive() {
		return IsAlive;
	}
	void Speak(bool isWin)const override {
		if (isWin) {
			cout << "RAAAAAAAAAAAAAAR" << endl;
		}
		else {
			cout << "Raaaar..." << endl;
		}
	}
	void LevelUp()override {
		if (IsAlive) {
			HP += 2;
			strength += 2;
			lvl++;
		}
	}
	void Dead(Hero& hero) override{
		coins.Falling(coins.getCount(),hero);
		diamonds.Falling(diamonds.getCount(), hero);
		if (healthPotion.getCount() > 0) {
			healthPotion.NewPotion(healthPotion.getCount(), hero);
		}
		hero.AddExp(exp);
		SetIsAlive(false);
	}
	void Print()const {
		cout << " -==== " << name << " ====-" << endl;
		cout << "Status: ";
		IsAlive ? cout << "Alive" << endl : cout << "Dead" << endl;
		Enemy::Print();
	}
};
class Monster:public Enemy {
private:
	Coins coins;
	Nuggets nuggets;
	int exp;
public:
	Monster():exp{5}{
		type = "Monster";
		coins.Add(1);
		nuggets.Add(3);
		strength = 4;
	}
	void Speak(bool isWin)const override {
		if (isWin) {
			cout << "Ar Ar AAAR" << endl;
		}
		else {
			cout << "Argh..." << endl;
		}
	}
	void Dead(Hero& hero) override {
		coins.Falling(coins.getCount(), hero);
		nuggets.Falling(nuggets.getCount(), hero);
		hero.AddExp(exp);
		Monster();
	}
	void Print()const {
		cout << " -= Monster =-" << endl;
		Enemy::Print();
	}
};
class Animals:public Enemy {
private:
	Nuggets nuggets;
	int exp;
public:
	Animals() :exp{ 3 }{
		type = "Animal";
		nuggets.Add(2);
		strength = 0;
	}
	void Speak(bool isWin)const override {
		cout << "Oh..." << endl;
	}
	void Dead(Hero& hero) override {
		nuggets.Falling(nuggets.getCount(), hero);
		hero.AddExp(exp);
		Animals();
	}
	void Print()const {
		cout << " -= Animal =-" << endl;
		Enemy::Print();
	}
};

void Enemy::Attack(Hero& hero)const {
	cout << "You have ";
	hero.LossHP(strength);
}
void Diamonds::Falling(int count, Hero& hero)const {
	hero.GetInventory().AddDiamonds(count);
}
void Coins::Falling(int count, Hero& hero)const {
	cout << "Click click click" << endl;
	hero.GetInventory().AddCoins(count);
}
void Nuggets::Falling(int count, Hero& hero)const {
	cout << "Click click" << endl;
	hero.GetInventory().AddNuggets(count);
}
void Wood::CuttingDown(int count, Hero& hero)const {
	cout << "Took Took Took" << endl;
	hero.GetInventory().AddWood(count);
}
void HealthPotion::NewPotion(int count, Hero& hero)const {
	cout << "Bulk Bulk" << endl;
	cout << "+" << count << " health potion" << endl;
	hero.GetInventory().AddHealthPotion(count);
}
void StrengthPotion::NewPotion(int count, Hero& hero)const {
	cout << "Bulk Bulk" << endl;
	cout << "+" << count << " strength potion" << endl;
	hero.GetInventory().AddStrengthPotion(count);
}

class Shop {
	HealthPotion healthPotion;
	StrengthPotion strengthPotion;
	int healthRecoveryCount;
public:
	Shop() {
		healthPotion.Add(10);
		strengthPotion.Add(3);
		healthRecoveryCount = 2;
	}
	void Print()const {
		cout << " -==== SHOP ====-" << endl;
		cout << "Health potion: " << healthPotion.getCount() << "\t\t\tCost: " << healthPotion.getCost()<<endl;
		cout << "Strength potion: " << strengthPotion.getCount() << "\t\t\tCost: " << strengthPotion.getCost() << endl;
		cout << "Remainder of full health recovery: " << healthRecoveryCount<<"\tCost: 1" << endl;
	}
	void SellHealthPotion(Hero& hero)const {
		if (healthPotion.getCount() > 0 && hero.GetInventory().getMoney() - healthPotion.getCost() >= 0) {
			healthPotion.NewPotion(1, hero);
			hero.GetInventory().RemoveMoney(healthPotion.getCost());
		}
		else {
			if (healthPotion.getCount() == 0) {
				cout << "No health potion" << endl;
			}
			else { cout << "Not enough money" << endl; }
		}
	}
	void SellStrengthPotion(Hero& hero)const {
		if (strengthPotion.getCount() > 0 && hero.GetInventory().getMoney()- strengthPotion.getCost() >=0){
			strengthPotion.NewPotion(1, hero);
			hero.GetInventory().RemoveMoney(strengthPotion.getCost());
		}
		else {
			if (strengthPotion.getCount() == 0) {
				cout << "No strength potion" << endl;
			}
			else{ cout << "Not enough money" << endl; }
		}
	}
	void BuyWood( Hero& hero)const {
		if (hero.GetInventory().getWoodCount() > 0) {
			hero.GetInventory().AddMoney(hero.GetInventory().getWoodCount()* hero.GetInventory().getWoodCost());
			hero.GetInventory().RemoveWood(hero.GetInventory().getWoodCount());
		}
		else {
			cout << "You have not enough wood"<<endl;
		}
	}
	void BuyDiamonds(Hero& hero)const {
		if (hero.GetInventory().getDaimondsCount() > 0) {
			hero.GetInventory().AddMoney(hero.GetInventory().getDaimondsCost() * hero.GetInventory().getDaimondsCount());
			hero.GetInventory().RemoveDiamonds(hero.GetInventory().getDaimondsCount());
		}
		else {
			cout << "You have not enough daimonds" << endl;
		}
	}
	void BuyCoins(Hero& hero)const {
		if (hero.GetInventory().getCoinsCount() > 0) {
			hero.GetInventory().AddMoney(hero.GetInventory().getCoinsCost() * hero.GetInventory().getCoinsCount());
			hero.GetInventory().RemoveCoins(hero.GetInventory().getCoinsCount());
		}
		else {
			cout << "You have not enough coins" << endl;
		}
	}
	void BuyNuggets(Hero& hero)const {
		if (hero.GetInventory().getNuggetsCount() > 0) {
			hero.GetInventory().AddMoney(hero.GetInventory().getNuggetsCost() * hero.GetInventory().getNuggetsCount());
			hero.GetInventory().RemoveNuggets(hero.GetInventory().getNuggetsCount());
		}
		else {
			cout << "You have not enough nuggets" << endl;
		}
	}
	void FullHealthRecovery(Hero& hero) {
		if (hero.GetMaxHP() - hero.GetHP() != 0) {
			hero.AddHP(hero.GetMaxHP() - hero.GetHP());
			healthRecoveryCount--;
			hero.GetInventory().RemoveMoney(1);
		}
		else {
			cout << "You have full HP" << endl;
		}
	}
};
void Store(Shop& shop, Hero& hero) {
	int choise;
	do {
		shop.Print();
		cout << endl;
		cout << "Enter 1 to buy 1 health potion" << endl;
		cout << "Enter 2 to buy 1 strength potion" << endl;
		cout << "Enter 3 to sell all wood" << endl;
		cout << "Enter 4 to sell all diamonds" << endl;
		cout << "Enter 5 to sell all coins" << endl;
		cout << "Enter 6 to sell all nuggets" << endl;
		cout << "Enter 7 to recover all HP" << endl;
		cout << "Enter 8 to see your inventory" << endl;
		cout << "Enter 0 to exit shop" << endl;
		cout << "Enter your choise (Remember you cannot change your choice. So think carefully!): ";
		cin >> choise;
		cout << endl;
		if (choise >= 0 && choise <= 8) {
			switch (choise)
			{
			case 1:
				shop.SellHealthPotion(hero);
				break;
			case 2:
				shop.SellStrengthPotion(hero);
				break;
			case 3:
				shop.BuyWood(hero);
				break;
			case 4:
				shop.BuyDiamonds(hero);
				break;
			case 5:
				shop.BuyCoins(hero);
				break;
			case 6:
				shop.BuyNuggets(hero);
				break;
			case 7:
				shop.FullHealthRecovery(hero);
				break;
			case 8:
				hero.GetInventory().Print();
				break;
			}
			if (choise == 0) {
				char ch;
				do{
					cout << "Remember, if you leave the store, you will have to wait for the next store on the way." << endl;
					cout << "Enter [+] to leave or [-] to continue shopping: ";
					cin >> ch;
					if (ch == '+') {
						cout << "You leave the store" << endl;
						break;
					}
					else if (ch == '-') {
						choise = 9;
						break;
					}
					else {
						cout << "Enter right value!!!" << endl;
						continue;
					}
				} while (ch!=0);
			}
		}
		else {
			cout << "Enter right value!!!" << endl;
			continue;
		}
	}while (choise != 0);
}
void Fight(Enemy& enemy, Hero& hero) {
	bool IsHeroAlive=true;
	char choise;
	cout << "The fight started!!!" << endl;
	cout << endl;
	while (IsHeroAlive ) {
		hero.Attack(enemy);
		cout << endl;
		if (enemy.GetHP()<= 0) {
			hero.Speak(IsHeroAlive);
			enemy.Speak(!IsHeroAlive);	
			cout << "Enemy is dead" << endl;
			enemy.Dead(hero);
			break;
		}
		enemy.Print();
		do{
			cout << "Enemy attacking. Where will you dodge to the right(Enter [R]) or to the left(Enter [L])?" << endl;
			cout << "Enter your choise: ";
			cin >> choise;
			if (choise != 'R' && choise != 'L') {
				cout << "Enter right value!"<<endl;
			}
			else {break;}
		} while (choise != 0);
		int random= (rand() % 2 + 1);//1 - right		2 - left
		if (random == 1 && choise == 'R') {
			enemy.Attack(hero);
			if (hero.GetHP() <= 0) {				
				IsHeroAlive = false;
				hero.Speak(IsHeroAlive);
				enemy.Speak(!IsHeroAlive);
				hero.Dead();
			}}
		else if (random == 1 && choise == 'L') {
			cout << "You dodged successfully" << endl;
		}
		else if (random == 2 && choise == 'L') {
			enemy.Attack(hero);
			if (hero.GetHP() <= 0) {
				IsHeroAlive = false;
				hero.Speak(IsHeroAlive);
				enemy.Speak(!IsHeroAlive);
				hero.Dead();
			}}
		else if (random == 2 && choise == 'R') {
			cout << "You dodged successfully" << endl;
		}
		cout << endl;
		hero.Print();
		cout << endl;
		if(hero.GetInventory().GetHealthPotionCount()!=0||hero.GetInventory().GetStrengthPotionCount()!=0){
			cout << " Enter [+] to use {Health potion}, [-] to use {Strength potion} or [0] to skip: ";
			cin >> choise;
			cout << endl;
			if (choise == '+') {
				hero.GetNewHP();
			}
			else if (choise == '-') {
				hero.GetNewStrength();
			}
		}
	}
}

static int position;
void Map( Dragon& dragon1, Dragon& dragon2, Dragon& dragon3) {
	cout << "Curent position: " << position << endl;
	if(dragon1.GetIsAlive()){
		cout << "Distance to the next shop: " << 45 - position << endl;
		cout << "Distance to the next dragon: "<<50-position << endl;
	}
	else if (dragon2.GetIsAlive()) {
		cout << "Distance to the next shop: " << 95 - position << endl;
		cout << "Distance to the next dragon: " << 100 - position << endl;
	}
	else if (dragon3.GetIsAlive()) {
		cout << "Distance to the next shop: " << 145 - position << endl;
		cout << "Distance to the next dragon: " << 150 - position << endl;
	}
	else {
		cout << "Distance to the next shop: " << 195 - position << endl;
		cout << "Distance to the final boss: " << 200 - position << endl;
	}
}

void UserMenu() {
	cout << "Enter 1 to exit game and save" << endl;
	cout << "Enter 2 to see map" << endl;
	cout << "Enter 3 to see inventory" << endl;
	cout << "Enter 0 to exit menu" << endl;
}

void Game(Dragon& dragon1, Dragon& dragon2, Dragon& dragon3, Monster& monster, Animals& animal, Hero& hero, Wood& wood,Shop& shop) {
	char move;
	int random;
	do {
		if (position % 50 == 0) {
			cout << "You meet dragon! Get Ready!" << endl;
			hero.Print();
			if (hero.GetInventory().GetHealthPotionCount() != 0 || hero.GetInventory().GetStrengthPotionCount() != 0) {
				cout << " Enter [+] to use {Health potion}, [-] to use {Strength potion} or [0] to skip: ";
				cin >> move;
				if (move == '+') {
					hero.GetNewHP();
				}
				else if (move == '-') {
					hero.GetNewStrength();
				}
			}
			cout << endl;
			if (dragon1.GetIsAlive()) {
				cout << "Your enemy: ";
				dragon1.Print();
				Fight(dragon1, hero);
			}
			else if (dragon2.GetIsAlive()) {
				cout << "Your enemy: ";
				dragon2.Print();
				Fight(dragon2, hero);
			}
			else if (dragon3.GetIsAlive()) {
				cout << "Your enemy: ";
				dragon3.Print();
				Fight(dragon3, hero);
			}
			/*else {
				cout << "Distance to the next shop: " << 195 - position << endl;
				cout << "Distance to the final boss: " << 200 - position << endl;
			}*/
		}
		else if ((position >= 1 && position <= 10) || (position >= 51 && position <= 60) || (position >= 101 && position <= 110) || (position >= 151 && position <= 160)) {
			if (wood.getCount() > 0) {				
				random = rand() % 4;
				if (random == 0) { cout << "Nothing..." << endl; }
				else{ cout << "Cutting tree..." << endl;
					wood.CuttingDown(random, hero);
					wood.Sub(random);
				}
			}
		}
		else if (position == 45 || position == 95 || position == 145 || position == 195) {
			Store(shop,hero);
		}
		else {
			random = rand() % 3 + 1;//1-wood 2-animals 3-monters
			if (random == 1 && wood.getCount() == 0) { random++; }
			cout << endl;
			switch (random) {
			case 1:
				random = rand() % 4;
				if (random == 0) { cout << "Nothing..." << endl; }
				else{
					cout << "Cutting tree..." << endl;
					wood.CuttingDown(random, hero);
					wood.Sub(random);
				}
				break;
			case 2:
				cout << "You meet Animal! Get ready!" << endl;
				cout << endl;
				hero.Print();
				cout << endl;
				cout << " Enter [+] to use {Health potion}, [-] to use {Strength potion} or [0] to skip: ";
				cin >> move;
				if (move == '+') {
					hero.GetNewHP();
				}
				else if (move == '-') {
					hero.GetNewStrength();
				}
				cout << endl;
				animal.Print();
				Fight(animal, hero);
				break;
			case 3:
				cout << "You meet Monster! Get ready!" << endl;
				cout << endl;
				hero.Print();
				cout << endl;
				if (hero.GetInventory().GetHealthPotionCount() != 0 || hero.GetInventory().GetStrengthPotionCount() != 0) {
					cout << " Enter [+] to use {Health potion}, [-] to use {Strength potion} or [0] to skip: ";
					cin >> move;
					if (move == '+') {
						hero.GetNewHP();
					}
					else if (move == '-') {
						hero.GetNewStrength();
					}
					cout << endl;
				}
				monster.Print();
				Fight(monster, hero);
				break;
			}
		}
		do {cout << endl;
			cout << "Enter [G] to visit game menu" << endl;
			cout << "Enter [M] to see map" << endl;
			cout << "Enter [S] to make next step and move" << endl;
			cout << "Your choise: ";
			cin >> move;
			cout << endl;
			if (move=='G'){
				UserMenu();
			}
			else if (move=='M') {
				Map(dragon1, dragon2, dragon3);
			}
			else if (move == 'S') {
				cout << "Moving..." << endl;
				++position;
			}
			else {
				cout << "Enter right value! (It's important to write letters in upper case)" << endl;
			}
		} while (move!='S');
	} while (position != 0&&position<=200);
}

int main(){
	srand(time(0));
	position = 1;////////////// = 0;
	Shop s;
	Dragon dragon1{ "d1" };
	Dragon dragon2{ "d2" };
	Dragon dragon3{ "d3" };
	Monster m;
	Animals a;
	Hero h;
	Wood wood;
	wood.Add(50);
	Game(dragon1,dragon2,dragon3,m,a,h,wood,s);
}