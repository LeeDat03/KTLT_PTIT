#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1e9 + 7;
const ld epsilon = 1e-6;


////////////////////////////////////////////////
//// KTCOBAN101 - ĐẾM CHỮ SỐ
// => thuat toan


////////////////////////////////////////////////
//// KTCOBAN102 - Tính 2004^X MOD 29
// => thuat toan

////////////////////////////////////////////////
//// KTCOBAN108 - Số đặc biệt
// => thuat toan


////////////////////////////////////////////////
//// KTCOBAN110 - Tìm số
// => thuat toan


////////////////////////////////////////////////
//// KTKNAPSACK001 - Bài toán cái túi
// => thuat toan

////////////////////////////////////////////////
//// KTCOVUA002 - Số cách đặt quân hậu
// => thuat toan => QUAY LUI


/*
////////////////////////////////////////////////
//// KTTAPCON001 - Tập con
// => thuat toan
int main(){
	int t;
	cin >> t;
	while(t--){		
		int n;
		cin >> n;
		int a[n];
		map<int, int> cnt;
		vector<int> v;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			cnt[a[i]] = 0;
		}
		sort(a, a + n);
		for(int i = 0; i < n; i++){
			cnt[a[i]]++;
			if(cnt[a[i]] == 1) v.push_back(a[i]);
		}

		// dem so tap con
		ll total = 1;
		for(int i = 0; i < v.size(); i++){
			total = (total * (cnt[v[i]] + 1) ) % MOD;
		}
		cout << (total - 1 + MOD) % MOD << " ";

		// tap con co tong lon nhat
		v.clear();
		for(int i = 0; i < n; i++){
			// loai bo het cac phan tu < 0 (neu co)
			if(a[i] >= 0){
				v.push_back(a[i]);
			}
		}
		if(v.size() == 1){
			cout << "[" << v[0] << "]\n";
		}else if(v.size() > 1){
			cout << "[" << v[0] << ", ";
			for(int i = 1; i < v.size() - 1; i++){
				cout << v[i] << ", ";
			}
			cout << v[v.size() - 1] << "]\n";
		}else{
			cout << "[" << a[n - 1] << "]\n";
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTIP001 - BÀI TOÁN IP
// => thuat toan
/ x: so bat dau, y: so ket thuc
bool check(int x, int y){
	// do dai ip > 3 thi  false
	if(y - x + 1 > 3) return 0;

	// ip khong dc bat dau tu 0 tru khi co dung so 0 xot lai
	if(s[x] == '0'){
		if(y - x + 1 == 1) return 1;
		return 0;
	}

	// do dai ip chia dc co 1 hoac 2 thi la true
	if(y - x + 1 == 1 || y - x + 1 == 2) return 1;

	// tinh toan ip thu dc
	int sum = 100 * (s[x] - '0') + 10 * (s[x + 1] - '0') + s[y] - '0';
	if(sum >= 0 && sum <= 255) return 1;
	return 0;
}

int main(){
	int t;
	cin >> t;
	while(t--){		
		cin >> s;
		int n = s.size();
		if(n < 4 || n > 12){
			cout << "0\n";
			 continue;
		} 

		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				for(int p = j + 1; p < n; p++){
					// check 0 - i co phai la IP khong
					// check i+1 - j co phai la IP khong
					// check j+1 - p co phai la IP khong
					// check p+1 - n co phai la IP khong
					if(check(0, i) && check(i + 1, j) && check(j + 1, p) && check(p + 1, n - 1)){
						// for(int t = 0; t < s.size(); t++){
						// 	if(t == i || t == j || t == p){
						// 		cout << s[t] << ","; 
						// 	}else{
						// 		cout << s[t];
						// 	}
						// }
						// cout << endl;
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
}
*/



////////////////////////////////////////////////
//// KTCOBAN215 - Tính giá trị biểu thức số lớn
// => thuat toan *dung python cho nhanh :)))))*


/*
////////////////////////////////////////////////
//// KTCOVUA001 - Mã đi tuần
// => thuat toan => QUAY LUI
int n, k;
int x[100][100], visited[100][100];

int dx[] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dy[] = {-1,  1, -2,  2, -2, 2, -1, 1};

bool check(int x, int y){
	if(x >= 1 && x <= n && y >= 1 && y <= n){
		return true;
	}
	return false;
}

void Try(int x, int y, int step){
	if(step == k + 1) return;

	visited[x][y] = 1;

	for(int i = 0; i <= 7; i++){
		int xn = x + dx[i];
		int yn = y + dy[i];

		if(check(xn, yn)){
			Try(xn, yn, step + 1);
		}
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> n >> k >> x >> y;
		memset(visited, 0, sizeof(visited));
		Try(x, y, 0);
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(visited[i][j]){
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
}
*/

/*
////////////////////////////////////////////////
//// KTCOBAN021 - Số có hai chữ số A và B
// => thuat toan 
string solve(string a, string b){
	
	int i= a.length()-1;
	int j= b.length()-1;
	
	int nho=0;
	string res="";
	
	while(i>=0 || j>=0 || nho!=0){
		int x = (i>=0) ? (a[i]-'0') : 0;
		int y = (j>=0) ? (b[j]-'0') : 0;
		
		int sum = x+y+nho;
		nho=sum/10;
		res+=to_string(sum%10);
		 i--;
		 j--;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main(){
	int t; cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		string res=solve(a,b);
		cout<<res<<endl;
	}	
}
*/

/*
////////////////////////////////////////////////
//// KTDAYSO007 - Đếm nhóm chữ số
//// idea: QUAY LUI MANG 2 CHIEU
int dem(char a[], int start, int end, int tongtruoc=0){
	if(start==end) return 1;
	
	int sum=0; int res=0;
	
	for(int i=start;i<end;i++){
		sum+=(a[i]-'0');
		if(sum>=tongtruoc) res+=dem(a,i+1,end,sum);
	}
	return res;
}

int main(){
	int t; cin>>t;
	while(t--){
		int n; 
		char a[41];
		cin>>n>>a;
		cout<<dem(a,0,n,0)<<endl;
	}
	
	return 0;
}
*/


/*
////////////////////////////////////////////////
//// KTDAYSO008 - Phân chia dãy số
//// idea: QUY HOACH DONG AO VCL
int n , a[100];
map<int,int>dp;
long long sum,sum2,ans;

int main(){
    int t ;
    cin >> t;
    while(t--){
        cin >> n;
        sum=0;ans=INT_MAX;
        for(int i=1; i<=n; ++i)cin >> a[i],sum+=a[i];
        sum2 = sum/2;
        for(int i=1; i<=sum2; ++i)dp[i]=0;
        dp[0]=1;
        for(int i=1; i<=n; ++i){
            for(int j=sum2; j>=a[i]; --j){
                if(dp[j-a[i]]==1)dp[j]=1;
            }
        }
        for(int i=0; i<=sum2; ++i){
            if(dp[i]==1)ans=min(ans,abs(sum-2*i));
        }
        cout << ans;
        cout << '\n';
    }
    return 0;
}
*/



////////////////////////////////////////////////
//// KTBDS009 - Biểu diễn số thành tổng của các số lẻ
//// QHD 

////////////////////////////////////////////////
//// KTBDS010 - Biểu diễn số thành tổng của các số 1 và 2
//// QHD 

////////////////////////////////////////////////
//// KTDT002 - Biểu diễn giai thừa
//// QHD

////////////////////////////////////////////////
//// KTDT007 - Loại số
//// QHD

////////////////////////////////////////////////
//// KTDT006 - Hiệu 2 số lớn theo phần bù của 10
//// chiu

////////////////////////////////////////////////
//// KTDT005 - Hiệu 2 số lớn theo phần bù của 9
//// chiu

////////////////////////////////////////////////
///// KTDT003 - Dãy con dài nhất sao cho các phần tử liền kề có ít nhất một chữ số chung


////////////////////////////////////////////////
///// KTBDS006	Biểu diễn số thành tổng K số nguyên tố phân biệt	


/*
////////////////////////////////////////////////
//// KTCOBAN203 - Xâu mẹ chung ngắn nhất
// => thuat toan
// Dai khai la quy hoach dong
// Shortest Common Supersequence 

int dp[1001][1001] = {0};

int main(){
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;

		memset(dp, 0, sizeof(dp));
		int n = a.size(), m = b.size();
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i - 1] == b[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}else{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << n + m - dp[n][m] << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN016 - Bình phương số lớn
// => thuat toan
//// Output co form la: 1234......1234...0987654321
// vi tri cuoi cung la 2 * n - 1
char P[1000001]; 

int main(){
	int t;	cin >> t;
	while(t--){
		memset(P, 0, sizeof(P));
		int n;
		cin >> n;
		int k = 0;
		for(int i = 1; i < 2 * n; i++){
			if(i <= n){
				k += i;
			}else{
				k += 2 * n - i;
			}
			P[2 * n - i] = k % 10 + '0';
			k /= 10;
		}

		for(int i = 1; i < 2 * n; i++){
			cout << P[i];
		}
		cout << endl;
		
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN015 - Tổ hợp k phần tử
//// => thuat toan, phai de ll moi dung
ll n, k, final = 0;
ll x[100];

void setup(){
	final = 0;
	for(ll i = 1; i <= k; i++){
		x[i] = i;
	}
}

void sinh(){
	ll i = k;
	while(i >= 1 && x[i] == n - k + i){
		i--;
	}
	if(i == 0){
		final = 1;
	}else{
		x[i]++;
		for(ll j = i + 1; j <= k; j++){
			x[j] = x[j - 1] + 1;
		}
	}
}


int main(){
	ll gt[20];
	gt[0] = gt[1] = 1;
	for(ll i = 2; i <= 19; i++){
		gt[i] = gt[i - 1] * i;
	}

	ll t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		setup();
		cout << 1ll * gt[n] / (gt[k] * gt[n - k]) << endl;

		while(!final){
			cout << "[";
			for(ll i = 1; i <= k; i++){
				cout << x[i];

				if(i != k){
					cout << " ";
				}
			}
			cout << "]\n";
			sinh();
		}
	}
}
*/



/*
///////////////////////////////////////////////
//// KTNGTO008 - Bộ N số nguyên tố
//// idea: sang so nguyen to => Try(i, start, total)
int prime[1005], x[1000];
int p, n, s, ok = 0;

void sang(){
	for(int i = 1; i <= 1000; i++){
		prime[i] = 1;
	}
	prime[1] = 0; 
	for(int i = 2; i <= sqrt(1000); i++){
		for(int j = i * i; j <= 1000; j += i){
			prime[j] = 0;
		}
	}
}

void Try(int i, int start, int total){
	for(int j = start; j <= s; j++){
		if(prime[j]){
			x[i] = j;
			total += j;

			if(total == s && i == n){
				ok = 1;
				for(int t = 1; t <= i; t++){
					cout << x[t] << ' ';
				}
				cout << endl;
			}else if(total < s && i < n){
				Try(i + 1, j + 1, total);
			}

			total -= j;
		}
	}
}

int main(){
	sang();
	cin >> p >> n >> s;
	Try(1, p + 1, 0);
	if(ok == 0){
		cout << "-1";
	}
}
*/


/*
////////////////////////////////////////////////
///// KTDT001 - Tìm số cách biểu diễn của N thành tổng của hai số tự nhiên liên tiếp trở lên
// idea a = (n - (i + 1) * i / 2) / (i + 1)
int main(){
	int t;	cin >> t;
	while(t--){
		ll n;	cin >> n;
		int cnt = 0;

		for(ll i = 1; i * (i + 1) <= 2 *n;i++){
			ll a = (n - (i + 1) * i / 2)/ (i + 1);
			ll b = (n - (i + 1) * i / 2)% (i + 1);
			if(a > 0 && b == 0){
				++cnt;
			}
		}
		cout << cnt << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTDT008 - Lũy Thừa
// 1. phai dung long double + epsilon= 1e-6
// k: 1 -> 40
// 2. Lay can bac k cua trai, phai
// 3. Tim sai so trai - floor, phai - ceil
// 4. Sai so nho hon epsilon thi lam tron xuong, nguoc lai lam tro len
// 5. neu r - l >= 0 thi tim dc k
int main(){
	int t;	cin >> t;
	while(t--){	
		ld a, b;
		cin >> a >> b;

		ll ans = 0;
		for(int k = 1; k <= 40; k++){
			ld l = pow(a, 1.0 / k);
			ld r = pow(b, 1.0 / k);

			ld check_l = l - floor(l);
			ld check_r = r - ceil(r);

			if(abs(check_l) <= epsilon){
				l = floor(l);
			}else{
				l = ceil(l);
			}

			if(abs(check_r) <= epsilon){
				r = ceil(r);
			}else{
				r = floor(r);
			}

			if(r - l >= 0){
				ans = k;
			}
		}
		cout << ans << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTDT010 - Quân tượng
//// neu n = 1 thi co 1 cach con khong thi co n + n - 2
int main(){
	int t;	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(n == 1){
			cout << "1\n";
		}else{
			cout << n + n - 2 << endl;
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN119 - Đếm dãy nhị phân thỏa mãn điều kiện
//// Dua ve nhi phan => dem '0'
bool nhiphan(int n, int k){
	int dem = 0;
	while(n){
		int x = n % 2;
		if(x == 0){
			++dem;
		}
		n /= 2;
	}
	return dem == k;
}


int main(){
	int t;	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int dem = 0;
		for(int i = 1; i <= n; i++){
			if(nhiphan(i, k)){
				++dem;
			}
		}
		cout << dem << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBT003 - Dãy chữ số đầu tiên của lũy thừa
//// idea: ket hop nhan 2 string vs luy thua nhi phan
string mul(string a, string b){
	string ans(a.size() + b.size(), 0);
	for(int i = a.size() - 1; i >= 0; i--){
		for(int j = b.size() - 1; j >=0; j--){
			int x = (a[i] - '0') * (b[j] - '0') + ans[i + j + 1];
			ans[i + j + 1] = x % 10;
			ans[i + j] += x / 10;
		}
	}
	for(auto &x : ans){
		x += '0';
	}
	if(ans[0] == '0'){
		ans = ans.substr(1);
	}
	return ans;
}

string binpow(string a, int b){
	if(b == 0){
		return "1";
	}
	string x = binpow(a, b / 2);
	if(b % 2 == 0){
		return mul(x, x);
	}else{
		return mul(a, mul(x, x));
	}
}


int main(){
	int t;	cin >> t;
	while(t--){
		string a;
		int b, k;
		cin >> a >> b >> k;
		
		string x = binpow(a, b);
		for(int i = 0; i < k; i++){
			cout << x[i];
		}
		cout << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBT002 - Khoảng cách hoán vị
//// idea: dung ham next_permutation
// phai luu vao 1 vector to
int main(){
	int t;	cin >> t;
	while(t--){
		int n;	cin >> n;
		vector<vector<int>> v;

		// sap xep de so be hon dung trc
		for(int k = 1; k <= 2; k++){
			vector<int> tmp;
			for(int i = 1; i <= n; i++){
				int x;	cin >> x;
				tmp.push_back(x);
			}
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		string s;
		int count = 0;
		for(int i = 0; i < n; i++){
			s = s + to_string(v[1][i]);
		}

		do{
			string tmp;
			for(int i = 0; i < n; i++){
				tmp = tmp + to_string(v[0][i]);
			}
			if(tmp == s) break;

			++count;
		}while(next_permutation(v[0].begin(), v[0].end()));
		cout << count << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTFIBO005 - Biểu diễn số N dưới dạng tổng của các số Fibonacci không lặp lại
// idea: dung 1 arr luu lai cac so fibo (bat dau tu 1) 
// QHD cong thuc a[j] + a[j - fibo[i]]
// i: fibo     j: (n, i, j--)
ll fibo[45];

ll find(int n){
	int a[n + 1] = {0};
	a[0] = 1;
	for(int i = 0; i <= 40; i++){
		for(int j = n; j >= fibo[i]; j--){
			a[j] = a[j] + a[j - fibo[i]];
		}
	}
	return a[n];
}

int main(){
	fibo[0] = 1;
	fibo[1] = 2;
	for(int i = 2; i <= 40; i++){
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}

	int t;	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << find(n) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// Biểu diễn số N dưới dạng tổng của 2 số Fibonacci	
//// idea: dung 1 array luu lai cac so fibo
// binarysearch n - fibo[i]

ll fibo[50];

int main(){
	fibo[0] = 0;
	fibo[1] = 1;
	for(int i = 2; i <= 45; i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int t;	cin >> t;
	while(t--){
		int n;	cin >> n;
		int ok = 0;
		for(int i = 0; i < n; i++){
			if(binary_search(fibo, fibo + 45, n - fibo[i])){
				cout << fibo[i] << ' ' << n - fibo[i] << endl;
				ok = 1;
				break;
			}
		}
		if(ok == 0){
			cout << "-1\n";
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTFIBO003 - Số phi Fibonacci kế tiếp
//// idea: dung 1 array luu lai cac so fibo
// vs n <= 3 thi tra ve 4
// => tra ve n + 1 hoac n + 2 
ll fibo[45];

int find(int n){
	if(n <= 3) return 4;

	// n + 1 la so fibo
	if(binary_search(fibo, fibo + 40, n + 1)){
		return n + 2;
	}
	return n + 1;
}

int main(){
	fibo[0] = fibo[1] = 1;
	for(int i = 2; i <= 40; i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int t;	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << find(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTFIBO002 - Tổng các số Fibonacci chẵn không vượt quá n
//// idea: 1 arry luu lai cac so fibo
int main(){
	ll fibo[50];
	fibo[0] = fibo[1] = 1;
	for(int i = 2; i <= 45; i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int t;	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll tong = 0;
		for(int i = 0; i <= 45; i++){
			if(fibo[i] <= n && fibo[i] % 2 == 0){
				tong += fibo[i];
			}
		}
		cout << tong << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTFIBO001 - Tìm số thứ n không thuộc dãy Fibonacci
//// thuoc ham
int non_fibo(int n){
	int a = 1, b = 2, c = 3;
	while(n > 0){
		a = b;
		b = c;
		c = a + b;
		n = n - (c - b - 1);
	}
	n = n + (c - b - 1);
	return n + b;
}

int main(){
	int t;	cin >> t;
	while(t--){
		int n;	cin >> n;
		cout << non_fibo(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBDS008 - Biểu diễn số thành tổng của các số chẵn
//// n le => -1, n chan thi co 2^(n/2 - 1) cach
// dua ve mu nhi phan => cho nhanh

// TLE
ll bds8(ll n){
	if(n % 2 == 1) return -1;

	ll x = n / 2 - 1;
	ll tich = 1;
	for(int i = 1; i <= x; i++){
		tich = (tich * 2) % MOD;
	}
	return tich;
}

ll mu(ll n){
	if(n == 0) return 1;

	if(n % 2 == 1) return (2 * mu(n - 1)) % MOD;

	ll tmp = mu(n / 2);

	return (tmp * tmp % MOD) % MOD;
}

int main(){
	int t;	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(n % 2){
			cout << "-1\n";
		}else{
			cout << mu(n/2 - 1) << endl;
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBDS007 - Biểu diễn số thành tổng của các số luỹ thừa của 2
//// QHD: cong thuc a[j] = a[j] + a[j - i]
//// i: (1, n, *= 2)     j: (i, n, ++j)
int bds7(int n){
	int a[n + 1] = {0};
	a[0] = 1;

	for(int i = 1; i <= n; i *= 2){
		for(int j = i; j <= n; j++){
			a[j] = a[j] + a[j - i];
		}
	}
	return a[n];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;	cin >> n;
		cout << bds7(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBDS005 - Biểu diễn số thành tổng các số chính phương
//// QHD: cong thuc a[j] = a[j] + a[j - i * i]
//// i: (1, sqrt(n), i++)    j: (i*i, n, j++)

int bds5(int n){
	int a[n + 1] = {0};
	a[0] = 1;

	for(int i = 1; i <= sqrt(n); i++){
		for(int j = i * i; j <= n; j++){
			a[j] = a[j] + a[j - i * i];
		}
	}
	return a[n];
}

int main(){
	int t;	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << bds5(n) << endl;
	}
}



/*
////////////////////////////////////////////////
//// KTBDS004 - Biểu diễn số thành tổng K số fibonacci
//// lay 1 mang luu lai het cac so fibo (42 so)
// Quay lui tim tong => Try(i, start, tong)
int fibo[43];
int n, k, dem = 0;
int x[101];

void setup(){
	memset(fibo, 0, sizeof(fibo));
	fibo[0] = 1;
	fibo[1] = 2;
	for(int i = 2; i <= 42; i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
} 

void in(int i){
	for(int k = 1; k <= i; k++){
		cout << x[k] << ' ';
	}
	cout << endl;
}

// TLE
void Try(int i, int start, int total){
	for(int j = start; j <= 42; j++){
		if(total + fibo[j] > n) return;

		x[i] = fibo[j];
		total += fibo[j];
		if(total == n && i == k){
			++dem;
			// in(i);
		}else if(total < n && i < k){
			Try(i + 1, j, total);
		}
		total -= fibo[j];
	}
}

// int Try2(int n, int k, int index){
// 	if(k == 0){
// 		if(n == 0) return 1;
// 		else return 0;
// 	}

// 	int sum = 0;
// 	for(int i = 42; i >= 0 && fibo[i] * k >= n; i--){
// 		if(fibo[i] > n) continue;
// 		else sum += Try2(n - fibo[i], k - 1, i);
// 	}
// 	return sum;
// }


int main(){
	setup();
	int t;	cin >> t;
	while(t--){
		dem = 0;
		cin >> n >> k;
		Try(1, 0, 0);
		cout << dem << endl;
		// cout << Try2(n, k, 42) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBDS003 - Biểu diễn số 03
//// CAC NGHIEM KHAC 0
// C(n - 1, k - 1)
ll tohop(int n, int k){
	if(n < k){
		return 0;
	}

	k = min(n - k, k);
	ll C[k + 1] = {0};
	C[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = min(i, k); j >= 1; j--){
			C[j] = C[j] + C[j - 1];
		}
	}
	return C[k];
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << tohop(n - 1, k - 1) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBDS002 - Biểu diễn số 02
// CAC NGHIEM CO THE BANG 0
//// idea: tinh C(n + k - 1, n) => so nghiem
ll tohop(int n, int k){
	k = min(k, n - k);
	ll C[k + 1] = {0};
	C[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = min(i, k); j >= 1; j--){
			C[j] = C[j] + C[j - 1];
		}
	}
	return C[k];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << tohop(n + k - 1, n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBDS001 - Biểu diễn số 01
//// QHD: CONG THUC a[j] = (a[j] + a[j - i]) % mod
//// i: (1, n - 1, i++)    j: (i, n, j++)
// return a[n] - 1
int bds1(int n){
	int a[n + 1] = {0};
	a[0] = 1;
	
	for(int i = 1; i < n; i++){
		for(int j = i; j <= n; j++){
			a[j] = (a[j] + a[j - i]) % MOD;
		}
	}
	return (a[n] - 1) % MOD;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << bds1(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTDAYS10 - Tìm thẻ bị thiếu
//// idea: ct cap so cong n * u1 + n * (n - 1) / 2
int main(){
	int t;
	cin >> t;
	while(t--){
		ull n, l;	
		cin >> n >> l;
		// ull a[n - 1];
		ull sum = 0;
		for(ull i = 0; i < n - 1; i++){
			ull x;	cin >> x;
			sum += x;
		}
		ull total = n * l + (n * (n - 1)) / 2;
		cout << total - sum << endl;
	}
}
*/

/*
////////////////////////////////////////////////
//// KTDAYSO009 - Chênh lệch lớn nhất giữa 0 và 1 trong dãy nhị phân
//// idea: dem so so 0, so so 1
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int ans = 0;
		int dem = 0;
		for(char x : s){
			if(x == '0'){
				dem++;
			}else{
				dem--;
			}

			if(dem < 0){
				dem = 0;
			}
			ans = max(ans, dem);
		}
		
		if(ans == 0){
			cout << "-1\n";
		}else{
			cout << ans << endl;
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN025 - Số Catalan thứ n
//// idea: dung 1 mang de luu lai
// c1 = c0
// c2 = c0*c1 + c1*c0
// c3 = c0*c1 + c1*c1 + c2*c0

int main(){
	ll c[32] = {0};
	c[0] = 1;
	for(int k = 1; k <= 31; k++){
		for(int i = 0; i <= k - 1; i++){
			c[k] += c[i] * c[k - 1 - i];
		}
	}

	int t;
	cin >> t;
	while(t--){
		int n;	cin >> n;
		cout << c[n] << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTMATRAN001 - Đường đi lớn nhất
//// idea: dua ve dang:
// -1  -1  -1  -1  -1  -1  -1 
// -1   a   a   a   a   a  -1
// -1   a   a   a   a   a  -1
// -1  -1  -1  -1  -1  -1  -1
int a[1005][1005], p[1005][1005];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
				p[i][j] = a[i][j];
			}
		}
		for(int i = 0; i <= m + 1; i++){
			p[0][i] = 0;
			p[n + 1][i] = 0;
		}

		for(int i = 1; i <= n; i++){
			p[i][0] = 0;
			p[i][m + 1] = 0;
		}

		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= m; j++){
				p[i][j] = max(p[i - 1][j - 1], max(p[i - 1][j], p[i - 1][j + 1])) + a[i][j];
			}
		}

		int ans = 0;
		for(int i = 1; i <= m; i++){
			ans = max(ans, p[n][i]);
		}
		cout << ans << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTDAYSO006 - Tạo số lớn nhất
//// idea: sort => cong string
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a[n];
		for(auto &x : a){
			cin >> x;
		}
		sort(a, a + n, greater<string>());
		for(auto x : a){
			cout << x;
		}
		cout << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN023 - Số mũ lớn nhất của ước số
//// idea: tim xem x xuat hien bao nhieu lan trong p!
ll count(ll n, ll p){
	ll dem = 0;
	for(ll i = p; n / i >= 1; i *= p){
		dem += n / i;
	}
	return dem;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, x;
		cin >> n >> x;
		cout << count(n, x) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTDAYSO005 - Số cô đơn
//// idea: dung mang danh dau
int d[1000005] = {0};

int main(){
	int t;	cin >> t;
	while(t--){
		memset(d, 0, sizeof(d));
		int n;
		cin >> n;
		int a[n];
		for(int &x : a){
			cin >> x;
			d[x]++;
		}
		int ans = 0;
		for(int x : a){
			if(d[x] == 1){
				ans++;
			}
		}
		cout << ans << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTDAYSO004 - Dãy con đơn điệu tăng dài nhất
// dung 1 mang de duyet den dau luu lai so phan tu dai nhat den day
// dung vector moi dung ???
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(auto &x : a) cin >> x;

		vector<int> L(n, 1);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				if(a[j] < a[i]){
					L[i] = max(L[i], L[j] + 1);
				}
			}
		}
		int ans = 0;
		for(auto x : L){
			ans = max(ans, x);
		}
		cout << ans << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTGIAITHUA004 - Tính số dư tổ hợp chập k của n khi chia cho m
// idea: biet tinh to hop chap k cua n
int solve(int n, int k, int m){
	k = min(k, n - k);
	int C[k + 1];
	memset(C, 0, sizeof(C));
	C[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = min(i, k); j >= 1; j--){
			C[j] = (C[j] + C[j - 1]) % m;
		}
	}
	return C[k];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, m;
		cin >> n >> k >> m;
		cout << solve(n, k, m) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN022 - Mua Sô-cô-la
int main(){
	int t;
	cin >> t;
	while(t--){
		int x, y, m;
		cin >> x >> y >> m;
		ll total = 0;
		ll buy = m / x;	// so socola mua dc tu lan dau
		total += buy;
		while(buy >= y){
			ll exchange = buy / y;
			total += exchange;
			buy = buy % y + exchange;
		}
		cout << total << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTUOCSO008 - Liệt kê các cách phân tích số thành tích các số tự nhiên khác 1
// idea: QUAY LUI
int n;
vector< vector<int>> res;

void Try(int i, int total, vector<int> cur){
	if(i > n || total > n){
		return;
	}
	if(total == n){
		res.push_back(cur);
		return;
	}

	for(int k = i; k < n; k++){
		if(total * k > n){
			return;
		}

		if(n % k == 0){
			cur.push_back(k);
			Try(k, k * total, cur);
			cur.pop_back();
		}
	}
}

void solve(){
	vector<int> tmp;
	tmp.clear();
	Try(2, 1, tmp);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		res.clear();
		solve();
		cout << res.size() << endl;
		for(auto v : res){
			for(auto x : v){
				cout << x << " ";
			}
			cout << endl;
		}
	}
}
*/



/*
////////////////////////////////////////////////
//// KTDAYSO003 - Đếm số dãy con K phần tử có tổng nhỏ nhất
// idea: sort => k so dau co tong nho nhat
// biet tinh to hop: cho truong hop nhieu so

// so to hop chap k cua n
int tohop(int n, int k){
	k = min(k, n - k);
	int C[k + 1];
	memset(C, 0, sizeof(C));
	C[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = min(i, k); j >= 1; j--){
			C[j] = (C[j] + C[j - 1]);
		}
	}
	return C[k];
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		int a[n];
		for(auto &x : a){
			cin >> x;
		}
		sort(a, a + n);

		int tmp = 0, total = 0;
		// dem xem co bao nhieu so trung
		for(int i = 0; i <= k - 1; i++){
			if(a[i] == a[k - 1]){
				++tmp;
			}
		}

		for(int i = 0; i < n; i++){
			if(a[i] == a[k - 1]){
				++total;
			}
		}
		cout << tohop(total, tmp) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTDAYSO002 - Dãy con K phần tử có tổng bằng S
// idea: QUAY LUI
int n, k, s, cnt;
int a[100], x[100];

// void in(int i){
// 	for(int k = 1; k <= i; k++){
// 		cout << x[k] << ' ';
// 	}
// 	cout << endl;
// }

void Try(int i, int start, int total){
	for(int j = start; j <= n; j++){
		// x[i] = a[j];
		total += a[j];

		if(total == s && i == k){
			++cnt;
			// in(i);
		}else if(total < s && i < k){
			Try(i + 1, j + 1, total);
		}

		total -= a[j]; 	// backtrack
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k >> s;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		cnt = 0;
		Try(1, 1, 0);
		cout << cnt << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN020 ** Tích chữ số lớn nhất
// idea: QUAY LUI
ll solve(ll n){
	if(n == 0){
		return 1;
	}
	if(n < 10) return n;

	ll a = solve(n / 10) * (n % 10);
	ll b = solve(n / 10 - 1) * 9;
	return max(a, b);
}


int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << solve(n) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN019 - Biến đổi số
// idea: QUAY LUI
// n <= 1 thi tra ve n
// lay x = sqrt(n) => n - x * x + Tinh(x)
ll Tinh(ll n){
	if(n <= 1) return n;	// -1

	ll x = sqrt(n);
	ll a = n % 2 + Tinh(n / 2);	// chia cho 2
	ll b = n % 3 + Tinh(n / 3);	// chia cho 3
	ll c = n - x * x + Tinh(x); // lay can 2	
	return 1 + min(a, min(b, c));
}


int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << Tinh(n) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN018 - Ước luỹ thừa 2 lớn nhất
// idea: dem so lan 2 xuat hien trong n!
ll count_2(ll n){
	ll cnt = 0;
	for(ll i = 2; n / i >= 1; i *= 2){
		cnt += n / i;
	}
	return cnt;
}

int main(){
	int t;	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << count_2(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTTONG005 - Số các bộ số có tổng bằng S
// idea: neu s = 3 * k thi chi co 1 cach
ll dem(ll k, ll s){
	if(s == 3 * k){
		return 1;
	}

	int cnt = 0;
	for(int i = 0; i <= k; i++){
		int m1 = min(k, s - i);
		for(int j = 0; j <= m1; j++){
			int n = s - i - j;
			if(n <= k){
				++cnt;
			}
		}
	}
	return cnt;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll k, s;
		cin >> k >> s;
		cout << dem(k, s) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTDEC2HEX - Chuyển đổi thập phân sang hexa
// idea: chia cho 16 den chet
string p = "0123456789ABCDEF";

string convertHex(ll n){
	if(n == 0) return "0";
	string ans;
	while(n){
		int x = n % 16;
		ans = p[x] + ans;
		n /= 16;
	}
	return ans;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << convertHex(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBIN2DC - Chuyển đổi nhị phân sang thập phân
// idea: dung <<
int main(){
	int t;	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ull ans = 0, tmp = 1;
		for(int i = s.size() - 1; i >= 0; i--){
			if(s[i] == '1'){
				ans += tmp;
			}
			tmp = tmp << 1;
		}
		cout << ans << endl;
	}

}
*/


/*
////////////////////////////////////////////////
//// KTBIN2DC - Chuyển đổi nhị phân sang thập phân
// idea: C1: lam co ban
ll convertBin(string s){
	ll ans = 0;
	ll tmp = 1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1'){
			ans += pow(2, s.size() - 1 - i);
		}
	}
	return ans;
}


int main(){
	int t;	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << convertBin(s) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN017 - Dãy con liên tiếp tổng lớn nhất
// idea: sum += a[i], sum < 0 thi sum = 0;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll a[n];
		for(auto &x : a) cin >> x;
		ll ans = -INT_MAX, sum = 0; 	
		for(int i = 0; i < n; i++){
			sum += a[i];
			if(sum > ans){
				ans = sum;
			}
			if(sum < 0){
				sum = 0;
			}
		}
		cout << ans << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTUOCSO007 - Tổng ước số khác nhau
// idea: xet 3 TH
ll find(ll n, ll m){
	ll sum = 0;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			if(m % i != 0){
				sum += i;
			}
			if(m % (n / i) != 0){
				sum += n / i;
			}
			if(i * i == n && m % i != 0){
				sum -= i;
			}
		}
	}
	return sum;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		cout << find(n, m) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBISEARCH002 - Tìm kiếm trong dãy số
// idea: lam 1 cai pair luu gia tri + chi so
pair<int, int> a[100005];
int b[100005];
int n, m;

int binary_search(int x){
	int l = 1, r = n;
	while(l <= r){
		int m = (l + r) / 2;

		if(a[m].first == x && a[m - 1].first < x){
			return m;
		}
		if(a[m].first >= x){
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return 0;
}


int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= m; i++){
		int x = binary_search(b[i]);
		cout << a[x].second << " ";
	}
}
*/


/*
////////////////////////////////////////////////
//// KTBISEARCH001 - Tìm vị trí số x trong dãy số
// idea: viet ham binary_search
int binary_search(int a[], int n, int x){
	int left = 0, right = n - 1;
	int find = 0;
	while(left <= right){
		int mid = (left + right) / 2;
		if(a[mid] == x){
			find = mid + 1;
			right = mid - 1;
		}else if(a[mid] > x){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return find;
}


int main(){
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for(auto &x : a){
		cin >> x;
	}
	for(auto &x : b){
		cin >> x;
	}
	for(int i = 0; i < m; i++){
		cout << binary_search(a, n, b[i]) << " ";
	}
}
*/


/*
////////////////////////////////////////////////
//// KTLUYTHUA002 - Tính luỹ thừa a^n mod 10^9+7
// idea: luy thua nhi phan
ll binpow(int a, int b){
	if(b == 0){
		return 1;
	}
	ll x = binpow(a, b/2);
	if(b % 2 == 0){
		return (1ll * x * x % MOD) % MOD;
	}else{
		return a * (1ll * x * x % MOD) % MOD;
	}
}


int main(){
	int t;	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		cout << binpow(a, b) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTLUYTHUA001 - Tính luỹ thừa a^n
// idea: biet nhan 2 string => nhan
// ket hop luy thua nhi phan cho nhanh
string mul(string a, string b){
	string ans(a.size() + b.size(), 0);
	for(int i = a.size() - 1; i >= 0; i--){
		for(int j = b.size() - 1; j >= 0; j--){
			int x = (a[i] - '0') * (b[j] - '0') + ans[i + j + 1];
			ans[i + j + 1] = x % 10;
			ans[i + j] += x / 10;
		}
	}
	for(auto &x : ans){
		x += '0';
	}
	if(ans[0] == '0'){
		ans = ans.substr(1);
	}
	return ans;
}

string binpow(string a, int b){
	if(b == 0){
		return "1";
	}
	string x = binpow(a, b / 2);
	if(b % 2 == 0){
		return mul(x, x);
	}else{
		return mul(a, mul(x, x));
	}
}

int main(){
	int t;	cin >> t;
	while(t--){
		string a;
		int b;
		cin >> a >> b;
		cout << binpow(a, b) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTNHIPHAN001 - Đếm dãy nhị phân
// idea: doi tu nhi phan sang nhi phan => roi tru di nhau
// vi co the den 2^64 => unsigned long long, xet xem a > b hay b > a
// ans |= 1 << (n - 1 - i) moi dung ???
ull convert(string s, int n){
	ull ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			// ans += (ull)pow(2, n - 1 - i);
			ans |= 1 << (n - 1 - i);
		}
	}
	return ans;
}


int main(){
	int t;	cin >> t;
	while(t--){
		int n;	
		string a, b;
		cin >> n >> a >> b;
		ull x = convert(a, n);
		ull y = convert(b, n);
		if(x == y){
			cout << "0\n";
		}else if(x > y){
			cout << x - y - 1 << endl;
		}else{
			cout << y - x - 1 << endl;
		}
	}
}
*/



/*
////////////////////////////////////////////////
//// KTTONG004 - Tổng luỹ thừa bậc n
// idea: de quy: dem(m - pow, n, i + 1)
ll dem(ll m, ll n, ll start){
	if(m == 0){
		return 1;
	}
	ll count = 0;
	for(int i = start; pow(i, n) <= m; i++){
		count += dem(m - pow(i, n), n, i + 1);
	}
	return count;
}

int main(){
	int t;	cin >> t;
	while(t--){
		ll m, n;
		cin >> m >> n;
		cout << dem(m, n, 1) << endl;
	}
}
*/





/*
////////////////////////////////////////////////
//// KTCOBAN013 - Biến đổi dương
// idea: neu co 0 => return -1
// tim min giua so cac so am vs so cac so duong

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		int dem_duong = 0, dem_am = 0, zero = 0;
		for(int i = 0; i < n; i++){
			int x;	cin >> x;
			if(x == 0) zero = 1;
			else if(x < 0){
				dem_am++;
			}else{
				dem_duong++;
			}
		}

		if(zero == 1){
			cout << "-1\n";
		}else{
			cout << min(dem_am, dem_duong) << endl;
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN012 - Số đối xứng gần nhất
// idea: viet ham kt doi xung
// lay n lam trung tam, chay dan xuong + len cho den khi nao tim dc so day
// phai check n co phai la so doi xung khogn trc
bool dx(ll n){
	string s = to_string(n);
	string tmp = s;
	reverse(s.begin(), s.end());
	return tmp == s;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		if(dx(n)){
			cout << n << endl;
		}else{			
			ll left = n, right = n;
			while(dx(left) == 0 && dx(right) == 0){
				left--;
				right++;
			}
			if(dx(left) && dx(right)){
				cout << left << ' ' << right << endl;
			}else if(dx(left)){
				cout << left << endl;
			}else{
				cout << right << endl;
			}
		}
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN011 - Phép chia số lớn
// idea: biet +, - so lon
string add(string a, string b){
	int max_size = max(a.size(), b.size());
	while(a.size() < max_size)	a = '0' + a;
	while(b.size() < max_size)	b = '0' + b;
	string ans;
	int c = 0;
	for(int i = a.size() - 1; i >= 0; i--){
		int x = a[i] - '0' + b[i] - '0' + c;
		c = x / 10;
		ans = to_string(x % 10) + ans;
	}
	if(c == 1) ans = '1' + ans;
	return ans;
}

string sub(string a, string b){
	int max_size = max(a.size(), b.size());
	while(a.size() < max_size)	a = '0' + a;
	while(b.size() < max_size)	b = '0' + b;

	int c = 0;
	string ans;
	for(int i = a.size() - 1; i >= 0; i--){
		int x = a[i] - '0' - (b[i] - '0') - c;
		if(x < 0){
			x += 10;
			c = 1;
		}else{
			c = 0;
		}

		ans = to_string(x) + ans;
	}

	// th so o dau la 0
	while(ans[0] == '0' && ans.size() > 1){
		ans.erase(0, 1);
	}
	return ans;
}

int cmp(string a, string b){
	int max_size = max(a.size(), b.size());
	while(a.size() < max_size)	a = '0' + a;
	while(b.size() < max_size)	b = '0' + b;
	if(a < b){
		return -1;
	}else{
		return 0;
	}
}

string bigdiv(string a,string b){
	string kb[11];
	kb[0] = "0";
	for(int i = 1; i <= 10; i++){
		kb[i] = add(kb[i - 1], b);
	}
	string res, hold;
	int k;
	for(int i = 0; i < a.size(); i++){
		hold = hold + a[i];
		k = 1;
		while(cmp(hold, kb[k]) != -1){
			k++;
		}
		res += char(k - 1 + '0');
		hold = sub(hold, kb[k - 1]);
	}
	while(res[0] == '0' && res.size() > 1){
		res.erase(0, 1);
	}
	return res + " " + hold;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		cout << bigdiv(a, b) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN009 - Đếm số chữ số
// idea: dua ve string -> size
int main(){
	int t;	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ll ans = s.size();
		if(isdigit(s[0]) == 0){
			ans -= 1;
		}
		cout << ans << endl;
	}
}
*/




/*
////////////////////////////////////////////////
//// KTTONG001 - Tổng các số lẻ
// idea: dung cong thuc cho nhanh
int main(){
	int t;	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		int so_chu_so = (b - a) + 1;
		cout << so_chu_so * 1ll * (a + b) / 2 << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTTONG001 - Tổng các số lẻ
// idea: dung cong thuc cho nhanh
int main(){
	int t;	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;

		// dua ve so le
		if(a % 2 == 0){
			a += 1;
		}
		if(b % 2 == 0){
			b -= 1;
		}

		ll so_chu_so = (b - a) / 2 + 1;
		cout << 1ll * so_chu_so * (a + b) / 2 << endl; 
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN008 - Tổng hai số lớn
// idea: cong 2 string
string add(string a, string b){
	string ans;
	int max_size = max(a.size(), b.size());

	while(a.size() < max_size){
		a = '0' + a;
	}
	while(b.size() < max_size){
		b = '0' + b;
	}

	int carry = 0;
	for(int i = max_size - 1; i >= 0; i--){
		int x = a[i] - '0' + b[i] - '0' + carry;
		ans = to_string(x % 10) + ans;
		carry = x / 10;
	}

	if(carry) ans = '1' + ans;
	return ans;
}

int main(){
	int t;	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		cout << add(a, b) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN005 - Hàm mũ số lớn
// idea: 
// abcde MOD m = (a MOD m) * 10 + (bcde MOD m)
// => tinh string a, string b MOD m

// a^b MOD m = (a MOD m)^ (b MOD (m - 1)) MOD m
// tinh a^b
ll modString(string a, ll MOD){
	ll ans = 0;
	for(int i = 0; i < a.size(); i++){
		int x = a[i] - '0';
		ans = (ans * 10 + x) % MOD;
	}
	return ans;
}

ll binpow(ll a, ll b){
	if(b == 0){
		return 1;
	}
	ll x = binpow(a, b / 2);
	if(b % 2 == 0){
		return (1ll * x * x) % MOD;
	}else{
		return a * (1ll * x * x % MOD) % MOD;
	}
}

int main(){
	int t;	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		ll x = modString(a, MOD);
		ll y = modString(b, MOD - 1);
		cout << binpow(x, y) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN007 - M chữ số đầu trong luỹ thừa
// idea: tinh k * log10(n) => lay phan ao
// 	tinh 10^phan ao * 10^(m - 1)
// double moi dung, float bi sai
ll find(ll n, ll k, ll m){
	double x = (double)k * log10(n * 1.0);
	x = x - (ll)x;
	double y = pow(10.0, x * 1.0);

	return y * 1ll * pow(10, m - 1);
}


int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, k, m;
		cin >> n >> k >> m;
		cout << find(n, k, m) << endl;
	}
}
*/




/*
////////////////////////////////////////////////
//// KTNGTO007 - Tìm số có ước nguyên tố lớn nhất
//// idea: tim so nguyen to lon nhat
bool snt(ll n){
	if(n <= 1) return 0;
	if(n == 2 || n == 3) return 1;
	if(n % 2 == 0 || n % 3 == 0) return 0;

	for(int i = 5; i <= sqrt(n); i += 6){
		if(n % i == 0){
			return 0;
		}
		if(n % (i + 2) == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		ll ans = 0;
		for(ll i = a; i <= b; i++){
			if(snt(i)){
				ans = max(ans, i);
			}
		}
		cout << ans << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTNGTO006 - Tìm số đặc biệt lớn nhất
//// idea: sang uoc so nguyen to
int p[1000005];

void sieve(){
	for(int i = 2; i <= 1e6; i++){
		p[i] = i;
	}
	p[1] = 0;

	for(int i = 2; i <= 1e6; i++){
		if(p[i] == i){
			for(int j = i; j < 1e6; j += i){
				p[j] = i;
			}
		}
	}
}

int main(){
	sieve();

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = n; i >= 0; i--){
			if(p[i] > sqrt(i)){
				cout << i << endl;
				break;
			}
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTNGTO003 - Nguyên tố tổng
// idea: x = 2 + 1 so nguyen to nao day, x luon la so le
// neu n <= 4 thi so nguyen to la 5
bool check(ll n){
	if(n <= 1) return false;
	if(n == 2 || n == 3) return true;
	if(n % 2 == 0 || n % 3 == 0) return false;

	for(int i = 5; i <= sqrt(n); i += 6){
		if(n % i == 0){
			 return false;
		}
		if(n % (i + 2) == 0){
			return false;
		}
	}
	return 1;
}

ll find(ll n){
	if(n <= 4) return 5;

	// n la so chan += 1
	if(n % 2 == 0){
		n++;
	}

	while(check(n) == 0 || check(n - 2) == 0){
		n += 2;
	}
	return n;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << find(n) << endl;
	}
}
*/




/*
////////////////////////////////////////////////
//// KTNGTO002 - Đếm số nguyên tố
int p[1000001]; 
void sang(){
	for(int i = 0; i <= 1e6; i++){
		p[i] = 1;
	}
	p[0] = p[1] = 0;


	for(int i = 2; i <= sqrt(1e6); i++){
		for(int j = i * i; j <= 1e6; j += i){
			p[j] = 0;
		}
	}
}

int main(){
	sang();

	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		int dem = 0;
		for(int i = a; i <= b; i++){
			if(p[i]){
				++dem;
			}
		}
		cout << dem << endl;

	}
}
*/


/*
////////////////////////////////////////////////
//// KTNGTO005 - Tổng ước nguyên tố lớn nhất của các số không vượt quá N
// idea: sang nma lay cac uoc
int uoc[1000005];

void sang_uoc(){
	for(int i = 1; i <= 1e6; i++){
		uoc[i] = i;
	}
	uoc[1] = 0;

	for(int i = 2; i <= 1e6; i++){
		if(uoc[i] == i){
			for(int j = i; j < 1e6; j += i){
				uoc[j] = i;
			}
		}
	}
}

int main(){
	sang_uoc();
	
	int t;	cin >> t;
	while(t--){
		int n;	cin >> n;
		ll ans = 0;
		for(int i = 2; i <= n; i++){
			ans += uoc[i];
		}
		cout << ans << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTNGTO004 - Ước nguyên tố lớn nhất
// idea: nhu tim so nguyen to => neu chia het thi chia den chet
ll uoc(ll n){
	ll ans = 0;

	while(n % 2 == 0){
		ans = 2;
		n /= 2;
	}
	while(n % 3 == 0){
		ans = 3;
		n /= 3;
	}

	for(int i = 5; i <= sqrt(n); i += 6){
		while(n % i == 0){
			ans = i;
			n /= i;
		}
		while(n % (i + 2) == 0){
			ans = i + 2;
			n /= (i + 2);
		}
	}
	if(n > 4) ans = n;

	return ans;
}


int main(){
	int t;	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << uoc(n) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN004 - Số đối xứng
// idea: reverse string => doi xung
// k = 1, 2 => 9 so
// k = 3, 4 => 90 so
// k = 5, 6 => 900 so    => quy luat

ll doi_xung(int n){
	ll ans = 9;
	if(n == 1 || n == 2) return ans;

	if(n % 2 == 0){
		return 1ll * ans * pow(10, n / 2 - 1);
	}else{
		return 1ll * ans * pow(10, n / 2);
	}
}

int main(){
	int t;	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << doi_xung(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTNGTO001 - Đếm số nguyên tố hoàn toàn
// idea: viet ham check tung ky tu la snt + dung sang cho nhanh
int p[1000005];

void sang(){
	for(int i = 0; i <= 1e6; i++){
		p[i] = 1;
	}
	p[0] = p[1] = 0;
	for(int i = 2; i <= sqrt(1e6); i++){
		for(int j = i * i; j < 1e6; j += i){
			p[j] = 0;
		}
	}
}

bool checksnt(int n){
	if(p[n] == 0) return 0;

	string s = to_string(n);
	for(char x : s){
		if(x != '2' && x != '3' && x != '5' && x != '7'){
			return 0;
		}
	}
	return 1;
}

int main(){
	sang();
	int t;	cin >> t;
	while(t--){
		int n;	cin >> n;
		int dem  = 0;
		for(int i = 1; i <= n; i++){
			if(checksnt(i)){
				++dem;
			}
		}
		cout << dem << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTDEC2BIN - Đổi hệ thập phân sang hệ nhị phân
// idea: lay n % 2 => bit be nhat => o cuoi cung 
string convertBin(ll n){
	string ans;
	while(n){
		int x = n % 2;
		ans = to_string(x) + ans;
		n /= 2;
	}
	return ans;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << convertBin(n) << endl;
	}
}
*/




/*
////////////////////////////////////////////////
//// KTGTBT004 - Biểu thức căn-luỹ thừa
// tinh x^n roi ans = sqrt(x^n + ans)
int main(){
	int t;
	cin >> t;
	while(t--){
		float n, x;
		cin >> n >> x;
		float ans = 0.0;
		float tich = 1.0;
		for(int i = 1; i <= n; i++){
			tich *= x;
			ans = sqrt(ans + tich);
		}
		cout << setprecision(3) << fixed << ans << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTGTBT003 - Biểu thức căn-giai thừa
// idea: can bac x = mu 1/x
// tinh tu be den to, " \n"
ll gt[21];

void calc_gt(){
	gt[1] = 1;
	for(int i = 2; i <= 20; i++){
		gt[i] = gt[i - 1] * i;
	}
}

int main(){
	calc_gt();

	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		float ans = 0.0;
		for(int i = 1; i <= n; i++){
			float can = 1.0 / (i + 1);
			ans = pow(ans + (float)gt[i], can);
		}
		cout << setprecision(3) << fixed << ans << " \n";
	}
}
*/


/*
////////////////////////////////////////////////
//// KTTGTBT002 - Biểu thức tổng giai thừa
int main(){
	int t;
	cin >> t;
	while(t--){
		float n, x;
		cin >> n >> x;
		float sum = 0.0;
		float gt = 1.0;
		for(int k = 1; k <= n; k++){
			gt *= k;
			sum += pow(x, (float)k) / gt; 
		}
		cout << setprecision(3) << fixed << sum << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTTGTBT001 - Đa thức tổng
// note: dung float moi dung, double bi sai
// k = 1: x^1/ 1
// k = 2: x^2/ 1 + 2
// k = 3: x^3/ 1 + 2 + 3
int main(){
	int t;
	cin >> t;
	while(t--){
		float x, n;
		cin >> n >> x;
		float ans = 0.0;

		for(int k = 1; k <= n; k++){
			float mau = k * (k + 1) / 2;
			ans += pow(x, (float)k) / mau;
		}
		cout << setprecision(3) << fixed << ans << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTSTRING002 - Xâu thoi gian
// idea: 1. biet xu ly ??:??
//2. biet tach string
int main(){
	int t;	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		for(auto &x : s){
			if(x == '='){
				x = ' ';
			}
		}
		stringstream ss(s);
		string tmp;
		vector<string> v;
		while(ss >> tmp){
			v.push_back(tmp);
		}

		string time = v[1];	// time co dang "ab:cd"

		if(time[1] == '?'){
			if(time[2] - '0' < 4 || time[2] == '?'){
				time[1] = '2';
			}else{
				time[1] = '1';
			}
		}

		if(time[2] == '?'){
			if(time[1] == '2'){
				time[2] = '3';
			}else{
				time[2] = '9';
			}
		}

		if(time[4] == '?') time[4] = '5';
		if(time[5] == '?') time[5] = '9';

		cout << time << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTSTRING001 - Xâu kí tự
// idea: dung ham find => a.find(b) tra ve vi tri dau tien cua b trong a
// biet xu ly xau
string tach(string s){
	string ans;
	for(int i = 1; i < s.size() - 1; i++){
		ans = ans + s[i];
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);

		for(char &x : s){
			if(x == '=' || x == ','){
				x = ' ';
			}
		}

		vector<string> v;
		stringstream ss(s);
		string tmp;
		while(ss >> tmp){
			v.push_back(tmp);
		}

		string child = tach(v[1]);
		string parent = tach(v[3]);
		int ans = parent.find(child);
		cout << ans << endl;	
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN003 - Đếm số chính phương
// idea: [can b] - [can a]
int main(){
	int t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;

		ll max = floor(sqrt(b));
		ll min = ceil(sqrt(a));
		cout << max - min + 1 << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTKTCOBAN002 - Số Chính Phương
// idea: moi chu so cua no cung la so chinh phuong => 0, 1, 4, 9
// neu n le => 100, 10000, ....
// n chan:  x >= can(10^(n -1)) thi x * x co n chu so

bool check_kt(ll n){
	string s = to_string(n);
	for(auto c : s){
		if(c != '0' && c != '1' && c != '4' && c != '9'){
			return 0;
		}
	}
	return 1;
}

ll find(int n){
	if(n % 2 == 1){
		return pow(10, n - 1);
	}

	ll x = sqrt(pow(10, n - 1)) + 1;
	while(x * x < pow(10, n)){
		if(check_kt(x * x)){
			return x * x;
		}
		x++;
	}
	return -1;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << find(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTGIAITHUA003 - Đếm số số 0 liên tiếp cuối n!
// idea: dem xem so 5 xuat hien bao nhieu lan trong n!
// [x/5] + [x/25] + [x/125]
ll count_5(ll n){
	ll dem = 0;
	for(ll i = 5; n / i >= 1; i *= 5){
		dem += 1ll * (n / i);
	}
	return dem;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;	cin >> n;
		cout << count_5(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN008 - Tổng hai số lớn
// idea: biet tinh tong 2 so lon
string add(string a, string b){
	// tim so ky tu lon nhat
	int max_size = max(a.size(), b.size());
	string ans(max_size, '0');

	// THEM 0 o dau
	while(a.size() < max_size){
		a = '0' + a;
	}
	while(b.size() < max_size){
		b = '0' + b;
	}

	// XU LY tinh toan
	int carry = 0;
	for(int i = a.size() - 1; i >= 0; i--){
		int x = (a[i] - '0') + (b[i] - '0') + carry;
		carry = x / 10;
		ans[i] = (x % 10) + '0';
	}

	if(carry == 1) ans = '1' + ans;
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		cout << add(a, b) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTUOCSO005 - Phân tích số
// idea: giong vs kiem tra snt %2,%3, %i, %(i + 2)
map<ll, ll> ptich(ll n){
	map<ll, ll> ans;
	while(n % 2 == 0){
		ans[2]++;
		n /= 2;
	}

	while(n % 3 == 0){
		ans[3]++;
		n /= 3;
	}

	for(int i = 5; i <= sqrt(n); i += 6){
		while(n % i == 0){
			ans[i]++;
			n /= i;
		}
		while(n % (i + 2) == 0){
			ans[i + 2]++;
			n /= (i + 2);
		}
	}
	if(n > 2){
		ans[n]++;
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		map<ll, ll> mp = ptich(n);
		cout << mp.size() << endl;
		for(auto x : mp){
			cout << x.first << ' ' << x.second << endl;
		}
	}
}
*/



/*
////////////////////////////////////////////////
//// KTUOCSO004 - Ước nguyên tố
ll count(ll n){
	ll tich = 1;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			tich *= i;
			while(n % i == 0){
				n /= i;
			}
		}
	}
	if(n > 1) tich *= n;
	return tich;
}

int main(){
	int t;	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(count(n) < n){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}
*/

	

/*
////////////////////////////////////////////////
//// KTUOCSO002 - Ước số nguyên tố
// idea: neu n % i thi chia n/i den chet
ll count(ll n){
	ll dem = 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			dem++;
			// cout << i << ' ';
			while(n % i == 0){
				n /= i;
			}
		}
	}
	if(n > 1) ++dem;
	return dem;
}

int main(){
	int t;	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << count(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTUOCSO001 - Tổng các ước số
// idea: 
ll uoc(ll n){
	ll sum = 0;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			sum += i + n / i;
		}
		if(i * i == n){
			sum -= i;
		}
	}
	return sum - n;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << uoc(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTUOCSO006 - Cặp số bạn bè
// idea: nhu cau duoi
ll uoc(ll n){
	ll sum = 0;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			sum += i + n / i;

			if(i * i == n){
				sum -= i;
			}
		}
	}
	return sum - n;
}

int main(){
	int t;	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		if(uoc(a) == b && uoc(b) == a){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTUOCSO003 - Số hoàn hảo
// idea: duyet tu 1 -> sqrt(n) => tinh tong
ll uoc(ll n){
	ll sum = 0;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			sum += i + n / i;

			if(i * i == n){
				sum -= i;
			}
		}
	}
	sum -= n;
	return sum == n;
}

int main(){
	int t;	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << uoc(n) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN107 - LŨY THỪA MA TRẬN
// idea: biet nhan 2 ma tran + biet luy thua nhi phan => nhan 2 ma tran :)))
int n, k;
ll a[11][11];
ll tmp[11][11];	// copy of array A

void MulMaxtrix(ll a[11][11], ll b[11][11]){
	ll c[11][11] = {0};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				c[i][j] += (a[i][k] % MOD) * (b[k][j] % MOD);
				c[i][j] %= MOD;
			}
		}
	}
	for(int i =1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = c[i][j];
		}
	}
}

void PowMatrix(ll a[11][11], int k){
	if(k == 1) return;

	PowMatrix(a, k / 2);
	MulMaxtrix(a, a);

	if(k % 2 == 1){
		MulMaxtrix(a, tmp);
	}
}

int main(){
	int t;	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
				tmp[i][j] = a[i][j];
			}
		}
		PowMatrix(a, k);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
	}
} 
*/



/*
////////////////////////////////////////////////
//// KTCOBAN105 - GẮN DÂY
// idea: dung priority queue + greater => luon theo thu tu tu lon -> be
// => biet setup queue + lay phan tu tu queue

int main(){
	int t;	cin >> t;
	while(t--){
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> q;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			q.push(x);
		}
		ll ans = 0;
		while(q.size() > 1){
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();
			ans += a + b;
			q.push(a + b);
		}
		cout << ans << endl;
	}
} 
*/


/*
////////////////////////////////////////////////
//// KTCOBAN104 - NHẦM SỐ
// idea: dua ve string => doi 3 - 5, 5 - 3
ll convert_max(int n){
	string s = to_string(n);
	for(auto &c : s){
		if(c == '3') c = '5'; 
	}
	return stoll(s);
}

ll convert_min(int n){
	string s = to_string(n);
	for(auto &c : s){
		if(c == '5') c = '3'; 
	}
	return stoll(s);
}

int main(){
	int t;	cin >> t;
	while(t--){
		int a, b;	cin >> a >> b;
		cout << convert_min(a) + convert_min(b) << ' ';
		cout << convert_max(a) + convert_max(b) << endl; 
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN103 - ĐẾM GIAI THỪA
// idea: n = 1 => x = 1, 2, 3
// n = 2 => x = 4
// n = 3 => x = 5, 6
// vs n > 3 => so chu so cua x = [log10(x)] + 1
//  n! = 1*2*3*...*n => log10(n!) = log10(1) + log10(2) +....

int main(){
	int t;	cin >> t;
	while(t--){
		int n;	cin >> n;
		if(n < 1)	cout << "NO\n";
		else if(n == 1)		cout << "3 1 2 3\n";
		else if(n == 2)		cout << "1 4\n";
		else if(n == 3)		cout << "2 5 6\n";
		else{
			ll i = 0, k = 0;
			double sum = 0;
			while(k < n){
				i++;
				sum += double(log10(i));
				k = floor(sum) + 1;	// so chu so
			}
			if(k == n) cout << "1 " << i << " " << endl;
			else cout << "NO\n";
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN201 - Mật khẩu hợp lệ
// idea: biet vao ra file, thuoc ham check password
// isdigit: kiem tra so; isupper: kt in hoa, islower: kt in thuong; ispunct: kt ky tu dac biet

bool check_total(string s){
	if(s.size() < 8) return 0;

	for(int i = 1; i < s.size(); i++){
		if(s[i] == s[i - 1]) return 0;
	}
	return 1;
}

bool check_char(string s){
	bool digit = 0, up = 0, low = 0, punct = 0;
	for(auto x : s){
		if(isdigit(x)){
			digit = 1;
		}
		if(isupper(x)){
			up = 1;
		}
		if(islower(x)){
			low = 1;
		}
		if(ispunct(x)){
			punct = 1;
		}
	}
	return digit && up && low && punct;
}


int main(){
	ifstream inputFile("password.in");
	ofstream outputFile("res.out");

	string s;
	while(inputFile >> s){
		if(check_total(s) && check_char(s)){
			outputFile << "VALID\n";
		}else{
			outputFile << "INVALID\n";
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN200 - Mã cột trong file Excel
// idea: biet vao ra file, doi so ve ky ty
string convert(ll n){
	string res = "";
	if(n == 0) return "0";

	while(n > 0){
		// tim phan du
		char c = 'A' + (n - 1) % 26;
		// them vao cuoi
		res = c + res;
		n = (n - 1) / 26;
	}
	return res;
}

int main(){
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	ll tmp;
	while(inputFile >> tmp){
		outputFile << convert(tmp) << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// KTSOLON001 - Tổng & Tích
// idea: biet doc ghi file, xu ly string, thuoc ham + string, * string
string add(string a, string b){
	string ans;
	int max_size = max(a.size(), b.size());
	while(a.size() < max_size){
		a = "0" + a;
	}
	while(b.size() < max_size){
		b = "0" + b;
	}
	int carry = 0;
	for(int i = max_size - 1; i >= 0; i--){
		int x = (a[i] - '0') + (b[i] - '0') + carry;
		ans = to_string(x % 10) + ans;
		carry = x / 10;
	}
	if(carry == 1){
		ans = "1" + ans;
	}
	return ans;
}

string mul(string a, string b){
	string ans(a.size() + b.size(), 0);
	for(int i = a.size() - 1; i >= 0; i--){
		for(int j = b.size() - 1; j >= 0; j--){
			int x = (a[i] - '0') * (b[j] - '0') + ans[i + j + 1];
			ans[i + j + 1] = x % 10;
			ans[i + j] += x / 10;
		}
	}
	for(auto &x : ans){
		x += '0';
	}
	if(ans[0] == '0'){
		ans = ans.substr(1);
	}
	return ans;
}

string calc(string express){
	vector<string> v;
	int nhan = 0, cong = 0;
	for(char &c : express){
		if(c == '+'){
			cong = 1;
			c = ' ';
		}
		if(c == '*'){
			nhan = 1;
			c = ' ';
		}
	}

	stringstream ss(express);
	string tmp;
	while(ss >> tmp){
		v.push_back(tmp);
	}

	if(nhan){
		return mul(v[0], v[1]);
	}

	if(cong){
		return add(v[0], v[1]);
	}
}


int main(){
	// doc file
	ifstream inputFile("bignumber.in");
	ofstream outputFile("bignumber.out");

	int t;
	inputFile >> t;
	inputFile.ignore();
	while(t--){
		string express;
		getline(inputFile, express);
		outputFile << calc(express) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTCOBAN026 - Bài toán người du lịch
// idea: quay lui
int n, m, ans = INT_MAX, cmin = INT_MAX;
int c[500][500];
int check[50], luu[50], truoc[500];

void Try(int i){
	for(int j = 2; j <= n; j++){
		if(check[j] == 0 && c[truoc[i - 1]][j] != 0){
			check[j] = 1;
			luu[i] = luu[i - 1] + c[truoc[i - 1]][j];
			truoc[i] = j;

			if(i == n - 1){
				if(c[j][1]) ans = min(ans, luu[i] + c[j][1]);
			}else if(luu[i] + cmin * (n - i) < ans) Try(i + 1);
			check[j] = 0;
		}
	}
}

int main(){
	truoc[0] = 1;
	cin >> n >> m;
	while(m--){
		int i, j, cij;
		cin >> i >> j >> cij;
		c[i][j] = cij;
		cmin = min(cij, cmin);
	}
	Try(1);
	cout << ans << endl;
}
*/


/*
////////////////////////////////////////////////
//// KTDAYSO001 - Dãy cấp số cộng
// idea: 2 so lien tiep cach nhau 1 khoang bang nhau
bool check(ll a[], int n){
	if(n <= 2) return true;
	ll gap = a[1] - a[0];
	for(int i = 2; i < n; i++){
		if(a[i] - a[i - 1] != gap){
			return 0;
		}
	}
	return 1;
}

int main(){
	int t;	cin >> t;
	while(t--){
		int n;	cin >> n;
		ll a[n];
		for(auto &x : a) cin >> x;
		if(check(a, n)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
} 
*/



/*
////////////////////////////////////////////////
//// KTGIAITHUA002 - Giai thừa có n số không ở cuối
// idea: co bao nhieu so 0 o cuoi => tim xem co bao nhieu lan so 5 xuat hien

// HAM DEM SO LAN SO 5 XUAT HIEN TRONG GIAI THUA
ll count_5(ll n){
	ll cnt = 0;
	for(ll i = 5; n / i >= 1; i *= 5){
		cnt += n / i;
	}
	return cnt;
}

// binarysearch 0 -> 5 * n
ll bs(ll n){
	ll left = 0, right = n * 5;
	while(left < right){
		ll mid = (left + right) / 2;
		ll cnt = count_5(mid);
		if(cnt < n){
			left = mid + 1;
		}else{
			right = mid;
		}
	}
	return left;
}

int main(){
	int t;	cin >> t;
	while(t--){
		ll n;	cin >> n;
		cout << bs(n) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTHOANVI001 - Liệt kê hoán vị
// idea: dung ham next_permuration
// bug: neu i == n thi phai xuong dong, k dc cach
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;	cin >> n;
		int a[n + 1];
		for(int i = 1; i <= n; i++){
			a[i] = i;
		}
		for(int i = 1; i <= n; i++){
			if(i == n){
				cout << a[i] << endl;
			}else{
				cout << a[i] << ' ';
			}
		}
		
		while(next_permutation(a + 1, a + n + 1)){
			for(int i = 1; i <= n; i++){
				if(i == n){
					cout << a[i] << endl;
				}else{
					cout << a[i] << ' ';
				}
			}
		}
	}
}
*/


/*
////////////////////////////////////////////////
//// KTCOBAN010 - Luỹ thừa dư
// idea: thuoc ham binpow
ll binpow(int a, int b){
	if(b == 0) return 1;

	ll tmp = binpow(a, b / 2);

	if(b % 2 == 0){
		return (1ll * tmp * tmp % MOD) % MOD;
	}else{
		return (a * (1ll * tmp * tmp % MOD)) % MOD;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int a, n;	cin >> a >> n;
		cout << binpow(a, n) << endl;
	}
}
*/



/*
////////////////////////////////////////////////
//// KTTONG003 - Đường đi có tổng lớn nhất
// idea: no se di cheo len, sang phai, cheo xuong
// => tao 1 ma tran co duong di max

// -1 -1 -1 -1 -1
//	0  a  a  a  a
// -1 -1 -1 -1 -1

// n hang m cot
int a[1001][1001], dp[1001][1001];

int main(){
	int t;	cin >> t;
	while(t--){	
		int n, m;	cin >> n >> m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
			}
		}

		// setup de hang dau tien va cuoi cung la min
		for(int i = 1; i <= m; i++){
			dp[0][i] = -1e9;
			dp[n + 1][i] = -1e9;
		}

		// hang dau tien
		for(int i = 1; i <= n; i++){
			dp[i][1] = a[i][1];
		}

		for(int j = 2; j <= m; j++){
			for(int i = 1; i <= n; i++){
				dp[i][j] = max(dp[i -1][j -1], max(dp[i][j - 1], dp[i + 1][j - 1])) + a[i][j];
			}
		}

		int ans = -1e9;
		for(int i = 1; i <= n; i++){
			ans = max(ans, dp[i][m]);
		}
		cout << ans << endl;
	}
}
*/



/*
/////////////////////////////////////////////////
///// KTGIAITHUA001 - Giai thừa số lớn
// idea: nho ham nhan 2 string, luu lai ket qua sau moi lan tinh vao mang

// HAM NHAN 2 STRING
string mul(string a, string b){
	string ans(a.size() + b.size(), 0);

	for(int i = a.size() - 1; i >= 0; i--){
		for(int j = b.size() - 1; j >= 0; j--){
			int x = (a[i] - '0') * (b[j] - '0') + ans[i + j + 1];
			ans[i + j + 1] = x % 10;
			ans[i + j] += x / 10;
		}
	}
	for(int i = 0; i < ans.size(); i++){
		ans[i] += '0';
	}
	if(ans[0] == '0'){
		ans = ans.substr(1);
	}
	return ans;
}


int main(){
	// setup
	string gt[10001];
	gt[0] = "1";
	for(int i = 1; i <= 10000; i++){
		string x = to_string(i);
		gt[i] = mul(gt[i - 1], x);
	}

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << gt[n] << endl;
	}
}
*/


/*
/////////////////////////////////////////////////
///// KTCOBAN001 - Số Armstrong
// idea: dung string cho nhanh

bool check(ll n){
	ll tmp = 0;
	string s = to_string(n);
	for(auto c : s){
		tmp += pow(c - '0', s.size());
	}
	return tmp == n;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << check(n) << endl;
	}
}
*/


/*
/////////////////////////////////////////////////
///// KTUOCSO003 - Số hoàn hảo
// idea: kiem tra: 
// p la so nguyen to va (2^p - 1) la so nguyen to
// thi (2^p - 1) * 2^(p - 1) so nguyen to

bool check_prime(ll n){
	if(n <= 1) return 0;
	if(n == 2 | n == 3) return true;
	if(n % 2 == 0 || n % 3 == 0) return 0;

	for(int i = 5; i <= sqrt(n); i += 6){
		if(n % i == 0 || n % (i + 2) == 0) return 0;
	}
	return 1;
}



int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		bool ok = 0;
		for(int i = 0; i <= 20; i++){
			if(check_prime(i) && check_prime(pow(2,i) - 1)){
				if(n == pow(2, i - 1) * (pow(2,i) - 1)){
					ok = 1;
					break;
				}
			}
		}
		if(ok == 1){
			cout << "1\n";
		}else{
			cout << "0\n";
		}
	}
}
*/