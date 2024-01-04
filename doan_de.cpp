#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;

/*
//////////////////////////////////////////
//// TEST001 - Tính giá trị biểu thức số lớn
// tinh 2^n * n!
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

int main(){
	string p[1001];
	p[0] = "1";
	p[1] = "2";
	for(int i = 2; i <= 1000; i++){
		p[i] = mul(p[i - 1], to_string(2 * i));
	}

	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << p[n] << endl;
	}
}
*/


/*
//////////////////////////////////////////
//// TEST003 - Ước nguyên tố luỹ thừa lớn nhất
// tim uoc nguyen to co so mu lon nhat 

void find(ll n){
	ll luythua = 0;
	ll uoc = 0;

	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			int dem = 0;
			while(n % i == 0){
				dem++;
				n /= i;
			}

			if(dem > luythua){
				uoc = i;
				luythua = dem;
			}
		}
	}

	if(n > 1 && luythua == 0){
		uoc = n;
		luythua = 1;
	}
	cout << uoc << ' ' << luythua << endl;
}

int main(){
	ll n;
	cin >> n;
	find(n);
}
*/


/*
//////////////////////////////////////////
//// TEST005 - Tính giá trị biểu thức số lớn = COBAN215
// nhan 2 string

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

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		int a = n - k + 1;
		string tich = "1";
		for(int i = a; i <= n; i++){
			tich = mul(tich, to_string(i));
		}
		cout << tich << endl;
	}
}
*/

/*
//////////////////////////////////////////
//// TEST006 - Biểu diễn số
// bieu dien n thanh tong luy thua cua m
// while(m^dem <= n){
//		j: x -> n   dp[j] = dp[j] + dp[j - x]
// }
ll bdstest(int n, int m){
	ll dp[n + 1] = {0};
	dp[0] = 1;
	int dem = 0;
	while(pow(m, dem) <= n){
		int x = pow(m, dem);
		for(int j = x; j <= n; j++){
			dp[j] += dp[j - x];
		}
		++dem;
	}
	return dp[n];
}

int main(){
	int n, m;
	cin >> n >> m;
	cout << bdstest(n, m) << endl;
}
*/

//////////////////////////////////////////
//// TEST002 - Đường đi ngắn nhất


/*
//////////////////////////////////////////
//// EXAM001 - Đếm số kí tự nhìn thấy trong mã nguồn
int main(){
	ifstream inputFile("main.cpp");

	string s;
	ll dem = 0;
	while(inputFile >> s){
		// cout << s << ' ' << s.size() << endl;
		dem += s.size();
	}	
	cout << dem << endl;
}
*/


/*
//////////////////////////////////////////
//// EXAM002 - Phép toán cộng số lớn
//// cong so lon vs so 2022

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
		int x = (a[i] - '0') + (b[i] - '0') + carry;
		ans = to_string(x % 10) + ans;
		carry = x / 10;
	}

	if(carry == 1){
		ans = '1' + ans;
	}
	return ans;
}


int main(){
	int t;cin >> t;
	while(t--){
		string s;
		cin >> s;
		string a = "2022";
		cout << add(a, s) << endl;
	}
}
*/


/*
//////////////////////////////////////////
//// EXAM003 - Mã cột trong file Excel
int main(){
	ll n;
	cin >> n;
	string ans;
	while(n){
		char x = 'A' + (n - 1) % 26;
		ans = x + ans;
		n = (n - 1) / 26;
	}
	cout << ans << endl;
}
*/



/*
//////////////////////////////////////////
//// EXAM004 - Mật khẩu hợp lệ
bool check1(string s){
	if(s.size() < 8) return 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i] == s[i - 1]){
			return 0;
		}
	}
	return 1;
}

bool check_char(string s){
	bool hoa = 0, thuong = 0, so = 0, kytu = 0;
	for(auto x : s){
		if(isupper(x)){
			hoa = 1;
		}
		if(islower(x)){
			thuong = 1;
		}
		if(isdigit(x)){
			so = 1;
		}
		if(ispunct(x)){
			kytu = 1;
		}
	}
	return hoa && thuong && so && kytu;
}


int main(){
	string s;
	cin >> s;
	if(check1(s) && check_char(s)){
		cout << "VALID\n";
	}else{
		cout << "INVALID\n";
	}
}
*/


/*
//////////////////////////////////////////
//// KLKT001 - Xâu nhị phân
// idea: convert sang he 10 => cong vao => convert lai sang he 2
// bitset
int main(){
	int n, k;
	string s;
	cin >> n >> k >> s;

	// doi tu nhi phan ve he 10
	int num = bitset<50>(s).to_ulong();
	// + k + 1 va lay du cho 2^n
	int y = (num + k + 1) % (1 << n);
	
	// dua tu so nguyen ve xau nhi phan
	bitset<50>bs(y);
	string res = bs.to_string();
	// xoa so 0 o dau
	res = res.substr(res.size() - n);
	cout << res << endl;
}
*/


/*
//////////////////////////////////////////
//// KLKT002 - Khoảng cách hoán vị - KTBT002
// res += sml * gt(n - i - 1)

int gt(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	return n * gt(n - 1);
}

int dem(vector<int> a, vector<int> b){
	int n = a.size();
	int cnt = 0;
	for(int i = 0; i < n; i++){
		int sml = 0;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[i]){
				++sml;
			}
		}
		cnt += sml * gt(n - i - 1);
	}

	for(int i = 0; i < n; i++){
		int sml = 0;
		for(int j = i + 1; j < n; j++){
			if(b[j] < b[i]){
				++sml;
			}
		}
		cnt -= sml * gt(n - i - 1);
	}
	return abs(cnt);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		int res = dem(a, b);
		cout << res << endl;
	}
}
*/


/*
//////////////////////////////////////////
//// KLKT003 - Dãy chữ số đầu tiên của lũy thừa - KTBT003
// idea: tinh k * log10(n) => lay phan ao
// 	tinh 10^phan ao * 10^(m - 1)
// double moi dung, float bi sai

ll find(ll n, ll m, ll k){
	double x = (double)k * log10(n * 1.0);
	x = x - (ll)x;
	double y = pow(10.0, x * 1.0);
	return y * 1ll * pow(10, m - 1);
}

int main(){
	int t;	cin >> t;
	while(t--){
		ll n, m, k;
		cin >> n >> k >> m;
		cout << find(n, m, k) << endl;
	}
}
*/


/*
//////////////////////////////////////////
//// KLKT005 - Xâu từ điển dài nhất
// sAxbCa => AbC
// lowerbound(v, s[i]) => neu khac v.end => add k thi *it = s[i]

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector<char> v;
		for(int i = 0; i < s.size(); i++){
			s[i] = tolower(s[i]);
		}
		for(int i = 0; i < s.size(); i++){
			auto it =lower_bound(v.begin(), v.end(), s[i]);
			if(it == v.end()){
				v.push_back(s[i]);
			}else{
				*it = s[i];
			}
		}
		cout << v.size() << endl;
	}
}
*/



/*
//////////////////////////////////////////
//// SCTDL031 - Mãy Gray004
//// Cho một số thập phân n. Tìm mã màu xám của số này ở dạng thập phân.
// n ^ (n >> 1)

int main(){
	int n;
	cin >> n;
	int grayCode = n ^ (n >> 1);
	cout << grayCode << endl;
}
*/


/*
//////////////////////////////////////////
//// SCTDL047 - SỐ MAY MẮN
// Hoàng yêu thích các số may mắn. Ta biết rằng một số là số may mắn nếu biểu diễn thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. Hoàng muốn tìm số may mắn bé nhất có tổng các chữ số bằng n. Hãy giúp anh ấy
// 11 -> 47,   10 -> -1

int main(){
	int n;
	cin >> n;
	int check = 0;
	int so4, so7;
	for(int  i = n / 7; i >= 0; i--){
		if((n - i * 7) % 4 == 0){
			so7 = i;
			so4 = (n - i * 7) / 4;
			check = 1;
			break;
		}
	}

	if(check == 1){
		for(int i = 1; i <= so4; i++){
			cout << "4";
		}
		for(int i = 1; i <= so7; i++){
			cout << "7";
		}
		cout << endl;
	}else{
		cout << "-1\n";
	}
}
*/


/*
//////////////////////////////////////////
//// SCTDL053 - ĐẾM SỐ BIT 1
//// N thành [N/2], N mod 2, [N/2]
// testcase: 7 2 5 => 4,    10 3 10 => 5
vector<ll> a;

void setup(ll n){
	int dem = 0;
	ll mu = 1;
	while(n / 2 > 0){
		dem++;
		if(dem == 1){
			a.push_back(2);
			mu = 2;
		}else{
			mu *= 2;
			a.push_back(mu);
		}
		n /= 2;
	}	
}

ll calc(ll i, ll n, ll pos){
	if(i % 2 == 1)	return 1;

	if(i == a[pos])	return n % 2;
	else if(i < a[pos]) calc(i, n / 2, pos - 1);
	else if(i > a[pos]) calc(2 * a[pos] - i, n / 2, pos - 1);
}


int main(){
	a.clear();
	ll n, l, r;
	cin >> n >> l >> r;
	setup(n);

	ll res = 0;
	for(ll i = l; i <= r; i++){
		res += calc(i, n, a.size() - 1);
	}
	cout << res << endl;
}
*/


/*
//////////////////////////////////////////
//// SCTDL055 - SỐ FIBONACCI THỨ N
// tim so fibonacci thu n % 1e9 + 7
unordered_map<ll, ll> F;
ll fibo(ll n){
	if(F[n] != 0){
		return F[n];
	}
	ll k = n / 2;
	if(n % 2 == 1){
		return F[n] = (fibo(k) * fibo(k + 1) + fibo(k - 1) * fibo(k)) % MOD;
	}else{
		return F[n] = (fibo(k) * fibo(k) + fibo(k - 1) * fibo(k - 1)) % MOD;
	}
}

int main(){
	F[0] = F[1] = 1;
	int n;	cin >> n;
	if(n == 0){
		cout << 0 << endl;
	}else{
		cout << fibo(n - 1) << endl;
	}
}
*/


/*
//////////////////////////////////////////
//// SCTDL056 - Tích nhị phân
// 1100 * 01 -> 12
ull convert(string s){
	ull ans = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1'){
			// ans |= (1 << s.size() - 1 - i);
			ans += pow(2, s.size() - 1 - i);
		}
	}
	return ans;
}


int main(){
	string a, b;
	cin >> a >> b;
	ull x = convert(a);
	ull y = convert(b);
	cout << x * y << endl;
}
*/


/*
//////////////////////////////////////////
//// CB11520220 - Lũy thừa ma trận 1
// nhan 2 ma tran + binpow

int n, k;
ll a[11][11], tmp[11][11];

void Mul(ll a[11][11], ll b[11][11]){
	ll c[11][11] = {0};

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				c[i][j] += (a[i][k] % MOD) * (b[k][j] % MOD);
				c[i][j] %= MOD;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = c[i][j];
		}
	}
}

void Pow(ll a[11][11], int k){
	if(k == 1) return;

	Pow(a, k / 2);
	Mul(a, a);
	if(k % 2 == 1){
		Mul(a, tmp);
	}
}


int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			tmp[i][j] = a[i][j];
		}
	}

	Pow(a, k);
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j){
				sum += a[i][j] % MOD;
			}
		}
	}
	cout << sum <<endl;
}
*/


//////////////////////////////////////////////
//// COBAN61120221 - Đếm dãy
//// Hãy cho biết có bao nhiêu dãy số nguyên dương có tổng các phần tử trong dãy bằng n.
// so cach 2 ^ (n - 1)



/*
//////////////////////////////////////////////
//// COBAN--020 - HOÁN VỊ KẾ TIẾP
// in ra hoan vi tiep theo
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n + 1];
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(next_permutation(a + 1, a + n + 1)){
			for(int i = 1; i <= n; i++){
				cout << a[i] << ' ';
			}
		}else{
			for(int i = 1; i <= n; i++){
				cout << i << ' ';
			}
		}
		cout << endl;
	}
}
*/


/*
////////////////////////////////////////////////
//// COBAN--021 - Mã Nhị Phân 1
//// in ra tat ca ma gray co do dai n
void grayCode(int n){
	vector<string> gray;
	gray.push_back("0");
	gray.push_back("1");

	for(int i = 2; i < (1 << n); i = i << 1){
		for(int j = i - 1; j >= 0; j--){
			gray.push_back(gray[j]);
		}
		for(int j = 0; j < i; j++){
			gray[j] = "0" + gray[j];
			gray[i + j] = "1" + gray[i + j];
		}
	}
	for(int i = 0; i < (1 << n); i++){
		cout << gray[i] << " ";
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	grayCode(n);
}
*/


/*
////////////////////////////////////////////////
//// SCTDL001 - Sinh xâu nhị phân N bit
int a[100], n;

void in(){
	for(int i =1; i <= n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}

void Try(int i){
	for(int j = 0; j < 2; j++){
		a[i] = j;
		if(i == n){
			in();
		}else{
			Try(i + 1);
		}
	}
}

int main(){
	cin >> n;
	Try(1);
}
*/


/*
////////////////////////////////////////////////
//// SCTDL003 - Xâu nhị phân kế tiếp
int main(){
	string s;
	cin >> s;
	int i = s.size() - 1;
	while(i >= 0 && s[i] == '1'){
		s[i] = '0';
		i--;
	}
	if(s[i] == '0'){
		s[i] = '1';
	}
	cout << s << endl;
}
*/


/*
////////////////////////////////////////////////
//// SCTDL004 - Sinh xâu AB
int n;
char c[10001];

void in(){
	for(int i = 1; i <= n; i++){
		cout << c[i];
	}
	cout << ' ';
}


void Try(int i){
	for(int j = 0; j <= 1; j++){
		c[i] = 'A' + j;
		if(i == n){
			in();
		}else{
			Try(i + 1);
		}
	}
}

int main(){
	cin >> n;
	Try(1);
}
*/


/*
////////////////////////////////////////////////
// SCTDL006 - Tách số
// 4 => (4)(31)(22)(211)(1111)
// => SINH PHAN HOACH
int x[1001], n, cnt, final = 0;

void ktao(){
	cnt =  1;
	x[1] = n;
}

void sinh(){
	int i = cnt;
	while(i >= 1 && x[i] == 1){
		i--;
	}
	if(i == 0){
		final = 1;
	}else{
		x[i]--;

		// so luong tong con lai = cnt - i
		int d = cnt - i + 1;
		cnt = i;
		int q = d / x[i], r = d % x[i];
		for(int j = 1; j <= q; j++){
			x[i + j] = x[i];
		}
		cnt += q;
		if(r > 0){
			x[cnt + 1] = r;
			++cnt;
		}
	}
}

int main(){
	cin >> n;
	ktao();
	while(!final){
		cout << "(";
		for(int i = 1; i <= cnt; i++){
			cout << x[i];
		}
		cout << ")";
		sinh();
	}
}
*/


/*
////////////////////////////////////////////////
// SCTDL010 - Xâu nhị phân số bit 1 bằng bit 0
// Cho một số nguyên N, nhiệm vụ là tạo ra tất cả cácchuỗi nhị phân có 0s và 1s bằng nhau. Nếu không thể in chuỗi, hãy in -1
void binarySum(int n, string s, int ones, int zeros){
	if(s.size() == n){
		cout << s << ' ';
		return;
	}

	if(zeros < n / 2){
		binarySum(n, s + "0", ones, zeros + 1);
	}
	if(ones < n / 2){
		binarySum(n, s + "1", ones + 1, zeros);
	}

}

int main(){
	int n;
	cin >> n;
	if(n % 2 == 0){
		binarySum(n, "", 0, 0);
		cout << endl;
	}else{
		cout << "-1\n";
	}
}
*/


/*
//////////////////////////////////////////////
//// SCTDL013 - Tổ hợp
// sinh to hop chap k cua n
int a[100], n, k, ok;

void ktao(){
	for(int i = 1; i <= k; i++){
		a[i] = i;
	}
}

void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i){
		--i;
	}
	if(i == 0){
		ok = 0;
	}else{
		a[i]++;
		for(int j = i + 1; j <= k; j++){
			a[j] = a[j - 1] + 1;
		}
	}
}

int main(){
	cin >> n >> k;
	ok = 1;
	ktao();
	while(ok){
		for(int i = 1; i <= k; i++){
			cout << a[i];
		}
		cout << " ";
		sinh();
	}
}
*/


/*
//////////////////////////////////////////////
//// HOANVI002 - Hoán vị thần kỳ
// Các phần tử ở cùng một vị trí trong cả A và B đều có chênh lệch bằng K
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		bool check[n + 1] = {0};
		int ok = 1;
		vector<int> v;
		for(int i = n; i >= 1; i--){
			if(i + k > n){
				check[i - k] = 1;
				v.push_back(i - k);
			} else if(i - k <= 0){
				check[i + k] = 1;
				v.push_back(i + k);
			} else{
				if(check[i + k] != 1){
					check[i + k] = 1;
					v.push_back(i + k);
				}else if(check[i - k] != 1){
					check[i - k] = 1;
					v.push_back(i - k);
				}
			}
		}

		for(int i = 1; i <= n; i++){
			if(check[i] == 0){
				ok = -1;
				break;
			}
		}

		if(ok == -1){
			cout << ok << endl;
		}else{
			for(auto it = v.rbegin(); it != v.rend(); it++){
				cout << *it << ' ';
			}
			cout << endl;
		}
	}
}
*/


/*
///////////////////////////////////////////////
//// Day xau fibonaci
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n + 1];
        a[1] = 1;
        a[2] = 1;
        for (int i = 3; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2];
        while (1)
        {
            if (n == 1)
            {
                cout << "A\n";
                break;
            }
            else if (n == 2)
            {
                cout << "B\n";
                break;
            }
            if (k > a[n - 2])
            {
                k -= a[n - 2];
                n--;
            }
            else
                n -= 2;
        }
    }
}
*/