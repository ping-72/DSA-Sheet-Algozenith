#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;

class ProductOfKNumbers {
public:
    vector<int> arr;
	ll binary_exponentiation(ll a, ll b, ll mod){ll ans=1;
    while(b){if(b%2==1){
            ans=(ans*a)%mod;}
        a=(a*a)%mod;b=b/2;}
    return ans%mod;}

ll inv(ll x, ll mod){ return binary_exponentiation(x,mod-2,mod); }
ll add(ll a, ll b, ll mod){ return (mod + (a%mod + b%mod)%mod)%mod; }
ll sub(ll a, ll b, ll mod){ return (mod + (a%mod - b%mod)%mod)%mod; }
ll mul(ll a, ll b, ll mod){ return (mod + (a%mod * b%mod)%mod)%mod; }
ll div(ll a, ll b, ll mod){ return (mod + (a%mod * inv(b,mod)%mod)%mod)%mod; }


	ProductOfKNumbers() {
		    arr.push_back(1);
	}

	void add(int num) {
		if(num == 0){
            arr.clear();
            arr = {1};
        }
        else{
            arr.push_back((mul(num, arr.back(),mod)));
        }
	}

	int getProduct(int k) {
		if(k>=arr.size() ) return 0;
        return( div(arr.back(), arr[arr.size() - k - 1], mod));
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	cin >> Q;

	ProductOfKNumbers productOfKNumbers;

	while(Q--) {
		string op;
		cin >> op;

		if (op == "add") {
			int num;
			cin >> num;
			productOfKNumbers.add(num);
		}
		else {
			int k;
			cin >> k;

			cout << productOfKNumbers.getProduct(k) << "\n";
		}
	}

	return 0;
}