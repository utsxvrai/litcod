class Solution {
public:
    int calcTravelTime(int distance, vector<int>& travel)
    {
        int total = 0; int at = 0;
        while (distance > 0)
        {
            if (at >= travel.size()){break;}
            total += travel[at];
            at++;
            distance -= 1;
        } 
        total = total;
        return total;

    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int metal = 0; int paper = 0; int glass = 0;
        int totalTime = 0;
        vector<string>::iterator i = garbage.end();
        int lengthCurrent = garbage.size()-1;
        while (i != garbage.begin()) /*could optimize by checking if glass, metal, paper are 0 */
        {
            --i;
            totalTime += i->length();
            if (metal == 0 && i->find('M')!= -1)
            {
                metal = lengthCurrent;
            }
            if (glass == 0 && i->find('G')!= -1)
            {
                glass = lengthCurrent;
            }
            if (paper == 0 && i->find('P')!= -1)
            {
                paper = lengthCurrent;
            }
            lengthCurrent-=1;
        }
        /*Gets the furthest house the trucks have to go*/
        totalTime += calcTravelTime(metal,travel)+calcTravelTime(paper,travel)+calcTravelTime(glass,travel);
        return totalTime; 
    }
};