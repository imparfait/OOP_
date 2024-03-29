#include <iostream>
#include <fstream>
using namespace std;

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
	void SetWood(int count) {
		this->count = count;
	}
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
		cout << "Potion effect: +2 strength" << endl;
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
	}
	void AddCoins(int count) {
		coins.Add(count);
	}
	void AddNuggets(int count) {
		nuggets.Add(count);
	}
	void AddDiamonds(int count) {
		diamonds.Add(count);
	}
	void AddWood(int count) {
		wood.Add(count);
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
	int Exp;
public:
	Units() :HP{20} {}
	void LossHP(int hp) {HP -= hp;
		cout << "-" << hp << " HP" << endl;}
	int GetExp()const {return Exp;}
	int GetHP()const {return HP;}
	void SetHP(int hp) { HP = hp; }
	int GetStrength()const {return strength;}
	void SetStrength(int str) { strength = str; }
	void Print()const {
		cout << "Strength: " << strength << endl;
		cout << "HP: " << HP << endl;}
	virtual void LevelUp() {
		HP += 2;
		strength += 2;}
	virtual void Speak(bool isWin)const = 0;
};
class Enemy :public Units {
protected:
	string type;
public:
	void Attack(Hero& hero)const; 
	string GetType()const { return type; }
	virtual void Dead(Hero& hero)=0;
	void Print()const {
		cout << "Type: " << type << endl;
		Units::Print();}
};
class Hero :public Units {
private:
	int maxHP;
	int ExpToNextLvl;
	int lvl;
	Inventory inventory;
public:
	Hero() : maxHP{ 25 }, lvl{ 0 }, Units() {
		HP = 25;
		Exp = 0;
		ExpToNextLvl = 20;
		strength = 3;}
	Hero(int lvl, int hp, int exp, int diamC, int coinsC, int nuggetsC, int money, int hpC, int spC, int woodC) :lvl{ lvl } {
		maxHP = 25 + (2 * lvl);
		strength = 3 + (2 * lvl);
		HP = hp;
		Exp = exp;
		ExpToNextLvl =20+ (5 * lvl);
		inventory.AddDiamonds(diamC);
		inventory.AddCoins(coinsC);
		inventory.AddNuggets(nuggetsC);
		inventory.AddMoney(money);
		inventory.AddHealthPotion(hpC);
		inventory.AddStrengthPotion(spC);
		inventory.AddWood(woodC);}
	void LevelUp() override{
		cout << "\n\tLEVEL UP" << endl;
		Exp = Exp- ExpToNextLvl;
		ExpToNextLvl += 5;
		maxHP += 2;
		HP += 4;
		strength += 2;
		++lvl;}
	Inventory& GetInventory() {return inventory;}
	int GetMaxHP()const {return maxHP;}
	int GetLvl()const {return lvl;}
	int GetExpToNextLvl()const { return ExpToNextLvl; }
	void SetLvl(int lvl) { this->lvl = lvl; }
	void Print()const {
		cout << " -===== HERO =====-" << endl;
		cout << "Level: " << lvl << endl;
		Units::Print();
		cout << "Max HP: " << maxHP << endl;
		cout << "Experience: " << Exp << "\tExperience until the next level:" << ExpToNextLvl - Exp << endl;
		inventory.Print();}
	void Speak(bool isWin)const override {
		if (isWin) {cout << "YEES! I win!" << endl;}
		else {cout << "No..." << endl;}}
	void Attack(Enemy& enemy)const {
		cout << enemy.GetType() << " has ";
		enemy.LossHP(strength);}
	void AddHP(int hp) {
		if (GetHP() + hp <= GetMaxHP()) {
			HP += hp;
			cout << "+" << hp << " HP" << endl;
		}
		else {cout << "You have full HP or new HP exceeds the health limit" << endl;}}
	void AddStrength(int str) {
		strength += str;
		cout << "+" << str << " strength" << endl;}
	void AddExp(int exp) {Exp += exp;}
	void GetNewHP() {
		if (GetHP() + 4 <= GetMaxHP()) {
			if(inventory.GetHealthPotionCount()>0){
				inventory.RemoveHealthPotion(1);
				AddHP(4);}
			else {cout << "No health potion" << endl;}}
		else {cout << "You have full HP or too much HP to use potion" << endl;}}
	void GetNewStrength() {
		if(inventory.GetStrengthPotionCount()>0){
			inventory.RemoveStrengthPotion(1);
			AddStrength(2);}
		else { cout << "No strength potion" << endl; }}
	bool Dead() {cout << "You dead" << endl;
		return false;}
};
class Dragon :public Enemy {
private:
	string name;
	Diamonds diamonds;
	Coins coins;
	HealthPotion healthPotion;
	bool IsAlive;
public:
	Dragon(string name): name{ name }{
		HP = 30;
		Exp = 20;
		IsAlive = true;
		type = "DRAGON";
		strength = 6;
		diamonds.Add(1);
		coins.Add(2);
		if ((rand() % 2 + 1) == 2) {healthPotion.Add(1);}}
	Dragon(string name, int lvl, bool isAlive) : name{ name } {
		Exp = 20;
		IsAlive = isAlive;
		HP =30+ (2 * lvl);
		type = "DRAGON";
		strength = 6 + (2 * lvl);
		diamonds.Add(1);
		coins.Add(2);
		if ((rand() % 2 + 1) == 2) {healthPotion.Add(1);}}
	string GetName()const {return name;}
	void SetIsAlive(bool value) {IsAlive = value;}
	bool GetIsAlive() {return IsAlive;}
	void Speak(bool isWin)const override {
		if (isWin) {cout << "RAAAAAAAAAAAAAAR" << endl;}
		else {cout << "Raaaar..." << endl;}}
	void LevelUp()override {
		if (IsAlive) {
			HP += 2;
			strength += 2;}}
	void Dead(Hero& hero) override{
		coins.Falling(coins.getCount(),hero);
		diamonds.Falling(diamonds.getCount(), hero);
		if (healthPotion.getCount() > 0) {healthPotion.NewPotion(healthPotion.getCount(), hero);}
		hero.AddExp(this->Exp);
		SetIsAlive(false);}
	void Print()const {
		cout << " -==== " << name << " ====-" << endl;
		cout << "Status: ";
		IsAlive ? cout << "Alive" << endl : cout << "Dead" << endl;
		Enemy::Print();}
};
class Monster:public Enemy {
private:
	Coins coins;
	Nuggets nuggets;
public:
	Monster(){
		type = "Monster";
		Exp = 5;
		coins.Add(1);
		nuggets.Add(3);
		strength = 3 ;}
	Monster(int lvl)  {
		Exp = 5;
		type = "Monster";
		coins.Add(1);
		nuggets.Add(3);
		HP += (2 * lvl);
		strength = 3 + (2 * lvl);}
	void Speak(bool isWin)const override {
		if (isWin) {cout << "Ar Ar AAAR" << endl;}
		else {cout << "Argh..." << endl;}}
	void Dead(Hero& hero) override {
		coins.Falling(coins.getCount(), hero);
		nuggets.Falling(nuggets.getCount(), hero);
		hero.AddExp(Exp);
		Monster tmp(hero.GetLvl());
		*this=tmp;}
	void Print()const {
		cout << " -= Monster =-" << endl;
		Enemy::Print();}
};
class Animals:public Enemy {
private:
	Nuggets nuggets;
public:
	Animals() {
		HP = 10;
		Exp = 3;
		type = "Animal";
		nuggets.Add(2);
		strength = 0;}
	Animals(int lvl)  {
		Exp = 3;
		HP =10+ (2 * lvl);
		type = "Animal";
		nuggets.Add(2);
		strength = 0 + (2 * lvl);}
	void Speak(bool isWin)const override {cout << "Oh" << endl;}
	void Dead(Hero& hero) override {
		nuggets.Falling(nuggets.getCount(), hero);
		hero.AddExp(Exp);
		Animals tmp(hero.GetLvl());
		*this = tmp;}
	void Print()const {
		cout << " -= Animal =-" << endl;
		Enemy::Print();}
};
class FinalBoss :public Enemy {
public:
	FinalBoss() {HP = 125;
		type = "Alduin";
		strength = 18;}
	void Speak(bool isWin)const override  {cout << "RAAAAAAAAAAAAAAAAAAAAAAAAAAR" << endl;}
	void Dead(Hero& hero) override{cout << "You win the king of dragons!!! Congratulation!" << endl;}
	void LevelUp()override{}
	void Print()const {
		cout << "\n\t -======== Alduin ========- " << endl;
		cout << "HP: " << HP << endl;
		cout << "Strength: " << strength << endl;}
};

void Enemy::Attack(Hero& hero)const {
	cout << "You have ";
	hero.LossHP(strength);}
void Diamonds::Falling(int count, Hero& hero)const {
	hero.GetInventory().AddDiamonds(count);
	cout << " +" << count << " diamonds" << endl;}
void Coins::Falling(int count, Hero& hero)const {
	cout << "Click click click" << endl;
	cout << " +" << count << " coins" << endl;
	hero.GetInventory().AddCoins(count);}
void Nuggets::Falling(int count, Hero& hero)const {
	cout << "Click click" << endl;
	cout << " +" << count << " nuggets" << endl;
	hero.GetInventory().AddNuggets(count);}
void Wood::CuttingDown(int count, Hero& hero)const {
	cout << "Took Took Took" << endl;
	cout << " +" << count << " wood" << endl;
	hero.GetInventory().AddWood(count);}
void HealthPotion::NewPotion(int count, Hero& hero)const {
	cout << "Bulk Bulk" << endl;
	cout << "+" << count << " health potion" << endl;
	hero.GetInventory().AddHealthPotion(count);}
void StrengthPotion::NewPotion(int count, Hero& hero)const {
	cout << "Bulk Bulk" << endl;
	cout << "+" << count << " strength potion" << endl;
	hero.GetInventory().AddStrengthPotion(count);}

class Shop {
	HealthPotion healthPotion;
	StrengthPotion strengthPotion;
	int healthRecoveryCount;
public:
	Shop() {
		healthPotion.Add(7);
		strengthPotion.Add(2);
		healthRecoveryCount = 2;}
	Shop(int hpC,int spC, int hrC) {
		healthPotion.Add(hpC);
		strengthPotion.Add(spC);
		healthRecoveryCount = hrC;}
	void Print()const {
		cout << " -==== SHOP ====-" << endl;
		cout << "Health potion: " << healthPotion.getCount() << "\t\t\tCost: " << healthPotion.getCost()<<endl;
		cout << "Strength potion: " << strengthPotion.getCount() << "\t\t\tCost: " << strengthPotion.getCost() << endl;
		cout << "Remainder of full health recovery: " << healthRecoveryCount<<"\tCost: 10" << endl;}
	int GetCountHealthPotion() {return healthPotion.getCount();}
	int GetCountStrengthPotion() {return strengthPotion.getCount();}
	int GetHealthRecoveryCount() {return healthRecoveryCount;}
	void SellHealthPotion(Hero& hero) {
		if (healthPotion.getCount() > 0 && hero.GetInventory().getMoney() - healthPotion.getCost() >= 0) {
			healthPotion.NewPotion(1, hero);
			healthPotion.Sub(1);
			hero.GetInventory().RemoveMoney(healthPotion.getCost());}
		else {
			if (healthPotion.getCount() == 0) {cout << "No health potion" << endl;}
			else { cout << "Not enough money" << endl; }}}
	void SellStrengthPotion(Hero& hero) {
		if (strengthPotion.getCount() > 0 && hero.GetInventory().getMoney()- strengthPotion.getCost() >=0){
			strengthPotion.NewPotion(1, hero);
			strengthPotion.Sub(1);
			hero.GetInventory().RemoveMoney(strengthPotion.getCost());}
		else {
			if (strengthPotion.getCount() == 0) {cout << "No strength potion" << endl;}
			else{ cout << "Not enough money" << endl; }}}
	void BuyWood( Hero& hero)const {
		if (hero.GetInventory().getWoodCount() > 0) {
			cout << " +" << (hero.GetInventory().getWoodCount() * hero.GetInventory().getWoodCost()) << " money" << endl;
			hero.GetInventory().AddMoney(hero.GetInventory().getWoodCount()* hero.GetInventory().getWoodCost());
			hero.GetInventory().RemoveWood(hero.GetInventory().getWoodCount());}
		else {cout << "You have not enough wood"<<endl;}}
	void BuyDiamonds(Hero& hero)const {
		if (hero.GetInventory().getDaimondsCount() > 0) {
			cout << " +" << (hero.GetInventory().getDaimondsCost() * hero.GetInventory().getDaimondsCount()) << " money" << endl;
			hero.GetInventory().AddMoney(hero.GetInventory().getDaimondsCost() * hero.GetInventory().getDaimondsCount());
			hero.GetInventory().RemoveDiamonds(hero.GetInventory().getDaimondsCount());}
		else {cout << "You have not enough daimonds" << endl;}}
	void BuyCoins(Hero& hero)const {
		if (hero.GetInventory().getCoinsCount() > 0) {
			cout << " +" << (hero.GetInventory().getCoinsCost() * hero.GetInventory().getCoinsCount()) << " money" << endl;
			hero.GetInventory().AddMoney(hero.GetInventory().getCoinsCost() * hero.GetInventory().getCoinsCount());
			hero.GetInventory().RemoveCoins(hero.GetInventory().getCoinsCount());}
		else {cout << "You have not enough coins" << endl;}}
	void BuyNuggets(Hero& hero)const {
		if (hero.GetInventory().getNuggetsCount() > 0) {
			cout << " +" << (hero.GetInventory().getNuggetsCost() * hero.GetInventory().getNuggetsCount())<< " money" << endl;
			hero.GetInventory().AddMoney(hero.GetInventory().getNuggetsCost() * hero.GetInventory().getNuggetsCount());
			hero.GetInventory().RemoveNuggets(hero.GetInventory().getNuggetsCount());}
		else {cout << "You have not enough nuggets" << endl;}}
	void FullHealthRecovery(Hero& hero) {
		if (hero.GetMaxHP() - hero.GetHP() != 0) {
			hero.AddHP(hero.GetMaxHP() - hero.GetHP());
			healthRecoveryCount--;
			hero.GetInventory().RemoveMoney(10);}
		else {cout << "You have full HP" << endl;}}
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
			switch (choise){
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
				break;}
			if (choise == 0) {
				char ch;
				do{
					cout << "Remember, if you leave the store, you will have to wait for the next store on the way." << endl;
					cout << "Enter [+] to leave or [-] to continue shopping: ";
					cin >> ch;
					if (ch == '+') {
						cout << "You leave the store" << endl;
						break;}
					else if (ch == '-') {
						choise = 9;
						break;}
					else {
						cout << "Enter right value!!!" << endl;
						continue;}
				} while (ch!=0);}}
		else {
			cout << "Enter right value!!!" << endl;
			continue;}
	}while (choise != 0);}
bool Fight(Enemy& enemy, Hero& hero) {
	bool IsHeroAlive=true;
	char choise;
	if (hero.GetInventory().GetHealthPotionCount() != 0 || hero.GetInventory().GetStrengthPotionCount() != 0) {
		cout << " Enter [+] to use {Health potion}, [-] to use {Strength potion} or [0] to skip: ";
		cin >> choise;
		if (choise == '+') { hero.GetNewHP(); }
		else if (choise == '-') { hero.GetNewStrength(); }}
	cout << endl;
	cout << "\n\tThe fight started!!!\n" << endl;
	while (IsHeroAlive ) {
		hero.Attack(enemy);
		cout << endl;
		if (enemy.GetHP()<= 0) {
			hero.Speak(IsHeroAlive);
			enemy.Speak(!IsHeroAlive);	
			cout << "\n"<<enemy.GetType()<< " is dead" << endl;
			enemy.Dead(hero);
			return true;}
		enemy.Print();
		cout << endl;
		if(enemy.GetStrength()!=0){
			do {
				cout << "Enemy attacking. Where will you dodge to the right(Enter [R]) or to the left(Enter [L])?" << endl;
				cout << "Enter your choise: ";
				cin >> choise;
				if (choise != 'R' && choise != 'L') {cout << "Enter right value!" << endl;}
				else { break; }
			} while (choise != 0);
			int random = (rand() % 2 + 1);//1 - right		2 - left
			cout << endl;
			if (random == 1 && choise == 'R') { enemy.Attack(hero); }
			else if (random == 1 && choise == 'L') {cout << "You dodged successfully" << endl;}
			else if (random == 2 && choise == 'L') {enemy.Attack(hero);}
			else if (random == 2 && choise == 'R') {cout << "You dodged successfully" << endl;}
			if (hero.GetHP() <= 0) {
				IsHeroAlive = false;
				hero.Speak(IsHeroAlive);
				enemy.Speak(!IsHeroAlive);
				return hero.Dead();}
			cout << endl;
			hero.Print();
			cout << endl;}
		if(hero.GetInventory().GetHealthPotionCount()!=0||hero.GetInventory().GetStrengthPotionCount()!=0){
			cout << " Enter [+] to use {Health potion}, [-] to use {Strength potion} or [0] to skip: ";
			cin >> choise;
			cout << endl;
			if (choise == '+') {hero.GetNewHP();}
			else if (choise == '-') {hero.GetNewStrength();}}}}
static int position;
void Map( Dragon& dragon1, Dragon& dragon2, Dragon& dragon3) {
	cout << "Curent position: " << position << endl;
	if(dragon1.GetIsAlive()){
		if(position<=45){ cout << "Distance to the next shop: " << 45 - position << endl; }
		else {cout << "Distance to the next shop: " << 95 - position << endl;}
		cout << "Distance to the next dragon: "<<50-position << endl;}
	else if (dragon2.GetIsAlive()) {
		if (position <= 95) {cout << "Distance to the next shop: " << 95 - position << endl;}
		else {cout << "Distance to the next shop: " << 145 - position << endl;}
		cout << "Distance to the next dragon: " << 100 - position << endl;}
	else if (dragon3.GetIsAlive()) {
		if (position <= 145) { cout << "Distance to the next shop: " << 145 - position << endl; }
		else { cout << "Distance to the next shop: " << 195 - position << endl; }
		cout << "Distance to the next dragon: " << 150 - position << endl;}
	else {
		if (position <= 195) { cout << "Distance to the next shop: " << 195 - position << endl; }
		else { cout << "No more shop"<< endl; }
		cout << "Distance to the next shop: " << 195 - position << endl;
		cout << "Distance to the final boss: " << 200 - position << endl;}}

void SaveGame(Hero& hero, Dragon& dragon1, Dragon& dragon2, Dragon& dragon3, Shop& shop, Wood& wood ) {
	ofstream file("savegame.bin", ofstream::out | ofstream::trunc);
	if (file.is_open()) {
		file << hero.GetExp() << endl;
		file << hero.GetHP() << endl;
		file << hero.GetStrength() << endl;
		file << hero.GetLvl() << endl;
		file << hero.GetInventory().getCoinsCount() << endl;
		file << hero.GetInventory().getDaimondsCount() << endl;
		file << hero.GetInventory().getNuggetsCount() << endl;
		file << hero.GetInventory().getMoney()<< endl;
		file << hero.GetInventory().GetHealthPotionCount() << endl;
		file << hero.GetInventory().GetStrengthPotionCount() << endl;
		file << hero.GetInventory().getWoodCount()<< endl;
		file << dragon1.GetName() << endl;
		file << dragon1.GetIsAlive() << endl;
		file << dragon2.GetName() << endl;
		file << dragon2.GetIsAlive() << endl;
		file << dragon3.GetName() << endl;
		file << dragon3.GetIsAlive() << endl;
		file << shop.GetCountHealthPotion() << endl;
		file << shop.GetCountStrengthPotion() << endl;
		file << shop.GetHealthRecoveryCount() << endl;
		file << position << endl;
		file << wood.getCount() << endl;
		file.close();
		cout << "Game saved." << endl;}
	else {cout << "Could not open file for writing." << endl;}}
void LoadGame(Hero& hero, Dragon& dragon1, Dragon& dragon2, Dragon& dragon3, Shop& shop,  Monster& monster, Animals& animal, Wood& wood) {
	ifstream file("savegame.bin");
	if (!file.is_open()) {
		cout << "The game is not saved. Start of a new game..."<<endl;
		return ;}
	file.seekg(0, ios::end);
	if (file.tellg() == 0) {
		cout << "No saved game. Start of a new game..."<<endl;
		file.close();
		return;}
	file.seekg(0, ios::beg);
	int exp, heroHP,heroStr, heroLvl,coinsC,nuggetsC,diamC,money,hpC,spC,woodC,hrC,pos;
	file >> exp;
	file >> heroHP;
	file >> heroStr;
	file >> heroLvl;
	file >> coinsC;
	file >> diamC;
	file >> nuggetsC;
	file >> money;
	file >> hpC;
	file >> spC;
	file >> woodC;
	Hero herotmp{ heroLvl,  heroHP, exp, diamC, coinsC, nuggetsC,  money,  hpC,  spC,  woodC };
	hero = herotmp;
	hero.SetStrength(heroStr);
	string d1Name, d2Name,d3Name;
	bool d1IsAlive, d2IsAlive, d3IsAlive;
	file >> d1Name;
	file >> d1IsAlive;
	file >> d2Name;
	file >> d2IsAlive;
	file >> d3Name;
	file >> d3IsAlive;
	Dragon dragon1tmp{ d1Name,heroLvl,d1IsAlive }, dragon2tmp{ d2Name,heroLvl,d2IsAlive }, dragon3tmp{ d3Name,heroLvl,d3IsAlive };
	dragon1 = dragon1tmp;
	dragon2 = dragon2tmp;
	dragon3 = dragon3tmp;
	file >> hpC;
	file >> spC;
	file >> hrC;
	Shop sh{ hpC ,spC ,hrC };
	shop = sh;
	file >> pos;
	file >> woodC;
	position = pos;
	wood.SetWood(woodC);
	Monster m(heroLvl);
	Animals a(heroLvl);
	monster = m;
	animal = a;
	file.close();}

void MainMenu(Hero& hero, Dragon& dragon1, Dragon& dragon2, Dragon& dragon3, Shop& shop,  Monster& monster, Animals& animal, Wood& wood, FinalBoss& fb);
void GameMenu(Hero& hero, Dragon& dragon1, Dragon& dragon2, Dragon& dragon3, Shop& shop, Monster& monster, Animals& animal, Wood& wood, FinalBoss& fb) {
	char menu;
	do {
		cout << "Enter 1 to save game" << endl;
		cout << "Enter 2 to exit game" << endl;
		cout << "Enter 0 to exit menu" << endl;
		cout << "Enter your choise: ";
		cin >> menu;
		if (menu == '1') {SaveGame(hero, dragon1, dragon2, dragon3, shop, wood);}
		else if (menu == '2') {MainMenu(hero, dragon1, dragon2, dragon3, shop,  monster, animal,wood,fb);}
		else if (menu != '0') {
			cout << "Enter right value!" << endl;
			continue;}
	} while (menu!='0');}
void Game(Dragon& dragon1, Dragon& dragon2, Dragon& dragon3, Monster& monster, Animals& animal, Hero& hero, Wood& wood,Shop& shop, FinalBoss& king) {
	char move;
	int random;
	bool isAlive=true;
	do {
		if(position%25==0){ 
			if (hero.GetHP()+8 <= hero.GetMaxHP()) {hero.AddHP(8);}
			else if(hero.GetMaxHP()- hero.GetHP()<8){hero.AddHP(hero.GetMaxHP() - hero.GetHP());}}
		if (position % 50 == 0) {
			cout << "You meet dragon! Get Ready!" << endl;
			hero.Print();
			if (dragon1.GetIsAlive()) {
				cout << "Your enemy: ";
				dragon1.Print();
				isAlive = Fight(dragon1, hero);}
			else if (dragon2.GetIsAlive()) {
				cout << "Your enemy: ";
				dragon2.Print();
				isAlive = Fight(dragon2, hero);}
			else if (dragon3.GetIsAlive()) {
				cout << "Your enemy: ";
				dragon3.Print();
				isAlive = Fight(dragon3, hero);}
			else{cout << "Ooooh! This is the king of dragons!!!" << endl;
				isAlive=Fight(king, hero);}}
		else if ((position >= 1 && position <= 10) || (position >= 51 && position <= 60) || (position >= 101 && position <= 110) || (position >= 151 && position <= 160)) {
			if (wood.getCount() > 0) {				
				random = rand() % 4;
				if (random == 0) { cout << "Nothing..." << endl; }
				else{ cout << "Cutting tree..." << endl;
					wood.CuttingDown(random, hero);
					wood.Sub(random);}}}
		else if (position == 45 || position == 95 || position == 145 || position == 195) {Store(shop,hero);}
		else {
			random = rand() % 3 + 1;//1-wood 2-animals 3-monsters
			if (random == 1 && wood.getCount() == 0) { random++; }
			cout << endl;
			switch (random) {
			case 1:
				random = rand() % 4;
				if (random == 0) { cout << "Nothing..." << endl; }
				else{cout << "Cutting tree..." << endl;
					wood.CuttingDown(random, hero);
					wood.Sub(random);}
				break;
			case 2:
				cout << "\tYou meet Animal! Get ready!\n" << endl;
				hero.Print();
				cout << endl;
				animal.Print();
				do{ cout << "\n Fight the enemy(Enter [+]) or go around him(Enter [-])? Enter your choise: ";
					cin >> move;
					if (move == '+') {
						isAlive = Fight(animal, hero);
						break;}
					else if (move != '-') { cout << " Enter right value!" << endl; }
				} while (move!='-');
				break;
			case 3:
				cout << "\tYou meet Monster! Get ready!\n" << endl;
				hero.Print();
				cout << endl;
				monster.Print();
				do {cout << "\n Fight the enemy(Enter [+]) or go around him(Enter [-])? Enter your choise: ";
					cin >> move;
					if (move == '+') { isAlive = Fight(monster, hero); 
					break;}
					else if (move != '-') { cout << " Enter right value!" << endl; }
				} while (move != '-');
				break;}}
		if (!isAlive) { return; }
		if (hero.GetExp() >= hero.GetExpToNextLvl()) {
			dragon1.LevelUp();
			dragon2.LevelUp();
			dragon3.LevelUp();
			monster.LevelUp();
			animal.LevelUp();
			hero.LevelUp();}
		do {cout << "\nEnter [G] to visit game menu" << endl;
			cout << "Enter [M] to see map" << endl;
			cout << "Enter [S] to make next step and move" << endl;
			cout << "Your choise: ";
			cin >> move;
			cout << endl;
			if (move=='G'){	GameMenu(hero, dragon1, dragon2, dragon3, shop, monster,animal,wood,king);}
			else if (move=='M') {Map(dragon1, dragon2, dragon3);}
			else if (move == 'S') {
				cout << "Moving..." << endl;
				++position;}
			else {	cout << "Enter right value! (It's important to write letters in upper case)" << endl;}
		} while (move!='S');
	} while (position != 0&&position<=200);}
void MainMenu(Hero& hero, Dragon& dragon1, Dragon& dragon2, Dragon& dragon3, Shop& shop, Monster& monster, Animals& animal, Wood& wood, FinalBoss& fb) {
	int menu;
	do{ cout << "Enter 1 to start new game" << endl;
		cout << "Enter 2 to load game" << endl;
		cout << "Enter 0 to exit" << endl;
		cout << "Enter your choise: ";
		cin >> menu;
		if (menu == 1) {
			cout << "\n\tGame started\n" << endl;
			cout << " \nDear hero, glad to see you. \nAre you ready for adventure?" << endl;
			cout << " Heh. You don't really have a choice. " << endl;
			cout << " An order came from the king to kill the dragon Alduin, which often attacks the kingdom. " << endl;
			cout << " He lives far enough away that ordinary people can't reach him, but you're not ordinary here, are you? " << endl;
			cout << " On the way to his nest there are many other dangers that your predecessors could not pass through - losers. " << endl;
			cout << " Do you think you can handle it? Here I doubt. Well, I'm just kidding, let's continue. " << endl;
			cout << " We can thank those weaklings at least for drawing the map of the way to Alduin's lair. " << endl;
			cout << " Nests of other dragons and shops along the way will be marked here, and you will see everything else on the spot. " << endl;
			cout << " On the way you will come across wood and the more you collect, the better. " << endl;
			cout << " Gold can drop from the animals that I recommend being on guard with, from monsters and dragons, and sometimes some surprises are possible. Well, that's how lucky it is. " << endl;
			cout << " Also, in battles you gain experience, which makes you stronger, but remember that the further you go and the stronger you become, the more dangerous your enemies will be. " << endl;
			cout << " Get stronger, act smart and don't stay behind. I wish you luck, come back victorious. " << endl;
			Game(dragon1, dragon2, dragon3, monster, animal, hero, wood, shop, fb);}
		else if (menu == 2) {
			cout << "\n\tLoading the game\n" << endl;
			LoadGame(hero, dragon1, dragon2, dragon3, shop, monster, animal, wood);
			cout << "\n\tGame started\n" << endl;
			Game(dragon1, dragon2, dragon3, monster, animal, hero, wood, shop, fb);}
		else if (menu != 0) { cout << "Enter right value!" << endl; }
		else {	break; }} while (menu!=0);}

int main(){
	srand(time(0));
	position  = 1;
	Hero h;
	Shop s;
	Dragon dragon1{ "d1" };
	Dragon dragon2{ "d2" };
	Dragon dragon3{ "d3" };
	Monster m;
	Animals a;
	Wood wood;
	wood.SetWood(150);
	FinalBoss king;
	//MainMenu(h, dragon1, dragon2, dragon3, s,  m, a, wood, king);
}