class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        int slot = 1;
        string token;
        stringstream ss(preorder);
        while(getline(ss , token , ','))
        {
            if(slot == 0)
            return false;
            
            slot -= 1;

            if(token != "#")
            slot += 2;
        }

        if(slot == 0)
        return true;

        return false;
    }
};
