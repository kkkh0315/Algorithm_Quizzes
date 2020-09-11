def solution(s):
    # make a list of lists that contain sliced s
    # e.g.  if s = 'abab'
    #       options = [['a','b','a','b'],['ab','ab']]
    options = [[s[i:i+n] for i in range(0, len(s), n)] for n in range(1, len(s)//2 + 1)]
    if len(s) == 1:
        options = [s]

    # answers contain OPTIONs, which are the strings the question asks for.
    # e.g.  if options = [['a','b','a','b'],['ab','ab']]
    #       answers = ['abab','2ab']
    answers = []
    part = ''
    count = 1
    for comb in options:
        option = []
        for i, element in enumerate(comb):
            if i < len(comb) - 1 and comb[i] == comb[i+1]:
                if not part:
                    part = str(element)
                count += 1
            if i == len(comb) - 1 or comb[i] != comb[i+1]:
                if count != 1:
                    option.append(str(count) + element)
                else:
                    option.append(element)
                part = ''
                count = 1
        answers.append(''.join(option))
    
    # returns the minimum among lengths of strings in answers 
    return min([len(e) for e in answers])
