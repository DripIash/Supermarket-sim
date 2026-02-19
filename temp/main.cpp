#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// list of aisle names
enum GroceryType {
	CHECKOUT,				// 0
	FRUIT_VEG,				// 1
	FRIDGE_FREEZER,
	BAKERY_BREAKFAST,
	TEA_COFFEE,
	BISCUITS_CHIPS,
	DRINKS_CONFECTIONARY,
	BAKING_SAUCES_SPICES,
	PASTA_RICE_NOODLES,
	CANNED_FOOD,
	PET_FOOD,
	CLEANING_BATHROOM,		// 11
	CART					// 12
};

// the space that each item will take up in the cart
enum ItemSize {
	TINY = 1,
	SMALL = 2,
	MEDIUM = 4,
	LARGE = 8,
	XL = 16
};

// the amount of space in the cart
enum CartType {
	NONE = 16,
	BASKET = 24,
	SMALL_TROLLEY = 48,
	LARGE_TROLLEY = 144
};

// deals with some user input such as yes or no
struct Input {
	string choice;

	// returns true if the entered string is some variation of 'yes'
	bool EqualsYes() {
		if (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes" || choice == "YES")
			return true;
		else return false;
	}

	// returns true if the entered string is some variation of 'exit'
	bool EqualsExit() {
		if (choice == "exit" || choice == "Exit" || choice == "EXIT")
			return true;
		else return false;
	}
};

// grocery item's properties
struct Item {
	string name;
	ItemSize size;
	float price;
	GroceryType location;
};

vector<Item> shopContents = {
		{"NULL", ItemSize::TINY, 0.00, -1}, 
		{"Apple", ItemSize::SMALL, 0.75, 1},
		{"Banana", ItemSize::SMALL, 1.00, 1},
		{"Potato", ItemSize::SMALL, 0.50, 1},
		{"Onion", ItemSize::SMALL, 0.45, 1},
		{"Tomato", ItemSize::SMALL, 0.50, 1},
		{"Milk", ItemSize::LARGE, 5.55, 2},
		{"Eggs", ItemSize::LARGE, 6.50, 2},
		{"Ice Cream", ItemSize::LARGE, 0.50, 2},
		{"Butter", ItemSize::SMALL, 0.45, 2},
		{"Beef Mince", ItemSize::LARGE, 0.50, 2},
		{"Cheese", ItemSize::MEDIUM, 7.50, 2},
		{"Chicken", ItemSize::LARGE, 5.50, 2},
		{"Bread", ItemSize::LARGE, 4.50, 3},
		{"Weetbix", ItemSize::LARGE, 5.00, 3},
		{"Apple Juice", ItemSize::LARGE, 4.00, 3},
		{"Muesli Bar", ItemSize::TINY, 0.50, 3},
		{"Porridge", ItemSize::LARGE, 5.50, 3},
		{"Instant Coffee", ItemSize::MEDIUM, 15.5, 4},
		{"Coffee Sachet", ItemSize::TINY, 0.80, 4},
		{"Tea", ItemSize::MEDIUM, 7.00, 4},
		{"Milo", ItemSize::LARGE, 17.5, 4},
		{"Long Life Milk", ItemSize::MEDIUM, 2.00, 4},
		{"Sugar", ItemSize::MEDIUM, 2.50, 4},
		{"Shapes", ItemSize::MEDIUM, 2.00, 5},
		{"Tim Tam", ItemSize::MEDIUM, 6.00, 5},
		{"Smiths", ItemSize::LARGE, 4.00, 5},
		{"Twisties", ItemSize::LARGE, 4.00, 5},
		{"Oreos", ItemSize::SMALL, 3.00, 5},
		{"Coke", ItemSize::LARGE, 5.00, 6},
		{"Chocolate Block", ItemSize::SMALL, 7.00, 6},
		{"Mars Bar", ItemSize::TINY, 1.50, 6},
		{"Box Water", ItemSize::XL, 4.50, 6},
		{"Allens Party Mix", ItemSize::SMALL, 4.00, 6},
		{"Big Flour_Bag", ItemSize::XL, 15.00, 7},
		{"Mayo", ItemSize::MEDIUM, 6.00, 7},
		{"Breadcrumbs", ItemSize::MEDIUM, 2.30, 7},
		{"Salt", ItemSize::MEDIUM, 2.50, 7},
		{"Chilli Flakes", ItemSize::TINY, 3.00, 7},
		{"Pasta", ItemSize::MEDIUM, 2.95, 8},
		{"Rice", ItemSize::LARGE, 12.00, 8},
		{"Instant Noodles", ItemSize::LARGE, 3.95, 8},
		{"Taco Kit", ItemSize::LARGE, 5.00, 8},
		{"Pasta Sauce", ItemSize::MEDIUM, 4.00, 8},
		{"Beetroot Tin", ItemSize::MEDIUM, 3.80, 9},
		{"Beans", ItemSize::MEDIUM, 3.00, 9},
		{"Soup", ItemSize::MEDIUM, 4.50, 9},
		{"Tuna", ItemSize::TINY, 2.00, 9},
		{"Pineapple Tin", ItemSize::MEDIUM, 3.90, 9},
		{"Cat Biscuits", ItemSize::XL, 13.90, 10},
		{"Dog Mince", ItemSize::LARGE, 8.50, 10},
		{"Cat Food Tin", ItemSize::MEDIUM, 2.70, 10},
		{"Cat Litter", ItemSize::XL, 18.00, 10},
		{"Schmackos", ItemSize::LARGE, 17.00, 10},
		{"Tissues", ItemSize::LARGE, 3.00, 11},
		{"Toilet Paper", ItemSize::XL, 7.00, 11},
		{"Laundry Detergent", ItemSize::XL, 20.00, 11},
		{"Dishwashing Liquid", ItemSize::LARGE, 7.50, 11},
		{"Windex", ItemSize::MEDIUM, 4.00, 11},
};

struct Cart {
	CartType type = CartType::NONE;
	vector<Item> items;
	float totalPrice = 0;
	int storage;
	bool paidFor = false;

	void EnterAisle(int aisle){
		vector<Item> aisleContents;
		for (Item each : shopContents) {
			if (each.location == aisle)
				aisleContents.push_back(each);
		}

		Input input;
		Item itemChosen = shopContents[0];
		bool leave = false;

		while (!leave) {
			cout << "\n-- Items in aisle " << aisle;
			for (Item each : aisleContents) cout << " - " << each.name;
			cout << "\n-- View which item? (enter exact item name or enter exit)" << endl;
			getline(cin, input.choice);

			if (input.EqualsExit()) break;
			for (Item each : aisleContents) {
				if (each.name == input.choice)
					itemChosen = each;
			}
			if (itemChosen.location != -1)
				InspectItem(itemChosen);
			itemChosen = shopContents[0];
		}

		return;
	}

	void InspectItem(Item item){
		Input input;
		cout << "\n|| " << item.name << ": Size - " << item.size << ", Price - $" << item.price;
		cout << "\n-- Add to cart?" << endl;
		getline(cin, input.choice);

		if (input.EqualsYes())
			if (item.size <= (storage))
				AddToCart(item);
			else {
				cout << "\n-- Not enough space in cart. View cart?" << endl;
				cin >> input.choice;
				if (input.EqualsYes())
					ViewCart();
			}
	}

	void AddToCart(Item item){
		items.push_back(item);
		storage -= item.size;
		totalPrice += item.price;
		cout << "-- " << item.name << " added to cart" << endl;
	}

	bool RemoveFromCart(string itemName){
		Item chosenItem;
		bool matchFound = false;
		int index = 0;
		for (Item each : items) {
			if (each.name == itemName) {
				chosenItem = each;
				matchFound = true;
				break;
			}
			index++;
		}

		if (matchFound) {
			cout << "-- " << items[index].name << " removed from cart" << endl;
			totalPrice -= items[index].price;
			storage += items[index].size;
			items.erase(items.begin() + index);
			return true;
		}
		else return false;
	}

	void PrintCart() {
		unordered_map<Item, int> quantities;

		cout << "\n-- CART: Space left - " << storage << "/" << type << ", Total cost - $" << totalPrice;
		for (Item each : items) {
			for (auto i : quantities) {
				if (i.first.name == each.name) {
					i.second += 1;
				}
				else quantities.insert(each.name, 1);
			}
		}

		for (auto i : quantities) {
			if (i.second > 1)
				cout << "\n|| " << i.second << "X " << i.first.name << ": Size - " << i.first.size << ", Price - $" << i.first.price;
			else
				cout << "\n|| " << i.first.name << ": Size - " << i.first.size << ", Price - $" << i.first.price;
		}
	}

	void ViewCart(){
		Input input;
		bool exit = false;

		PrintCart();
		
		cout << "\n-- Remove an item?" << endl;
		getline(cin, input.choice);
		if (!input.EqualsYes())
			return;

		while (!exit) {
			cout << "\n-- Remove which item? (enter exact item name or enter exit)" << endl;
			cin >> input.choice;
			if (input.EqualsExit())
				break;
			exit = RemoveFromCart(input.choice);
		}
	}

	void Checkout(float& money){
		Input input;
		bool exit;

		PrintCart();
		cout << "\n-- For your " << items.size() << " items, the total is $" << totalPrice << ", you have $" << money << endl;
		while (money < totalPrice) {
			cout << "\n-- You don't have enough money, remove which item? (enter exact item name)" << endl;
			getline(cin, input.choice);

			exit = false;
			while (!exit)
				exit = RemoveFromCart(input.choice);

			PrintCart();
			cout << "\n-- For your " << items.size() << " items, the total is $" << totalPrice << ", you have $" << money << endl;
		}
		money -= totalPrice;
		paidFor = true;
	}
};

struct MainMenuInput {
	int cartChoice;
	unsigned int locationChoice;

	void SetCart(Cart& cart) {
		switch (cartChoice) {
		case 1: cart.type = CartType::NONE; break;
		case 2: cart.type = CartType::BASKET; break;
		case 3: cart.type = CartType::SMALL_TROLLEY; break;
		case 4: cart.type = CartType::LARGE_TROLLEY; break;
		}
	}

	void GoToLocation(Cart& cart, float& money) {
		switch (locationChoice) {
		case 0: cart.Checkout(money); break;
		case 12: cart.ViewCart(); break;
		default: cart.EnterAisle(locationChoice); break;
		}
	}
};

int main() {
	cout << "------------------------" << endl;
	cout << "----- Customer Sim -----" << endl;
	cout << "------------------------" << endl;
	Cart cart;
	MainMenuInput input;
	float money;

	cout << "-- How much money u got? ($)" << endl;
	cin >> money;

	cout << "\n-- Which cart would you like to use? (1 = none, 2 = basket, 3 = small trolley, 4 = large trolley)" << endl;
	cin >> input.cartChoice;
	input.SetCart(cart);
	cart.storage = cart.type;

	do {
		cout << "\n-- Where to next? (Checkout = 0, Aisles = 1-11, View Cart = 12)" << endl;
		cin >> input.locationChoice;
		if (input.locationChoice > 12) continue;
		input.GoToLocation(cart, money);
	} while (cart.paidFor == false);

	cout << "-- Shopping finished with " << cart.items.size() << " items, $" << money << " remaining" << endl;
	
	cout << "\n---------------CODE FINSIHED--------------" << endl;
}