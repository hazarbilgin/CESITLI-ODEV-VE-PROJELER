import string

def remove_stop_words(list_of_strings): 
    stop_words = ['a', 'an', 'the'] + string.punctuation.split()
    result = []
    for i in list_of_strings:
        if i.lower() not in stop_words:
            result.append(i)
    return result

def form_dictionary(list_of_words):
    result = {}
    for word in list_of_words:
        if word in result:
            result[word] += 1
        else:
            result[word] = 1
    return result

def remove_duplicate_words(list_of_words):
    result = []
    for word in list_of_words:
        if word not in result:
            result.append(word)
    return result

def form_3_grams(list_of_words):
    result = []
    for i in range(0, len(list_of_words), 3):
        result.append(list_of_words[i:i+3])
    return result

# There is a little dog in the University. The little cat saw the dog in the University.
# input_text = ["There", "is", "a", "little", "dog", "in", "the", "University", ".", "The", "little", "cat", "saw", "the", "dog", "in", "the", "University", "."]

input_text = input("Enter a sentence: ").split()

list_of_words = remove_stop_words(input_text)
print("Output after removing stop words: ", list_of_words)

dictionary = form_dictionary(list_of_words)
print("Dictionary: ", dictionary)

list_of_words = remove_duplicate_words(list_of_words)
print("Output after removing duplicate words: ", list_of_words)

list_of_3_grams = form_3_grams(list_of_words)
print("3-grams: ", list_of_3_grams)