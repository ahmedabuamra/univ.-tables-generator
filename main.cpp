#include <bits/stdc++.h>

using namespace std;
// n -> all available times, all -> number of subjects I have to attend
const int n = 46 + 5, all = 12;

int nDay[100], from[100], to[100];
string name[100], g[100], sec[100];

map<string, bool> isTaken; // key is the name of subject

vector<int> taken; // the indexes of taken subjects

set<int> st; // to filter by days counter
vector<vector<int>> filter[10];

int cnt = 0;
void solve(int cur, int prv) {
	if (taken.size() == all) {
		for (int i = 0; i < all; i++) {
			int ind = taken[i];
			st.insert(nDay[ind]);
		}
		filter[st.size()].push_back(taken);
		st.clear();
		cnt++; // to count number of ways! 1024 for group 1!
		return;
	}
	if (cur == n)
		return;

	solve(cur + 1, prv);

	if (!isTaken[name[cur]]
			&& (prv == -1 || nDay[prv] != nDay[cur] || from[cur] >= to[prv])) {
		taken.push_back(cur);
		isTaken[name[cur]] = 1;
		solve(cur + 1, cur);
		taken.pop_back();
		isTaken[name[cur]] = 0;
	}

}

int main() {
	for (int i = 0; i < n; i++) {
		cin >> nDay[i] >> name[i] >> from[i] >> to[i] >> sec[i] >> g[i];
	}
	solve(0, -1);

	int day; cin >> day;
	for (int i = 0; i < filter[day].size(); i++) {
		cout << "Day\tName\t\tFrom\tTo\tSec\tG" << endl;
		for (int j = 0; j < filter[day][i].size(); j++) {
			int ind = filter[day][i][j];
			cout << nDay[ind] << '\t' << name[ind] << '\t';
			if (name[ind].size() < 8)
				cout << '\t';
			cout << from[ind] << '\t' << to[ind] << '\t' << sec[ind] << '\t'
					<< g[ind] << endl << endl;

		}
	}
}
/*
 day name from to  sec gr
 1 prob_Lec 8 10 0   1
 1 math3_Lec 10 14 0 1
 1 IS_Lab 16 18 2 1
 2 math_ex 11 14 1,2 1
 2 math_ex 14 17 3,9 1
 2 IS_Lab 8 10 9 1
 2 IS_Lab 10 12 10 1
 2 IS_Lab 12 14 3 1
 2 IS_Lab 14 16 6 1
 2 IS_Lab 16 18 1 1
 2 IS_Lab 18 20 8 1
 2 prob_ex 14 16 1,2 1
 2 prob_ex 16 18 6,7,8 1
 2 DS_Lab 8 10 10 1
 2 DS_Lab 10 12 5 1
 2 DS_Lab 12 14 9 1
 2 DS_Lab 14 16 8 1
 2 DS_Lab 16 18 2 1
 2 DS_Lab 18 20 7 1
 2 logic_Lab 11 14 4 1
 2 logic_Lab 14 17 5 1
 2 logic_Lab 17 20 3 1

 2 logic_Lec 12 15 0 2
 2 wrtiting_ex 15 16 0 2
 2 writing_Lec 16 18 0 2


 3 math_ex 9 12 7,8 1
 3 math_ex 16 19 4,10 1
 3 IS_Lab 10 12 4 1
 3 IS_Lab 14 16 5 1
 3 prob_ex 14 16 4,9,10 1
 3 prob_ex 16 18 3,5 1
 3 DS_Lab 12 14 4 1
 3 DS_Lab 18 20 3 1
 3 logic_Lab 14 17 8 1
 3 logic_Lab 17 20 9 1

 4 math_ex 14 17 5,6 1
 4 IS_Lab 14 16 7 1
 4 logic_Lab 14 17 10 1
 4 wrtiting_ex 8 9 0 1
 4 writing_Lec 9 11 0 1
 4 IS_Lec 11 14 0 1

 4 prob_Lec 14 16 0 2
 4 math3_Lec 16 20 0 2

 5 DS_Lab 9 11 1 1
 5 DS_Lab 17 19 6 1
 5 logic_Lab 17 20 7 1
 5 DS_Lec 11 14 0 1
 5 logic_Lec 14 17 0 1
 6 logic_Lab 8 11 1 1
 6 logic_Lab 11 14 6 1
 6 logic_Lab 15 18 2 1
 */
