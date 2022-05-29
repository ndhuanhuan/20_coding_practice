class Solution {
public:
    string discountPrices(string sentence, int discount) {
        std::setprecision(10);
        const int n = sentence.size();
        double multi = 1 - (double)discount / 100;
        cout << multi << endl;
        string res = "";
        for(int i = 0; i < n; ++i) {
            if(sentence[i] == '$') {
                int j = i + 1;
                while(j < n && sentence[j] >= '0' && sentence[j] <= '9') j++;
                string price = sentence.substr(i+1, j - i - 1);
                // bool valid = true;
                // for(auto c: price) {
                //     if(c >= '0' && c <= '9') valid = false;
                // }
                // if(valid)
                if(price.length() > 0 && (i == 0 || sentence[i-1] == ' ') && ((j < n && sentence[j] == ' ') || (j>=n))) {
                    long intPrice = stol(price);
                    
                    //double disPrice = multi * intPrice;
                    double disPrice = (double) intPrice * (100-discount) / 100.00;
                    // disPrice = round(disPrice);
                    disPrice = (double)(disPrice * 100 + .5);
                    disPrice /= 100;
                    // std::fixed;
                    // std::setprecision(10);
                    cout << disPrice << endl;
                    
                    //disPrice = std::ceil(disPrice * 100.0) / 100.0;
                    // cout << price << endl;
                    // cout << disPrice << endl;
                    res += "$";
                    string strDisPrice = to_string(disPrice);
                    int k = 0;
                    while( k < strDisPrice.size() && strDisPrice[k] != '.') {
                        res += strDisPrice[k];
                        ++k;
                    }
                    //++k;
                    for(int kk = 0; kk < 3; ++kk) {
                        res += strDisPrice[k];
                        ++k;
                    }
                   
                    i = j-1;
                } else {
                    res += sentence[i];
                    //i = i + 1;
                }
                
                    
            } else {
                res += sentence[i];
            }
            
            
        }
        
        return res;
    }
};

//"1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
