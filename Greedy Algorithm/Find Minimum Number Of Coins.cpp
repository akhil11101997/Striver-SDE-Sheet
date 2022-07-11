int findMinimumCoins(int amount) 
{
    // Write your code here
    int count=0;
    vector<int> helper={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int i=8;
    while(amount>0){
        if(amount/helper[i]){
            count+=(amount/helper[i]);
            amount=amount%helper[i];
            i--;
        }
        else{
            i--;
        }
    }
    return count;
}
