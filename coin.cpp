#include <iostream>
#include <vector>

int main() {
    int num_of_denom = 4;
    int value_of_denom[] = {1,5,10,25};

    int change_amt;
    std::cout << "Enter change amount: ";
    std::cin >> change_amt;


    std::vector<int> min_coins_used(change_amt + 1, 0);
    std::vector<int> last_coin_used(change_amt + 1, 0);

    int cents = 1;
    while (cents <= change_amt) {
	    int min_coins = cents;
	    int new_coin = 1;
	    int j = 1;

	    while (j < num_of_denom) {
		    if (value_of_denom[j] <= cents) {
			int idx = cents - value_of_denom[j];
		    	
			if (min_coins_used.at(idx)+1 < min_coins) {
				min_coins = min_coins_used.at(idx) + 1;
				new_coin = value_of_denom[j];
			}
		    }
		    j++;
	    }

	    min_coins_used.at(cents) = min_coins;
	    last_coin_used.at(cents) = new_coin;
	    cents++;
    }

    std::cout << "Change amount: " << change_amt << std::endl;
    for (size_t i=0; i<min_coins_used.size(); i++ ) {
	    std::cout << "Min coins used for idx [" << i << "]" << ": " << min_coins_used.at(i) << std::endl;
	    std::cout << "Last coin used for idx (composition) [" << i << "]" << ": " << last_coin_used.at(i) << std::endl << std::endl;
    }
    
    std::cout << "Full composition needed for " <<  change_amt << " cents: ";
    int amt = change_amt;
    while(amt > 0) {
	int coin = last_coin_used.at(amt);
	std::cout << coin << " ";
	amt -= coin;
    }
}
