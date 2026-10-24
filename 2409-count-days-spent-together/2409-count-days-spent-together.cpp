class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, 
                          string arriveBob, string leaveBob) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 
                                   31, 31, 30, 31, 30, 31};
        
        auto toDayNumber = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            
            int dayNumber = day;
            for (int i = 0; i < month - 1; i++) {
                dayNumber += daysInMonth[i];
            }
            return dayNumber;
        };
        
        int aliceArrive = toDayNumber(arriveAlice);
        int aliceLeave = toDayNumber(leaveAlice);
        int bobArrive = toDayNumber(arriveBob);
        int bobLeave = toDayNumber(leaveBob);
        
        int overlapStart = max(aliceArrive, bobArrive);
        int overlapEnd = min(aliceLeave, bobLeave);
        
        return max(0, overlapEnd - overlapStart + 1);
    }
};