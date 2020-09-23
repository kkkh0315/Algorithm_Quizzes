def make_tree(word, target, words, count, answers):
    if word == target:
        answers.append(count)
        return answers 
    for index, element in enumerate(words):
        diff = 0
        for i in range(len(element)):
            if word[i] != element[i]:
                diff += 1
        if diff == 1:
            count += 1
            words[index] = ''
            answers = make_tree(element, target, words, count, answers)
            words[index] = element
    return answers

def solution(begin, target, words):
    answers = []
    if target in words:
        words.remove(target)
    else:
        return 0
    words.insert(0, target)
    answers = make_tree(begin, target, words, 0, answers)
    if not answers:
        return 0
    return sorted(answers)[0]