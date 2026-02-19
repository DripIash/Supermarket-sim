#include <iostream>
#include <string>
#include <vector>
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
	CART,					// 12
	EMPTY = -1
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

// list of grocery items available
vector<Item> shopContents = {
		{"NULL", ItemSize::TINY, 0.00, GroceryType::EMPTY },
		{"Apple", ItemSize::SMALL, 0.75, GroceryType::FRUIT_VEG},
		{"Banana", ItemSize::SMALL, 1.00, GroceryType::FRUIT_VEG},
		{"Potato", ItemSize::SMALL, 0.50, GroceryType::FRUIT_VEG},
		{"Onion", ItemSize::SMALL, 0.45, GroceryType::FRUIT_VEG},
		{"Tomato", ItemSize::SMALL, 0.50, GroceryType::FRUIT_VEG},
		{"Milk", ItemSize::LARGE, 5.55, GroceryType::FRIDGE_FREEZER},
		{"Eggs", ItemSize::LARGE, 6.50, GroceryType::FRIDGE_FREEZER},
		{"Ice Cream", ItemSize::LARGE, 0.50, GroceryType::FRIDGE_FREEZER},
		{"Butter", ItemSize::SMALL, 0.45, GroceryType::FRIDGE_FREEZER},
		{"Beef Mince", ItemSize::LARGE, 0.50, GroceryType::FRIDGE_FREEZER},
		{"Cheese", ItemSize::MEDIUM, 7.50, GroceryType::FRIDGE_FREEZER},
		{"Chicken", ItemSize::LARGE, 5.50, GroceryType::FRIDGE_FREEZER},
		{"Bread", ItemSize::LARGE, 4.50, GroceryType::BAKERY_BREAKFAST},
		{"Weetbix", ItemSize::LARGE, 5.00, GroceryType::BAKERY_BREAKFAST},
		{"Apple Juice", ItemSize::LARGE, 4.00, GroceryType::BAKERY_BREAKFAST},
		{"Muesli Bar", ItemSize::TINY, 0.50, GroceryType::BAKERY_BREAKFAST},
		{"Porridge", ItemSize::LARGE, 5.50, GroceryType::BAKERY_BREAKFAST},
		{"Instant Coffee", ItemSize::MEDIUM, 15.5, GroceryType::TEA_COFFEE},
		{"Coffee Sachet", ItemSize::TINY, 0.80, GroceryType::TEA_COFFEE},
		{"Tea", ItemSize::MEDIUM, 7.00, GroceryType::TEA_COFFEE},
		{"Milo", ItemSize::LARGE, 17.5, GroceryType::TEA_COFFEE},
		{"Long Life Milk", ItemSize::MEDIUM, 2.00, GroceryType::TEA_COFFEE},
		{"Sugar", ItemSize::MEDIUM, 2.50, GroceryType::TEA_COFFEE},
		{"Shapes", ItemSize::MEDIUM, 2.00, GroceryType::BISCUITS_CHIPS},
		{"Tim Tam", ItemSize::MEDIUM, 6.00, GroceryType::BISCUITS_CHIPS},
		{"Smiths", ItemSize::LARGE, 4.00, GroceryType::BISCUITS_CHIPS},
		{"Twisties", ItemSize::LARGE, 4.00, GroceryType::BISCUITS_CHIPS},
		{"Oreos", ItemSize::SMALL, 3.00, GroceryType::BISCUITS_CHIPS},
		{"Coke", ItemSize::LARGE, 5.00, GroceryType::DRINKS_CONFECTIONARY},
		{"Chocolate Block", ItemSize::SMALL, 7.00, GroceryType::DRINKS_CONFECTIONARY},
		{"Mars Bar", ItemSize::TINY, 1.50, GroceryType::DRINKS_CONFECTIONARY},
		{"Box Water", ItemSize::XL, 4.50, GroceryType::DRINKS_CONFECTIONARY},
		{"Allens Party Mix", ItemSize::SMALL, 4.00, GroceryType::DRINKS_CONFECTIONARY},
		{"Big Flour_Bag", ItemSize::XL, 15.00, GroceryType::BAKING_SAUCES_SPICES},
		{"Mayo", ItemSize::MEDIUM, 6.00, GroceryType::BAKING_SAUCES_SPICES},
		{"Breadcrumbs", ItemSize::MEDIUM, 2.30, GroceryType::BAKING_SAUCES_SPICES},
		{"Salt", ItemSize::MEDIUM, 2.50, GroceryType::BAKING_SAUCES_SPICES},
		{"Chilli Flakes", ItemSize::TINY, 3.00, GroceryType::BAKING_SAUCES_SPICES},
		{"Pasta", ItemSize::MEDIUM, 2.95, GroceryType::PASTA_RICE_NOODLES},
		{"Rice", ItemSize::LARGE, 12.00, GroceryType::PASTA_RICE_NOODLES},
		{"Instant Noodles", ItemSize::LARGE, 3.95, GroceryType::PASTA_RICE_NOODLES},
		{"Taco Kit", ItemSize::LARGE, 5.00, GroceryType::PASTA_RICE_NOODLES},
		{"Pasta Sauce", ItemSize::MEDIUM, 4.00, GroceryType::PASTA_RICE_NOODLES},
		{"Beetroot Tin", ItemSize::MEDIUM, 3.80, GroceryType::CANNED_FOOD},
		{"Beans", ItemSize::MEDIUM, 3.00, GroceryType::CANNED_FOOD},
		{"Soup", ItemSize::MEDIUM, 4.50, GroceryType::CANNED_FOOD},
		{"Tuna", ItemSize::TINY, 2.00, GroceryType::CANNED_FOOD},
		{"Pineapple Tin", ItemSize::MEDIUM, 3.90, GroceryType::CANNED_FOOD},
		{"Cat Biscuits", ItemSize::XL, 13.90, GroceryType::PET_FOOD},
		{"Dog Mince", ItemSize::LARGE, 8.50, GroceryType::PET_FOOD},
		{"Cat Food Tin", ItemSize::MEDIUM, 2.70, GroceryType::PET_FOOD},
		{"Cat Litter", ItemSize::XL, 18.00, GroceryType::PET_FOOD},
		{"Schmackos", ItemSize::LARGE, 17.00, GroceryType::PET_FOOD},
		{"Tissues", ItemSize::LARGE, 3.00, GroceryType::CLEANING_BATHROOM},
		{"Toilet Paper", ItemSize::XL, 7.00, GroceryType::CLEANING_BATHROOM},
		{"Laundry Detergent", ItemSize::XL, 20.00, GroceryType::CLEANING_BATHROOM},
		{"Dishwashing Liquid", ItemSize::LARGE, 7.50, GroceryType::CLEANING_BATHROOM},
		{"Windex", ItemSize::MEDIUM, 4.00, GroceryType::CLEANING_BATHROOM}
};

struct Cart {
	CartType type = CartType::NONE;
	vector<Item> items;
	float totalPrice = 0;
	int storage;
	bool paidFor = false;

	// runs when 1-11 is entered in main, shows items in aisle and allows to add to cart
	void EnterAisle(int aisle){
		// fetch the items in the aisle
		vector<Item> aisleContents;
		for (Item each : shopContents) {
			if (each.location == aisle)
				aisleContents.push_back(each);
		}

		Input input;
		Item itemChosen;
		bool leave = false;

		cin.ignore(); // so that getline doesn't take \n as input
		// main loop
		while (!leave) {
			itemChosen = shopContents[0]; // initialise/reset to dummy
			// prints available items
			cout << "\n-- Items in aisle " << aisle;
			for (Item each : aisleContents) cout << " - " << each.name;
			// prompts user to view an item or leave the aisle
			cout << "\n-- View which item? (enter exact item name or enter exit)" << endl;
			getline(cin, input.choice);

			if (input.EqualsExit()) break; // leave the aisle
			// matches input to the item name (case sensitive)
			for (Item each : aisleContents) {
				if (each.name == input.choice)
					itemChosen = each;
			}
			if (itemChosen.location != -1) // skips if dummy
				InspectItem(itemChosen);
		}
	}

	// what happens if you pick up an item and look at it
	void InspectItem(Item item){
		Input input;
		// show info and prompt if they wanna add it to cart
		cout << "\n|| " << item.name << ": Size - " << item.size << ", Price - $" << item.price;
		cout << "\n-- Add to cart?" << endl;
		getline(cin, input.choice);

		// if they say yes
		if (input.EqualsYes())
			// if theres enough room
			if (item.size <= (storage))
				AddToCart(item);
			// not enough room
			else {
				cout << "\n-- Not enough space in cart. View cart?" << endl;
				cin >> input.choice;
				if (input.EqualsYes())
					ViewCart();
			}
	}

	// add to cart and recalculate total cost and space left in cart
	void AddToCart(Item item){
		items.push_back(item);
		storage -= item.size;
		totalPrice += item.price;
		cout << "-- " << item.name << " added to cart" << endl;
	}

	// remove item from cart
	bool RemoveFromCart(string itemName){
		Item chosenItem;
		bool matchFound = false;
		int index = 0;
		// check if user input matches an item in the cart
		for (Item each : items) {
			if (each.name == itemName) {
				chosenItem = each;
				matchFound = true;
				break;
			}
			index++;
		}

		// if theres a match do the inverse of adding to cart
		if (matchFound) {
			cout << "-- " << items[index].name << " removed from cart" << endl;
			totalPrice -= items[index].price;
			storage += items[index].size;
			items.erase(items.begin() + index);
			return true;
		}
		else return false;
	}

	// print out the cart, stacking identical items and showing as #x-Item
	void PrintCart() {
		bool added;
		vector<pair<Item, int>> quantities; 
		// if cart is empty has different placeholder
		if (items.size() < 1)
			quantities = { {{"NO ITEMS IN CART"}, 0} };
		// adds the first item to cart as palceholder
		else quantities = { {items[0], 0} };

		cout << "\n-- CART: Space left - " << storage << "/" << type << ", Total cost - $" << totalPrice;

		// loop through each item in the cart
		for (Item each : items) {
			added = false;
			// compare it against the running list that has the quantities of each
			for (int i = 0; i < quantities.size(); i++)
				if (quantities[i].first.name == each.name) {
					quantities[i].second += 1;
					added = true;
					break;
				}
			if (!added)
				quantities.push_back({ each, 1 }); // add it to the list if its not already there
		}

		// loop through the list and print
		for (auto i : quantities) {
			if (i.second > 1)
				cout << "\n|| " << i.second << "x-" << i.first.name << ": Size - " << i.first.size << ", Price - $" << i.first.price;
			// if theres only 1 of an item
			else
				cout << "\n|| " << i.first.name << ": Size - " << i.first.size << ", Price - $" << i.first.price;
		}
	}

	// enter cart mode
	void ViewCart(){
		Input input;
		bool exit = false;

		PrintCart();
		
		// ask if user wants to remove an item
		cout << "\n-- Remove an item?" << endl;
		cin.ignore();
		getline(cin, input.choice);
		if (!input.EqualsYes()) // leave cart if answer is no
			return;

		// item removing loop
		cout << "\n-- Remove which item? (enter exact item name or enter exit)" << endl;
		while (!exit) {
			getline(cin, input.choice);
			if (input.EqualsExit())
				break;
			exit = RemoveFromCart(input.choice);
		}
	}
	
	// end shopping, prompts user to remove items from cart if they don't have enough $
	void Checkout(float& money){
		Input input;
		bool exit;

		// shows cart and total
		PrintCart();
		cout << "\n-- For your " << items.size() << " items, the total is $" << totalPrice << ", you have $" << money << endl;
		// if user is broke
		while (money < totalPrice) {
			cout << "\n-- You don't have enough money, remove which item? (enter exact item name)" << endl;
			// loop until an item's exact name is entered
			do {
				getline(cin, input.choice);
			} while (!RemoveFromCart(input.choice)); // doubles as the removing function and the looping condition

			// show cart and total after changes
			PrintCart();
			cout << "\n-- For your " << items.size() << " items, the total is $" << totalPrice << ", you have $" << money << endl;
		}
		money -= totalPrice;
		paidFor = true;
	}
};

// deals with going to aisles, cart, and checkout from the main state
struct MainMenuInput {
	int cartChoice;
	unsigned int locationChoice;

	// sets the cart type
	void SetCart(Cart& cart) {
		switch (cartChoice) {
		case 1: cart.type = CartType::NONE; break;
		case 2: cart.type = CartType::BASKET; break;
		case 3: cart.type = CartType::SMALL_TROLLEY; break;
		case 4: cart.type = CartType::LARGE_TROLLEY; break;
		}
	}

	// runs function for chosen location
	void GoToLocation(Cart& cart, float& money) {
		switch (locationChoice) {
		case 0: cart.Checkout(money); break;
		case 12: cart.ViewCart(); break;
		default: cart.EnterAisle(locationChoice); break;
		}
	}
};

int main() {
	// intro
	cout << "------------------------" << endl;
	cout << "----- Customer Sim -----" << endl;
	cout << "------------------------" << endl;
	// initialise variables
	MainMenuInput input;
	Cart cart;
	float money;

	// set money
	cout << "-- How much money u got? ($)" << endl;
	cin >> money;

	// choose cart
	cout << "\n-- Which cart would you like to use? (1 = none, 2 = basket, 3 = small trolley, 4 = large trolley)" << endl;
	cin >> input.cartChoice;
	input.SetCart(cart);
	cart.storage = cart.type;

	// main loop, stops once the cart is paid for
	do {
		cout << "\n-- Where to next? (Checkout = 0, Aisles = 1-11, View Cart = 12)" << endl;
		cin >> input.locationChoice;
		if (input.locationChoice > 12) continue; // tries again if input is invalid
		input.GoToLocation(cart, money);
	} while (cart.paidFor == false);

	// outro message
	cout << "-- Shopping finished with " << cart.items.size() << " items, $" << money << " remaining" << endl;
	
	cout << "\n---------------END OF SIMULATION--------------" << endl;
}