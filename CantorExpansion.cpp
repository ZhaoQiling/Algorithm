#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
long long fact(long long val)
{
	if(val == 0)
   		return 1;
   	long long ans = 1;
   	for(long long i = 1; i <= val; i++)
   		ans *= i;
   	return ans;
}
long long contor(string & s)
{
   long long ans = 0;
   for(long long loc = 0; loc <= s.length() - 1; loc++)
   {
   		string sub = s.substr(loc);
   		sort(sub.begin(), sub.end());
   		long long val = lower_bound(sub.begin(), sub.end(), s[loc]) - sub.begin();
   		ans = ans + fact(s.length() - 1 - loc) * val;
   }
   return ans;
}
string invcontor(long long val, string& s)
{
   sort(s.begin(), s.end());
   std::vector<long long> poly;
   for(long long i = 0; i != s.length(); i++)
   {
      poly.push_back(val / fact(s.length() - 1 - i));
      val = val % (fact(s.length() - 1 - i));
   }
   string ans;
   for(long long i = 0; i < poly.size(); i++)
   {
      //cout << poly[i] << endl;
      //cout << s << endl;
      ans = ans + s[poly[i]];
      s.erase(poly[i], 1);
   }
   return ans;
}
//using long long
int main()
{
   string s;
   cin >> s;
   cout << contor(s) << endl;

   long long val;
   cin >> val;

   string s1;
   cin >> s1;
   cout << invcontor(val, s1) << endl;
   return 0;
}
