n = int(input())
words = [input() for i in range(n)]
not_duplicated_words = list(set(words))

not_duplicated_words.sort(key=lambda x: (len(x), x))

for word in not_duplicated_words:
    print(word)