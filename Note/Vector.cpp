library vector
#include <vector>
vector <int> v;
1. v.push_back('angka') //belakang vector diisi dengan 'angka'
2. v.pop_back() //belakang vector dihapus
3. v.size() //panjang vector
4. sort(v.begin(),v.end()); //sort vector 
5. reverse(v.begin(),v.end()); //membalik data vector
6. v.erase(unique(v.begin(),v.end()),v.end()); 
/*
	3241523
	1234523
	12345
*/
7.	lower_bound	(>=)
	upper_bound (>)
