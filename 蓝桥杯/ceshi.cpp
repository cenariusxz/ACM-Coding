#include <bits/stdc++.h>
using namespace std;


int id[30], rid[30];
struct BigInteger {
	int len, s[10010];
	BigInteger() {
		memset(s, 0, sizeof(s));
		len = 1;
	}
	BigInteger(const char *str) {
		memset(s, 0, sizeof(s));
		len = strlen(str);
		for (int i = len - 1; i >= 0; -- i) {
			s[len - i - 1] = id[str[i]-'a'];
		}
	}

	BigInteger(const BigInteger &b) {
		memset(s, 0, sizeof(s));
		len = b.len;
		for (int i = 0; i < len; ++ i) s[i] = b.s[i];
	}

	BigInteger operator -(const BigInteger &b) const {
		BigInteger ans;
		ans.len = max(b.len, len);
		for (int i = 0; i < ans.len; ++ i) {
			ans.s[i] += s[i] - b.s[i];
			if (ans.s[i] < 0) {
				ans.s[i] += 26;
				-- ans.s[i + 1];
			}
		}
		while (ans.len > 1 && ans.s[ans.len - 1] == 0) -- ans.len;
		return ans;
	}

	string str() {
		string ans = "";
		for (int i = len - 1; i >= 0; -- i) {
			ans.push_back(rid[s[i]] + 'a');
		}
		if (ans.empty()) ans = rid[0] + 'a';
		return ans;
	}
};

int cmp(const string &s1, const string &s2) {
	if (s1.length() > s2.length()) return 1;
	else if (s1.length() == s2.length()) {
		for (int i = 0; i < (int)s1.length(); ++ i) {
			if (id[s1[i]-'a'] > id[s2[i]-'a']) return 1;
			else if (id[s1[i]-'a'] < id[s2[i]-'a']) return -1;
		}
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T -- > 0) {
		string s;
		cin >> s;
		for (int i = 0; i < (int)s.length(); ++ i) {
			id[s[i]-'a'] = i;
			rid[i] = s[i] - 'a';
		}
		string s1, s2;
		cin >> s1 >> s2;
		//        reverse(begin(s1), end(s1));
		//       reverse(begin(s2), end(s2));
		if (cmp(s1, s2) > 0) {
			swap(s1, s2);
		}
		BigInteger b1(s1.c_str()), b2(s2.c_str());
		BigInteger ans = (b2 - b1);
		//        for (int i = 0; i < ans.len; ++ i) cout << ans.s[i];
		cout << ans.str() << endl;
	}

	return 0;
}
