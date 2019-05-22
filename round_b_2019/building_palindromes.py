num_cases = int(input())
for case_id in range(num_cases):
    num_blocks, num_questions = map(int, input().split())
    l = input().strip()
    count = 0
    for __ in range(num_questions):
        left, right = map(int, input().split())
        if left == right:
            count += 1
            continue
        curr = l[left - 1: right]
        d = dict()
        num_odd = 0
        for ch in curr:
            d[ch] = d.get(ch, 0) + 1
        for k, v in d.items():
            if v % 2 != 0:
                num_odd += 1
        if (num_odd == 0 and len(curr) % 2 ==0) or (num_odd == 1 and len(curr) % 2 != 0):
        # if num_odd == 1 and 
            count += 1
    print('Case #%d: %d'%(case_id + 1, count))
