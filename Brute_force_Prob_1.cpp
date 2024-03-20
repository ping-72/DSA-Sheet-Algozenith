#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

// Question ->
// a,b,c,d,e,f,g,h,i,j,k are 10 distinct digits( zero to nine ) such that (abcdef)/(efghij) is a contant no N always say 2.....




void solve1(){
    // int n;
    // cin>>n;
    vector<int> arr={0,1,2,3,4,5,6,7,8,9};
    do
    {
        // for(auto v:arr){cout<<v<<" ";}cout<<endl; -> Printing the array made by permutation

        // O( 10^5)
        int abcde= arr[0]*10000+ arr[1]*1000+ arr[2]*100+ arr[3]*10+ arr[4] ;
        int fghij= arr[5]*10000+ arr[6]*1000+ arr[7]*100+ arr[8]*10+ arr[9];
        if(abcde % fghij == 0){
            // if(abcde / fghij == n){
            //     cout<<abcde<<" "<<fghij<<endl;
            // }
            cout<<abcde<<" "<<fghij<<" "<<(abcde/ fghij)<<endl;
        }
    } while (next_permutation(arr.begin(),arr.end()));
    
}
void solve2(){
    // O( 10^7 )
    int n;cin>>n;
    for(int fghij=01234; fghij< 99999/n ; fghij++){
        int abcde = fghij*n;
        set<int> st;

        int temp =abcde;
        for( int i=0; i<5; i++){
            st.insert( temp% 10);
            temp /= 10;
        }

        temp =fghij;
        for( int i=0; i<5; i++){
            st.insert( temp% 10);
            temp /= 10;
        }
        if(st.size() == 10){
            cout<<abcde<<" "<<fghij<<endl;
        }
    }
}

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
//int _t;cin>>_t;while(_t--)
solve2();
 
  return 0;
}