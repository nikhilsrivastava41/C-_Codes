#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define ll long long int
#define w(t) int t;cin>>t; while(t--)
#define mp make_pair
#define int128 __int128_t
#define pii pair<int,int>
#define fi first
#define se second
#define fr(n) for(int i=0;i<n;i++)
#define rep(j,n) for(int i=j;i<n;i++)
#define um unordered_map
#define M 1000000009
#define pq priority_queue
#define pqm priority_queue <int, vector<int>, greater<int> >
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(t){
		
	}
	return 0;
}
// int fast_expo(ll a, ll b, ll p)
// {

//     if (a == 0)
//         return 0;
//     ll ans = 1;
//     while (b)
//     {
//         if (b & 1)
//             ans *= a, ans %= p;
//         a *= a, a %= p;
//         b /= 2;
//     }
//     return ans;
// }


// ll gcd(ll a, ll b)
// {
// 	if (b == 0)
// 		return a;
// 	return gcd(b, a % b);
//}
// }// void dfs(int s) {
// 	if (visited[s])
// 		return;
// 	visited[s] = true;
// 	// process node s
// 	for (auto u : adj[s]) {
// 		dfs(u);
// 	}
// }
// void bfs(int x) {
// 	visited[x] = true;
// 	distance[x] = 0;
// 	q.push(x);
// 	while (!q.empty()) {
// 		int s = q.front(); q.pop();
// 		// process node s
// 		for (auto u : adj[s]) {
// 			if (visited[u]) continue;
// 			visited[u] = true;
// 			distance[u] = distance[s] + 1;
// 			q.push(u);
// 		}
// 	}
// }

//####### DIJKSTRA'S ALGO ############
// priority_queue<pair<int, int>> q;	first parameter is -ve of distance , second is node
// for (int i = 1; i <= n; i++) {
// 	distance[i] = INF;
// }
// distance[x] = 0;
// q.push({0, x});
// while (!q.empty()) {
// 	int a = q.top().second; q.pop();
// 	if (processed[a]) continue;
// 	processed[a] = true;
// 	for (auto u : adj[a]) {
// 		int b = u.first, w = u.second;
// 		if (distance[a] + w < distance[b]) {
// 			distance[b] = distance[a] + w;
// 			q.push({ -distance[b], b});
// 		}
// 	}