#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

int cnt_Pallindrome = 0;

vector<int> allprime(int a, int b){
    vector<bool> prime;
    prime.assign(b+1, true);

    prime[1] = false;
    for(int i = 2; i * i <= b; i++){ // seive menthod -> O( n log(log(n)))
        if(prime[i] ){
            for(int j = i*i; j <= b; j += i){
                prime[j] = false;
            }
            
        }

    }

    vector<int> result;
    for(int i=a; i <= b; i++){
        if(prime[i])
            result.push_back(i);
    }
    return result;
}

 
int oneDigit(int num) 
{ 
	
	// Comparison operation is faster 
	// than division 
	// operation. So using following 
	// instead of "return num 
	// / 10 == 0;" 
	return (num >= 0 && num < 10); 
} 

// A recursive function to find 
// out whether num is 
// palindrome or not. Initially, dupNum 
// contains address of 
// a copy of num. 
bool isPalUtil(int num, int* dupNum) 
{ 
	
	// Base case (needed for recursion 
	// termination): This 
	// statement mainly compares the 
	// first digit with the 
	// last digit 
	if (oneDigit(num)) 
		return (num == (*dupNum) % 10); 

	// This is the key line in this 
	// method. Note that all 
	// recursive calls have a separate 
	// copy of num, but they 
	// all share same copy of *dupNum. 
	// We divide num while 
	// moving up the recursion tree 
	if (!isPalUtil(num / 10, dupNum)) 
		return false; 

	// The following statements are 
	// executed when we move up 
	// the recursion call tree 
	*dupNum /= 10; 

	// At this point, if num%10 contains 
	// i'th digit from 
	// beginning, then (*dupNum)%10 
	// contains i'th digit 
	// from end 
	return (num % 10 == (*dupNum) % 10); 
} 


int isPal(int num) 
{ 
	
	// Check if num is negative, 
	// make it positive 
	if (num < 0) 
		num = -num; 

	// Create a separate copy of num, 
	// so that modifications 
	// made to address dupNum don't 
	// change the input number. 
	// *dupNum = num 
	int* dupNum = new int(num); 

	return isPalUtil(num, dupNum); 
} 



void solve(){
    int a,b;
    cin>>a>>b;
    vector<int> primes;
    primes = allprime(a,b);
    for(int i=0; i<primes.size(); i++){
        //cout<<primes[i]<<" ";
        if( isPal(primes[i]) )
            cnt_Pallindrome++;
    }

    cout<<cnt_Pallindrome;

}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
//int _t;cin>>_t;while(_t--)
solve();
 
  return 0;
}