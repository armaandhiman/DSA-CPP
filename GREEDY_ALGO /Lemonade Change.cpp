class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        
        int n = bills.size();
        int pock5 = 0;
        int pock10 = 0;

        for(int i = 0 ; i < bills.size() ; i++)
        {
            if(bills[i] == 10)
            {
                if(pock5 >= 5)
                {
                    pock5 -= 5;
                    pock10 += 10;
                }
                else
                return false;
            }
            else if(bills[i] == 20)
            {
                if(pock10 >= 10 && pock5 >= 5)
                {
                    pock10 -= 10;
                    pock5 -= 5;
                }
                else if(pock5 >= 15)
                {
                    pock5 -= 15;
                }
                else
                return false;
            }
            else 
            pock5 += 5;
        }
        return true;
    }
