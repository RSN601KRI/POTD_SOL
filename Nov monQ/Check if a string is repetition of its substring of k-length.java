class Solution {
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    if(n % k)
	        return 0;
	        
	    map<vector<int>, int> substr;
	    
	    vector<int> f(26, 0);
	    
	    for(int i = 0; i < n; i += k){
	        for(int j = i - k; j < i and j > -1; j++)
	            --f[s[j] - 'a'];
	        for(int j = i; j < i + k; j++)
	            ++f[s[j] - 'a'];
	        
	        substr[f]++;
	        
	        if(substr.size() > 2)
	            return 0;
	    }
	    
	    int freq = (*substr.begin()).second;
	    
	    return (freq == 1 or freq >= n / k - 1);
	}
};