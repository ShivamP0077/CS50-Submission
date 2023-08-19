def get_cents():
    while True:
        try:
            cash = float(input("Change owed: "))
            if cash >= 0:
                return cash
        except ValueError:
            pass

# Calculate the number of coins to give the customer
def calculate_coins(cents, coin_value):
    count = 0
    while cents >= coin_value:
        cents -= coin_value
        count += 1
    return count

# Main program
cents = int(get_cents() * 100)

quarters = calculate_coins(cents, 25)
cents -= quarters * 25

dimes = calculate_coins(cents, 10)
cents -= dimes * 10

nickels = calculate_coins(cents, 5)
cents -= nickels * 5

pennies = cents

coins = quarters + dimes + nickels + pennies
print(coins)
