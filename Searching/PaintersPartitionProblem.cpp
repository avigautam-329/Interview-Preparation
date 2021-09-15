typedef long long int lli;

bool isValid(vector<int> &arr, int A, int n, int x){
    int sumOfBoardLen = 0;
    int noOfPainters = 1;

    for(int i = 0 ; i < n; i++){

        if(arr[i] > x){
            return false;
        }

        sumOfBoardLen += arr[i];
        if(sumOfBoardLen > x){
            noOfPainters++;
            sumOfBoardLen = arr[i];
            if(noOfPainters > A){
                return false;
            }
        }
    }
    return true;
}

lli binarySearch(vector<int> &arr, int A, int n){
    lli lb = 0;
    lli ub = 0;
    for(int i = 0; i < n; i++){
        ub += arr[i];
    }

    lli ans = -1;
    while(lb <= ub){
        lli x = (ub + lb) / 2;

        if(isValid(arr , A, n , x)){
            ans = x % MOD;
            ub = x - 1;
        }else{
            lb = x + 1;
        }
    }

    return ans % MOD;
}

int Solution::paint(int A, int B, vector<int> &C) {
    
    lli n = C.size();

    lli minMaxBoard = binarySearch(C , A , n);
    return (minMaxBoard * B) % 10000003;
}

