from cs50 import get_string

word = get_string("Greeting: ")
word = word.lower()

if "hello" in word:
    print("$0")
elif word[0:1] == 'h':
    print("$20")
else:
    print("$100")

