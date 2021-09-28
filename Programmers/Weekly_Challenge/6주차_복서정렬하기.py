class Player:
    def __init__(self, number, weight):
        self.number = number
        self.weight = weight
        self.winRate = 0.
        self.heavyWinNumber = 0
        
    def setWinRate(self, winRate):
        self.winRate = winRate
        
    def setHeavyWinNumber(self, heavyWinNumber):
        self.heavyWinNumber = heavyWinNumber
        
    def __lt__(self, other):
        if self.winRate != other.winRate:
            return self.winRate > other.winRate
        elif self.heavyWinNumber != other.heavyWinNumber:
            return self.heavyWinNumber > other.heavyWinNumber
        elif self.weight != other.weight:
            return self.weight > other.weight
        else:
            return self.number < other.number
        
def solution(weights, head2head):
    N = len(weights)
    players = [Player(i+1, weights[i]) for i in range(N)]
    
    for i in range(N):
        if head2head[i].count('N') != N:
            players[i].setWinRate(head2head[i].count('W') / (head2head[i].count('W') + head2head[i].count('L')))
        
        cnt = 0
        for j in range(N):
            if head2head[i][j] == 'W' and weights[i] < weights[j]:
                cnt += 1
        players[i].setHeavyWinNumber(cnt)
        
        print(players[i].number, players[i].weight, players[i].winRate, players[i].heavyWinNumber)
        
    players = sorted(players)
    
    answer = [p.number for p in players]    
    return answer