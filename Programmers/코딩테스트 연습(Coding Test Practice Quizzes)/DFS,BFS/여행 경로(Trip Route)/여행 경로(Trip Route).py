def create_travel(travel, tickets):         # 각 공항에서 출발하는 티켓의 리스트를 담은 딕셔너리 생성
    for element in tickets:
        if element[0] not in travel:
            travel[element[0]] = []
        travel[element[0]].append(element[1])
    for airport in travel.values():
        airport.sort()
    return travel

def backtrack(answer, travel, depart):      # 백트래킹 방식으로 풀이
    flag = 0                                # 종료 조건에 해당할 시 부여하는 flag
    left_tickets = 0                        # 종료 조건
    for element in travel:                      
        left_tickets += len(travel[element])    
    if left_tickets == 0:                      
        flag = 1                               
        return answer, flag                 
    else:                                                # 이하 재귀를 활용한 백트래킹 알고리즘
        if depart in travel and len(travel[depart]):
            for index, airport in enumerate(travel[depart]):
                answer.append(airport)
                travel[depart].remove(airport)
                answer, flag = backtrack(answer, travel, airport)
                if flag == 1:
                    return answer, flag
                else:                           
                    answer.pop()
                    travel[depart].insert(index, airport)
        return answer, flag
            
    
def solution(tickets):
    answer = ['ICN']
    travel = {}
    travel = create_travel(travel, tickets)
    answer, flag = backtrack(answer, travel, 'ICN')
    return answer