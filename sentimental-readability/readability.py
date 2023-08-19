def count_words(text):
    count = 0
    for char in text:
        if char == ' ':
            count += 1
    return count + 1

def count_sentence(text):
    count = 0
    for char in text:
        if char == '!' or char == '.' or char == '?':
            count += 1
    return count

def count_letters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count

text = input("Text: ")
letters = count_letters(text)
sentences = count_sentence(text)
words = count_words(text)

L = (letters / words) * 100
S = (sentences / words) * 100
grade = round(0.0588 * L - 0.296 * S - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print("Grade", grade)
